/* MotorDriver.cpp */

#include "MotorDriver.hpp"
#include "Trace.h"

MotorDriver MotorDriverInstance;

Motor::Motor()
{
}

Motor::~Motor()
{

}

void Motor::SetupPwm(uint8_t pin)
{
    ledcAttachPin(pin, pwmChannel);
    ledcSetup(pwmChannel, PWM_Frequency, PWM_Resolution);
}

void Motor::SetSpeed(uint8_t speed)
{
    this->speed = speed;
    UpdatePwm(false);
}

void Motor::UpdatePwm(bool MotorStateChanged)
{
    if(MotorStateChanged)
    {
        switch(state)
        {
            case MotorState_Forward:
                SetupPwm(pinA);
                ledcWrite(pwmChannel, speed);
                pinMode(pinB, OUTPUT);
                digitalWrite(pinB, 0);
            break;
            case MotorState_Backward:
                SetupPwm(pinB);
                ledcWrite(pwmChannel, speed);
                pinMode(pinA, OUTPUT);
                digitalWrite(pinA, 0);
            break;
            case MotorState_Stop:
                pinMode(pinA, OUTPUT);
                digitalWrite(pinA, 0);
                pinMode(pinB, OUTPUT);
                digitalWrite(pinB, 0);
            break;
            default:
            break;
        }
    }
    else
    {
        if(state != MotorState_Stop)
        {
            ledcWrite(pwmChannel, speed);
        }
    }
}

MotorDriver::MotorDriver()
{
    motorL.pwmChannel = PWM_L_Ch;
    motorR.pwmChannel = PWM_R_Ch;

    motorL.pinA = MOTOR_L1_PIN;
    motorL.pinB = MOTOR_L2_PIN;
    motorR.pinA = MOTOR_R1_PIN;
    motorR.pinB = MOTOR_R2_PIN;
}

MotorDriver::~MotorDriver()
{
}

void MotorDriver::Init()
{
    Stop();
    SetSpeed(SPEED_DEFAULT);
}

/// @brief Stop both Motors
void MotorDriver::Stop()
{
    motorR.state = MotorState_Stop;
    motorL.state = MotorState_Stop;
    motorL.SetSpeed(0);
    motorR.SetSpeed(0);
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::Process()
{
}

void MotorDriver::SetSpeed(uint8_t speed)
{
    motorR.SetSpeed(speed);
    motorL.SetSpeed(speed);
    motorR.UpdatePwm(false);
    motorL.UpdatePwm(false);
}

void MotorDriver::Forward()
{
    motorR.state = MotorState_Forward;
    motorL.state = MotorState_Forward;
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::Backward()
{
    motorR.state = MotorState_Backward;
    motorL.state = MotorState_Backward;
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::Left()
{
    motorR.state = MotorState_Forward;
    motorL.state = MotorState_Stop;
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::Right()
{
    motorR.state = MotorState_Stop;
    motorL.state = MotorState_Forward;
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::RotateClockwise()
{
    motorR.state = MotorState_Backward;
    motorL.state = MotorState_Forward;
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::RotateCounterClockwise()
{
    motorR.state = MotorState_Forward;
    motorL.state = MotorState_Backward;
    motorR.UpdatePwm(true);
    motorL.UpdatePwm(true);
}

void MotorDriver::JoyStickControl(float x, float y)
{

    float overallSpeed = sqrt(x*x + y*y);
    //80...255
    uint8_t pwmOverallSpeed = map(overallSpeed * 255, 0, 255, SPEED_MIN, SPEED_MAX);
    uint8_t pwmXSpeed = map(abs(x) * 255 * overallSpeed, 0, 255, SPEED_MIN, SPEED_MAX);
    uint8_t pwmYSpeed = map(abs(y) * 255 * overallSpeed, 0, 255, SPEED_MIN, SPEED_MAX);

    TRACEPRINTF("overall:%d x:%d y:%d\n", pwmOverallSpeed, pwmXSpeed, pwmYSpeed);

    //lookup quadrant
    if(y==0 && y==0)
    {
        Stop();
    }
    //0...90°
    else if(x<0 && y<0)
    {
        motorL.SetSpeed(pwmYSpeed);
        motorR.SetSpeed(pwmOverallSpeed);
        if(motorR.state != MotorState_Forward || motorL.state != MotorState_Forward)
        {
            motorR.state = MotorState_Forward;
            motorL.state = MotorState_Forward;
            motorR.UpdatePwm(true);
            motorL.UpdatePwm(true);
        }
    }
    //90...180
    else if(x>0 && y<0)
    {
        motorL.SetSpeed(pwmOverallSpeed);
        motorR.SetSpeed(pwmYSpeed);
        if(motorR.state != MotorState_Forward || motorL.state != MotorState_Forward)
        {
            motorR.state = MotorState_Forward;
            motorL.state = MotorState_Forward;
            motorR.UpdatePwm(true);
            motorL.UpdatePwm(true);
        }
    }
    //180...270
    else if(x>0 && y>0)
    {
        motorL.SetSpeed(pwmOverallSpeed);
        motorR.SetSpeed(pwmYSpeed);
        if(motorR.state != MotorState_Backward || motorL.state != MotorState_Backward)
        {
            motorR.state = MotorState_Backward;
            motorL.state = MotorState_Backward;
            motorR.UpdatePwm(true);
            motorL.UpdatePwm(true);
        }
    }
    //270..360
    else if(x<0 && y>0)
    {
        motorL.SetSpeed(pwmYSpeed);
        motorR.SetSpeed(pwmOverallSpeed);
        if(motorR.state != MotorState_Backward || motorL.state != MotorState_Backward)
        {
            motorR.state = MotorState_Backward;
            motorL.state = MotorState_Backward;
             motorR.UpdatePwm(true);
            motorL.UpdatePwm(true);
       }
    }
    else
    {
        //TODO transients...
    }
}