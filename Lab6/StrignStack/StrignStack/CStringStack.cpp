#include "stdafx.h"
#include "CStringStack.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

bool CStringStack::Pop()
{
	if (!m_size == 0)
	{
		shared_ptr<Node> tmpNode = m_lastElement;

		m_lastElement = m_lastElement->prevElement;
		tmpNode.reset();

		--m_size;
		return true;
	}
	else
	{
		throw domain_error("Can't pop element from empty stack.");
	}
}

string CStringStack::GetElement()const
{
	if (!m_size == 0)
	{
		return m_lastElement->element;
	}
	else
	{
		throw domain_error("Can't get element from empty stack.");
	}
}

bool CStringStack::Push(const string &element)
{
	if (m_stack == nullptr)
	{
		shared_ptr<Node> newElement(new Node);

		newElement->element = element;
		newElement->prevElement = m_lastElement;

		m_stack = newElement;
		m_lastElement = m_stack;
	}

	shared_ptr<Node> newElement(new Node);

	newElement->element = element;
	newElement->prevElement = m_lastElement;

	m_lastElement = newElement;

	++m_size;

	return true;
}

bool CStringStack::IsEmpty()
{
	return(m_size == 0);
}