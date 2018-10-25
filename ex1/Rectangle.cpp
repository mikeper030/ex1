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
	if (bottomLeft.isValid()&&topRight.isValid())
	{
		m_bottom_left = bottomLeft;
		m_top_right = topRight;
	}
	else {
		//use default values
		m_bottom_left.m_x = default_x_bottom;
		m_bottom_left.m_y = default_y_bottom;
		m_top_right.m_x = default_x_top;
		m_top_right.m_y = default_y_top;
	}

}
Vertex Rectangle::getBottomLeft()const
{
	return Vertex{};
}
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	:Rectangle(Vertex{ x0,y0 }, Vertex{ x1,y1 })
{

}
Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	m_bottom_left = start;
	m_top_right.m_x = width +m_bottom_left.m_x;
	m_top_right.m_y = height + m_bottom_left.m_y;
}


Vertex Rectangle::getTopRight()const
{
	return m_top_right;
}


double Rectangle::getWidth()const
{
 	return m_top_right.m_x - m_bottom_left.m_x;
}


double Rectangle::getHeight()const
{
	return m_top_right.m_y - m_bottom_left.m_y;
}


Rectangle Rectangle::getBoundingRectangle() const
{
	return Rectangle(m_bottom_left,m_top_right);
}


double Rectangle::getArea() const
{
	return ((m_top_right.m_x-m_bottom_left.m_x)*(m_top_right.m_y -m_bottom_left.m_y));
}


double Rectangle::getPerimeter() const
{
	return 2*((m_top_right.m_x - m_bottom_left.m_x)+(m_top_right.m_y - m_bottom_left.m_y));
}


Vertex Rectangle::getCenter() const
{
	return Vertex{getWidth()/2,getHeight()/2};
}
bool isScalingLegal(const Rectangle& rect,double factor)
{
	double origin_width = rect.getWidth();
	double new_width = rect.getWidth()*factor;
	double origin_height = rect.getHeight();
	double new_height = rect.getHeight()*factor;
	//only check new x and y value with max values
	if ((rect.getTopRight().m_x + ((new_width - origin_width) / 2) > MAX_X)||
		rect.getTopRight().m_y + ((new_height - origin_width) / 2) > MAX_Y)
		return false;

	return true;
	
}
bool Rectangle::scale(double factor)
{
	if (factor >= 1) 
	{
		//scale to bigger
		double origin_width = getWidth();
		double new_width = getWidth()*factor;
		m_bottom_left.m_x = m_bottom_left.m_x - ((new_width - origin_width )/ 2);
		m_top_right.m_x = m_top_right.m_x + ((new_width -origin_width )/ 2);
		double origin_height = getHeight();
		double new_height = getHeight()*factor;
		m_bottom_left.m_y = m_bottom_left.m_y - ((new_height -origin_height) / 2);
		m_top_right.m_y = m_top_right.m_y + ((new_height -origin_height) / 2);
	}
	else//scale to smaller
	{
		double origin_width = getWidth();
		double new_width = getWidth()*factor;
		m_bottom_left.m_x = m_bottom_left.m_x + ((origin_width -new_width  ) / 2);
		m_top_right.m_x = m_top_right.m_x - ((origin_width -new_width ) / 2);
		double origin_height = getHeight();
		double new_height = getHeight()*factor;
		m_bottom_left.m_y = m_bottom_left.m_y + ((origin_height-new_height  ) / 2);
		m_top_right.m_y = m_top_right.m_y - ((origin_height-new_height ) / 2);
	}
	return true;
}
void Rectangle::draw(Board&board)const
{
	Vertex m_top_left = { m_bottom_left.m_x,m_top_right.m_y };
	Vertex m_bottom_right = { m_top_right.m_x,m_bottom_left.m_y };
	board.drawLine(m_bottom_left, m_bottom_right);
	board.drawLine(m_bottom_right, m_top_right);
	board.drawLine(m_top_right, m_top_left);
	board.drawLine(m_top_left, m_bottom_left);
}
Rectangle::~Rectangle()
{
}