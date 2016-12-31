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
			throw std::underflow_error("Can't pop element from empty stack.");
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
			throw std::underflow_error("Can't get last element from empty stack.");
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
			Copy(stack);
		}

		return *this;
	}

	CMyStack &operator=(CMyStack<T> &&stack)
	{
		if (*this != stack)
		{
			Move(stack);
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
	 
	void Copy(CMyStack const &stack)
	{
		Clear();
		auto tmpNode = stack.m_lastElement;

		auto seed = std::make_shared<Node>();
		auto prevNode = seed;

		seed->element = tmpNode->element;

		tmpNode = tmpNode->prevElement;

		while (tmpNode != nullptr)
		{
			auto newNode = std::make_shared<Node>();
			newNode->element = tmpNode->element;

			prevNode->prevElement = newNode;
			prevNode = newNode;

			tmpNode = tmpNode->prevElement;
		}

		m_size = stack.GetSize();
		m_lastElement = seed;
	}

	void Move(CMyStack &stack)
	{
		if (*this != stack)
		{
			m_lastElement = stack.m_lastElement;
			m_size = stack.GetSize();

			stack.m_lastElement = nullptr;
			stack.m_size = 0;
		}
	}

	std::shared_ptr<Node> m_lastElement = nullptr;
	size_t m_size = 0;
};