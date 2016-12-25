#include "stdafx.h"
#include "CMyStack.h"
#include <iostream>

using namespace std;

int main()
{
	CMyStack<int> stack1;

	stack1.Push(1);

	CMyStack<int> stack2(move(stack1));
	cout << stack1.GetSize() << endl;
	cout << stack2.GetSize() << endl;

    return 0;
}