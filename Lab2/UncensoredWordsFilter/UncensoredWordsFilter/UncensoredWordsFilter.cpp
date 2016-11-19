#include "stdafx.h"
#include "UncensoredWordsFilter.h"
#include <set>

void ReadListOfUncensoredWords(wifstream &file, set<wstring> &setOfUncensoredWords)
{
	while (!file.eof())
	{
		wstring uncensoredWord;
		getline(file, uncensoredWord);
		if (uncensoredWord == (L""))
		{
			continue;
		}
		setOfUncensoredWords.insert(uncensoredWord);
	}
}

wstring DeleteUncensoredWords(const set<wstring> &setOfUncensoredWords, const wstring &inputString)
{
	wstring processedString;

	for (size_t i = 0; i < inputString.size(); i++)
	{
		wstring word;
		//������� ����� � ������
		while ((iswalpha(inputString[i]) || iswdigit(inputString[i])) && i < inputString.size())
		{
			word += inputString[i];
			++i;
		}
		//���������, ������ �� ��� �� ��������� ����������� ����
		if (setOfUncensoredWords.find(word) != setOfUncensoredWords.end())
		{
			//���� �� - ������� ���, ������� �� ������
			word = (L"");
		}
		word += inputString[i];
		//���� ��� - �������������� � �������� ������
		processedString += word;
	}

	return processedString;
}