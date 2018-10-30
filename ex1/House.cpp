#pragma once
#include "House.h"
#include"Rectangle.h"
#include "IsoscelesTriangle.h"



House::House()
{

}

House::House(const Rectangle& rectangle, const IsoscelesTriangle& triangle)
	//:House()
{
	if (rectangle.getTopRight().m_y == triangle.getVertex(0).m_y
		&& rectangle.getBottomLeft().m_x >= triangle.getVertex(0).m_x
		&& rectangle.getTopRight().m_x <= triangle.getVertex(2).m_x)
	{
		m_rect = rectangle;
		m_trig = triangle;
	}
	else
	{
		m_rect.getBottomLeft() = { 20,10 };
		m_rect.getTopRight() = { 30,20 };
		m_trig.getVertex(0) = { 20,20 };
		m_trig.getVertex(1) = { 25,25 };
		m_trig.getVertex(2) = { 30,20 };
	}
}


House::House(const Vertex & roofTop, double width, double roofHeight, double baseHeight)
{
	m_rect.getBottomLeft() = { roofTop.m_y - roofHeight - baseHeight, roofTop.m_x - width / 2 };
	m_rect.getTopRight() = { roofTop.m_x + width / 2, roofTop.m_y + width/2};
	m_trig.getVertex(0) = { m_rect.getBottomLeft().m_x,m_rect.getBottomLeft().m_y };
	m_trig.getVertex(1) = { roofTop };
	m_trig.getVertex(2) = { m_rect.getTopRight().m_x ,m_rect.getTopRight().m_y };
}

bool House::extendRoof(double width)
{
	if (m_trig.getLength() < width)
	{
		m_trig.getVertex(0) = { m_trig.getVertex(1).m_x - width / 2 ,m_rect.getTopRight().m_y };
		m_trig.getVertex(2) = { width / 2 + m_trig.getVertex(1).m_x ,m_rect.getTopRight().m_y };
		return true;
	}
	else
	{
		return false;
	}
}

double House::getHeight() const
{
	return (m_rect.getHeight()+m_trig.getHeight());
}

double House::getWidthDifferent() const
{
	if (distance(m_trig.getVertex(0),m_trig.getVertex(2))
	> distance({m_rect.getBottomLeft().m_x,m_rect.getTopRight().m_y}, m_rect.getTopRight()))
	{
		return (distance(m_trig.getVertex(0), m_trig.getVertex(2))
	- distance({ m_rect.getBottomLeft().m_x,m_rect.getTopRight().m_y }, m_rect.getTopRight()));
	}
	else
	{
		return 0;
	}
}
//need to fix here
void House::draw(Board & board) const
{
	Vertex topLeft = { m_rect.getBottomLeft().m_x,m_rect.getTopRight().m_y };
	Vertex bottomRight = { m_rect.getBottomLeft().m_y,m_rect.getTopRight().m_x };
	board.drawLine(m_trig.getVertex(0), m_trig.getVertex(1));
	board.drawLine(m_trig.getVertex(1), m_trig.getVertex(2));
	board.drawLine(m_trig.getVertex(0), m_trig.getVertex(2));
	board.drawLine(m_rect.getBottomLeft(),topLeft);
	//board.drawLine(topLeft,m_rect.getTopRight());
	board.drawLine(m_rect.getTopRight(),bottomRight );
	board.drawLine(bottomRight,m_rect.getBottomLeft());
}

Rectangle House::getBoundingRectangle() const
{
	return Rectangle({ m_trig.getVertex(0).m_x ,m_rect.getBottomLeft().m_y}, { m_trig.getVertex(2).m_x,m_trig.getVertex(1).m_y });
}

double House::getArea() const
{
	return (m_rect.getArea()+m_trig.getArea());
}

double House::getPerimeter() const
{
	return (m_rect.getPerimeter()+m_trig.getPerimeter());
}

Vertex House::getCenter() const
{
	return Vertex{m_trig.getVertex(0).m_x + (m_trig.getLength()/2),m_trig.getVertex(0).m_y};
}

bool House::scale(double factor)
{
	return false;
}


House::~House()
{
}

