#pragma once
#include <math.h>
struct Vector3 {
	double x;
	double y;
	double z;
	
	Vector3(double x, double y, double z) :
		x(x), y(y), z(z)
	{

	}

	Vector3() {
		x = y = z = 0;
	}

	double Vector3::distance(Vector3 o) {
		//Returns the absolute of the distance between two points
		double xDist = (this->x - o.x) * (this->x - o.x);
		double yDist = (this->y - o.y) * (this->y - o.y);
		double zDist = (this->z - o.z) * (this->z - o.z);
		double fullDist = xDist + yDist + zDist;
		return sqrt(fullDist);
	}

	double Vector3::dotProduct(Vector3 o) {
		//Returns the dot product of two vectors
		double result;
		result = (this->x * o.x) + (this->y * o.y) + (this->z * o.z);
		return result;
	}

	double Vector3::magnitude() {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	double Vector3::angle(Vector3 o) {
		//Returns the angle between two vectors in radians
		return acos((this->dotProduct(o)) / (this->magnitude() * o.magnitude()));
	}
};