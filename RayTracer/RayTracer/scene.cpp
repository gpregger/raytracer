#include "scene.h"

using namespace std;

Scene::Scene(Vector cv, Vector lv, Color lc, Color bc) :
cameraVector(cv), lightVector(lv), lightColor(lc), backgroundColor(bc)
{}

void Scene::addShape(Shape* shape)
{
	shapeVec.push_back(shape);
}

Color Scene::traceRay(const Ray& ray, int iterations) const
{ 
	Color resultColor(0,0,0);
	Color recursion(0, 0, 0);
	double t = MAXDIST;
	Shape* interShape = intersect(ray, t);
	//cout << ray.direction << endl;
	//cout << t << endl;								//DEBUG
	if (t < MAXDIST)								//Intersection found intersecting shape interShape
	{
		Vector hitpoint = ray.direction*t;
		//cout << hitpoint << endl;						//DEBUG
		resultColor = resultColor + interShape->color;
		Vector interShapeNormal = interShape->getNormal(hitpoint);

		Ray sRay = shadowRay(hitpoint, lightVector, interShapeNormal);
		Ray rRay = reflectRay(ray, interShapeNormal, hitpoint);

		double shadowT = MAXDIST;
		intersect(sRay, shadowT);

		if (shadowT = MAXDIST)						//No intersection until MAXDIST is reached
		{
			resultColor = resultColor + lightColor * interShape->diffColor * (sRay.direction * interShapeNormal);
			resultColor = resultColor + lightColor * interShape->specColor * pow((rRay.direction * sRay.direction), 8);
		}

		if (iterations < 5)
		{
			recursion = traceRay(rRay, ++iterations);
			resultColor = resultColor + recursion*interShape->specColor;
		}
	}

	else
		resultColor = resultColor + backgroundColor;
	return resultColor;
}

Shape* Scene::intersect(const Ray& ray, double& t) const
{
	if (!shapeVec.empty())
	{
		vector<double> tVec;
		double tempT;

		for_each(shapeVec.begin(), shapeVec.end(), [&ray, &tVec, &tempT](Shape* ishape)	//try to intersect ray with every shape
		{
			tempT = MAXDIST;
			ishape->intersect(ray, tempT);
			tVec.push_back(tempT);
		});

		/*for (vector<double>::iterator it = tVec.begin(); it != tVec.end(); ++it)
			cout << *it << endl;*/
		vector<double>::iterator min = min_element(tVec.begin(), tVec.end());
		t = *min;
		int shapeindex = min - tVec.begin();	//get the index of the first intersection
		return shapeVec[shapeindex];			//return shape* at that index
	}
}