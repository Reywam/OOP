#include "stdafx.h"
#include "../htmlencode/HTMLEncode.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(html_decode_function)
	BOOST_AUTO_TEST_CASE(can_encode_html_entities)
	{
		BOOST_CHECK_EQUAL(HtmlEncode("&"), "&amp;");
		BOOST_CHECK_EQUAL(HtmlEncode("<"), "&lt;");
		BOOST_CHECK_EQUAL(HtmlEncode(">"), "&gt;");
		BOOST_CHECK_EQUAL(HtmlEncode("\""), "&quot;");
		BOOST_CHECK_EQUAL(HtmlEncode("'"), "&apos;");
	}

	BOOST_AUTO_TEST_CASE(can_encode_html_entities_in_text)
	{
		string testString = "Cat <says> \"Meow\". M&M's";
		string expectedString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	
		string encodedString = HtmlEncode(testString);
		BOOST_CHECK_EQUAL(encodedString, expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()
