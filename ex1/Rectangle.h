#pragma once
#include "Vertex.h"
#include "Board.h"
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
	double getWidth() const;
	double getHeight() const;
	//function method
	void draw(Board & board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool isScalingLegal(const Rectangle&,double);
	bool scale(double factor);


private:
	Vertex m_bottom_left,m_top_right; // m_bottomLeft
	void verifyInput();

};

