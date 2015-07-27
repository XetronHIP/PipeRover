#include "../Flags.h"

#define solenoidPin 7
#define motorPin 3

bool solenoid = false;
bool buttonPressed = false;

void setup()
{
	pinMode(solenoidPin, OUTPUT);
	pinMode(motorPin, OUTPUT);

	digitalWrite(solenoidPin, HIGH);

	Serial.begin(BAUD);
}

void loop()
{
	if(!solenoid && buttonPressed)
	{
		digitalWrite(solenoidPin, LOW);
		delay(200);
		digitalWrite(solenoidPin, HIGH);
		solenoid = true;
	}
	else if(solenoid && !buttonPressed)
	{
		solenoid = false;
	}
}

void SerialEvent()
{
	byte input = Serial.read();

	#ifdef DEBUG
	Serial.println(input);
	#endif

	if((input & serialHeader) == serialHeader)
	{
		byte data = input & serialHeader;

		if((data & buttonBit) == buttonBit)
		{
			Serial.println("Button Pressed");
			buttonPressed = true;
		}

		if((data & leftBit) == leftBit)
		{
			Serial.println("Left Pressed");
		}

		if((data & rightBit) == rightBit)
		{
			Serial.println("Right Pressed");
		}

		if((data & upBit) == upBit)
		{
			Serial.println("Up Pressed");
		}

		if((data & downBit) == downBit)
		{
			Serial.println("Down Pressed");
		}
	}
}
