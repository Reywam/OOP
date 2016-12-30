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
		auto newElement = std::make_shared<Node>();

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
		if (IsEmpty())
		{
			throw std::domain_error("Can't pop element from empty stack.");
		}

		m_lastElement = m_lastElement->prevElement;

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

	size_t GetSize()const
	{
		return(m_size);
	}

	bool IsEmpty()const
	{
		return(m_size == 0);
	}

	CMyStack &operator =(CMyStack<T> const &stack)
	{
		if (*this != stack)
		{
			Copy(stack.m_lastElement);
		}

		return *this;
	}

	CMyStack &operator=(CMyStack<T> &&stack)
	{
		if (*this != stack)
		{
			Move(stack.m_lastElement);
			stack.Clear();
		}

		return *this;
	}

	bool CMyStack<T>::operator ==(CMyStack const &stack)const
	{
		if (GetSize() != stack.GetSize())
		{
			return false;
		}

		auto tmpNode1 = m_lastElement;
		auto tmpNode2 = stack.m_lastElement;

		while (tmpNode1 != nullptr)
		{
			if (tmpNode1->element != tmpNode2->element)
			{
				return false;
			}

			tmpNode1 = tmpNode1->prevElement;
			tmpNode2 = tmpNode2->prevElement;
		}

		return true;
	}
	
	bool CMyStack<T>::operator !=(CMyStack const &stack)const
	{
		return !(*this == stack);
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
	size_t m_size = 0;
};