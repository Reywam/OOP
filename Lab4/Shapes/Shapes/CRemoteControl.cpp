#include "stdafx.h"
#include "CRemoteControl.h"
#include "IShape.h"
#include "CLineSegment.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include <sstream>
#include <iterator>

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(std::istream & input, std::ostream & output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "line", bind(&CRemoteControl::CreateLineSegment, this, _1) },
		{ "circle", bind(&CRemoteControl::CreateCircle, this, _1) },
		{ "triangle", bind(&CRemoteControl::CreateTriangle, this, _1) },
		{ "rectangle", bind(&CRemoteControl::CreateRectangle, this, _1) },
})
{
}

bool CmpAreas(shared_ptr<IShape> const &firstShape, shared_ptr<IShape> const &secondShape)
{
	return firstShape->GetArea() < secondShape->GetArea();
}

bool CmpPerimeters(shared_ptr<IShape> const &firstShape, shared_ptr<IShape> const &secondShape)
{
	return firstShape->GetPerimeter() < secondShape->GetPerimeter();
}

void CRemoteControl::PrintInfo(std::ostream &output)
{
	if (!m_shapes.empty())
	{
		auto shapeWithMaxArea = max_element(m_shapes.begin(), m_shapes.end(), CmpAreas);

		auto shapeWithMinPerimeter = min_element(m_shapes.begin(), m_shapes.end(), CmpPerimeters);

		output << "Shape with max area: " << endl;
		output << (*shapeWithMaxArea)->ToString() << endl;
		output << "Area: " << (*shapeWithMaxArea)->GetArea() << endl;
		output << "Perimeter: " << (*shapeWithMaxArea)->GetPerimeter() << endl;

		output << endl;

		output << "Shape with min perimeter: " << endl;
		output << (*shapeWithMinPerimeter)->ToString() << endl;
		output << "Area: " << (*shapeWithMinPerimeter)->GetArea() << endl;
		output << "Perimeter: " << (*shapeWithMinPerimeter)->GetPerimeter() << endl;
	}
}

vector<string> CRemoteControl::GetShapeParameters(std::string const &paramsLine)const
{
	vector<std::string> params;

	const boost::char_separator<char> separator(" ");
	boost::tokenizer<boost::char_separator<char>> tokenizer(paramsLine, separator);

	copy(tokenizer.begin(), tokenizer.end(), back_inserter(params));

	return params;
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CRemoteControl::CreateLineSegment(std::istream &args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 5)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage line <x1> <y1> <x2> <y2> <outlineColor>" << endl;
		return true;
	}

	CPoint startPoint, endPoint;
	string outlineColor;
	try
	{
		startPoint.x = boost::lexical_cast<double>(parameters[0]);
		startPoint.y = boost::lexical_cast<double>(parameters[1]);

		endPoint.x = boost::lexical_cast<double>(parameters[2]);
		endPoint.y = boost::lexical_cast<double>(parameters[3]);

		outlineColor = parameters[4];
	}
	catch (boost::bad_lexical_cast const &e)
	{
		m_output << e.what() << endl;
		return false;
	}

	m_shapes.push_back(make_shared<CLineSegment>(CLineSegment(startPoint, endPoint, outlineColor)));

	m_output << "line segment was created" << endl;
	return true;
}

bool CRemoteControl::CreateCircle(std::istream &args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 5)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage circle <x1> <y1> <radius> <outlineColor> <fillColor>" << endl;
		return true;
	}

	CPoint center;
	double radius;

	try
	{
		center.x = boost::lexical_cast<double>(parameters[0]);
		center.y = boost::lexical_cast<double>(parameters[1]);

		radius = boost::lexical_cast<double>(parameters[2]);
		if (radius < 0)
		{
			m_output << "Circle radius can't be negative value." << endl;
			return true;
		}
	}
	catch (boost::bad_lexical_cast const &e)
	{
		m_output << e.what() << endl;
		return false;
	}

	m_shapes.push_back(make_shared<CCircle>(CCircle(center, radius, parameters[3], parameters[4])));
	m_output << "circle was created" << endl;
	return true;
}

bool CRemoteControl::CreateTriangle(std::istream &args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 8)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage triangle <x1> <y1> <x2> <y2> <x3> <y3> <outlineColor> <fillColor>" << endl;
		return true;
	}

	CPoint vertex1, vertex2, vertex3;

	try
	{
		vertex1.x = boost::lexical_cast<double>(parameters[0]);
		vertex1.y = boost::lexical_cast<double>(parameters[1]);

		vertex2.x = boost::lexical_cast<double>(parameters[2]);
		vertex2.y = boost::lexical_cast<double>(parameters[3]);

		vertex3.x = boost::lexical_cast<double>(parameters[4]);
		vertex3.y = boost::lexical_cast<double>(parameters[5]);
	}
	catch (boost::bad_lexical_cast const &e)
	{
		m_output << e.what() << endl;
		return false;
	}

	m_shapes.push_back(make_shared<CTriangle>(CTriangle(vertex1, vertex2, vertex3, parameters[6], parameters[7])));

	m_output << "triangle was created" << endl;
	return true;
}

bool CRemoteControl::CreateRectangle(std::istream &args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 6)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage rectangle <x1> <y1> <width> <height> <outlineColor> <fillColor>" << endl;
		return true;
	}

	CPoint leftTop = CPoint(0, 0);
	double width = 0;
	double height = 0;

	try
	{
		leftTop.x = boost::lexical_cast<double>(parameters[0]);
		leftTop.y = boost::lexical_cast<double>(parameters[1]);
		width = boost::lexical_cast<double>(parameters[2]);
		height= boost::lexical_cast<double>(parameters[3]);
		if (width < 0 || height < 0)
		{
			m_output << "Width and height can't be negative value." << endl;
			return true;
		}
	}
	catch (boost::bad_lexical_cast const &e)
	{
		m_output << e.what() << endl;
	}

	m_shapes.push_back(make_shared<CRectangle>(CRectangle(leftTop, width, height, parameters[4], parameters[5])));

	m_output << "rectangle was created" << endl;
	return true;
}