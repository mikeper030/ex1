#pragma once
#include "IsoscelesTriangle.h"
#include "Rectangle.h"
class House
{
public:
	House();
	//ksdjhfakjhaf
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);
	bool extendRoof(double width);
	double getHeight()const;
	double getWidthDifferent()const;
	~House();
};

