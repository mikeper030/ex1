#pragma once
#include "IsoscelesTriangle.h"
#include "Rectangle.h"
#include "Board.h"

class House
{
public:
	House();
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);
	bool extendRoof(double width);
	double getHeight()const;
	double getWidthDifferent()const;
	//function method
	void draw(Board & board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	~House();
};

