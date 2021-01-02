#!/bin/bash

#
# Build a file with different compiler and execute some code checks
#

echo "Call gcc"
g++ -c $1 \
	-Wall \
       	-Wextra \
       	-Wshadow \
       	-Wnon-virtual-dtor \
       	-pedantic \
       	-Wpedantic \
       	-Wold-style-cast \
	-Wcast-align \
	-Wunused \
	-Woverloaded-virtual \
	-Wconversion \
	-Wsign-conversion \
	-Wmisleading-indentation \
	-Wduplicated-cond \
	-Wduplicated-branches \
	-Wlogical-op \
	-Wnull-dereference \
	-Wuseless-cast \
	-Warray-bounds \
	-Wdouble-promotion \
	-Weffc++

echo "Call clang"
clang -c $1 \
	-Wall \
       	-Wextra \
       	-Wshadow \
       	-Wnon-virtual-dtor \
       	-pedantic \
       	-Wpedantic \
       	-Wold-style-cast \
	-Wcast-align \
	-Wunused \
	-Woverloaded-virtual \
	-Wconversion \
	-Wsign-conversion \
	-Wmisleading-indentation \
	-Wnull-dereference \
	-Wdouble-promotion \
	-Weffc++ \
        -Weverything # May be too much...

echo "Call cppcheck"
cppcheck --enable=all $1

echo "Call clang-tidy"
clang-tidy --checks="*" $1 --
