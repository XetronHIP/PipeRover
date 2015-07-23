#include "../Flags.h"

#define solenoidPin 7
#define motorPin 3

void setup()
{
	pinMode(solenoidPin, OUTPUT);
	pinMode(motorPin, OUTPUT);

	Serial.begin(BAUD);
}

void loop()
{

}
