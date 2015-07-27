#include "common.h"

void setup() {
 Serial.begin (9600);
 pinMode(trigPinF, OUTPUT);
 pinMode(echoPinF, INPUT);
 pinMode(trigPinL, OUTPUT);
 pinMode(echoPinL,INPUT);
 pinMode(trigPinR, OUTPUT);
 pinMode(echoPinR, INPUT);
 pinMode(wheelLeftPos, OUTPUT);
 pinMode(wheelRightPos, OUTPUT);
 pinMode(wheelLeftNeg, OUTPUT);
 pinMode(wheelRightNeg, OUTPUT);
 pinMode(LEDPin,OUTPUT);
}
