/*
  AxButton.h - I2C Button interface for PayTestHub devices Frontend processor
  (c) Abrantix AG
*/

#ifndef __AXBUTTON_H
#define __AXBUTTON_H

#include <Arduino.h>
#include "Pinout.h"
#include "CoreDefinitions.h"


#define DEBOUNCE 20  // button debouncer, how many ms to debounce, 5+ ms is usually plenty

#define NUMBUTTONS 1

typedef enum _BUTTON_TYPE
{
  BUTTON_TYPE_FRONT = 0,
  BUTTON_TYPE_UP,
  BUTTON_TYPE_DOWN,
  BUTTON_TYPE_HALT,
} BUTTON_TYPE;

/* Flags */
typedef enum _BUTTON_OPTION
{
	BUTTON_OPTION_NONE = 0,
	BUTTON_OPTION_INVERTED = 1,
	BUTTON_OPTION_ENABLE_PULLUP = 2,
} BUTTON_OPTION;

typedef struct _ButtonEntry
{
  BUTTON_TYPE Button;
  byte  ButtonPin;
  BUTTON_OPTION ButtonOptions;
  uint16_t analogCount;
  uint32_t analogSum;
} ButtonEntry, *PButtonEntry;

extern ButtonEntry buttons[NUMBUTTONS];

typedef struct _ButtonStatus
{
  unsigned long PressStart;
  unsigned long PressStop;
  byte Pressed:1;
	byte JustPressed:1;
	byte JustReleased:1;
} ButtonStatus, *PButtonStatus;

class AxButton
{
public:
  AxButton();
  void Process();
  void Init();
  bool IsButtonPressed(BUTTON_TYPE button);
  bool IsButtonJustPressed(BUTTON_TYPE button);
  bool IsButtonJustReleased(BUTTON_TYPE button);
  unsigned long GetLastPressDuration(BUTTON_TYPE button);
  unsigned long GetCurrentPressDuration(BUTTON_TYPE button);

private:
	// we will track if a button is just pressed, just released, or 'currently pressed' 
  ButtonStatus buttonStatus[NUMBUTTONS];
};

#endif
