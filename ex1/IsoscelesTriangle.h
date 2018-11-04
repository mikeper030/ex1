#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"
#include <math.h>
class IsoscelesTriangle
{
public:

	IsoscelesTriangle(const Vertex vertices[3]);//create triangle by capturing points from left to right
	IsoscelesTriangle(const Vertex& center, double width, double height);//center is bottom left 
	//function methods
	Vertex getVertex(int index)const;//returns vertex by index
	double getLength()const;//returns the base length
	double getScelesLength()const;
	double getHeight()const;
	void draw(Board & board) const;//draws the triagle to the board
	Rectangle getBoundingRectangle() const;//returns the bounding rectangle
	double getArea() const;//returns the area
	double getPerimeter() const;
	Vertex getCenter() const;//returns the center vertex
	bool scale(double factor);//simple scale
	bool scale(double factor, Vertex center,bool);//complex scale for kite or house
	
private:
	Vertex m_vertices[3];//private member variable
	void init(); //init to default values
	bool parallel()const;//returns if both left and right vertices are parallel
	bool checkRange(Vertex,Vertex,Vertex) const;//verify vertices range
	bool valid(Vertex,Vertex,Vertex);//check validity of triangle by given rules

};

