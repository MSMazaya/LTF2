#include "States.hpp"
#include <Arduino.h>

void Jalan::change(TrafficLight *traffic_light)
{
	traffic_light->setState(SiapHenti::getInstance());
}

void Jalan::enter(TrafficLight *traffic_light)
{
	traffic_light->greenLed->turnOnThenDelayInSecond(10);
}

void Jalan::action(TrafficLight *traffic_light)
{
	traffic_light->greenLed->turnOn();
}

void Jalan::exit(TrafficLight *traffic_light)
{
	traffic_light->greenLed->turnOff();
}

TrafficLightState &Jalan::getInstance()
{
	static Jalan singleton;
	return singleton;
}

void SiapHenti::change(TrafficLight *traffic_light)
{
	traffic_light->setState(Berhenti::getInstance());
}

void SiapHenti::action(TrafficLight *traffic_light)
{
	traffic_light->yellowLed->flicker(10, 1000);
	traffic_light->change();
}

void SiapHenti::exit(TrafficLight *traffic_light)
{
	traffic_light->yellowLed->turnOff();
}

TrafficLightState &SiapHenti::getInstance()
{
	static SiapHenti singleton;
	return singleton;
}

void Berhenti::change(TrafficLight *traffic_light)
{
	traffic_light->setState(Jalan::getInstance());
}

void Berhenti::action(TrafficLight *traffic_light)
{
	traffic_light->redLed->turnOnThenDelayInSecond(10);
	traffic_light->change();
}

void Berhenti::exit(TrafficLight *traffic_light)
{
	traffic_light->redLed->turnOff();
}

TrafficLightState &Berhenti::getInstance()
{
	static Berhenti singleton;
	return singleton;
}
