#include "TrafficLight.hpp"
#include "States.hpp"
#include "Led.hpp"

TrafficLight::TrafficLight(Led *green, Led *yellow, Led *red)
{
	this->greenLed = green;
	this->redLed = red;
	this->yellowLed = yellow;
	currentState = &Jalan::getInstance();
}

void TrafficLight::setState(TrafficLightState &newState)
{
	currentState->exit(this);
	currentState = &newState;
	currentState->enter(this);
}

void TrafficLight::change()
{
	currentState->change(this);
}

void TrafficLight::actionBasedOnState()
{
	currentState->action(this);
}