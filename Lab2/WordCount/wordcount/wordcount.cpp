#include "stdafx.h"
#include "WordFrequency.h"
#include <map>


using namespace std;

void main()
{
	map<string, int> wordFrequency;
	
	wordFrequency = ReadWordAndAddInMap(cin);
	PrintWordsFrequency(cout, wordFrequency);
}

