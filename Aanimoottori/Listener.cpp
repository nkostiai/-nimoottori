#define _USE_MATH_DEFINES
#include "Listener.h"


Listener::Listener(double px, double py, double pz, double sx, double sy, double sz)
{
	this->position = Vector3(px, py, pz);
	this->facing = Vector3(sx, sy, sz);
}

Vector3 Listener::getPosition()
{
	return this->position;
}

Vector3 Listener::getFacing()
{
	return this->facing;
}

void Listener::setPosition(double px, double py, double pz)
{
	this->position = Vector3(px, py, pz);
}

void Listener::setFacing(double sx, double sy, double sz)
{
	this->facing = Vector3(sx, sy, sz);
}

double Listener::getAttenuationByDistance(double distance)
{
	if (distance < 10) {
		return 1;
	}
	else if (distance > 100) {
		return 0;
	}
	else {
		return 1 - (distance / 100);
	}
}

double Listener::getPanningByLocation(Vector3 location)
{
	double angle = this->facing.angle(location);
	if (0 < angle < M_PI) {
		return -(angle / M_PI);
	}
	else {
		return angle / M_PI;
	}
	return 0;
}

double Listener::getDopplerShift(Vector3 location, Vector3 speed) {
	return (100 + this->getFacing().magnitude()) / (100 + speed.magnitude());

}
