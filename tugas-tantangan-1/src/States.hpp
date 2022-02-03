#pragma once
#include "TrafficLightState.hpp"

class Jalan : public TrafficLightState
{
public:
	void enter(TrafficLight *traffic_light);
	void change(TrafficLight *traffic_light);
	void exit(TrafficLight *traffic_light);
	void action(TrafficLight *traffic_light);
	static TrafficLightState &getInstance();

private:
	Jalan() {}
	Jalan(const Jalan &other);
	Jalan &operator=(const Jalan &other);
};

class SiapHenti : public TrafficLightState
{
public:
	void enter(TrafficLight *traffic_light) {}
	void change(TrafficLight *traffic_light);
	void exit(TrafficLight *traffic_light);
	void action(TrafficLight *traffic_light);
	static TrafficLightState &getInstance();

private:
	SiapHenti() {}
	SiapHenti(const SiapHenti &other);
	SiapHenti &operator=(const SiapHenti &other);
};

class Berhenti : public TrafficLightState
{
public:
	void enter(TrafficLight *traffic_light) {}
	void change(TrafficLight *traffic_light);
	void exit(TrafficLight *traffic_light);
	void action(TrafficLight *traffic_light);
	static TrafficLightState &getInstance();

private:
	Berhenti() {}
	Berhenti(const Berhenti &other);
	Berhenti &operator=(const Berhenti &other);
};