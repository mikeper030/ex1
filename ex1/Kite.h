#pragma once
#include "Vertex.h"

class Kite
{
public:
	Kite();
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	double getTotalHeight()const;
	~Kite();
};

