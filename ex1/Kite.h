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
	//returns the total height of the triangles
	double getTotalHeight()const; 
	//draws the kite to the board
	void draw(Board & board)const;
	//returns the bounding rectangle
	Rectangle getBoundingRectangle()const;
	//returns the area of the kite
	double getArea()const;
	double getPerimeter()const;
	//returns center point of the kite
	Vertex getCenter()const;
	//scale the kite by a given factor
	bool scale(double);
	
private:
	//member variables
	IsoscelesTriangle m_lower, m_upper;
	//verify the legality of given triangles as a kite
	bool isTrianglesok(IsoscelesTriangle first, IsoscelesTriangle second)const;
	//scale the kite function overloading
	bool scale(double,Vertex);
	//checks if points are in range
	bool checkRange(IsoscelesTriangle)const;
	//init to default values
	void init();
};

