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
		//Находим слово в строке
		while ((iswalpha(inputString[i]) || iswdigit(inputString[i])) && i < inputString.size())
		{
			word += inputString[i];
			++i;
		}
		//Проверяем, входит ли оно во множество нецензурных слов
		if (setOfUncensoredWords.find(word) != setOfUncensoredWords.end())
		{
			//Если да - удаляем его, заменяя на другое
			word = (L"");
		}
		word += inputString[i];
		//Если нет - приплюсовываем к выходной строке
		processedString += word;
	}

	return processedString;
}