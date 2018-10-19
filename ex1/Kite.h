#pragma once
#include "Vertex.h"
#include "IsoscelesTriangle.h"
#include "Board.h"
#include "Rectangle.h"
class Kite
{
public:
	Kite();
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	Kite(const IsoscelesTriangle triangles[2]);
	double getTotalHeight()const;
	void draw(Board&board)const;
	Rectangle getBoundingRectangle()const;
	double getArea()const;
	double getPerimeter()const;
	Vertex getCenter()const;
	bool scale(double factor)const;
	~Kite();
private:
	IsoscelesTriangle upper,lower;

};

