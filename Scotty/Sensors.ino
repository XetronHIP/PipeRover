#include "common.h" 

int maximumRange = 50; // Maximum range needed
int minimumRange = 10; // Minimum range needed
long duration, distance; // Duration used to calculate distance 

int getForwardDistance() {
  return getDistance(trigPinF, echoPinF);
}

int getRightDistance() {
  return getDistance(trigPinL, echoPinL);
}
int getLeftDistance() {
  return getDistance(trigPinR, echoPinR);
}
int getDistance(int trigPin, int echoPin) {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(20); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(100); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 if (distance > 150)
 {
   distance=150;
 }
 return distance; 
}
    
