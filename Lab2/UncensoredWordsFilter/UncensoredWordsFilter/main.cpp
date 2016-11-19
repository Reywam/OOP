#include "stdafx.h"
#include "UncensoredWordsFilter.h"
#include <set>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 2)
	{
		cout << "Invalid count of arguements" << endl;
		return;
	}

	wifstream fileWithUncensoredWords(argv[1]);

	if (!fileWithUncensoredWords)
	{
		cout << "Opening file error" << endl;
		return;
	}

	set<wstring> setOfUncensoredWords;
	
	ReadListOfUncensoredWords(fileWithUncensoredWords, setOfUncensoredWords);

	while (!wcin.eof())
	{
		wstring inputString;
		getline(wcin, inputString);

		wstring outputString = DeleteUncensoredWords(setOfUncensoredWords, inputString);
		wcout << outputString << endl;
	}

    return;
}