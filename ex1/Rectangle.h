#pragma once
#include"Vertex.h"
class Rectangle
{
public:
	Rectangle();
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	~Rectangle();
};

