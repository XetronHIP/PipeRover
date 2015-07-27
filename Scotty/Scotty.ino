#include "common.h"

void loop() {
  


  //github practice

  int leftDis=getLeftDistance();
  String leftText = "Left:";
  String lString = leftText + leftDis;
  Serial.println(lString);
  
  int rightDis=getRightDistance();
  String rightText = "Right:";
  String rString = rightText + rightDis;
  Serial.println(rString);
  
  int frontDis=getForwardDistance();
  String frontText = "Front:";
  String fString = frontText + frontDis;
  Serial.println(fString);

  





 if (frontDis > minDis && leftDis > minDis && rightDis > minDis) 
  {
      forward();
      Serial. println("forwrd");
  }  
  else if (leftDis < 10)
  {
  right();
  }
  else if (rightDis < 10)
  {
    left();
  }
  else if ( frontDis < minDis)
  {
      if (leftDis < minDis)
      {  
        right();
        Serial. println("right");
      } 
      else if ( frontDis < 5 )
      {
        backward();
        Serial. println("back");
      }
      else
      {
        left();
        Serial. println("left");
      }      
  }
  else {
     robotStop();
  } 
  
  
     delay(500);  
}   

   
