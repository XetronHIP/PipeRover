#include "../Flags.h"

//#define DEBUG

#define buttonPin 2
#define xPin A3
#define yPin A1
#define greenPin 7
#define yellowPin 13 

int count = 0;

bool lightOn = false;

void setup()
{
	pinMode(buttonPin, INPUT_PULLUP);
	pinMode(xPin, INPUT);
	pinMode(yPin, INPUT);

	pinMode(greenPin, OUTPUT);
	pinMode(yellowPin, OUTPUT);

	digitalWrite(yellowPin, HIGH);

	Serial.begin(BAUD);
}

void loop()
{

	byte serialOut = 0;

	serialOut |= serialHeader;

	if(count % 20 == 0)
	{
		bool changed = false;

		int xIn = analogRead(xPin);
		int yIn = analogRead(yPin);

		xIn = map(xIn, 0, 1023, 0, 100);
		yIn = map(yIn, 0, 1023, 0, 100);
		
		if(digitalRead(buttonPin) == LOW)
		{
			serialOut |= buttonBit;
			changed = true;
		}

		if(xIn > 70)
		{
			serialOut |= rightBit;
			changed = true;
		}
		else if(xIn < 40)
		{
			serialOut |= leftBit;
			changed = true;
		}

		if(yIn > 65)
		{
			serialOut |= upBit;
			changed = true;
		}
		else if(yIn < 30)
		{
			serialOut |= downBit;
			changed = true;

		}
		count = 0;

		#ifdef DEBUG
		Serial.println(serialOut);
		#else
		Serial.write(serialOut);
		#endif

		lightOn = changed;
	}

	if(lightOn)
	{
		digitalWrite(greenPin, HIGH);
	}
	else
	{
		digitalWrite(greenPin, LOW);
	}
	
	count++;
}
