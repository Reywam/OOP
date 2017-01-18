#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public CShape, public ISolidShape
{
public:
	CSolidShape() = default;
	CSolidShape(std::string outlineColor, std::string fillColor);

	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string ToString()const = 0;

	virtual std::string GetFillColor()const;
	std::string GetOutlineColor()const;
private:
	std::string m_fillColor;
};