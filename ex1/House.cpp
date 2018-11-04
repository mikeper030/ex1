#pragma once
#include "House.h"
#include "iostream"
const Vertex vertices_r[] = { { 20,10 },{ 30,20 } };
const Vertex vertices_t[] = { {20,20},{25,25},{30,20} };

House::House(const Rectangle& rectangle, const IsoscelesTriangle& triangle)
	:m_rect(vertices_r),m_trig(vertices_t)
{
	if (valid(rectangle,triangle)&&checkRange(triangle,rectangle))
	{
		m_rect =Rectangle( rectangle);
		m_trig = IsoscelesTriangle(triangle);
	}
	
}


House::House(const Vertex & roofTop, double width, double roofHeight, double baseHeight)
	:m_rect(vertices_r), m_trig(vertices_t)
{
	
	Rectangle r = Rectangle({ roofTop.m_y - roofHeight - baseHeight, roofTop.m_x - width / 2 },
		{ roofTop.m_x + width / 2, roofTop.m_y + width / 2 });
	
	Vertex vrs[] = { { m_rect.getBottomLeft().m_x , m_rect.getBottomLeft().m_y }
		, { roofTop }, 
	{ m_rect.getTopRight().m_x ,m_rect.getTopRight().m_y } };
	
	IsoscelesTriangle t = IsoscelesTriangle(vrs);
	if (valid(r, t)&checkRange(t,r))
	{
		m_rect = r;
		m_trig = t;
	}
}

bool House::extendRoof(double width)
{
	
	if (m_trig.getLength() <= width&&isRoofExtensionLegal(width))
	{
		m_trig.getVertex(0) = { m_trig.getVertex(1).m_x - width / 2 ,m_rect.getTopRight().m_y };
		m_trig.getVertex(2) = { width / 2 + m_trig.getVertex(1).m_x ,m_rect.getTopRight().m_y };
		return true;
	}
		return false;
	
}

double House::getHeight() const
{
	return (m_rect.getHeight() + m_trig.getHeight());
}



void House::draw(Board & board) const
{
	Vertex topLeft = { m_rect.getBottomLeft().m_x,m_rect.getTopRight().m_y };
	Vertex bottomRight = { m_rect.getTopRight().m_x , m_rect.getBottomLeft().m_y };
	board.drawLine(m_trig.getVertex(0), m_trig.getVertex(1));
	board.drawLine(m_trig.getVertex(1), m_trig.getVertex(2));
	board.drawLine(m_trig.getVertex(0), m_trig.getVertex(2));
	board.drawLine(m_rect.getBottomLeft(), topLeft);
	board.drawLine(m_rect.getTopRight(), bottomRight);
	board.drawLine(m_rect.getBottomLeft(), bottomRight);
}

Rectangle House::getBoundingRectangle() const
{
	return Rectangle({ m_trig.getVertex(0).m_x ,m_rect.getBottomLeft().m_y }, { m_trig.getVertex(2).m_x,m_trig.getVertex(1).m_y });
}

double House::getArea() const
{
	return (m_rect.getArea() + m_trig.getArea());
}
//need to fix the crossing line
double House::getPerimeter() const
{
	return (m_rect.getPerimeter() + m_trig.getPerimeter());
}

Vertex House::getCenter() const
{
	return Vertex{ m_trig.getVertex(0).m_x + (m_trig.getLength() / 2),m_trig.getVertex(0).m_y };
}

bool House::scale(double factor)
{
	House tempHouse(m_rect, m_trig);
	tempHouse.m_rect.scale(factor, tempHouse.getCenter());
	tempHouse.m_trig.scale(factor, tempHouse.getCenter(), true);
	if (isLegal(tempHouse))
	{
		m_rect = tempHouse.m_rect;
		m_trig = tempHouse.m_trig;
		return true;
	}
	
		return false;
	
}
bool  House::valid(Rectangle r,IsoscelesTriangle t)const
{
	return(sameY(r.getTopRight(),t.getVertex(0))
		&& r.getBottomLeft().m_x >= t.getVertex(0).m_x
		&& getWidthDifference()>=0)
		&&t.getVertex(1).m_y>=r.getTopRight().m_y;
}

bool House::checkRange(const IsoscelesTriangle&t,const Rectangle&r)const 
{
	return (t.getVertex(0).isValid()&&t.getVertex(1).isValid()&&t.getVertex(2).isValid()
		&&r.getBottomLeft().isValid()&&r.getTopRight().isValid());
}

double House::getWidthDifference() const
{
	return m_trig.getVertex(2).m_x-m_rect.getTopRight().m_x>0? 
		m_trig.getVertex(2).m_x - m_rect.getTopRight().m_x > 0:0;
}
bool House::isRoofExtensionLegal(double width)
{
	double ex = width / 2;
	double o_xl = m_trig.getVertex(0).m_x;
	double o_xr = m_trig.getVertex(2).m_x;
	Vertex v1{ o_xl - ex,1 }, v2{ o_xr + ex,1 };

	return (v1.isValid()&&v2.isValid());

}
bool House::isLegal(House& h)
{
	return(h.m_rect.getBottomLeft().isValid()&&
		h.m_rect.getTopRight().isValid()
		&&h.m_trig.getVertex(0).isValid()
		&&m_trig.getVertex(1).isValid()
		&&h.m_trig.getVertex(2).isValid());
}


