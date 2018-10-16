#pragma once
#include "Vertex.h"
class Rectangle
{
public:
	Rectangle();
	Rectangle(const Vertex veritces[2]);
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	~Rectangle();
	Vertex getBottomLeft() const;
	Vertex getTopRight()const;
	Vertex getWidth() const;
	Vertex getHeight() const;


  
private:
	void verifyInput();

};

