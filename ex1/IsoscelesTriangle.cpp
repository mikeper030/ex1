#include "IsoscelesTriangle.h"
const double Epsilon = 0.01;

IsoscelesTriangle::IsoscelesTriangle()
{

	m_vertices[0] = Vertex{ 20,20 };
	m_vertices[1] = Vertex{ 25,25 };
	m_vertices[2] = Vertex{ 30,20 };
}

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
	:IsoscelesTriangle()
{
	if (vertices[0].isValid() && vertices[1].isValid() 
		&& vertices[2].isValid() && )
	{
		m_vertices[0] = vertices[0];

	}

}

IsoscelesTriangle::IsoscelesTriangle(const Vertex & center, double width, double height)
{

}

Vertex IsoscelesTriangle::getVertex(int index) const
{
	return Vertex();
}

double IsoscelesTriangle::getLength() const
{
	return 0.0;
}


IsoscelesTriangle::~IsoscelesTriangle()
{

}
