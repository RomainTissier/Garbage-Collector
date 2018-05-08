/**
 * @file TestLauncher.cpp
 * @brief Test Launcher class, it handles and execute tests
 * @author Romain TISSIER
 * @date 04/11/2017
 */
#include "TestLauncher.h"

#include <iostream>
#include "BooleanListTests.h"
#include "BinaryTupleTests.h"
#include "CppExecuteCommandTests.h"
#include "FileProjectTests.h"

/**
 * @brief Constructor which register tests classes
 */
TestLauncher::TestLauncher() {
	tests.push_back(new MyTests());
}

/**
 * @brief Execute each registered tests
 * @return The number of failed test
 */
int TestLauncher::run(){
	int err = 0;
	std::cout << "Starting tests" << std::endl;

	// Loop over registered tests and execute them
	for (unsigned int i = 0; i < tests.size(); i++) {
		std::cout << std::endl << "Start : " << tests.at(i)->getName()
				<< std::endl;
		int res = tests.at(i)->execute();
		std::cout << std::endl << "  -> " << tests.at(i)->getName();
		if (res == 0)
			std::cout << " [OK]";
		else
			std::cout << " [FAILED]";
		std::cout << std::endl;
		err += res;
	}

	// Return the number of failed tests
	return err;
}

/**
 * @brief Destructor, freeing test class memory
 */
TestLauncher::~TestLauncher() {

	// Loop over register test classes and free them
	for (unsigned int i = 0; i < tests.size(); i++)
		delete(tests.at(i));
}

