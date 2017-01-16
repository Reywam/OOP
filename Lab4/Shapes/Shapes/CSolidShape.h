#pragma once
#include "ISolidShape.h"

class CSolidShape : public ISolidShape
{
public:
	virtual std::string GetFillColor()const;
protected:
	std::string m_fillColor;
};