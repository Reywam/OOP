#include "stdafx.h"
#include "CTriangle.h"
#include "CLineSegment.h"
#include "CPoint.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, std::string outlineColor, std::string fillColor)
	:CShape(outlineColor), CSolidShape(fillColor)
{
	m_vertex1 = vertex1;
	m_vertex2 = vertex2;
	m_vertex3 = vertex3;
}

double CTriangle::GetPerimeter()const
{
	return (CLineSegment(m_vertex1, m_vertex2, "white").GetPerimeter()
		+ CLineSegment(m_vertex2, m_vertex3, "white").GetPerimeter()
		+ CLineSegment(m_vertex3, m_vertex1, "white").GetPerimeter());
}

double CTriangle::GetArea()const
{
	auto P = GetPerimeter() / 2;

	auto S = sqrt(P * (P - CLineSegment(m_vertex1, m_vertex2, "white").GetPerimeter()) 
		* (P - CLineSegment(m_vertex2, m_vertex3, "white").GetPerimeter())
		* (P - CLineSegment(m_vertex3, m_vertex1, "white").GetPerimeter()));

	return S;
}

std::string CTriangle::ToString()const
{
	return (m_name 
		+ " " + m_vertex1.ToString() 
		+ " " + m_vertex2.ToString() 
		+ " " + m_vertex3.ToString()
		+ " " + CShape::GetOutlineColor()
		+ " " + CSolidShape::GetFillColor());
}

std::string CTriangle::GetOutlineColor()const
{
	return CShape::GetOutlineColor();
}

std::string CTriangle::GetFillColor()const
{
	return CSolidShape::GetFillColor();
}

CPoint CTriangle::GetVertex1()const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2()const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3()const
{
	return m_vertex3;
}