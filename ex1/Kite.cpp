#include "Kite.h"
#include "Board.h"

//default constructor
Kite::Kite()
{
}
//first constructor expect two triangles in array need to check which is lower or upper
Kite::Kite(const IsoscelesTriangle triangles[2])
{

}
//second constructor argumnets are clear..
Kite::Kite(const Vertex& top, double width, double topHeight, double bottomHeight)
{
}
//draw the kite method
void Kite::draw(Board&board)const
{
//drawLine method accepts two vertices as parameters
 	board.drawLine();
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
bool Kite::scale(double factor) const
{

}
Kite::~Kite()
{
}
