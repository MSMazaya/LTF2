#pragma once
#include "TrafficLightState.hpp"

class Led
{
public:
	Led(int pin);
	void flicker(int second, int interval);
	void turnOn();
	void turnOnThenDelayInSecond(int second);
	void turnOff();

private:
	int pin;
};
