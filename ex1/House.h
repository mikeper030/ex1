#pragma once
#include "IsoscelesTriangle.h"
#include "Rectangle.h"
#include "Board.h"
#include "Vertex.h"
#include "Utilities.h"
#include"Rectangle.h"
#include "IsoscelesTriangle.h"
class House
{
public:
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);
	//function method
	bool extendRoof(double width);
	double getHeight()const;
	void draw(Board & board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	double getWidthDifference()const;

	

private:
	Rectangle m_rect;
	IsoscelesTriangle m_trig;
	bool isRoofExtensionLegal(double);
	bool isLegal(House&);
	bool valid(Rectangle, IsoscelesTriangle)const;
	bool checkRange(const IsoscelesTriangle&,const Rectangle&)const;
};

