#pragma once
#include "TrafficLight.hpp"

class TrafficLight;

class TrafficLightState
{
public:
	virtual void enter(TrafficLight *traffic_light) = 0;
	virtual void change(TrafficLight *traffic_light) = 0;
	virtual void exit(TrafficLight *traffic_light) = 0;
	virtual void action(TrafficLight *traffic_light) = 0;
	virtual ~TrafficLightState() {}
};