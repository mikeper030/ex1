#include "IsoscelesTriangle.h"
const double Epsilon = 0.01;

//default constructor
IsoscelesTriangle::IsoscelesTriangle()
{
	m_vertices[0] = Vertex{ 20,20 };
	m_vertices[1] = Vertex{ 25,25 };
	m_vertices[2] = Vertex{ 30,20 };
}
//
IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
	:IsoscelesTriangle()
{
	if (vertices[0].isValid() && vertices[1].isValid() 
		&& vertices[2].isValid() && (vertices[0].m_y - vertices[2].m_y) <= 0)
	{
		m_vertices[0] = vertices[0];
		m_vertices[1] = vertices[1];
		m_vertices[2] = vertices[2];
	}

}
//to ask mike what to do here
IsoscelesTriangle::IsoscelesTriangle(const Vertex & center, double width, double height)
{
	m_vertices[1] = center;
	m_vertices[0].m_y = m_vertices[2].m_y = center.m_y - height ;
	m_vertices[0].m_x = m_vertices[1].m_x - width / 2;
	m_vertices[2].m_x = m_vertices[1].m_x + width / 2;
	//check vertex to find if something is not leagal
	// if not parallel or the point not leagal
	if (!checkVer() || !parallel())
	{
		inithlizing();
	}
}
// check variable of vertex
bool IsoscelesTriangle::checkVer() const
{
	if (m_vertices[0].isValid() && m_vertices[1].isValid() && m_vertices[2].isValid())
	{
		return true;
	}
	return false;
}
//check if is parallel
bool IsoscelesTriangle::parallel() const
{
	if (m_vertices[0].m_x != m_vertices[2].m_x)
		return false;
	else
		return true;
}

void IsoscelesTriangle::inithlizing()
{
	m_vertices[0] = Vertex{ 20,20 };
	m_vertices[1] = Vertex{ 25,25 };
	m_vertices[2] = Vertex{ 30,20 };
}

Vertex IsoscelesTriangle::getVertex(int index) const
{
	return Vertex(m_vertices[index]) ;
}
 
double IsoscelesTriangle::getLength() const
{
	return (m_vertices[2].m_x - m_vertices[0].m_x);
}

double IsoscelesTriangle::getScelesLength() const
{
	return sqrt(pow(m_vertices[0].m_x-m_vertices[1].m_x ,2)+pow(m_vertices[0].m_y - m_vertices[1].m_y, 2));
}

double IsoscelesTriangle::getHeight() const
{
	return m_vertices[1].m_y;
}

Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	return Rectangle();
}


IsoscelesTriangle::~IsoscelesTriangle()
{

}

