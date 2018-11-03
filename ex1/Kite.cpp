#include "Kite.h"

const Vertex vertices1[3] = { {20,20},{25,25},{30,20} };
const Vertex vertices2[3] = { {20,20} ,{25, 15},{30, 20} };

//first is upper second is lower since there is no default constructor immidieate init is executed
Kite::Kite(const IsoscelesTriangle triangles[2]) :m_lower(vertices2),m_upper(vertices1)
{
	
	if (isTrianglesok(triangles[0], triangles[1]))
	{
		m_upper = triangles[0];
		m_lower = triangles[1];
	}
	
	
		
}
//second constructor argumnets are clear..
Kite::Kite(const Vertex& top, double width, double topHeight, double bottomHeight) :m_lower(vertices2), m_upper(vertices1)
{   
	//extract the points from given data
    Vertex vertices_top[3] = { Vertex{(top.m_x-width)/2,top.m_y-topHeight} ,top,Vertex{(top.m_x + width) / 2,top.m_y-topHeight} };
	Vertex vertices_bottom[3] = { Vertex{},Vertex{},Vertex{} };
	IsoscelesTriangle upper(vertices_top),lower(vertices_bottom);
	if (isTrianglesok(upper, lower))
	{
		m_lower = lower;
		m_upper = upper;
	}
	
	
}
//draw the kite method

//private method to verify triangles sizes and relativeness
bool Kite::isTrianglesok(IsoscelesTriangle first,IsoscelesTriangle second)const
{
	Vertex v;
	//check if top is indeed top
	if (first.getVertex(1).m_y > second.getVertex(1).m_y)
	{
		//first check if points are in range
		if (checkRange(first) && checkRange(second))
		{
			//check if bases are equal
			if (v.equals(first.getVertex(0), second.getVertex(0)) && v.equals(first.getVertex(2), second.getVertex(2)))
			{
				//x coordinates of two triangles are equal now check if the claves length are equal by distance
				if (doubleEqual(distance(m_lower.getVertex(0), m_lower.getVertex(1)), distance(m_lower.getVertex(1), m_lower.getVertex(2)))
					&& doubleEqual(distance(m_upper.getVertex(0), m_upper.getVertex(1)), distance(m_upper.getVertex(1), m_upper.getVertex(2))))

					return true;

			}
		}
	}
	return false;
}



//calculates and returns the total height of the kite
double Kite:: getTotalHeight()const
{
	return (std::abs(m_lower.getHeight()*2));
}


Rectangle Kite::getBoundingRectangle()const
{
	Vertex bottom_left = { m_lower.getVertex(0).m_x,m_lower.getVertex(1).m_y };
	Vertex top_right = { m_upper.getVertex(2).m_x,m_upper.getVertex(1).m_y };
	return Rectangle(bottom_left, top_right);
}


double Kite::getArea()const
{
	return std::abs(m_lower.getArea() *2);
}


double Kite::getPerimeter()const
{
	return (m_lower.getPerimeter() + m_upper.getPerimeter()) - ((m_lower.getVertex(2).m_x - m_lower.getVertex(0).m_x)*2);
}


Vertex Kite::getCenter()const
{
	return Vertex{m_lower.getVertex(1).m_x,m_lower.getVertex(0).m_y};
}


bool Kite::scale(double factor)
{
	if (scale(factor, m_upper.getVertex(0)))
		return true;
	
	return false;
}

bool Kite::scale(double factor,Vertex center)
{
	IsoscelesTriangle l_temp(m_lower), u_temp(m_upper);
	if (l_temp.scale(factor, center,false) && u_temp.scale(factor, center,true))
	{
		m_lower = l_temp; m_upper = u_temp;
		return true;
	}
	return false;
}
bool Kite::checkRange(IsoscelesTriangle t)const
{
	//std::cout << t.getVertex(0).m_x <<" "<< t.getVertex(0).m_y <<"|" <<t.getVertex(1).m_x<<" " <<t.getVertex(1).m_y<<"|"<< t.getVertex(2).m_x<<" "<<t.getVertex(2).m_y<<"|   ";
	if (t.getVertex(0).isValid()&&t.getVertex(1).isValid()&&t.getVertex(2).isValid())
		return true;

		return false;
}
void Kite::draw(Board& board)const
{
	
	board.drawLine(m_upper.getVertex(0), m_upper.getVertex(1));
	board.drawLine(m_upper.getVertex(1), m_upper.getVertex(2));
	board.drawLine(m_upper.getVertex(0), m_upper.getVertex(2));
	board.drawLine(m_lower.getVertex(0), m_lower.getVertex(1));
	board.drawLine(m_lower.getVertex(1), m_lower.getVertex(2));

}
void Kite::init()
{
	m_lower = IsoscelesTriangle(vertices2);
	m_upper = IsoscelesTriangle(vertices1);
}

