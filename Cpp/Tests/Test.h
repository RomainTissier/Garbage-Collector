/**
 * @file Test.h
 * @brief Test abstract class
 * @author Romain TISSIER
 * @date 04/11/2017
 */
#ifndef TESTS_TEST_H_
#define TESTS_TEST_H_

#include <iostream>

/**
 * @brief Test abstract class
 */
class Test {
public:

	/**
	 * Constructor, unused here
	 */
	Test();

	/**
	 * Destructor, unused here
	 */
	virtual ~Test();

	/**
	 * @brief Execute the test (has to be implemented)
	 * @return The number of failed tests
	 */
	virtual int execute()=0;

	/**
	 * @brief Set the name of the test (has to be implemented)
	 * @return the test name
	 */
	virtual const std::string getName()=0;
};

#endif
