#include "IsoscelesTriangle.h"

const double Epsilon = 0.01;



IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
{
	if (checkRange(vertices[0], vertices[1], vertices[2])& valid(vertices[0],vertices[1],vertices[2]))
	{
		m_vertices[0] = vertices[0];
		m_vertices[1] = vertices[1];
		m_vertices[2] = vertices[2];
	}
	else
		init();
	
}
//get the vertex by center  width and height
IsoscelesTriangle::IsoscelesTriangle(const Vertex & center, double width, double height)
{
	//first  extract the points from given info
	Vertex temp[3]; 
	temp[1] = center;
	temp[0].m_y = temp[2].m_y = center.m_y - height ;
	temp[0].m_x =temp[1].m_x - width / 2;
	temp[2].m_x = m_vertices[1].m_x + width / 2;
	
	if (height < 0)
	{
		temp[1].m_y =  0 - std::abs(height);
	}
	//check vertex if something is not legal
	// if not parallel or the point not legal
	if (!checkRange(temp[0], temp[1], temp[2]) || !valid(m_vertices[0], m_vertices[1], m_vertices[2]))
		{
			init();
		}
		else
		{
			m_vertices[0] = temp[0];
			m_vertices[1] = temp[1];
			m_vertices[2] = temp[2];
		}
	
	
		
}
// check legality of vertex
bool IsoscelesTriangle::checkRange(Vertex v1,Vertex v2,Vertex v3) const
{
	return (v1.isValid() && v2.isValid() && v3.isValid());
	
}
//check if is parallel
bool IsoscelesTriangle::parallel() const
{
	return (doubleEqual(m_vertices[0].m_x , m_vertices[2].m_x));
}

bool IsoscelesTriangle::valid(Vertex v1, Vertex v2,Vertex v3)
{
	return(std::abs(v1.m_y - v3.m_y)) <= Epsilon &&
		  doubleEqual(distance(v1, v2), distance(v2, v3))&& parallel();
}

Vertex IsoscelesTriangle::getVertex(int index) const
{
	return m_vertices[index] ;
}
 
double IsoscelesTriangle::getLength() const
{
	return (m_vertices[2].m_x - m_vertices[0].m_x);
}

double IsoscelesTriangle::getScelesLength() const
{
	return (distance(m_vertices[0],m_vertices[2]));
}

double IsoscelesTriangle::getHeight() const
{
	return std::abs(m_vertices[1].m_y-m_vertices[0].m_y);
}

void IsoscelesTriangle::draw(Board & board) const
{
	board.drawLine(m_vertices[0],m_vertices[1]);
	board.drawLine(m_vertices[1], m_vertices[2]);
	board.drawLine(m_vertices[0], m_vertices[2]);
}

Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	return Rectangle(m_vertices[0], Vertex{m_vertices[2].m_x,m_vertices[1].m_y});
}

double IsoscelesTriangle::getArea() const
{
	return (getLength()*getHeight()/2);
}

double IsoscelesTriangle::getPerimeter() const
{
	return (getScelesLength()*2)+getLength();
}

Vertex IsoscelesTriangle::getCenter() const
{
	return Vertex{m_vertices[0].m_x+(getLength()/2),m_vertices[0].m_y+(getHeight()/2)};
}
//intended to be used when scaling kite 
bool IsoscelesTriangle::scale(double factor, Vertex center,bool isUpper)
{
	IsoscelesTriangle temp(m_vertices);
	
	if (sameY(center, m_vertices[0]))
	{
		IsoscelesTriangle temp(m_vertices);
		double new_height = getHeight() * factor;
		double old_height = getHeight();
		double old_width = getLength();
		double new_width = getLength()*factor;
		//scale to bigger
		if (factor >= 1)
		{
			temp.m_vertices[0].m_x = temp.m_vertices[0].m_x - ((new_width - old_width) / 2);
			temp.m_vertices[2].m_x = temp.m_vertices[2].m_x + ((new_width - old_width) / 2);
			if(isUpper)
			temp.m_vertices[1].m_y = temp.m_vertices[1].m_y + ((new_height - old_height));
			else
			temp.m_vertices[1].m_y = temp.m_vertices[1].m_y - ((new_height - old_height));

		}
		//scale to smaller
		else
		{
			temp.m_vertices[0].m_x = temp.m_vertices[0].m_x + ((new_width - old_width) / 2);
			temp.m_vertices[2].m_x = temp.m_vertices[2].m_x - ((new_width - old_width) / 2);
			if(isUpper)
			temp.m_vertices[1].m_y = temp.m_vertices[1].m_y - ((new_height - old_height));
			else
			temp.m_vertices[1].m_y = temp.m_vertices[1].m_y + ((new_height - old_height));

		}
		//check if the scaling is legal
		if (temp.m_vertices[0].m_x<0 || temp.m_vertices[2].m_x>MAX_X || temp.m_vertices[1].m_y > MAX_Y || temp.m_vertices[0].m_y < 0)
			return false;

		m_vertices[0] = temp.m_vertices[0];
		m_vertices[1] = temp.m_vertices[1];
		m_vertices[2] = temp.m_vertices[2];
	}
	return true;
}

//scale from center point
bool IsoscelesTriangle::scale(double factor)
{
	
	IsoscelesTriangle temp(m_vertices);
	double new_height = getHeight() * factor;
	double old_height = getHeight();
	double old_width = getLength();
	double new_width = getLength()*factor;
	//scale to bigger
	if (factor >= 1)
	{
		temp.m_vertices[0].m_x = temp.m_vertices[0].m_x - ((new_width - old_width) / 2);
		temp.m_vertices[2].m_x = temp.m_vertices[2].m_x + ((new_width - old_width) / 2);
		temp.m_vertices[0].m_y = temp.m_vertices[0].m_y - ((new_height - old_height) / 2);
		temp.m_vertices[2].m_y = temp.m_vertices[2].m_y - ((new_height - old_height) / 2);
		temp.m_vertices[1].m_y = temp.m_vertices[1].m_y + ((new_height - old_height) / 2);
	}
	//scale to smaller
	else
	{
		temp.m_vertices[0].m_x = temp.m_vertices[0].m_x + ((new_width - old_width) / 2);
		temp.m_vertices[2].m_x = temp.m_vertices[2].m_x - ((new_width - old_width) / 2);
		temp.m_vertices[0].m_y = temp.m_vertices[0].m_y + ((new_height - old_height) / 2);
		temp.m_vertices[2].m_y = temp.m_vertices[2].m_y + ((new_height - old_height) / 2);
		temp.m_vertices[1].m_y = temp.m_vertices[1].m_y - ((new_height - old_height) / 2);
	}
	//check if the scaling is legal
	if (temp.m_vertices[0].m_x<0 || temp.m_vertices[2].m_x>MAX_X || temp.m_vertices[1].m_y > MAX_Y || temp.m_vertices[0].m_y < 0)
		return false;
	
	m_vertices[0] = temp.m_vertices[0];
	m_vertices[1] = temp.m_vertices[1];
	m_vertices[2] = temp.m_vertices[2];

	return true;
}
void IsoscelesTriangle::init()
{
	m_vertices[0] = Vertex{ 20,20 };
	m_vertices[1] = Vertex{ 25,25 };
	m_vertices[2] = Vertex{ 30,20 };
}




