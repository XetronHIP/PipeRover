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

		Serial.print("X: "); Serial.print(xIn);
		Serial.print("\tY: "); Serial.println(yIn);
	}

	count++;
}
