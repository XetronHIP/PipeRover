#include "../Flags.h"

#include <Servo.h>

#define solenoidPin 7
#define m1 3
#define m2 5

bool solenoid = false;
bool buttonPressed = false;

Servo motor1;
Servo motor2;

char butter[64];

void setup()
{
	pinMode(solenoidPin, OUTPUT);
	pinMode(13, OUTPUT);

	digitalWrite(solenoidPin, HIGH);

	Serial.begin(BAUD);

	motor1.attach(m1);
	motor2.attach(m2);

	motor1.writeMicroseconds(1500);
	motor2.writeMicroseconds(1500);
}

void loop()
{
	if(!solenoid && buttonPressed)
	{
		digitalWrite(solenoidPin, LOW);
		digitalWrite(13, HIGH);
		delay(200);
		digitalWrite(solenoidPin, HIGH);
		digitalWrite(13, LOW);
		solenoid = true;
		Serial.println("Ding!");
	}
	else if(solenoid && !buttonPressed)
	{
		solenoid = false;
	}

	while(Serial.available() > 0)
	{
		int mSpeed1 = 0;
		int mSpeed2 = 0;

		byte input = Serial.readBytes(butter, 1);

		input = butter[0]; 

		if((input & upBit) == upBit)
		{
			Serial.println("UP");
			mSpeed1 -= 250;
			mSpeed2 -= 250;
		}
		else if((input & downBit) == downBit)
		{
			Serial.println("DOWN");
			mSpeed1 += 250;
			mSpeed2 += 250;
		}
		if((input & leftBit) == leftBit)
		{
			Serial.println("LEFT");
			mSpeed2 += 250;
			mSpeed1 -= 250;
		}
		else if((input & rightBit) == rightBit)
		{
			Serial.println("RIGHT");
			mSpeed1 += 250;
			mSpeed2 -= 250;
		}
		if((input & buttonBit) == buttonBit)
		{
			buttonPressed = true;
			Serial.println("Button Pressed");
		}
		else
		{
			buttonPressed = false;
		}

		motor1.writeMicroseconds(1500 + mSpeed1);
		motor2.writeMicroseconds(1500 + mSpeed2);
	}
}
