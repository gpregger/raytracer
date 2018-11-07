#include <iostream>
#include "bitmap.h"
#include "vector3.h"
#include "shape.h"
#include "scene.h"

using namespace std;

void rayTrace(Scene&, Bitmap&, int, int);

int main()
{
	int bmHeight = 512;
	int bmWidth = 512;

	double dist = 2;
	Vector cameraVector(0, 0, -dist);
	Vector lightVector(10, 10, -1);
	Color lightColor = White;
	Color backgroundColor = Color(0.1, 0, 0.1);

	Scene* scene1 = new Scene(cameraVector, lightVector, lightColor, backgroundColor);
	Ball* ball1 = new Ball(Vector(1.5, 0, 5), 1, Color(1, 0, 0), 0.1, 1);
	Ball* ball2 = new Ball(Vector(0, 1.5, 5), 1, Color(1, 1, 0), 0.2, 1);
	Ball* ball3 = new Ball(Vector(-1, -1, 5), 0.75, Color(0, 1, 0), 0.8, 1);
	Plane* plane1 = new Plane(Vector(0, 1, 0), -1.5, White, 0.01, 1);

	scene1->addShape(ball1);
	scene1->addShape(ball2);
	scene1->addShape(ball3);
	scene1->addShape(plane1);

	/*DEBUG
	double test = 0;
	Ray testray(Vector(0, 0, 1), Vector(0, 0, 0));
	ball1->intersect(testray,test);
	cout << test << " -- " << ball1->getNormal(testray.direction*test) <<endl;
	*/
	
	Bitmap bitmap(bmWidth, bmHeight);

	rayTrace(*scene1, bitmap, bmWidth, bmHeight);
	
	return 0;
}

void rayTrace(Scene& scene, Bitmap& bitmap, int bmWidth, int bmHeight)
{
	int iterations = 0;
	for (int y = 0; y < bmHeight; ++y)
	{
		for (int x = 0; x < bmWidth; ++x)
		{
			Vector planePoint((double(x) / bmWidth)-0.5, (-double(y) / bmHeight)+0.5, 0);
			Ray tRay(planePoint - scene.cameraVector, planePoint);
			bitmap(x, y) = AdjustColor(scene.traceRay(tRay, iterations));
		}
	}

	bitmap.Save("RayTrace.bmp");
}