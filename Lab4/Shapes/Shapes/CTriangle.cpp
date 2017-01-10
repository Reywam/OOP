#include "stdafx.h"
#include "CTriangle.h"
#include "CLineSegment.h"
#include "CPoint.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, std::string outlineColor, std::string fillColor)
{
	m_vertex1 = vertex1;
	m_vertex2 = vertex2;
	m_vertex3 = vertex3;

	m_outlineColor = outlineColor;
	m_fillColor = fillColor;
}

double CTriangle::GetPerimeter()const
{
	return (CLineSegment(m_vertex1, m_vertex2, m_outlineColor).GetPerimeter()
		+ CLineSegment(m_vertex2, m_vertex3, m_outlineColor).GetPerimeter()
		+ CLineSegment(m_vertex3, m_vertex1, m_outlineColor).GetPerimeter());
}

double CTriangle::GetArea()const
{
	auto P = GetPerimeter() / 2;

	auto S = sqrt(P * (P - CLineSegment(m_vertex1, m_vertex2, m_outlineColor).GetPerimeter()) 
		* (P - CLineSegment(m_vertex2, m_vertex3, m_outlineColor).GetPerimeter()) 
		* (P - CLineSegment(m_vertex3, m_vertex1, m_outlineColor).GetPerimeter()));

	return S;
}

std::string CTriangle::ToString()const
{
	return (m_name 
		+ " " + m_vertex1.ToString() 
		+ " " + m_vertex2.ToString() 
		+ " " + m_vertex3.ToString()
		+ " #" + m_outlineColor
		+ " #" + m_fillColor);
}

std::string CTriangle::GetOutlineColor()const
{
	return m_outlineColor;
}

std::string CTriangle::GetFillColor()const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1()
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2()
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3()
{
	return m_vertex3;
}