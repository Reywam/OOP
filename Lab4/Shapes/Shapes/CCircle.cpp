#include "stdafx.h"
#include "CCircle.h"

#define _USE_MATH_DEFINES
#include "math.h"

CCircle::CCircle(CPoint center, double radius, std::string outlineColor, std::string fillColor)
	:CSolidShape(outlineColor, fillColor)
{
	m_center = center;
	m_radius = radius;
}

double CCircle::GetArea()const
{
	return (M_PI * m_radius * m_radius);
}

double CCircle::GetPerimeter()const
{
	return (2 * M_PI * m_radius);
}

std::string CCircle::GetOutlineColor()const
{
	return CSolidShape::GetOutlineColor();
}

std::string CCircle::GetFillColor()const
{
	return CSolidShape::GetFillColor();
}

CPoint CCircle::GetCenter()const
{
	return m_center;
}

double CCircle::GetRadius()const
{
	return m_radius;
}

std::string CCircle::ToString()const
{
	return m_name
		+ " " + m_center.ToString()
		+ " " + std::to_string(m_radius)
		+ " " + GetOutlineColor()
		+ " " + CSolidShape::GetFillColor();
}