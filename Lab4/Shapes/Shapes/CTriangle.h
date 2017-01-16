#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

class CTriangle final: public CSolidShape, public CShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, std::string outlineColor, std::string fillColor);
	virtual ~CTriangle() = default;

	double GetArea()const;
	double GetPerimeter()const;

	std::string ToString()const;
	std::string GetOutlineColor()const;
	std::string GetFillColor()const;

	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();
private:
	std::string m_name = "triangle";

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
