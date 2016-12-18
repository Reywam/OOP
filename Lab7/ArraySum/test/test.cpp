#include "stdafx.h"
#include "../ArraySum/ArraySum.h"
#include <vector>
#include <string>

BOOST_AUTO_TEST_SUITE(ArraySum_function)
	BOOST_AUTO_TEST_CASE(can_calculate_sum_of_integers)
	{
		std::vector<int> testData = { 0, -2, 3 };
		int sum = ArraySum(testData);
		int expectedSum = 1;
		BOOST_CHECK_EQUAL(sum, expectedSum);
	}

	BOOST_AUTO_TEST_CASE(can_calculate_sum_of_strings)
	{
		std::vector<std::string> testData = {"Hello ", "World!", ""};
		std::string sum = ArraySum(testData);
		std::string expectedSum = "Hello World!";
		BOOST_CHECK_EQUAL(sum, expectedSum);
	}

	BOOST_AUTO_TEST_CASE(can_calculate_sum_of_doubles)
	{
		std::vector<double> testData = {-0.1, 0.0, 2.0};
		double sum = ArraySum(testData);
		double expectedSum = 1.9;
		BOOST_CHECK_EQUAL(sum, expectedSum);
	}

	BOOST_AUTO_TEST_CASE(returns_default_type_value_when_array_is_empty)
	{
		std::vector<int> testData1;
		int sum1 = ArraySum(testData1);
		BOOST_CHECK_EQUAL(sum1, 0);

		std::vector<std::string> testData2;
		std::string sum2 = ArraySum(testData2);
		BOOST_CHECK_EQUAL(sum2, "");

		std::vector<double> testData3;
		double sum3 = ArraySum(testData3);
		BOOST_CHECK_EQUAL(sum3, 0.0);
	}
BOOST_AUTO_TEST_SUITE_END()