#pragma once
#include "Vertex.h"
#include "IsoscelesTriangle.h"
#include "Board.h"
#include "Utilities.h"
#include <math.h>

class Kite
{
public:
	Kite(const IsoscelesTriangle triangles[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	//function methods
	double getTotalHeight()const; //returns the total height of the triangles
	void draw(Board & board)const;//draws the kite to the board
	Rectangle getBoundingRectangle()const;//returns the bounding rectangle
	double getArea()const;//returns the area of the kite
	double getPerimeter()const;
	Vertex getCenter()const;//returns center point of the kite
	bool scale(double);//scale the kite by a given factor
	
private:
	IsoscelesTriangle m_lower, m_upper;//member variables
	bool isTrianglesok(IsoscelesTriangle first, IsoscelesTriangle second)const;//verify the legality of given triangles as a kite
	bool scale(double,Vertex);//scale the kite function overloading
	bool checkRange(IsoscelesTriangle)const;//checks if points are in range
	void init();//init to default values

};

