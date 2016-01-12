#include "Arduino.h"
#include "RotoPhone.h"

RotoPhone::RotoPhone(uint8_t pin1, uint8_t  pin2, int8_t  pin3  ,bool pullUp){
  //Turn on pull up resistor in the arduino to avoid short circuit
  _pullUp = pullUp;
  _startTime = 0;

  if(pullUp){
    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2,  INPUT_PULLUP);
    if(pin3 != -1){
      pinMode(pin3, INPUT);
    }
  }else{
    pinMode(pin1, INPUT);
    pinMode(pin2,  INPUT);
    if(pin3 != -1){
      pinMode(pin3, INPUT_PULLUP);
    }
  }
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
}

int8_t RotoPhone::number(){
  _state1  = digitalRead(_pin1);
  _state2 = digitalRead(_pin2);

  if(_pullUp){
    if (_isNum && _state1 == HIGH && _lastState == LOW ) {
      _number ++ ;
    }
  }else{
    if (_isNum && _state1 == LOW && _lastState == HIGH) {
      _number ++ ;
    }
  }
  if (_state1 == _state2 ) {
    _isNum = true;
    if(_startTime == 0 ){
      _startTime = millis();
    }
  }else{
    if(_finalNumber != _number ){
      _finalTime = millis() - _startTime;
    }
    _finalNumber = _number ;
    _isNum = false;
    _startTime = 0;
    //return _finalNumber =-1 ;
  //  if(_pullUp){ _finalNumber = _number -1 ; }else{ _finalNumber = _number ;}
    //return number;
    _number = -1;
  }
  _lastState = digitalRead(_pin2);
  delay(5);
  return _finalNumber;

}
bool RotoPhone::isNum(){
  return _isNum;
}
unsigned long RotoPhone::numTime(){
  return _finalTime;
}

bool RotoPhone::isPick(){

  if(_pin3 != -1){

    _pinBRead = digitalRead(_pin3);


    if( _state3 != _pinBRead ) {
      _state3 = _pinBRead;
      _startTimePickChange = millis();
      _pickChanged = true;
    }

    if(_pickChanged){
      if(millis() - _startTimePickChange > 100){
        _state4 = _state3;
        _pickChanged = false;
      }
    }
    return _state4;

    // if( _pinBRead != _lastPinBState ) {
    //   _startTimePickChange = millis();
    // }
    //
    // if ((millis() - _startTimePickChange) > 10) {
    //   if ( _pinBRead != _pinBState ) {
    //     _pinBState = _pinBRead;
    //     return _pinBState;
    //   }
    // }

    //_lastPinBState = _pinBRead;

  } else {
    Serial.println("You need to set Pin 3 ! ");
  }
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
