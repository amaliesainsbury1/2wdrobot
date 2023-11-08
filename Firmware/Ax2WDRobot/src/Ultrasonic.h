#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

#include "Pinout.h"

#define ULTRASONIC_INTERVAL_MILLIS 300
#define ULTRASONIC_MAX_DISTANCE_CM 200

class Ultrasonic 
{
public:
  Ultrasonic();
  void Init();
  void Process();

private:
  unsigned long lastReadMillis;
};


#endif 