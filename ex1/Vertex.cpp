#include "Vertex.h"
#include "macros.h"
#include "cmath"

bool Vertex::equals(const Vertex & first, const Vertex & second) const
{

	double epsilon = 0.001;
	if ((std::abs(first.m_x - second.m_x) <= epsilon) && (std::abs(first.m_y - second.m_y <= epsilon)))
		return true;

	return false;
}
bool Vertex::isHigherThan(const Vertex& other) const
{
	return (m_y > other.m_y);
}

bool Vertex::isRighterThan(const Vertex& other) const
{
	return (m_x > other.m_x);
}

bool Vertex::isEqual(const Vertex & other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}

//function to compare between two vertices with Epsilon

bool Vertex::isValid() const
{
	return m_x >= 0 && m_x <= MAX_X && m_y >= 0 && m_y <= MAX_Y;
}
