#pragma once
#include <string>
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape() = default;
	virtual ~CShape() = default;

	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string ToString()const = 0;
	virtual std::string GetOutlineColor()const;
protected:
	std::string m_outlineColor;
};