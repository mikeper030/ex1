#include "House.h"



House::House()
{
	m_rect[0] = { 20,10 };
	m_rect[1] = { 30,20 };
	m_triag[0] = { 20,20 };
	m_triag[1] = { 25,25 };
	m_triag[2] = { 30,20 };
}

House::House(const Rectangle & rectangle, const IsoscelesTriangle & triangle)
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

}

bool House::extendRoof(double width)
{
	return false;
}

double House::getHeight() const
{
	return 0.0;
}

double House::getWidthDifferent() const
{
	return 0.0;
}


House::~House()
{
}

