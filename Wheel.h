// Wheel

// Wraps Servo in a construct that makes continuous rotation easier
// Write values range from -1 to 1. Values beyond this range -will- work
// but it is preferrable to modify calibration.

// Lesson Learned: PinMode in constructor's called before init don't work
// FIXME: Servo.h is uncooperative when being imported
// TODO: Remove personal calibration out of wheel abstraction because that's not cool.

#ifndef _WHEEL_H_
#define _WHEEL_H_

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <Servo.h> // FIXME: Why is this broken?

class Wheel {
  public:
    Wheel(int pin, int directionMultiplier);
    void write(double speed);
    double read() const;
    void stop() {return write(0);};
  
  private:
    const int _pin;
    const int _directionMultiplier;
    double _speed;
    Servo _servo;
    boolean _started;
    
    void start();
};

#endif
