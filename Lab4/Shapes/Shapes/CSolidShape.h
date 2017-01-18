#pragma once
#include "ISolidShape.h"

class CSolidShape : public ISolidShape
{
public:
	CSolidShape() = default;
	CSolidShape(std::string color);

	virtual std::string GetFillColor()const;

private:
	std::string m_fillColor;
};