#include "stdafx.h"
#include "../UncensoredWordsFilter/UncensoredWordsFilter.h"

BOOST_AUTO_TEST_SUITE(uncensored_words_filter)
	BOOST_AUTO_TEST_CASE(can_delete_uncensored_words)
	{
		set<wstring> testSet = {(L"дурак"), (L"лосось"), (L"door"), (L"hell")};

		wstring testString = (L"Что за hell, дурак?! Выкинь\t этот лосось\n за door сейчас же!");
		wstring expectedString = (L"Что за , ?! Выкинь\t этот \n за  сейчас же!");

		BOOST_CHECK(DeleteUncensoredWords(testSet, testString) == expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()