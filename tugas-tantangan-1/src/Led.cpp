#include "Led.hpp"
#include <Arduino.h>

Led::Led(int input_pin)
{
	pin = input_pin;
	pinMode(input_pin, OUTPUT);
}

void Led::flicker(int second, int interval)
{
	int secondCounter = 0;
	int ledState = LOW;
	while (secondCounter != 10)
	{
		if (ledState == LOW)
		{
			ledState = HIGH;
		}
		else
		{
			ledState = LOW;
		}
		digitalWrite(pin, ledState);
		delay(1000);
		secondCounter++;
	}
};

void Led::turnOn()
{
	digitalWrite(pin, HIGH);
};

void Led::turnOnThenDelayInSecond(int second)
{
	digitalWrite(pin, HIGH);
	delay(second * 1000);
};

void Led::turnOff()
{
	digitalWrite(pin, LOW);
};