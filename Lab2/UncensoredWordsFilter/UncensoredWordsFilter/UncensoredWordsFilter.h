#pragma once
#include <string>
#include <fstream>
#include <set>

using namespace std;

void ReadListOfUncensoredWords(wifstream &file, set<wstring> &setOfUncensoredWords);
wstring DeleteUncensoredWords(const set<wstring> &setOfUncensoredWords, const wstring &inputString);
