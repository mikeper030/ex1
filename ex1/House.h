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
	//function methods
	bool extendRoof(double width);//extendes the roof by given width
	double getHeight()const; //return the total height of the house
	void draw(Board & board) const;//draw the house to the board
	Rectangle getBoundingRectangle() const;//returns the bounding rectangle
	double getArea() const;//returns the total area of the house
	double getPerimeter() const;
	Vertex getCenter() const;//returns the total height of the house
	bool scale(double factor);//scale the house by a given factor
	double getWidthDifference()const;//returns the width difference of roof and base

	

private:
	Rectangle m_rect;  //private member variable
	IsoscelesTriangle m_trig; //private member variable
	bool isRoofExtensionLegal(double);//checks if the given roof extension is legal
	bool isLegal(House&);//checks if the house is in range
	bool valid(Rectangle, IsoscelesTriangle)const;//check if the rectangle and triangle objects are valid by given rules
	bool checkRange(const IsoscelesTriangle&,const Rectangle&)const;//check if the house object is legal by given rulse
};

