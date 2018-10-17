#pragma once
class Kite
#include "Vertex.h"
{
public:
	Kite();
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	double getTotalHeight()const;
	~Kite();
};

