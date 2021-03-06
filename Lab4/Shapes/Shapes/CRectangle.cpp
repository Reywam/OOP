#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTopPoint, double width, double height, std::string outlineColor, std::string fillColor)
	:CSolidShape(outlineColor, fillColor)
{
	m_leftTop = leftTopPoint;
	m_width = width;
	m_height = height;
}

double CRectangle::GetArea()const
{
	return (m_width * m_height);
}

double CRectangle::GetPerimeter()const
{
	return (2 * (m_width + m_height));
}

std::string CRectangle::GetOutlineColor()const
{
	return CSolidShape::GetOutlineColor();
}

std::string CRectangle::GetFillColor()const
{
	return CSolidShape::GetFillColor();
}

CPoint CRectangle::GetLeftTop()const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom()const
{
	return CPoint(m_leftTop.x + m_width, m_leftTop.y + m_height);
}

double CRectangle::GetWidth()const
{
	return m_width;
}

double CRectangle::GetHeight()const
{
	return m_height;
}

std::string CRectangle::ToString()const
{
	return (m_name
		+ " " + m_leftTop.ToString()
		+ " " + std::to_string(m_width)
		+ " " + std::to_string(m_height)
		+ " " + GetOutlineColor()
		+ " " + CSolidShape::GetFillColor()
		);
}