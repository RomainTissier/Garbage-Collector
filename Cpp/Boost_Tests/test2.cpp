#include <boost/test/unit_test.hpp>

// Simple cube function
int cube(int n)
{
	return n * n * n;
}

BOOST_AUTO_TEST_SUITE(Cube_tests)

BOOST_AUTO_TEST_CASE(Cube_test)
{
	// Non-blocking checks
	BOOST_CHECK(cube(2) == 8);
	if (cube(2) != 8) {
		BOOST_ERROR("Error cube(2) should be equals to 8");
	}
	BOOST_CHECK_MESSAGE(cube(2) == 8, "cube(2)=" << cube(2));

	// Blocking checks
	BOOST_REQUIRE(cube(2) == 8);
	if (cube(2) != 8) {
		BOOST_FAIL("Error cube(2) should be equals to 8");
	}
	BOOST_REQUIRE_MESSAGE(cube(2) == 8, "cube(2)=" << cube(2));
}

BOOST_AUTO_TEST_SUITE_END()

