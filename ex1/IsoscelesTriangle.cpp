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

IsoscelesTriangle::IsoscelesTriangle(const Vertex & center, double width, double height)
	:IsoscelesTriangle(m_vertices)
{

}

Vertex IsoscelesTriangle::getVertex(int index) const
{
	return Vertex();
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


IsoscelesTriangle::~IsoscelesTriangle()
{

}
