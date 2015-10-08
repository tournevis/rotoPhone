#include "Arduino.h"
#include "RotoPhone.h"

RotoPhone::RotoPhone(uint8_t pin1, uint8_t  pin2, bool pullUp){
  //Turn on pull up resistor in the arduino to avoid short circuit
  _pullUp = pullUp;
  if(pullUp){
    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2,  INPUT_PULLUP);
  }else{
    pinMode(pin1, INPUT);
    pinMode(pin2,  INPUT);
  }
  _pin1 = pin1;
  _pin2 = pin2;
}

int8_t RotoPhone::number(){
  _state1  = digitalRead(_pin1);
  _state2 = digitalRead(_pin2);
  if(_pullUp){
    if (_isNum && _state1 == HIGH && _lastState ==LOW ) {
      _number ++ ;
    }
  }else{
    if (_isNum && _state1 == LOW && _lastState == HIGH) {
      _number ++ ;
    }
  }
  if (_state1 == _state2 ) {
    _isNum = true;
  }else{
    _finalNumber = _number;
    _isNum = false;

    //return _finalNumber =-1 ;
  //  if(_pullUp){ _finalNumber = _number -1 ; }else{ _finalNumber = _number ;}
    //return number;


    _number = -1;
  }
  _lastState =digitalRead(_pin2);
  delay(10);
  return _finalNumber;

}
void RotoPhone::debug(){
  //if(Serial.available() > 0){
    Serial.print("Pin state are : Pin1 : ");
    Serial.print(_state1);
    Serial.print("    Pin state are Pin2 : ");
    Serial.print(_state2);
    Serial.print("    And current number is : ");
    Serial.println( _number);
//  }
}
