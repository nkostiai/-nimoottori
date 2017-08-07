#pragma once
#include "Vector3.h"

class Listener {
public:
	Listener(double px, double py, double pz, double fx, double fy, double fz);
	Vector3 getPosition();
	Vector3 getFacing();
	void setPosition(double px, double py, double pz);
	void setFacing(double px, double py, double pz);
	virtual double getAttenuationByDistance(double distance);
	virtual double getPanningByLocation(Vector3 location);
	virtual double getDopplerShift(Vector3 location, Vector3 speed);
private:
	Vector3 position;
	Vector3 facing;

};