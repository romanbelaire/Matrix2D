Roman Belaire
Contained in this folder is the source code as my submission for the interview challenge. Matrix2D.h contains the definitions and implementation for my matrix class, while main.cpp contains a few test cases.

Test cases:
Test 1 creates a 3x5 float matrix and performs all available matrix operations on it. 
Test 2 creates a 2x2 int matrix of zeros and performs all available matrix operations on it.
Test 3 creates a 2x2 string matrix and tests string-friendly operations (i.e. addition), to test template functionality.

These tests are not fully robust or comprehensive, they just show the functionality of the code. A more complete testing scenario would include performance tests such as exceedingly large matrix sizes or matrices with values that are near storage limits. These cases wouldn't be beyond the ordinary, as many datasets have tens of thousands of observations (rows). Datasets of this size may expose time and space inefficiencies that slow down or even break the operations, and would be important to test.

To run:
For convenience, a build of the file is included in the folder as 'main.exe'. I programmed and compiled this on Windows 10 in Visual Studio 17, though it could be linked and compiled through a command line as well. This source code is not dependent on anything outside of the c++ standard libraries.