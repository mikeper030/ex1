#pragma once
#include "IsoscelesTriangle.h"
#include "Rectangle.h"
class House
{
public:
	House();
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);
	double getHeight()const;
	double getWidthDifferent()const;
	~House();
};
