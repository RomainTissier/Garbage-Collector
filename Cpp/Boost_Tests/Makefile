all: tests

tests: main.o test1.o test2.o
	g++ -o $@ $^ -lboost_unit_test_framework

%.o: %.cpp
	g++ -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf tests

