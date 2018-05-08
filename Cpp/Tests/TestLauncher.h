/**
 * @file TestLauncher.h
 * @brief Test Launcher class, it handles and execute tests (header file)
 * @author Romain TISSIER
 * @date 04/11/2017
 */
#ifndef TESTS_TESTLAUNCHER_H_
#define TESTS_TESTLAUNCHER_H_

#include <vector>
#include "Test.h"

/**
 * @brief Test Launcher class, it handles and execute tests for YATA
 */
class TestLauncher {
private:
	std::vector<Test*> tests;/*!< Handle tests classes to execute*/
public:

	/**
	 * @brief Constructor which register tests classes
	 */
	TestLauncher();

	/**
	 * @brief Execute each registered tests
	 * @return The number of failed test
	 */
	int run();

	/**
	 * @brief Destructor, freeing test class memory
	 */
	virtual ~TestLauncher();
};

#endif
