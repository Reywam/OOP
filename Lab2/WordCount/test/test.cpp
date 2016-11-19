#include "stdafx.h"
#include <sstream>
#include "../wordcount/WordFrequency.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(word_frequency_function)
	BOOST_AUTO_TEST_CASE(cant_count_words_when_input_is_empty)
	{
		map<string, int> result = {};
		std::istringstream test("");
		BOOST_CHECK(result == ReadWordAndAddInMap(test));
	}

	BOOST_AUTO_TEST_CASE(can_count_words_when_input_is_not_empty)
	{
		map<string, int> result = { { "hello", 4 },{ "world", 5 } };
		std::istringstream test("Hello World\nHELLO WORLD     hello world\t HellO WoRlD world");
		BOOST_CHECK(result == ReadWordAndAddInMap(test));
	}
BOOST_AUTO_TEST_SUITE_END()