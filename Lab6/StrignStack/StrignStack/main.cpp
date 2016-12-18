#include "stdafx.h"
#include "CStringStack.h"
#include <iostream>

int main()
{
	CStringStack stack;
	stack.Push("A");

	std::cout << stack.GetElement() << std::endl; 
	stack.Pop();
	std::cout << stack.GetElement() << std::endl;
    return 0;
}