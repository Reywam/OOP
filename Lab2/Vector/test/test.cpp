#include "stdafx.h"
#include "../vector/VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(vector_processor_function)

	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(processed_not_empty_vector)
	{
		vector<double> numbers = { 2, 5, -3, 3.5 };
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, { (2 * (-3)), (5 * (-3)), (-3 * (-3)), (3.5 *(-3)) }));
	}

	BOOST_AUTO_TEST_CASE(when_min_value_is_zero)
	{
		vector<double> numbers = { 2, 5, 0, 3.5 };
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, { (2 * (0)), (5 * (0)), (-3 * (0)), (3.5 *(0)) }));
	}

BOOST_AUTO_TEST_SUITE_END()