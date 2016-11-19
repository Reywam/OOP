#include "stdafx.h"
#include <iostream>
#include <string>
#include "HTMLEncode.h"

using namespace std;

void main()
{
	while (!cin.eof())
	{
		string textString;
		getline(cin, textString);
		string encodedString = HtmlEncode(textString);
		cout << encodedString << endl;
	}

	return;
}