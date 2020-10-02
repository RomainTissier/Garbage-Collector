#!/bin/bash
clang-format -i main.cpp
cppcheck --enable=all main.cpp
clang-tidy --checks="*,-fuchsia-trailing-return,-bugprone-infinite-loop" main.cpp --
clang -lstdc++ -lpthread main.cpp \
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
	-Weffc++
