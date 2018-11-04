#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"
#include <math.h>
class IsoscelesTriangle
{
public:
	//create triangle by capturing points from left to right
	IsoscelesTriangle(const Vertex vertices[3]);
	//function methods
	//center is bottom left 
	IsoscelesTriangle(const Vertex& center, double width, double height);
	//returns vertex by index
	Vertex getVertex(int index)const;
	//returns the base length
	double getLength()const;
	double getScelesLength()const;
	double getHeight()const;
	//draws the triagle to the board
	void draw(Board & board) const;
	//returns the bounding rectangle
	Rectangle getBoundingRectangle() const;
	//returns the area
	double getArea() const;
	double getPerimeter() const;
	//returns the center vertex
	Vertex getCenter() const;
	//simple scale
	bool scale(double factor);
	//complex scale for kite or house
	bool scale(double factor, Vertex center,bool);
	
private:
	//private member variable
	Vertex m_vertices[3];
	//init to default values
	void init(); 
	//returns if both left and right vertices are parallel
	bool parallel()const;
	//verify vertices range
	bool checkRange(Vertex,Vertex,Vertex) const;
	//check validity of triangle by given rules
	bool valid(Vertex,Vertex,Vertex);

};

