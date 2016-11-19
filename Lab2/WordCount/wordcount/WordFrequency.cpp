#include "stdafx.h"
#include "WordFrequency.h"
#include <numeric>
#include <map>
#include <functional>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

void StringToLower(string &str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void PrintWordsFrequency(ostream &output, map<string, int> const &wordFreq)
{
	for (auto wordInfo : wordFreq)
	{
		output << wordInfo.first << "->" << wordInfo.second << endl;
	}
}

map<string, int> ReadWordAndAddInMap(istream &input)
{
	string word;
	map<string, int> wordFrequency;

	while (input >> word)
	{
		StringToLower(word);
		++wordFrequency[word];
	}

	return wordFrequency;
}