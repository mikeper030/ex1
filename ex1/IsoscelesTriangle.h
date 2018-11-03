#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"
#include <math.h>
class IsoscelesTriangle
{
public:

	//IsoscelesTriangle();
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(const Vertex& center, double width, double height);
	Vertex getVertex(int index)const;
	double getLength()const;
	double getScelesLength()const;//{return 2*(getHeight()+getLength()); }
	double getHeight()const;
	//function method
	void draw(Board & board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	bool scale(double factor, Vertex center,bool);
	
private:
	Vertex m_vertices[3];
	void init();
	bool parallel()const;
	bool checkRange(Vertex,Vertex,Vertex) const;
	bool valid(Vertex,Vertex,Vertex);

};

