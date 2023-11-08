/*
  Pinout.h - Pin definitions for Abrantix PayTestHub devices Frontend processor
  (c) Abrantix AG
*/

#ifndef __PINOUT_H
#define __PINOUT_H

//peripheral I2C bus (display, crypto...)
#define I2C_SDA_PIN 26
#define I2C_SCL_PIN 27

#define MOTOR_R2_PIN 12
#define MOTOR_R1_PIN 13
#define MOTOR_L2_PIN 14
#define MOTOR_L1_PIN 15

#define HSPI_MISO   12
#define HSPI_MOSI   13
#define HSPI_SCLK   14

#define ULTRASONIC_TRIG_PIN 4
#define ULTRASONIC_ECHO_PIN 2

#define FRONT_BUTTON_PIN  33
#define TWI_SEL_PIN       32


#endif
