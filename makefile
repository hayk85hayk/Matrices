matrix_app: Matrix.o
	g++ -v -o $@ $^

Matrix.o: Matrix.cpp
	g++ -c $^

test_app: Test.o
	g++ -v -o $@ $^

Test.o: Test.cpp
	g++ -c $^
