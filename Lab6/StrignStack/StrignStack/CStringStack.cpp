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

CStringStack::~CStringStack() noexcept
{
	std::shared_ptr<Node> curr = m_lastElement;

	while (curr != nullptr)
	{
		std::shared_ptr<Node> tmpNode = curr->prevElement;

		curr.reset();

		curr = tmpNode;
	}

	m_lastElement = nullptr;
}

void CStringStack::Push(const std::string &string)
{
	try
	{
		shared_ptr<Node> newElement(new Node);

		newElement->element = string;

		if (m_lastElement != nullptr)
		{
			newElement->prevElement = m_lastElement;
		}

		m_lastElement = newElement;

	}
	catch (...)
	{
		cout << "Error: " << "Not enough memory to push new element." << endl;
	}

	++m_size;
}

void CStringStack::Pop()
{
	try
	{
		shared_ptr<Node> tmpNode = m_lastElement;

		if (IsEmpty())
		{
			throw std::domain_error("Can't pop elements from empty stack.");
		}

		m_lastElement = m_lastElement->prevElement;

		tmpNode.reset();
	}
	catch (std::bad_alloc)
	{
		cout << "Error: " << "Not enough memory to push new element." << endl;
	}

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

bool CStringStack::IsEmpty()const
{
	return(m_size == 0);
}