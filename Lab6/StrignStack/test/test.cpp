#include "stdafx.h"
#include "../StrignStack/CStringStack.h"

BOOST_AUTO_TEST_SUITE(class_StringStack)
	BOOST_AUTO_TEST_CASE(is_empty_by_default)
	{
		CStringStack stack;
		BOOST_CHECK(stack.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(can_push_elements)
	{
		CStringStack stack;
		stack.Push("12");
		std::string result = stack.GetElement();

		BOOST_CHECK_EQUAL(result, "12");
	}

	BOOST_AUTO_TEST_CASE(can_pop_elements)
	{
		CStringStack stack;
		stack.Push("42");

		BOOST_CHECK(!stack.IsEmpty());

		stack.Pop();

		BOOST_CHECK(stack.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(can_not_pop_elements_when_stack_is_empty)
	{
		CStringStack stack;

		BOOST_CHECK_THROW(stack.Pop(), std::domain_error);
	}

	BOOST_AUTO_TEST_CASE(can_get_last_element)
	{
		CStringStack stack;

		stack.Push("Hello World!");
		std::string expectedString = "Hello World!";

		BOOST_CHECK_EQUAL(stack.GetElement(), expectedString);
	}

	BOOST_AUTO_TEST_CASE(can_not_get_last_element_when_stack_is_empty)
	{
		CStringStack stack;
		BOOST_CHECK_THROW(stack.GetElement(), std::domain_error);
	}

BOOST_AUTO_TEST_SUITE_END()