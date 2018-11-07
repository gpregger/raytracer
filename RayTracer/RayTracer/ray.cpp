#include "ray.h"

Ray::Ray(Vector _direction, Vector _start) :
direction(Normalize(_direction)), start(_start)
{}

Ray::Ray() :
direction(Vector(1, 0, 0)), start(Vector())
{}

Ray reflectRay(Ray incoming, Vector normal, Vector hitpoint)
{
	Ray reflectRay((incoming.direction - 2 * normal*(incoming.direction*normal)), hitpoint);
	return reflectRay;
}

Ray shadowRay(Vector hitpoint, Vector light, Vector normal)
{
	Ray shadowRay(-light, hitpoint + normal*0.0001);
	return shadowRay;
}