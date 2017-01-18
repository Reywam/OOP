#pragma once
#include <string>
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape() = default;
	CShape(std::string color);

	~CShape() = default;

	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string ToString()const = 0;
	virtual std::string GetOutlineColor()const;

private:
	std::string m_outlineColor;
};