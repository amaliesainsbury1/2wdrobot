#include <Arduino.h>
#include <SPI.h>
#include <ArduinoOTA.h>
#include "CoreDefinitions.h"
#include "CameraHandler.h"
#include "MotorDriver.hpp"
#include "Ultrasonic.h"
#include "Bitmap.h"

//
// WARNING!!! PSRAM IC required for UXGA resolution and high JPEG quality
//            Ensure ESP32 Wrover Module or other board with PSRAM is selected
//            Partial images will be transmitted if image exceeds buffer size
//

AxWebServer axWebServer;
AxButton axButton;
Ultrasonic ultrasonic;
bool alwaysFalse = false;
unsigned long startupCompleteMillis;

//forward declarations
bool setFuses();
void configureOTA();
void processButtons();
void OnNetworkChanged();

void setup() {
  #ifdef SERIAL_TRACE
    Serial.begin(SERIAL_TRACE_BAUDRATE);
  #endif

  // Force the FLASH voltage regulator to 3.3v, disabling "MTDI" strapping check at startup
  bool fusesChanged = setFuses();

  if(fusesChanged)
  {
    TRACELN("Fuse setting changed");
  }

  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  Wire.setClock(400000L);

  //Camera and Display use same I2C address so we will switch Clk line between those two devices/buses
  //LOW: Display
  //HIGH: Camera
  pinMode(TWI_SEL_PIN, OUTPUT);

  AxDisplayInstance.Init(&Wire);
  AxDisplayInstance.DisplayBitmap(epd_bitmap_picasso, 1024);
  delay(3000);
  AxDisplayInstance.Display("Examining\nHardware");

  MotorDriverInstance.Init();

  /* Hack to assure that VERSION_PROGMEM isn't optimized away from binary firmware file */
  if(alwaysFalse)
  {
    Serial.print(VERSION_PROGMEM);
  }

  Serial.setDebugOutput(true);
  Serial.println("Startup...");

  AxEEPROMInstance.Init();
  axButton.Init();
  ultrasonic.Init();
  axWebServer.Init();
  AxNetworkInstance.Setup(&(EEPROMData.IPConfiguration));
  AxNetworkInstance.ConnectionChanged = OnNetworkChanged;
  CameraHandlerInstance.Init();

  startupCompleteMillis = millis();
}

void loop() 
{
  axWebServer.Process();
  AxDisplayInstance.Process();
  axButton.Process();
  AxNetworkInstance.Process();
  ultrasonic.Process();
  processButtons();
  CameraHandlerInstance.Process();
  MotorDriverInstance.Process();
}


void OnNetworkChanged()
{
  TRACELN("Restarting Webserver");
  axWebServer.OnNetworkChanged();
}

void factoryReset()
{
    TRACELN("FACTORY RESET");
    //Perform factory reset but keep MAC address;
    AxDisplayInstance.Display("\n  FACTORY RESET\n");
    AxEEPROMInstance.LoadEEPROM(true);
    delay(3000);
    ESP.restart();
}

void processButtons()
{
  if(axButton.IsButtonJustPressed(BUTTON_TYPE_FRONT))
  {
    TRACELN("Disable Screen Saver");
    AxDisplayInstance.DisableScreenSaver();
    AxDisplayInstance.DisplayBitmap(epd_bitmap_monalisa, 1024);
    delay(3000);
  }

  /* Check if Front button was pressed for long time - either directly at startup or at a later time */
  if(axButton.IsButtonPressed(BUTTON_TYPE_FRONT))
  {
    if(5000 <= axButton.GetCurrentPressDuration(BUTTON_TYPE_FRONT))
    {
      TRACE("front button pressed for ");
      TRACE(millis() - startupCompleteMillis - axButton.GetCurrentPressDuration(BUTTON_TYPE_FRONT));
      TRACE(" ms since start ");
      TRACELN();
      if(3000 > millis() - startupCompleteMillis - axButton.GetCurrentPressDuration(BUTTON_TYPE_FRONT))
      {
        factoryReset();
      }
      else
      {
        //Perform soft reset;
        AxDisplayInstance.Display("\n     REBOOT\n");
        delay(3000);
        ESP.restart();
      }
    }
  }
}

// Force the FLASH voltage regulator to 3.3v, disabling "MTDI" strapping check at startup
//https://github.com/espressif/esp-idf/tree/release/v3.2/examples/storage/sd_card#note-about-gpio12
bool setFuses()
{
  bool changed = false;
  
  //burning SDIO_TIEH -> sets SDIO voltage regulator to pass-thru 3.3v from VDD
  if ((REG_READ(EFUSE_BLK0_RDATA4_REG) & EFUSE_RD_SDIO_TIEH) == 0) 
  {changed = true; esp_efuse_reset(); REG_WRITE(EFUSE_BLK0_WDATA4_REG, EFUSE_RD_SDIO_TIEH); esp_efuse_burn_new_values();} 

  //burning SDIO_REG -> enables SDIO voltage regulator (otherwise user must hardwire power to SDIO)
  if ((REG_READ(EFUSE_BLK0_RDATA4_REG) & EFUSE_RD_XPD_SDIO_REG) == 0) 
  {changed = true; esp_efuse_reset(); REG_WRITE(EFUSE_BLK0_WDATA4_REG, EFUSE_RD_XPD_SDIO_REG); esp_efuse_burn_new_values();} 

  //burning SDIO_FORCE -> enables SDIO_REG and SDIO_TIEH
  if ((REG_READ(EFUSE_BLK0_RDATA4_REG) & EFUSE_RD_SDIO_FORCE) == 0) 
  {changed = true; esp_efuse_reset(); REG_WRITE(EFUSE_BLK0_WDATA4_REG, EFUSE_RD_SDIO_FORCE); esp_efuse_burn_new_values();} 

  return changed;
}
