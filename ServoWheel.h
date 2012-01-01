// Wheel

// Wraps Servo in a construct that makes continuous rotation easier
// Write values range from -1.0 to 1.0
// Values beyond this range will pass through the software layer and are
// only limited by your servo.
// but it is preferrable to modify calibration.

// Lesson Learned: PinMode in constructor's called before init don't work
// FIXME: Servo.h is uncooperative when being imported
// TODO: Remove personal calibration because that's not cool.

#ifndef _SERVOWHEEL_H_
#define _SERVOWHEEL_H_

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Wheel.h>
#include <Servo.h> // FIXME: Why is this broken?

class ServoWheel : public Wheel {
  public:
    ServoWheel(int pin, int directionMultiplier);
    void write(double speed);
  
  private:
    const int _pin;
    const int _directionMultiplier;
    Servo _servo;
    boolean _started;
    
    void start();
};

#endif
