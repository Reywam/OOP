#pragma once
#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include <sstream>
#include "CShape.h"

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(std::istream & input, std::ostream & output);
	bool HandleCommand();
	void PrintInfo(std::ostream &output);
private:
	bool CreateLineSegment(std::istream &args);
	bool CreateCircle(std::istream &args);
	bool CreateTriangle(std::istream &args);
	bool CreateRectangle(std::istream &args);
	std::vector<std::string> GetShapeParameters(std::string const &paremeters)const;
private:
	typedef std::map<std::string, std::function<bool(std::istream & args) >> ActionMap;

	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::istream &m_input;
	std::ostream &m_output;

	const ActionMap m_actionMap;
};