#include "stdafx.h"
#include "../UncensoredWordsFilter/UncensoredWordsFilter.h"

BOOST_AUTO_TEST_SUITE(uncensored_words_filter)
	BOOST_AUTO_TEST_CASE(can_delete_uncensored_words)
	{
		set<wstring> testSet = {(L"�����"), (L"������"), (L"door"), (L"hell")};

		wstring testString = (L"��� �� hell, �����?! ������\t ���� ������\n �� door ������ ��!");
		wstring expectedString = (L"��� �� , ?! ������\t ���� \n ��  ������ ��!");

		BOOST_CHECK(DeleteUncensoredWords(testSet, testString) == expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()