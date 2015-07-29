#include "../Flags.h"

#define solenoidPin 7
#define motorPin 3

bool solenoid = false;
bool buttonPressed = false;

char butter[64];

void setup()
{
	pinMode(solenoidPin, OUTPUT);
	pinMode(motorPin, OUTPUT);
	pinMode(13, OUTPUT);

	digitalWrite(solenoidPin, HIGH);

	Serial.begin(BAUD);
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

		byte input = Serial.readBytes(butter, 1);

		input = butter[0]; 

		if((input & upBit) == upBit)
		{
			Serial.println("UP");
		}
		else if((input & downBit) == downBit)
		{
			Serial.println("DOWN");
		}
		if((input & leftBit) == leftBit)
		{
			Serial.println("LEFT");
		}
		else if((input & rightBit) == rightBit)
		{
			Serial.println("RIGHT");
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
	}
}
