#pragma once
#include "Vertex.h"
#include "Board.h"
#include "IsoscelesTriangle.h"


class Kite
{
public:
	Kite();
	Kite(const IsoscelesTriangle triangles[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	double getTotalHeight()const;
	//function method
	void draw(Board & board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	~Kite();
};

