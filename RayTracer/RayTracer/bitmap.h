#ifndef BITMAP_H
#define BITMAP_H

#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>

//##########-----COLOR-----##########//
struct Color
{
	float r, g, b;

	Color();
	Color(float, float, float);

	Color& operator += (Color);
	Color& operator -= (Color);
	Color& operator *= (float);
	Color& operator *= (Color);
};

Color operator + (Color a, const Color& b);

Color operator - (Color a, const Color& b);

Color operator * (Color a, const Color& b);


Color operator * (Color a, const float b);

Color operator * (const float b, Color a);

std::ostream& operator << (std::ostream& out, Color color);

bool operator == (const Color& a, const Color& b);

bool operator != (const Color& a, const Color& b);

Color AdjustColor(Color c);



const Color Red(1, 0, 0);
const Color Green(0, 1, 0);
const Color Blue(0, 0, 1);
const Color Black(0, 0, 0);
const Color White(1, 1, 1);

//##########-----BITMAP-----##########//
class Bitmap
{
public:
	Bitmap(unsigned, unsigned);

	Color& operator () (unsigned, unsigned);
	Color operator () (unsigned, unsigned) const;

	unsigned GetWidth() const;
	unsigned GetHeight() const;

	void Fill(Color);
	void Save(const char*) const;

private:
	unsigned width, height;
	std::vector<Color> pixels;

	static void Write(std::ostream&, float);
	static void Write(std::ostream&, unsigned, int);
};

#endif