#include "stdafx.h"
#include "CStringStack.h"
#include <iostream>
#include <string>
#include <exception>
#include <memory>

using namespace std;

CStringStack::CStringStack()
{

}

CStringStack::~CStringStack()
{
	while (m_lastElement != nullptr)
	{
		Pop();
	}
}

void CStringStack::Push(const std::string &string)
{
	shared_ptr<Node> newElement(new Node);
	
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
	shared_ptr<Node> tmpNode = m_lastElement;

	if (IsEmpty())
	{
		throw std::domain_error("Can't pop element from empty stack.");
	}

	m_lastElement = m_lastElement->prevElement;

	tmpNode.reset();

	--m_size;
}

string CStringStack::GetLastElement()const
{
	if (IsEmpty())
	{
		throw std::domain_error("Can't get last element from empty stack.");
	}

	return m_lastElement->element;
}

int CStringStack::GetSize()const
{
	return m_size;
}

bool CStringStack::IsEmpty()const
{
	return(m_size == 0);
}