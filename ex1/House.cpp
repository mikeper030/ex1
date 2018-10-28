#pragma once
#include "House.h"
#include"Rectangle.h"
#include "IsoscelesTriangle.h"



House::House()
{
	m_rect[0] = { 20,10 };
	m_rect[1] = { 30,20 };
	m_triag[0] = { 20,20 };
	m_triag[1] = { 25,25 };
	m_triag[2] = { 30,20 };
}

House::House(const Rectangle& rectangle, const IsoscelesTriangle& triangle)
	:House()
{
	if (rectangle.getTopRight().m_y == triangle.getVertex(2).m_y 
		|| triangle.getVertex(0).m_y == rectangle.getTopRight().m_y
		|| rectangle.getBottomLeft().m_x >= triangle.getVertex(0).m_x
		|| rectangle.getTopRight().m_x <= triangle.getVertex(2).m_x)
	{
		m_rect[0] = rectangle.getBottomLeft();
		m_rect[1] = rectangle.getTopRight();
		m_triag[0] = triangle.getVertex(0);
		m_triag[1] = triangle.getVertex(1);
		m_triag[2] = triangle.getVertex(2);
	}
}


House::House(const Vertex & roofTop, double width, double roofHeight, double baseHeight)
{
	m_rect[0].m_y = roofTop.m_y - roofHeight - baseHeight;
	m_rect[0].m_x = roofTop.m_x - width / 2;
	m_rect[1].m_x = roofTop.m_x + width / 2;
	m_triag[1] = roofTop;
	m_rect[1].m_y = m_triag[0].m_y = m_triag[2].m_y = roofTop.m_y - roofHeight;
	m_triag[2] = m_rect[1];
	m_triag[0].m_x = m_rect[0].m_x;
}

bool House::extendRoof(double width)
{
	if (m_triag[2].m_x - m_triag[0].m_x < width)
	{
		m_triag[2].m_x = width / 2 + m_triag[1].m_x;
		m_triag[0].m_x = m_triag[2].m_x - width;
		return true;
	}
	else
	{
		return false;
	}
}

double House::getHeight() const
{
	return (m_triag[1].m_y - m_rect[0].m_y);
}

double House::getWidthDifferent() const
{
	if ((m_triag[2].m_x - m_triag[0].m_x) - (m_rect[1].m_x - m_rect[0].m_x) > 0)
	{
		return ((m_triag[2].m_x - m_triag[0].m_x)-(m_rect[1].m_x-m_rect[0].m_x));
	}
	else
	{
		return 0;
	}
}

void House::draw(Board & board) const
{
	Vertex bottomRight = { m_rect[1].m_x,m_rect[0].m_y },
		topLeft = {m_rect[0].m_x,m_rect[1].m_y};



	board.drawLine(m_rect[0], topLeft);
	board.drawLine(topLeft, m_rect[1]);
	board.drawLine(m_rect[1], bottomRight);
	board.drawLine(bottomRight,m_rect[0]);
	board.drawLine(m_triag[0], m_triag[2]);
	board.drawLine(m_triag[0], m_triag[1]);
	board.drawLine(m_triag[1], m_triag[2]);

}

Rectangle House::getBoundingRectangle() const
{
	return Rectangle();
}

double House::getArea() const
{
	return (m_rect[1].m_x - m_rect[0].m_x)*(m_rect[1].m_y - m_rect[0].m_y)
		+(m_triag[2].m_x-m_triag[0].m_x)*(m_triag[1].m_y - m_triag[0].m_y);
}

double House::getPerimeter() const
{
	return (m_rect[1].m_x - m_rect[0].m_x) + 2*(m_rect[1].m_y - m_rect[0].m_y) + 2*(distance(m_triag[0],m_triag[1]));
}

Vertex House::getCenter() const
{
	return Vertex{m_triag[0].m_x+(m_triag[2].m_x-m_triag[0].m_x)/2,m_rect[1].m_y};
}

bool House::scale(double factor)
{
	return false;
}


House::~House()
{
}

