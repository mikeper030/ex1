#include "Rectangle.h"

const double default_x_bottom = 20, default_y_bottom = 10;
const double default_x_top = 30, default_y_top = 20;


//first element is bottom left second is top right
Rectangle::Rectangle(const Vertex vertices[2])
	:Rectangle(vertices[0], vertices[1])
{
	//empty constructor because delegation is being used
}
//2 vertices 
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	Vertex t1 = bottomLeft, t2 = topRight;
	if ((!bottomLeft.isValid() || !topRight.isValid()) || !valid(t1, t2))
	{
		//reset to default values
		init();
	}
	else
	{
		m_bottom_left = bottomLeft;
		m_top_right = topRight;
	}

}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	:Rectangle(Vertex{ x0,y0 }, Vertex{ x1,y1 })
{
	
}
Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	
	m_bottom_left = start;
	m_top_right.m_x = start.m_x+width ;
	m_top_right.m_y = start.m_y+height;
	Vertex v1{ m_bottom_left }, v2{ m_top_right };
	if ((!v1.isValid() || !v2.isValid()) || !valid(v1, v2))
	{
		//reset to default values
		init();
	}
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
	return getHeight()*2+getWidth()*2;
}

void Rectangle::init()
{
	m_bottom_left.m_x = default_x_bottom;
	m_bottom_left.m_y = default_y_bottom;
	m_top_right.m_x = default_x_top;
	m_top_right.m_y = default_y_top;
}

Vertex Rectangle::getBottomLeft()const
{
	return Vertex{ m_bottom_left.m_x,m_bottom_left.m_y };
}

Vertex Rectangle::getCenter() const
{
	return Vertex{m_bottom_left.m_x+getWidth()/2,m_bottom_left.m_y+getHeight()/2};
}
//intended to be used when scaling kite or house
bool Rectangle::scale(double factor, Vertex center)
{
	Rectangle temp(m_bottom_left,m_top_right);
	if (sameY(center,m_top_right))
	{
		if (factor >= 1)
		{
			//scale to bigger
			double origin_width = getWidth();
			double new_width = getWidth()*factor;
			double origin_height = getHeight();
			double new_height = getHeight()*factor;
			temp.m_bottom_left.m_x = temp.m_bottom_left.m_x - ((new_width - origin_width) / 2);
			temp.m_top_right.m_x = temp.m_top_right.m_x + ((new_width - origin_width) / 2);
			
			temp.m_bottom_left.m_y = temp.m_bottom_left.m_y - ((new_height - origin_height));
			
		}
		else//scale to smaller
		{
			double origin_width = getWidth();
			double new_width = getWidth()*factor;
			double origin_height = getHeight();
			double new_height = getHeight()*factor;
			m_bottom_left.m_x = m_bottom_left.m_x + ((origin_width - new_width) / 2);
			m_top_right.m_x = m_top_right.m_x - ((origin_width - new_width) / 2);
			
			m_bottom_left.m_y = m_bottom_left.m_y + ((origin_height - new_height));
		}
		if(temp.getBottomLeft().m_x<0 || temp.getBottomLeft().m_y<0 || temp.getTopRight().m_x>MAX_X || temp.getTopRight().m_y>MAX_Y)
		return false;
	}
	m_bottom_left = temp.getBottomLeft();
	m_top_right = temp.getTopRight();
	
	return true;
}
bool Rectangle::scale(double factor)
{
	Rectangle temp(m_bottom_left, m_top_right);

	if (factor >= 1) 
	{
		//scale to bigger
		double origin_width = getWidth();
		double new_width = getWidth()*factor;
		double origin_height = getHeight();
		double new_height = getHeight()*factor;
		temp.m_bottom_left.m_x = temp.m_bottom_left.m_x - ((new_width - origin_width )/ 2);
		temp.m_top_right.m_x = temp.m_top_right.m_x + ((new_width -origin_width )/ 2);
		temp.m_bottom_left.m_y = temp.m_bottom_left.m_y - ((new_height -origin_height) / 2);
		temp.m_top_right.m_y = temp.m_top_right.m_y + ((new_height -origin_height) / 2);
	}
	else//scale to smaller
	{
		double origin_width = getWidth();
		double new_width = getWidth()*factor;
		double origin_height = getHeight();
		double new_height = getHeight()*factor; 
		temp.m_bottom_left.m_x = temp.m_bottom_left.m_x + ((origin_width -new_width  ) / 2);
		temp.m_top_right.m_x = temp.m_top_right.m_x - ((origin_width -new_width ) / 2);
		temp.m_bottom_left.m_y = temp.m_bottom_left.m_y + ((origin_height-new_height  ) / 2);
		temp.m_top_right.m_y = temp.m_top_right.m_y - ((origin_height-new_height ) / 2);
	}
	//now check if the temp scaling is legal
	if (temp.getBottomLeft().m_x<0||temp.getBottomLeft().m_y<0||temp.getTopRight().m_x>MAX_X||temp.getTopRight().m_y>MAX_Y)
		return false;
	//scaling is legal so update the object
	m_bottom_left = temp.getBottomLeft();
	m_top_right = temp.getTopRight();
	return true;
}
bool Rectangle::valid(Vertex&bottom,Vertex&top)
{
	if (bottom.m_x>top.m_x || bottom.m_y>top.m_y)
		return false;

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
