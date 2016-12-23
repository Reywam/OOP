#pragma once
#include <string>
#include <memory>

class CStringStack
{
public:
	CStringStack();
	~CStringStack() noexcept;

	void Push(const std::string &string);
	void Pop();

	std::string GetLastElement()const;

	bool IsEmpty()const;

private:
	struct Node
	{
		std::string element = "";
		std::shared_ptr<Node> prevElement = nullptr;
	};

	std::shared_ptr<Node> m_lastElement;

	int m_size = 0;
};