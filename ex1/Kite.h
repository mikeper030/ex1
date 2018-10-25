#pragma once
#include "Vertex.h"
#include "IsoscelesTriangle.h"
class Kite
{
public:
	Kite();
	Kite(const IsoscelesTriangle triangles[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	double getTotalHeight()const;
	void draw(Board&board)const;
	Rectangle getBoundingRectangle()const;
	double getArea()const;
	double getPerimeter()const;
	Vertex getCenter()const;
	bool scale(double);
	~Kite();
private:
	bool isTrianglesok(IsoscelesTriangle first, IsoscelesTriangle second)const;
	IsoscelesTriangle m_upper,m_lower;

};

