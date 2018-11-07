#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <algorithm>
#include "bitmap.h"
#include "vector3.h"
#include "ray.h"
#include "shape.h"

using namespace std;

class Scene
{
private:
	Shape* intersect(const Ray&, double&) const;

public:
	Vector cameraVector;
	Vector lightVector;
	Color lightColor;
	Color backgroundColor;

	vector<Shape*> shapeVec;

	Scene(Vector, Vector, Color, Color);

	void addShape(Shape*);
	Color traceRay(const Ray&, int) const;
};


#endif