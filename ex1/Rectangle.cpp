#include "Rectangle.h"
#include "macros.h"
const double default_x_bottom = 20, default_y_bottom = 10;
const double default_x_top = 30, default_y_top = 20;

//default constructor
Rectangle::Rectangle()
{
}
//first element is bottom left second is top right
Rectangle::Rectangle(const Vertex vertices[2])
	:Rectangle(vertices[0], vertices[1])
{

}
//2 vertices 
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (bottomLeft.isValid&&topRight.isValid)
	{
		bottom_left = bottomLeft;
		top_right = topRight;
	}
	else {
		//use default values
		bottom_left.m_x = default_x_bottom;
		bottom_left.m_y = default_y_bottom;
		top_right.m_x = default_x_top;
		top_right.m_y = default_y_top;
	}

}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	:Rectangle(Vertex{ x0,y0 }, Vertex{ x1,y1 })
{

}
Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	bottom_left = start;
	top_right.m_x = width + bottom_left.m_x;
	top_right.m_y = height + bottom_left.m_y;
}
Vertex Rectangle::getTopRight()const
{
	return top_right;
}
double Rectangle::getWidth()const
{
	return top_right.m_x - bottom_left.m_x;
}
double Rectangle::getHeight()const
{
	return top_right.m_y - top_right.m_y;
}
Rectangle::~Rectangle()
{
}