#include "stdafx.h"
#include "HTMLEncode.h"
#include <string>

using namespace std;

string HtmlEncode(std::string const &text)
{
	char ch = NULL;
	string encodedString = "";

	for (size_t i = 0; i < text.size(); i++)
	{
		ch = text[i];
		switch (ch)
		{
		case '\"':
			encodedString += "&quot;";
			break;
		case '\'':
			encodedString += "&apos;";
			break;
		case '<':
			encodedString += "&lt;";
			break;
		case '>':
			encodedString += "&gt;";
			break;
		case '&':
			encodedString += "&amp;";
			break;
		default:
			encodedString += ch;
			break;
		}
	}

	return encodedString;
}