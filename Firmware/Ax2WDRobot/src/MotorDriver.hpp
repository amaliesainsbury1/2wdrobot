/* MotorDriver.hpp */

#ifndef __MOTOR_H
#define __MOTOR_H

#pragma once

#include <Arduino.h>
#include "Pinout.h"

#define PWM_Resolution  8
#define PWM_Frequency   5000

#define PWM_L_Ch        2
#define PWM_R_Ch        3

#define SPEED_MIN         130
#define SPEED_DEFAULT     200
#define SPEED_MAX         255

enum MotorState
{
    MotorState_Stop,
    MotorState_Forward,
    MotorState_Backward,
};

class Motor
{ 
private:
    uint8_t speed;
    void SetupPwm(uint8_t pin);

public:
    MotorState state;
    uint8_t pinA;
    uint8_t pinB;
    uint8_t pwmChannel;

    Motor();
    ~Motor();
    void SetSpeed(uint8_t speed);
    void UpdatePwm(bool MotorStateChanged);
};

class MotorDriver
{
private:
    Motor motorR;
    Motor motorL;
    void UpdatePwm(bool MotorStateChanged);

public:
  MotorDriver();
  ~MotorDriver();
  void Init();
  void Process();
  void Stop();
  void SetSpeed(uint8_t speed);
  void Forward();
  void Backward();
  void Left();
  void Right();
  void RotateClockwise();
  void RotateCounterClockwise();
  void JoyStickControl(float x, float y);
};

extern MotorDriver MotorDriverInstance;

#endif