#include "stdafx.h"
#include "CStringStack.h"
#include <string>
#include <memory>

using namespace std;

CStringStack::~CStringStack()
{
	while (m_lastElement != nullptr)
	{
		Pop();
	}
}

void CStringStack::Push(const std::string &string)
{
	auto newElement = std::make_shared<Node>();
	
	newElement->element = string;

	if (m_lastElement != nullptr)
	{
		newElement->prevElement = m_lastElement;
	}

	m_lastElement = newElement;

	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::underflow_error("Can't pop element from empty stack.");
	}

	m_lastElement = m_lastElement->prevElement;

	--m_size;
}

string CStringStack::GetLastElement()const
{
	if (IsEmpty())
	{
		throw std::underflow_error("Can't get last element from empty stack.");
	}

	return m_lastElement->element;
}

size_t CStringStack::GetSize()const
{
	return m_size;
}

bool CStringStack::IsEmpty()const
{
	return(m_size == 0);
}