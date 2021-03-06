#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

class CTriangle final: public CSolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, std::string outlineColor, std::string fillColor);
	~CTriangle() = default;

	double GetArea()const;
	double GetPerimeter()const;

	std::string ToString()const;
	std::string GetOutlineColor()const;
	std::string GetFillColor()const;

	CPoint GetVertex1()const;
	CPoint GetVertex2()const;
	CPoint GetVertex3()const;
private:
	std::string m_name = "triangle";

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
