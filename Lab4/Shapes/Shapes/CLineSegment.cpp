#include "stdafx.h"
#include "CLineSegment.h"

CPoint CLineSegment::GetStartPoint()const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint()const
{
	return m_endPoint;
}

double CLineSegment::GetArea()const
{
	return 0;
}

double CLineSegment::GetPerimeter()const
{
	return sqrt(pow((m_endPoint.x - m_startPoint.x), 2) + pow((m_endPoint.y - m_startPoint.y), 2));
}

std::string CLineSegment::ToString()const
{
	return (m_name + " " + m_startPoint.ToString() + " " + m_endPoint.ToString() + " " + m_outlineColor);
}

std::string CLineSegment::GetOutlineColor()const
{
	return m_outlineColor;
}