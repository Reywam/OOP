#pragma once
#include "ISolidShape.h"

class CSolidShape : public ISolidShape
{
public:
	virtual std::string GetFillColor()const;
	void SetFillColor(std::string color);
private:
	std::string m_fillColor;
};