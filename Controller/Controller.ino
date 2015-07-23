#include "../Flags.h"

#define buttonPin 2
#define xPin A3
#define yPin A1

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

	byte serialOut = 0;

	serialOut |= serialHeader;

	if(digitalRead(buttonPin) == LOW)
	{
		serialOut |= buttonBit;
	}

	if(count % 20 == 0)
	{
		int xIn = analogRead(xPin);
		int yIn = analogRead(yPin);

		xIn = map(xIn, 0, 1023, 0, 100);
		yIn = map(yIn, 0, 1023, 0, 100);

		if(xIn > 70)
		{
			serialOut |= rightBit;
		}
		else if(xIn < 40)
		{
			serialOut |= leftBit;
		}

		if(yIn > 65)
		{
			serialOut |= upBit;
		}
		else if(yIn < 30)
		{
			serialOut |= downBit;
		}
		count = 0;

		Serial.write(serialOut);

	}
	
	count++;
}
