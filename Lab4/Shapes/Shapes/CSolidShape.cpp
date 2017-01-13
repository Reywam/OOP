#include "stdafx.h"
#include "CSolidShape.h"

void CSolidShape::SetFillColor(std::string color)
{
	m_fillColor = color;
}

std::string CSolidShape::GetFillColor()const
{
	return m_fillColor;
}