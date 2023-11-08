/*  
    CameraHandler.h
*/

#ifndef __CAMERA_HANDLER
#define __CAMERA_HANDLER

#include <Arduino.h>
#include "esp_camera.h"
#include "Trace.h"

// Select camera model
//#define CAMERA_MODEL_WROVER_KIT // Has PSRAM
//#define CAMERA_MODEL_ESP_EYE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_PSRAM // Has PSRAM
//#define CAMERA_MODEL_M5STACK_V2_PSRAM // M5Camera version B Has PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_ESP32CAM // No PSRAM
//#define CAMERA_MODEL_M5STACK_UNITCAM // No PSRAM
#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#define CAMERA_MODEL_TTGO_T_JOURNAL // No PSRAM

//#define CONFIG_LED_ILLUMINATOR_ENABLED
//#define CONFIG_LED_MAX_INTENSITY 255
//#define CONFIG_LED_LEDC_CHANNEL LEDC_CHANNEL_1

#define OV5640_AF_CMD_MAIN   0x3022
#define OV5640_AF_CMD_ACK    0x3023
#define OV5640_AF_CMD_PARA0  0x3024
#define OV5640_AF_CMD_PARA1  0x3025
#define OV5640_AF_CMD_PARA2  0x3026
#define OV5640_AF_CMD_PARA3  0x3027
#define OV5640_AF_CMD_PARA4  0x3028
#define OV5640_AF_FW_STATUS  0x3029
#define OV5640_AF_SC_POWER_CONTROL 0x3031

#define OV5640_TRIG_AUTO_FOCUS       0x03
#define OV5640_RELEASE_FOCUS         0x08
#define OV5640_RELAUNCH_FOCUS_ZONES  0x12

#include "camera_pins.h"

typedef enum _AF_STATUS
{
  AF_STATUS_UNKNOWN = 0xEE,
  AF_STATUS_FW_NOT_RUNNING = 0x7F,
  AF_STATUS_STARTUP = 0x7E,
  AF_STATUS_IDLE = 0x70,
  AF_STATUS_FOCUSING = 0x00,
  AF_STATUS_FOCUSED = 0x10,

} AF_STATUS;

 class CameraHandler 
{
public:
  CameraHandler();
  void Init();
  void Process();

private:
  sensor_t * sensor;
  AF_STATUS afStatus;
  uint8_t ledValue;

  bool WaitForRegisterValue(int reg, int mask, int expectedValue, uint16_t timeoutMillis);
};

extern CameraHandler CameraHandlerInstance;

#endif