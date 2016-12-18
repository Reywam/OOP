#pragma once
#include <string>
#include <memory>

class CStringStack
{
public:
	CStringStack()
	{
		m_stack = nullptr;
		m_lastElement = m_stack;
	}

	~CStringStack()
	{
		if (m_size != 0)
		{
			while (m_lastElement->prevElement != m_stack)
			{
				std::shared_ptr<Node> tmpNode = m_lastElement;
				m_lastElement = m_lastElement->prevElement;
				tmpNode.reset();
			}
		}
	}

	bool Push(const std::string &string);
	bool Pop();
	std::string GetElement()const;
	bool IsEmpty();

private:
	struct Node
	{
		std::string element = "";
		std::shared_ptr<Node> prevElement = nullptr;
	};

	std::shared_ptr<Node> m_stack;
	std::shared_ptr<Node> m_lastElement;

	int m_size = 0;
};