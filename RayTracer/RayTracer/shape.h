#ifndef SHAPE_H
#define SHAPE_H

const int MAXDIST = 10000;

#include <cmath>
#include <cassert>
#include "vector3.h"
#include "ray.h"
#include "bitmap.h"

//##########-----SHAPE-----##########
class Shape
{
public:
	Color color;
	Color diffColor;
	Color specColor;
	double reflectivity;
	double alpha;

	Shape();
	Shape(Color, double, double);

	virtual bool intersect(const Ray& ray, double& t) const = 0;
	virtual Vector getNormal(const Vector& at) const = 0;
};

//##########-----BALL-----##########
class Ball :public Shape
{
private:
	double radius;
	Vector center;
public:
	Ball(Vector, double, Color, double, double);
	bool intersect(const Ray& ray, double& t) const;
	Vector getNormal(const Vector& at) const;
	double getRadius();
	Vector getCenter();
};

//##########-----PLANE-----##########
class Plane :public Shape
{
private:
	Vector normal;
	double distance;
public:
	Plane(Vector, double, Color, double, double);
	bool intersect(const Ray& ray, double& t) const;
	Vector getNormal(const Vector& at) const;
};

#endif