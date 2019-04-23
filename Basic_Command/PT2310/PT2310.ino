#include "PT231X.h"

PT2310 uPA;

int dataPin = 2;
int clockPin = 3;
int stbPin = 4;
int csVal = HIGH;

void setup() {
  uPA.begin(clkPin,dataPin,stbPin,csVal);

  for(int a = 0; a <= 40; a++){
    uPA.Volume(a);
  }
  for(int a = 39; a >= 0; a--){
    uPA.Volume(a);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
