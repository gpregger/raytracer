#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>


struct Vector{
	double x, y, z;
	Vector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
	Vector() : x(0), y(0), z(0){}
};

Vector& operator += (Vector& l, const Vector& r);

Vector& operator -= (Vector& l, const Vector& r);

Vector& operator *= (Vector& l, const double r);

Vector& operator /= (Vector& l, const double r);

Vector operator -(const Vector& r);

double operator * (const Vector& l, const Vector& r);

std::ostream& operator << (std::ostream& out, const Vector& r);

Vector operator + (Vector l, const Vector& r);

Vector operator - (Vector l, const Vector& r);

Vector operator * (Vector l, const double r);

Vector operator * (const double l, Vector r);

Vector operator / (Vector l, const double r);

double Norm(const Vector& v);

Vector Normalize(const Vector& v);

#endif