#include "Kite.h"
#include "Board.h"
#include "Vertex.h"
#include "IsoscelesTriangle.h"
#include <iostream>
const Vertex vertices1[3] = { {30,20},{25,25},{20,20} };
const Vertex vertices2[3] = { {30, 20} ,{25, 15}, {20, 20} };
//default constructor
Kite::Kite()
{
	m_lower = IsoscelesTriangle(vertices1);
	m_upper = IsoscelesTriangle(vertices2);
}
//first constructor expect two triangles in array need to check which is lower or upper
Kite::Kite(const IsoscelesTriangle triangles[2])
	: Kite()
{
	if (isTrianglesok(triangles[0], triangles[1]))
	{
		
	//triangles are ok now check which is lower or upper
		if (triangles[0].getVertex(1).m_y > triangles[1].getVertex(1).m_y)
		{	//first is top
			m_upper = triangles[0];
			m_lower = triangles[1];
		}
		else
		{
			m_upper = triangles[1];
			m_lower = triangles[0];
		}
	}
	
		
}
//second constructor argumnets are clear..
Kite::Kite(const Vertex& top, double width, double topHeight, double bottomHeight)
{   
	//extract the points from given data
	Vertex vertices_top[3] = { Vertex{(top.m_x-width)/2,top.m_y-topHeight} ,top,Vertex{(top.m_x + width) / 2,top.m_y-topHeight} };
	Vertex vertices_bottom[3] = { Vertex{},Vertex{},Vertex{} };
	IsoscelesTriangle upper(vertices_top);
}
//draw the kite method

//private method to verify triangles sizes and relativeness
bool Kite::isTrianglesok(IsoscelesTriangle first,IsoscelesTriangle second)const
{
	Vertex v;
	if (v.equals(first.getVertex(0),  second.getVertex(0)) && v.equals(first.getVertex(2), second.getVertex(2))) {
		//x coordinates of two triangles are equal now check if the claves length are equal by checking the height 
	   if(v.equals(first.getVertex(1),second.getVertex(1)))
		   return true;

   }
	return false;
}

//calculates and returns the total height of the kite
double Kite:: getTotalHeight()const
{
	return (m_lower.getHeight()+m_upper.getHeight());
}
Rectangle Kite::getBoundingRectangle()const
{
	Vertex bottom_left = { m_lower.getVertex(0).m_x,m_lower.getVertex(1).m_y };
	Vertex top_right = { m_upper.getVertex(2).m_x,m_upper.getVertex(1).m_y };
	return Rectangle(bottom_left, top_right);
}
double Kite::getArea()const
{
	return m_lower.getArea() + m_upper.getArea();
}
double Kite::getPerimeter()const
{
	return (m_lower.getPerimeter() + m_upper.getPerimeter()) - ((m_lower.getVertex(2).m_x - m_lower.getVertex(0).m_x)*2);
}
Vertex Kite::getCenter()const
{
	return Vertex{(m_lower.getVertex(2).m_x-m_lower.getVertex(0).m_x)/2,m_upper.getVertex(1).m_y-m_lower.getVertex(1).m_y};
}
bool Kite::scale(double factor)
{
	return false;
}
void Kite::draw(Board& board)const
{
    //need to implement the drawing
	board.drawLine(m_upper.getVertex(0), m_upper.getVertex(1));
	board.drawLine(m_upper.getVertex(1), m_upper.getVertex(2));
	board.drawLine(m_upper.getVertex(0), m_upper.getVertex(2));
	board.drawLine(m_lower.getVertex(0), m_lower.getVertex(1));
	board.drawLine(m_lower.getVertex(1), m_lower.getVertex(2));

}
Kite::~Kite()
{
}
