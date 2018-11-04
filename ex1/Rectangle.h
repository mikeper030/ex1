#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"
#include "macros.h"
class Rectangle
{
public:
	
	Rectangle(const Vertex veritces[2]);//first is bot_left,second is top_right
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(double x0, double y0, double x1, double y1);//coordinates ltr bottom,top
	Rectangle(const Vertex& start, double width, double height);
	//function methods
	Vertex getBottomLeft() const;
	Vertex getTopRight()const;
	double getWidth() const;//return the base width
	double getHeight() const;
	void draw(Board & board) const;//draw the rectangle on the board
	Rectangle getBoundingRectangle() const;//returns the bounding rectangle
	double getArea() const;//returns the area of th rectangle
	double getPerimeter() const;
	Vertex getCenter() const;//returns center point of rectangle
	bool scale(double factor);//regular scale
	bool scale(double factor, Vertex center);//complex scale for kite or house


private:
	Vertex m_bottom_left,m_top_right; //private member variables
	void init() ;//init with default values
	bool valid(Vertex&,Vertex&);//checks points in range

};

