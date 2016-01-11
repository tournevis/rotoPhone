#ifndef RotoPhone_h
#define RotoPhone_h
#endif

#include "Arduino.h"
class RotoPhone{
  public :
    RotoPhone(uint8_t pin1, uint8_t pin2, bool pullUp = true);
    int8_t number();
    unsigned long numTime();
    bool isNum();
    void debug();
  private :
    uint8_t _number;
    int8_t _finalNumber;
    uint8_t _pin1;
    uint8_t _pin2;
    uint8_t _lastState;
    unsigned long _startTime  ;
    unsigned long _finalTime;
    bool _state1;
    bool _state2;
    bool _isNum;
    bool _pullUp;
};
