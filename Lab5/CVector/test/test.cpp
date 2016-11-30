#include "stdafx.h"
#include "../CVector/CVector3D.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(class_Vector3D)

struct MyFirstFixture_
{
	MyFirstFixture_()
		: vector(1,2,3)
		, vectorOne(3 * vector)
		, vectorTwo(0*vector)
		, vectorThree(-1 * vector)
		, expectedVectorOne(3,6,9)
		, expectedVectorTwo(0,0,0)
		, expectedVectorThree(-1,-2,-3)
	{}

	CVector3D vector;

	CVector3D vectorOne;
	CVector3D vectorTwo;
	CVector3D vectorThree;

	CVector3D expectedVectorOne;
	CVector3D expectedVectorTwo;
	CVector3D expectedVectorThree;
};

struct SecondTestFixture_
{
	SecondTestFixture_()
		: vectorOne(0, 1, 1)
		, vectorTwo(1, 1, 2)
		, vectorThree(2, 2, 3)
	{}
	CVector3D vectorOne;
	CVector3D vectorTwo;
	CVector3D vectorThree;
};

struct ThirdTestFixture_
{
	ThirdTestFixture_()
		: vector(1, 2, 3)
		, vectorOne(vector / 1)
		, vectorTwo(vector / 0)
		, vectorThree(vector / -1)
		, expectedVectorOne(1, 2, 3)
		, expectedVectorTwo(expectedVectorOne)
		, expectedVectorThree(-expectedVectorOne)
	{}
	CVector3D vector;

	CVector3D vectorOne;
	CVector3D vectorTwo;
	CVector3D vectorThree;

	CVector3D expectedVectorOne;
	CVector3D expectedVectorTwo;
	CVector3D expectedVectorThree;
};

	BOOST_AUTO_TEST_CASE(can_create_zero_vector)
	{
		CVector3D emptyVector;
		BOOST_CHECK_EQUAL(emptyVector.x, 0);
		BOOST_CHECK_EQUAL(emptyVector.y, 0);
		BOOST_CHECK_EQUAL(emptyVector.z, 0);
	}
	
	BOOST_AUTO_TEST_CASE(can_create_not_zero_vector)
	{
		CVector3D newVector(1, 2, 3);
		BOOST_CHECK_EQUAL(newVector.x, 1);
		BOOST_CHECK_EQUAL(newVector.y, 2);
		BOOST_CHECK_EQUAL(newVector.z, 3);
	}

	BOOST_AUTO_TEST_CASE(can_get_vector_length)
	{
		CVector3D newVector(2, 2, 1);

		double vectorLength = newVector.GetLength();
		double expectedVectorLength = 3;

		BOOST_CHECK_EQUAL(vectorLength, expectedVectorLength);
	}

	BOOST_AUTO_TEST_CASE(can_normalize_vector)
	{
		CVector3D newVector(0, 0, 1);
		CVector3D expectedVector(0 / 1, 0 / 1, 1 / 1);

		newVector.Normalize();
		BOOST_CHECK(newVector == expectedVector);
	}

	BOOST_AUTO_TEST_CASE(unary_plus_returns_equal_vector)
	{
		CVector3D newVector(0, 0, 1);
		BOOST_CHECK(+newVector == newVector);
	}

	BOOST_AUTO_TEST_CASE(unary_minus_returns_vector_with_inverse_direction)
	{
		CVector3D newVector(1, 2, 3);
		CVector3D expectedVector(-1, -2, -3);

		BOOST_CHECK(-newVector == expectedVector);
	}

	BOOST_FIXTURE_TEST_CASE(can_add_vectors, SecondTestFixture_)
	{
		CVector3D vectorsSum = vectorOne + vectorTwo + vectorThree;

		CVector3D expectedVector(3, 4, 6);

		BOOST_CHECK(expectedVector == vectorsSum);
	}

	BOOST_FIXTURE_TEST_CASE(can_subtract_vectors, SecondTestFixture_)
	{
		CVector3D vectorsDiffirence = vectorOne - vectorTwo - vectorThree;

		CVector3D expectedVector(-3, -2, -4);

		BOOST_CHECK(expectedVector == vectorsDiffirence);
	}

	BOOST_AUTO_TEST_CASE(can_increase_magnitude_of_vector)
	{
		CVector3D vectorOne(1, 2, 3);
		CVector3D vectorTwo(3, 2, 1);

		CVector3D expectedVector(4, 4, 4);

		vectorOne += vectorTwo;

		BOOST_CHECK(expectedVector == vectorOne);
	}

	BOOST_AUTO_TEST_CASE(can_decrease_magnitude_of_vector)
	{
		CVector3D vectorOne(1, 2, 3);
		CVector3D vectorTwo(1, 1, 1);

		CVector3D expectedVector(0, 1, 2);

		vectorOne -= vectorTwo;

		BOOST_CHECK(expectedVector == vectorOne);
	}

	BOOST_FIXTURE_TEST_CASE(can_multiply_scalar_by_vector, MyFirstFixture_)
	{
		BOOST_CHECK(expectedVectorOne == vectorOne);
		BOOST_CHECK(expectedVectorTwo == vectorTwo);
		BOOST_CHECK(expectedVectorThree == vectorThree);
	}

	BOOST_FIXTURE_TEST_CASE(can_multiply_vector_by_scalar, MyFirstFixture_)
	{
		BOOST_CHECK(expectedVectorOne == vectorOne);
		BOOST_CHECK(expectedVectorTwo == vectorTwo);
		BOOST_CHECK(expectedVectorThree == vectorThree);
	}

	BOOST_FIXTURE_TEST_CASE(can_divide_vector_by_scalar, ThirdTestFixture_)
	{
		BOOST_CHECK(expectedVectorOne == vectorOne);
		BOOST_CHECK(expectedVectorTwo == vectorTwo);
		BOOST_CHECK(expectedVectorThree == vectorThree);
	}

	BOOST_AUTO_TEST_CASE(can_increase_magnitude_of_vector_by_multiplying_vector_and_scalar)
	{
		CVector3D vector(1, 2, 3);
		CVector3D expectedVector(10, 20, 30);
		vector *= 10;

		BOOST_CHECK(expectedVector == vector);
	}

	BOOST_AUTO_TEST_CASE(can_decrease_magnitude_of_vector_by_deviding_vector_and_scalar)
	{
		CVector3D vector(1, 2, 3);
		CVector3D expectedVector(0.1, 0.2, 0.3);

		vector /= 10;
		BOOST_CHECK(expectedVector == vector);

		vector /= 0;
		BOOST_CHECK(expectedVector == vector);

		vector /= -1;
		BOOST_CHECK(expectedVector == -vector);
	}

	BOOST_AUTO_TEST_CASE(can_compare_vectors)
	{
		CVector3D vectorOne(1, 2, 3);
		CVector3D vectorTwo(6, 5, 3);
		CVector3D vectorThree(1, 2, 3);

		BOOST_CHECK(vectorOne != vectorTwo);
		BOOST_CHECK(vectorOne == vectorThree);
	}
BOOST_AUTO_TEST_SUITE_END()