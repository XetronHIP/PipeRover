#include "common.h"

 void left() {
     Serial.println("left");
     digitalWrite(wheelLeftPos, LOW); 
     digitalWrite(wheelRightPos, LOW);
     digitalWrite(wheelLeftNeg, HIGH );
     digitalWrite(wheelRightNeg, LOW ); 
 }
 
 void right()  {
     Serial.println("right");
     digitalWrite(wheelLeftPos,HIGH); 
     digitalWrite(wheelRightPos,LOW);
     digitalWrite(wheelLeftNeg,LOW);
     digitalWrite(wheelRightNeg,LOW);
 }
 
 void robotStop()  {
     Serial.println("stop");
     digitalWrite(wheelLeftPos, LOW); 
     digitalWrite(wheelRightPos, LOW);
     digitalWrite(wheelLeftNeg, LOW);
     digitalWrite(wheelRightNeg, LOW);
  }
  
  void forward()  {
     Serial.println("Forwards");
     digitalWrite(wheelLeftPos, HIGH); 
     digitalWrite(wheelRightPos, HIGH);
     digitalWrite(wheelLeftNeg, LOW );
     digitalWrite(wheelRightNeg, LOW );
  }
  
 
 void backward() {
     Serial.println("backward");
     digitalWrite(wheelLeftPos, LOW); 
     digitalWrite(wheelRightPos, LOW);
     digitalWrite(wheelLeftNeg, HIGH );
     digitalWrite(wheelRightNeg, HIGH);
 }
