# Matrices
Problem: Create app to obtain Y wich is equal to:
              Y = (A+B)*(C+D), where A, B, C, D and Y are Matrices with same size stored in corresponding .txt files.

matrix_abcd_numpy.py is Python application for generating .txt files A, B, C, D in wich matrices are stored and then solving current problem with use of NumPy package to obtain file Y_numpy.txt with results for checking.

matrix_app is C++ application from the Matrix.cpp file with Matrix class and functions to solve current problem and store results in Y.txt file.
test_app is C++ application from the Test.cpp file wich compares results from matrix_app (Y.txt) and matrix_abcd_numpy.py (Y_numpy.txt).

makefile for making apps matrix_app and test_app.

