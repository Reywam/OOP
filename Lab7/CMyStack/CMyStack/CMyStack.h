#pragma once
#include <memory>

template <typename T>
class CMyStack
{
public:
	CMyStack() = default;

	CMyStack(CMyStack<T> const &stack)
	{
		*this = stack;
	}

	CMyStack(CMyStack<T> &&stack)
	{
		*this = std::move(stack);
	}

	~CMyStack()
	{
		Clear();
	}

	void Push(T const &element)
	{
		std::shared_ptr<Node> newElement(new Node);

		newElement->element = element;

		if (m_lastElement != nullptr)
		{
			newElement->prevElement = m_lastElement;
		}

		m_lastElement = newElement;

		++m_size;
	}

	void Pop()
	{
		std::shared_ptr<Node> tmpNode = m_lastElement;

		if (IsEmpty())
		{
			throw std::domain_error("Can't pop element from empty stack.");
		}

		m_lastElement = m_lastElement->prevElement;

		tmpNode.reset();

		--m_size;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	T GetLastElement()const
	{
		if (IsEmpty())
		{
			throw std::domain_error("Can't get last element from empty stack.");
		}

		return(m_lastElement->element);
	}

	int GetSize()const
	{
		return(m_size);
	}

	bool IsEmpty()const
	{
		return(m_size == 0);
	}

	CMyStack &operator =(CMyStack<T> const &stack)
	{
		Copy(stack.m_lastElement);

		return *this;
	}

	CMyStack& operator=(CMyStack &&stack)
	{
		Move(stack.m_lastElement);
		stack.Clear();

		return *this;
	}
private:
	struct Node
	{
		T element = T();
		std::shared_ptr<Node> prevElement = nullptr;
	};

	void Copy(std::shared_ptr<Node> lastElement)
	{
		if (lastElement != nullptr)
		{
			Copy(lastElement->prevElement);
			Push(lastElement->element);
		}
	}

	void Move(std::shared_ptr<Node> lastElement)
	{
		if (lastElement != nullptr)
		{
			Move(lastElement->prevElement);

			auto copy = std::move(lastElement->element);
			Push(copy);
		}
	}

	std::shared_ptr<Node> m_lastElement = nullptr;
	int m_size = 0;
};