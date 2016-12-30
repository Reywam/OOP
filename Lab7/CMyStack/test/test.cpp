#include "stdafx.h"
#include "../CMyStack/CMyStack.h"

struct EmptyStack
{
	CMyStack<std::string> stringStack;
	CMyStack<int> intStack;
};

BOOST_FIXTURE_TEST_SUITE(Stack, EmptyStack)
	BOOST_AUTO_TEST_SUITE(Stack_Class)
		BOOST_AUTO_TEST_CASE(is_empty_by_default)
		{
			BOOST_CHECK(stringStack.IsEmpty());

			BOOST_CHECK(intStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_push_elements)
		{
			intStack.Push(12);
			BOOST_CHECK(!intStack.IsEmpty());

			stringStack.Push("42");
			BOOST_CHECK(!stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_get_last_element)
		{
			intStack.Push(9);
			BOOST_CHECK_EQUAL(intStack.GetLastElement(), 9);

			stringStack.Push("6");
			BOOST_CHECK_EQUAL(stringStack.GetLastElement(), "6");
		}

		BOOST_AUTO_TEST_CASE(can_not_get_last_element_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(intStack.GetLastElement(), std::domain_error);
			BOOST_CHECK_THROW(stringStack.GetLastElement(), std::domain_error);
		}

		BOOST_AUTO_TEST_CASE(can_get_size_of_stack)
		{
			intStack.Push(1);
			BOOST_CHECK_EQUAL(intStack.GetSize(), (size_t)1);

			stringStack.Push("18900");
			BOOST_CHECK_EQUAL(stringStack.GetSize(), (size_t)1);
		}

		BOOST_AUTO_TEST_CASE(can_pop_elements)
		{
			intStack.Push(19);
			BOOST_CHECK(!intStack.IsEmpty());

			intStack.Pop();
			BOOST_CHECK(intStack.IsEmpty());

			stringStack.Push("42");
			BOOST_CHECK(!stringStack.IsEmpty());

			stringStack.Pop();
			BOOST_CHECK(stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_not_pop_elements_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(intStack.Pop(), std::domain_error);

			BOOST_CHECK_THROW(stringStack.Pop(), std::domain_error);
		}

		BOOST_AUTO_TEST_CASE(can_delete_all_elements_in_stack)
		{
			size_t currentSize = 3;
			size_t expectedSize = 0;

			for (size_t i = 0; i < currentSize; ++i)
			{
				intStack.Push((int)i);
			}
			BOOST_CHECK_EQUAL(intStack.GetSize(), currentSize);

			intStack.Clear();
			BOOST_CHECK_EQUAL(intStack.GetSize(), expectedSize);

			for (size_t i = 0; i < currentSize; ++i)
			{
				stringStack.Push("42");
			}
			BOOST_CHECK_EQUAL(stringStack.GetSize(), currentSize);

			stringStack.Clear();
			BOOST_CHECK_EQUAL(stringStack.GetSize(), expectedSize);
		}

		BOOST_AUTO_TEST_CASE(can_compare_stacks)
		{
			CMyStack<int> newIntStack;

			newIntStack.Push(12);
			intStack.Push(12);
			BOOST_CHECK(intStack == newIntStack);

			intStack.Push(42);
			newIntStack.Push(666);

			BOOST_CHECK(intStack != newIntStack);

			CMyStack<std::string> newStringStack;

			newStringStack.Push("Шла Саша по шоссе");
			stringStack.Push("Шла Саша по шоссе");

			BOOST_CHECK(newStringStack == stringStack);

			stringStack.Push("А может быть и не шла, кто её знает, в конце концов, Александры - странный народ.");
			BOOST_CHECK(newStringStack != stringStack);
		}

		BOOST_AUTO_TEST_CASE(can_be_copied)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				intStack.Push((int)i);
			}

			CMyStack<int> newIntStack(intStack);

			BOOST_CHECK_EQUAL(newIntStack.GetSize(), intStack.GetSize());

			for (size_t i = newIntStack.GetSize(); i > 0; --i)
			{
				BOOST_CHECK_EQUAL(intStack.GetLastElement(), newIntStack.GetLastElement());
				intStack.Pop();
				newIntStack.Pop();
			}
		}

		BOOST_AUTO_TEST_CASE(can_not_be_copied_by_themself)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				intStack.Push((int)i);
				stringStack.Push(std::to_string(i));
			}

			CMyStack<int> prevIntStackState = intStack;
			BOOST_CHECK(prevIntStackState == intStack);

			BOOST_CHECK_EQUAL(intStack.GetSize(), (size_t)10);

			intStack = intStack;

			BOOST_CHECK_EQUAL(intStack.GetSize(), (size_t)10);
			BOOST_CHECK(intStack == prevIntStackState);



			CMyStack<std::string> prevStringStackState = stringStack;
			BOOST_CHECK(prevStringStackState == stringStack);

			BOOST_CHECK_EQUAL(stringStack.GetSize(), (size_t)10);

			stringStack = stringStack;

			BOOST_CHECK_EQUAL(stringStack.GetSize(), (size_t)10);
			BOOST_CHECK(stringStack == prevStringStackState);
		}

		BOOST_AUTO_TEST_CASE(can_be_moved)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				intStack.Push((int)i);
				stringStack.Push(std::to_string(i));
			}

			CMyStack<int> prevIntStackState = intStack;
			CMyStack<std::string> prevStringStackState = stringStack;

			CMyStack<int> newIntStack(std::move(intStack));
			BOOST_CHECK(intStack.IsEmpty());
			BOOST_CHECK(newIntStack == prevIntStackState);

			CMyStack<std::string> newStringStack(std::move(stringStack));
			BOOST_CHECK(stringStack.IsEmpty());
			BOOST_CHECK(newStringStack == prevStringStackState);
		}

		BOOST_AUTO_TEST_CASE(can_not_be_moved_by_themself)
		{
			for (size_t i = 0; i < 5; ++i)
			{
				intStack.Push((int)i);
				stringStack.Push(std::to_string(i));
			}

			CMyStack<int> prevIntStackState = intStack;
			CMyStack<std::string> prevStringStackState = stringStack;

			intStack = std::move(intStack);
			BOOST_CHECK(intStack == prevIntStackState);
			BOOST_CHECK_EQUAL(intStack.GetSize(), (size_t)5);

			stringStack = std::move(stringStack);
			BOOST_CHECK(stringStack == prevStringStackState);
			BOOST_CHECK_EQUAL(stringStack.GetSize(), (size_t)5);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()