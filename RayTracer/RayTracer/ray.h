#ifndef RAY_H
#define RAY_H

#include "vector3.h"

struct Ray
{
	Vector direction;
	Vector start;

	Ray(Vector, Vector);
	Ray();
};


Ray reflectRay(Ray incoming, Vector normal, Vector hitpoint);

Ray shadowRay(Vector hitpoint, Vector light, Vector normal);

#endif