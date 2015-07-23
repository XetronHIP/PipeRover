#include "../Flags.h"

#define buttonPin 2
#define xPin A2
#define yPin A1

bool pressed = false;

int count = 0;

void setup()
{
	pinMode(buttonPin, INPUT_PULLUP);
	pinMode(xPin, INPUT);
	pinMode(yPin, INPUT);
	Serial.begin(BAUD);
}

void loop()
{

	if(!pressed && digitalRead(buttonPin) == LOW)
	{
		pressed = true;
		Serial.println("Button Pressed");
	}
	if(pressed && digitalRead(buttonPin) == HIGH)
	{
		pressed = false;
		Serial.println("Button Released");
	}

	if(count % 20 == 0)
	{
		int xIn = analogRead(xPin);
		int yIn = analogRead(yPin);

		xIn = map(xIn, 0, 1023, 0, 100);
		yIn = map(yIn, 0, 1023, 0, 100);

		if(xIn > 70)
		{
			Serial.println("RIGHT");
		}
		else if(xIn < 40)
		{
			Serial.println("LEFT");
		}

		if(yIn > 65)
		{
			Serial.println("FORWARD");
		}
		else if(yIn < 30)
		{

			Serial.println("BACKWARDS");
		}
	}
	
	count++;
}
