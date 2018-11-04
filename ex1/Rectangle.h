#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"
#include "macros.h"
class Rectangle
{
public:
	//first is bot_left,second is top_right
	Rectangle(const Vertex veritces[2]);
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	//coordinates ltr bottom,top
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	//function methods
	Vertex getBottomLeft() const;
	Vertex getTopRight()const;
	//return the base width
	double getWidth() const;
	double getHeight() const;
	//draw the rectangle on the board
	void draw(Board & board) const;
	//returns the bounding rectangle
	Rectangle getBoundingRectangle() const;
	//returns the area of th rectangle
	double getArea() const;
	double getPerimeter() const;
	//returns center point of rectangle
	Vertex getCenter() const;
	//regular scale
	bool scale(double factor);
	//complex scale for kite or house
	bool scale(double factor, Vertex center);


private:
	//private member variables
	Vertex m_bottom_left,m_top_right; 
	//init with default values
	void init() ;
	//checks points in range
	bool valid(Vertex&,Vertex&);

};

