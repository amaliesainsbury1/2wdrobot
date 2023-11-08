/*
  AxButton.cpp - I2C Button interface for PayTestHub devices Frontend processor
  (c) Abrantix AG
*/


#include <Wire.h>
#include "Trace.h"
#include "AxButton.h"

#define BATTERY_MILLIS_OFFSET -50

ButtonEntry buttons[NUMBUTTONS] = 
{
  { BUTTON_TYPE_FRONT,  FRONT_BUTTON_PIN, BUTTON_OPTION_INVERTED, 0, 0 },
}; 

AxButton::AxButton()
{
}


void AxButton::Init()
{
  analogSetAttenuation(ADC_11db);
  for (int i=0; i<NUMBUTTONS; i++) 
  {
    byte inputType = BUTTON_OPTION_ENABLE_PULLUP & buttons[i].ButtonOptions ? INPUT_PULLUP : INPUT;
    
    pinMode(buttons[i].ButtonPin, inputType);
  }
}

unsigned long AxButton::GetCurrentPressDuration(BUTTON_TYPE button)
{
  return millis() - buttonStatus[button].PressStart;
}

unsigned long AxButton::GetLastPressDuration(BUTTON_TYPE button)
{
	return buttonStatus[button].PressStop - buttonStatus[button].PressStart;
}

bool AxButton::IsButtonPressed(BUTTON_TYPE button)
{
  return buttonStatus[button].Pressed;
}

bool AxButton::IsButtonJustPressed(BUTTON_TYPE button)
{
  return buttonStatus[button].JustPressed;
}

bool AxButton::IsButtonJustReleased(BUTTON_TYPE button)
{
  return buttonStatus[button].JustReleased;
}

void AxButton::Process()
{
  static byte previousstate[NUMBUTTONS];
  static byte currentstate[NUMBUTTONS];
  static unsigned long lasttime;
  byte index;

  for (index = 0; index < NUMBUTTONS; index++) {
    buttonStatus[index].JustPressed = 0;       // when we start, we clear out the "just" indicators
    buttonStatus[index].JustReleased = 0;
  }
  
  if (millis() < lasttime) {
     lasttime = millis(); // we wrapped around, lets just try again
  }
 
  if ((lasttime + DEBOUNCE) > millis()) {
    return; // not enough time has passed to debounce
  }
  // ok we have waited DEBOUNCE milliseconds, lets reset the timer
  lasttime = millis();
 
  for (index = 0; index < NUMBUTTONS; index++) {
    uint16_t currentAnalogValue = analogReadMilliVolts(buttons[index].ButtonPin) * 2;   // read the button
    //don't count while button is pressed
    if(currentAnalogValue > 1000)
    {
      buttons[index].analogSum += currentAnalogValue;
      buttons[index].analogCount++;
    }
    //Average 
    if(buttons[index].analogCount >= 200)
    {
      //Serial.print()
      uint16_t averageMilliVolts = (uint16_t)(roundf((buttons[index].analogSum / buttons[index].analogCount)/10.0) * 10) + BATTERY_MILLIS_OFFSET;
      //TRACELN(averageMilliVolts);
      AxDisplayInstance.UpdateBatteryVoltage(averageMilliVolts);
      buttons[index].analogSum = 0;
      buttons[index].analogCount = 0;
    }
    currentstate[index] = currentAnalogValue < 1000;
    
    if(0 != (BUTTON_OPTION_INVERTED & buttons[index].ButtonOptions))
    {
      currentstate[index] = !currentstate[index];
    }
    if (currentstate[index] == previousstate[index]) 
	  {
      if ((buttonStatus[index].Pressed == LOW) && (currentstate[index] == LOW)) 
  	  {
          // just Pressed
  		    buttonStatus[index].PressStart = millis();
          buttonStatus[index].JustPressed = 1;
          TRACE(F("Just Pressed Button "));
          TRACELN(index);
      }
      else if ((buttonStatus[index].Pressed == HIGH) && (currentstate[index] == HIGH)) 
  	  {
          // just released
  		    buttonStatus[index].PressStop = millis();
          buttonStatus[index].JustReleased = 1;
          TRACE(F("Just released Button "));
          TRACE(index);
  		    TRACE(F(" duration:"));
  		    TRACELN(buttonStatus[index].PressStop - buttonStatus[index].PressStart);
      }
      buttonStatus[index].Pressed = !currentstate[index];  // remember, digital HIGH means NOT Pressed
  }
      //Serial.println(Pressed[index], DEC);
    previousstate[index] = currentstate[index];   // keep a running tally of the buttons
  }
}
