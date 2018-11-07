#include "shape.h"

Shape::Shape() : color(1, 0, 0), reflectivity(0), alpha(0)
{
	diffColor = color*0.2;
	specColor = color + White*0.5;
}

Shape::Shape(Color c, double r, double a) : color(c), reflectivity(r), alpha(a)
{
	assert(reflectivity <= 1 && reflectivity >= 0);
	diffColor = color - White*(1-reflectivity);
	specColor = color + White*reflectivity;
}

//##########-----BALL-----##########
Ball::Ball (Vector _center, double _radius, Color _color, double _reflectivity, double _alpha) :
center(_center), radius(_radius), Shape(_color, _reflectivity, _alpha)
{}

double Ball::getRadius()
{
	return radius;
}

Vector Ball::getCenter()
{
	return center;
}

bool Ball::intersect(const Ray& ray, double& t) const
{
	t = MAXDIST;

	Vector v = ray.start - center;
	if (pow(v*ray.direction, 2) - v*v + pow(radius, 2) < 0)
		return false;

	double tempPlus = -v*ray.direction + sqrt(pow(v*ray.direction, 2) - v*v + pow(radius, 2));
	double tempMinus = -v*ray.direction - sqrt(pow(v*ray.direction, 2) - v*v + pow(radius, 2));

	if (tempPlus < 0 && tempMinus < 0)
		return false;

	if (tempPlus < 0 && tempMinus >= 0)
	{
		t = tempMinus;
		return true;
	}

	if (tempPlus >= 0 && tempMinus < 0)
	{
		t = tempPlus;
		return true;
	}

	if (tempPlus < tempMinus)
		t = tempPlus;
	else
		t = tempMinus;
	return true;
}

Vector Ball::getNormal(const Vector& at) const
{
	Vector normal = -(at - center);
	Vector normalized = Normalize(normal);
	return normalized;
}

//##########-----PLANE-----##########
Plane::Plane(Vector _normal, double _distance, Color _color, double _reflectivity, double _alpha) :
normal(Normalize(_normal)), distance(_distance), Shape(_color, _reflectivity, _alpha)
{}

bool Plane::intersect(const Ray& ray, double& t) const
{
	t = MAXDIST;
	double tempT = MAXDIST;

	if (ray.direction*normal == 0)	//Ray is parallel to plane
		return false;
	else
		tempT = (distance - ray.start*normal) / (ray.direction*normal);
	if (tempT < 0)
		return false;
	else
		t = tempT;
	return true;
}

Vector Plane::getNormal(const Vector& at) const
{
	return normal;
}