#include "stdafx.h"
#include "CStringStack.h"
#include <iostream>

int main()
{
	CStringStack stack;
	stack.Push("A");

	std::cout << stack.GetLastElement() << std::endl; 
	stack.Pop();
	std::cout << stack.GetLastElement() << std::endl;
    return 0;
}