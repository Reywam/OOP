#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"

class CCircle final : public CSolidShape, public CShape
{
public:
	CCircle(CPoint center, double radius, std::string outlineColor, std::string fillColor);
	~CCircle() = default;

	double GetArea()const;
	double GetPerimeter()const;

	std::string ToString()const;
	std::string GetOutlineColor()const;
	std::string GetFillColor()const;

	CPoint GetCenter()const;
	double GetRadius()const;
private:
	std::string m_name = "circle";

	CPoint m_center;
	double m_radius;
};