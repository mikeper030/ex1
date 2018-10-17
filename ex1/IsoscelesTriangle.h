#pragma once
#include "Vertex.h"
class IsoscelesTriangle
{
public:
	IsoscelesTriangle();
	IsoscelesTriangle(const Vertex vertices[3]);
	Vertex getVertex(int index)const;
	double getLength()const;
	double getScelesLength()const;
	double getHeight()const;
	~IsoscelesTriangle();
};

