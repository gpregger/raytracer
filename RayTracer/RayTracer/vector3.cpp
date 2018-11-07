#include "vector3.h"


Vector& operator += (Vector& l, const Vector& r)
{
    l.x += r.x;
    l.y += r.y;
    l.z += r.z;
    return l;
}

Vector& operator -= (Vector& l, const Vector& r)
{
    l.x -= r.x;
    l.y -= r.y;
    l.z -= r.z;
    return l;
}

Vector& operator *= (Vector& l, const double r)
{
    l.x *= r;
    l.y *= r;
    l.z *= r;
    return l;
}

Vector& operator /= (Vector& l, const double r)
{
    l.x /= r;
    l.y /= r;
    l.z /= r;
    return l;
}

Vector operator -(const Vector& r)
{
    return Vector (-r.x, -r.y, -r.z);
}

double operator * (const Vector& l, const Vector& r)
{
 return l.x * r.x + l.y * r.y + l.z * r.z;
}

std::ostream& operator << (std::ostream& out, const Vector& r)
{
    return out << r.x << " " << r.y << " " << r.z;
}

Vector operator + (Vector l, const Vector& r)
{
    return l += r;
}

Vector operator - (Vector l, const Vector& r)
{
    return l -= r;
}

Vector operator * (Vector l, const double r)
{
    return l *= r;
}

Vector operator * (const double l, Vector r)
{
    return r *= l;
}

Vector operator / (Vector l, const double r)
{
    return l /= r;
}

double Norm (const Vector& v)
{
    return std::sqrt(v*v);
}

Vector Normalize (const Vector& v)
{
   return v / Norm(v);
}