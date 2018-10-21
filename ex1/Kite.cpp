#include "Kite.h"
#include "Board.h"
#include "Vertex.h"
#include "IsoscelesTriangle.h"
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
		if (triangles[0].getVertex[1] > triangles[1].getVertex[1])
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
}
//draw the kite method
void Kite::draw(Board&board)const
{
//drawLine method accepts two vertices as parameters
 	//board.drawLine();
}
//private method to verify triangles sizes and relativeness
bool Kite::isTrianglesok(IsoscelesTriangle first,IsoscelesTriangle second)const
{
	if (equals(first.getVertex[0].m_x,  second.getVertex[0].m_x) && equals(first.getVertex[2].m_x , second.getVertex[2].m_x)) {
		//x coordinates of two triangles are equal now check if the claves length are equal by checking the height 
	   if(equals(std::abs(first.getVertex[1].m_y),std::abs(second.getVertex[1].m_y)))
		   return true;

   }
	return false;
}

//clalculates and returns the total height of the kite
double Kite:: getTotalHeight()const
{

}
Rectangle Kite::getBoundingRectangle()const
{

}
double Kite::getArea()const
{

}
double Kite::getPerimeter()const
{

}
Vertex Kite::getCenter()const
{


}
Kite::~Kite()
{
}
