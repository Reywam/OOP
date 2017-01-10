#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment final: public IShape
{
public:
	CLineSegment() = default;
	~CLineSegment() = default;

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
	std::string m_outlineColor;

	CPoint m_startPoint;
	CPoint m_endPoint;
};