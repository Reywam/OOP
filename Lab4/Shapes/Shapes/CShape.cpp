#include "stdafx.h"
#include "CShape.h"

CShape::CShape(std::string color)
{
	m_outlineColor = color;
}

std::string CShape::GetOutlineColor()const
{
	return m_outlineColor;
}
