#pragma once
#include "CShape.h"
#include "CPoint.h"

class CLineSegment final: public CShape
{
public:
	CLineSegment() = default;
	virtual ~CLineSegment() = default;

	CLineSegment(CPoint startPoint, CPoint endPoint, std::string outlineColor)
	{
		m_startPoint = startPoint;
		m_endPoint = endPoint;
		m_outlineColor = outlineColor;
	}

	CPoint GetStartPoint()const;
	CPoint GetEndPoint()const;
	double GetArea()const;
	double GetPerimeter()const;
	std::string ToString()const;
	std::string GetOutlineColor()const;
private:
	std::string m_name = "line segment";

	CPoint m_startPoint;
	CPoint m_endPoint;
};