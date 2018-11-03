#pragma once
#include "macros.h"
#include <cmath>

struct Vertex
{
	double m_x;
	double m_y;

	bool equals(const Vertex& first, const Vertex& second) const;
	bool isHigherThan(const Vertex& other) const;
	bool isRighterThan(const Vertex& other) const;
	bool isEqual(const Vertex& other) const;
	bool isValid() const;
	
};
