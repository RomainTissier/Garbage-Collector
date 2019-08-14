#include <boost/test/unit_test.hpp>

// Simple square function
int square(int n)
{
	return n * n;
}

BOOST_AUTO_TEST_SUITE(Square_tests)

BOOST_AUTO_TEST_CASE(Square_test)
{
	// Non-blocking checks
	BOOST_CHECK(square(2) == 4);
	if (square(2) != 4) {
		BOOST_ERROR("Error square(2) should be equals to 4");
	}
	BOOST_CHECK_MESSAGE(square(2) == 4, "square(2)=" << square(2));

	// Blocking checks
	BOOST_REQUIRE(square(2) == 4);
	if (square(2) != 4) {
		BOOST_FAIL("Error square(2) should be equals to 4");
	}
	BOOST_REQUIRE_MESSAGE(square(2) == 4, "square(2)=" << square(2));
}

BOOST_AUTO_TEST_SUITE_END()

