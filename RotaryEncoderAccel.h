// -----
// RotaryEncoderAccel.h - Library for using rotary encoders.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// -----
// 18.01.2014 created by Matthias Hertel
// -----

#ifndef RotaryEncoderAccel_h
#define RotaryEncoderAccel_h

#include "Arduino.h"

#define LATCHSTATE 3

class RotaryEncoderAccel
{
public:
  // ----- Constructor -----
  RotaryEncoderAccel(int pin1, int pin2);

  // retrieve the current position
  int  getPosition();

  // adjust the current position
  void setPosition(int newPosition);

  // call this function every some milliseconds or by using an interrupt for handling state changes of the rotary encoder.
  void tick(void);

  // Switches acceleration mode (fast response)
  void setAccel(unsigned int value1, int value2);

private:
  int _pin1, _pin2; // Arduino pins used for the encoder.

  int8_t _oldState;

  unsigned int accel;
  int multipleter;
  unsigned long prevTick;

  int _position;     // Internal position (4 times _positionExt)
  int _positionExt;  // External position
};

#endif

// End
