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

		newElement->data = element;

		if (m_lastElement != nullptr)
		{
			newElement->prevNode = m_lastElement;
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

		m_lastElement = m_lastElement->prevNode;

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

		return(m_lastElement->data);
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
			Move(std::move(stack));
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
			if (tmpNode1->data != tmpNode2->data)
			{
				return false;
			}

			tmpNode1 = tmpNode1->prevNode;
			tmpNode2 = tmpNode2->prevNode;
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
		T data = T();
		std::shared_ptr<Node> prevNode = nullptr;
	};
	 
	void Copy(CMyStack const &stack)
	{
		auto tmpNode = stack.m_lastElement;

		auto seed = std::make_shared<Node>();
		auto prevNode = seed;

		seed->data = tmpNode->data;

		tmpNode = tmpNode->prevNode;

		while (tmpNode != nullptr)
		{
			auto newNode = std::make_shared<Node>();
			newNode->data = tmpNode->data;

			prevNode->prevNode = newNode;
			prevNode = newNode;

			tmpNode = tmpNode->prevNode;
		}

		m_size = stack.GetSize();
		m_lastElement = seed;
	}

	void Move(CMyStack &&stack)
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