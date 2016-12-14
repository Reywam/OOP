#include "stdafx.h"
#include "../solve4/solve4.h"

bool RootsAreEqual(EquationRoots const &expectedRoots, EquationRoots const &resultRoots)
{
	for (size_t i = 0; i < resultRoots.numRoots; ++i)
	{
		if (abs(resultRoots.root[i] - expectedRoots.root[i]) < DBL_EPSILON)
		{
			return true;
		}
	}

	return false;
}

BOOST_AUTO_TEST_SUITE(solve4_function)
	BOOST_AUTO_TEST_CASE(can_find_equation_roots)
	{
		EquationRoots solution = Solve4(1, 4, 6, 4, 1);

		EquationRoots expectedRoots;
		expectedRoots.numRoots = 2;
		expectedRoots.root[0] = -1;
		expectedRoots.root[1] = -1;

		BOOST_CHECK(RootsAreEqual(expectedRoots, solution));

		solution = Solve4(1, 4, 2, 4, 0);

		expectedRoots.numRoots = 2;
		expectedRoots.root[0] = 0;
		expectedRoots.root[1] = -3.7511;

		BOOST_CHECK(RootsAreEqual(expectedRoots, solution));
	}
	
	BOOST_AUTO_TEST_CASE(first_coefficient_must_be_not_equal_zero)
	{
		double a = 0;

		BOOST_CHECK_THROW(Solve4(a, 1, 2, 3, 4), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(may_have_not_real_roots)
	{
		BOOST_CHECK_THROW(Solve4(1, 2, 3, 4, 5), std::domain_error);
	}

BOOST_AUTO_TEST_SUITE_END()