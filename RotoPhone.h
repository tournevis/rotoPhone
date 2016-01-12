#ifndef RotoPhone_h
#define RotoPhone_h
#endif

#include "Arduino.h"
class RotoPhone{
  public :
    RotoPhone(uint8_t pin1, uint8_t pin2, int8_t pin3 = 0, bool pullUp = false);
    int8_t number();
    unsigned long numTime();
    bool isNum();
    bool isPick();
    void debug();
  private :
    uint8_t _number;
    int8_t _finalNumber;
    uint8_t _pin1;
    uint8_t _pin2;
    int8_t _pin3;
    uint8_t _lastState;
    uint8_t  _pinBState;
    uint8_t  _pinBRead;
    uint8_t _lastPinBState;
    unsigned long _startTime;
    unsigned long _startTimePickChange;
    unsigned long _finalTime;
    bool _state1;
    bool _state2;
    bool _state3;
    bool _state4;
    bool _pickChanged;
    bool _isNum;
    bool _pullUp;
};
