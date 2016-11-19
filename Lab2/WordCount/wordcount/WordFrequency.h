#pragma once
#include <map>
#include <iostream>

using namespace std;

void StringToLower(string &str);
map<string, int> ReadWordAndAddInMap(istream &input);
void PrintWordsFrequency(ostream &output, map<string, int> const &wordFreq);