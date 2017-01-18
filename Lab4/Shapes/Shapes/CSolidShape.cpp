#include "stdafx.h"
#include "CSolidShape.h"

std::string CSolidShape::GetFillColor()const
{
	return m_fillColor;
}

CSolidShape::CSolidShape(std::string color)
{
	m_fillColor = color;
}