#pragma once
#include <string>
#include <memory>

class CStringStack
{
public:
	~CStringStack();

	void Push(const std::string &string);
	void Pop();

	std::string GetLastElement()const;
	size_t GetSize()const;

	bool IsEmpty()const;

private:
	struct Node
	{
		std::string element = "";
		std::shared_ptr<Node> prevElement = nullptr;
	};

	std::shared_ptr<Node> m_lastElement;

	size_t m_size = 0;
};