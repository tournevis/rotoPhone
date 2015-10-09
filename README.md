# RotoPhone

Simple lib to control rotary dial with Arduino
### Fonction

  **number()**

return -1 if nothing was type. If user input a number return it once at the end of the keyboard rotation.

  **numTime()**
return a unsigned long , it time of the numerotation 

  **debug()**

print value on each loop in serial. Don't forget to init your serial to use this function



### Usage

**Code:**
```
#include <RotoPhone.h>

//Declare Rotophone Object
int number ;
RotoPhone roto(4,5);

void setup() {
  // if you use debug don't forget to init Serial
   Serial.begin(9600);
   number = 0;
}
void loop() {
  number = roto.number();
  if(number>= 0){
    Serial.println(number);
    Serial.println(roto.numTime());
  }

  // print value on each loop
  roto.debug();
  delay(20);
}
```

**Prototype :**

![](http://i.imgur.com/mYJ91SB.png)
### WIP
