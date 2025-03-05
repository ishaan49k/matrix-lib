CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2
LDFLAGS = -lgtest

# Compile the test program
all: build/matrix_tests

build/matrix_tests: tests/test_matrix.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf build/matrix_tests
