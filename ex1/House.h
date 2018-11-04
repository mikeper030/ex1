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
	//constructor that initializes by using  objects of
	//rectangle and triangle
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);

	//create the  of House by using parameters of width roofheight and baseHeight
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);
	//function method

	// check if the roof is legal
	bool extendRoof(double width);

	//function returns height of house
	double getHeight()const;

	//draw house by using he draw of rectangle and triangle
	void draw(Board & board) const;

	//function return two points for bounding shape
	Rectangle getBoundingRectangle() const;

	//function return area of House
	double getArea() const;

	//function return Perimeter of house
	double getPerimeter() const;

	//function returns center of house
	Vertex getCenter() const;

	//function doing the scales of house by using scales scales implemented
	//of triangle and rectangle
	bool scale(double factor);

	//function return width difference between roof and basis
	double getWidthDifference()const;



private:
	Rectangle m_rect;
	IsoscelesTriangle m_trig;
	bool isRoofExtensionLegal(double);
	bool isLegal(House&);
	bool valid(Rectangle, IsoscelesTriangle)const;
	bool checkRange(const IsoscelesTriangle&, const Rectangle&)const;
};