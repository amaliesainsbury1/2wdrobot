# Abrantix Ax2WDRobot

![Assembled Ax2WDRobot](Doc/assembly/final.png)

## Overview
The Ax2WDRobot is a 2 Wheel-Drive platform based on espressif's ESP32 module. It is WIFI controlled and has the following features:
- WIFI controlled over an integrated Web-Browser. Supports any platform. *No* Android/Iphone app required
- OLED 128x64 display
- 2 independently controlled DC motors
- Omnivision camera module
- Ultrasonic distance sensor
- 6-axis gyroscope (no firmware support so far)
- LiIon powered (18650 cell)
- Charging and programming over USB-C connector
- Easy to assemble; No soldering required

## Assembly
[Assembly instructions](Doc/assembly_instructions.md)

## Programming
[Programming instructions](Doc/programming.md)

## Troubleshooting
*My Ax2WDRobot doesn't turn on*
1. The battery protection circuit prevents powering on as long as there was no initial charge from USB port.
    - Insert the battery, then connect a USB cable (either from PC or from a USB charger) to start charging/enabling the battery.
    
    
*I can't update the firmware; Error during firmware Upload*
1. Please make sure that the required drivers are installed on the machine. For manual installation, see https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
2. The *Ax2WDRobot* requires a charged battery and must be turned on to upload the firmware

