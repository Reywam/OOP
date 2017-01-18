#include "stdafx.h"
#include "CSolidShape.h"
#include "CShape.h"

std::string CSolidShape::GetFillColor()const
{
	return m_fillColor;
}

CSolidShape::CSolidShape(std::string outlineColor, std::string fillColor)
	:CShape(outlineColor)
{
	m_fillColor = fillColor;
}

std::string CSolidShape::GetOutlineColor()const
{
	return CShape::GetOutlineColor();
}