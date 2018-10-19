#pragma once
#include "Vertex.h"
{
public:
	Kite();
	Kite(const IsoscelesTriangle triangles[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	Kite(const IsoscelesTriangle triangles[2]);
	double getTotalHeight()const;
	~Kite();
private:
	IsoscelesTriangle upper,lower;

};

