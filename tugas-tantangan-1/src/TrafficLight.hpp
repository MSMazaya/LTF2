#pragma once
#include "TrafficLightState.hpp"
#include "Led.hpp"

// Forward declaration to resolve circular dependency/include
class TrafficLightState;
class Led;

class TrafficLight
{
public:
	Led *greenLed;
	Led *yellowLed;
	Led *redLed;
	TrafficLight(Led *green, Led *yellow, Led *red);
	inline TrafficLightState *getCurrentState() const { return currentState; }
	void change();
	void setState(TrafficLightState &newState);
	void actionBasedOnState();

private:
	TrafficLightState *currentState;
};
