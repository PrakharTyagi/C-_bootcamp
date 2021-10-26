# the compiler: gcc for C program, g++ for C++ program
CXX = g++

GIT_VERSION := "$(shell git describe --abbrev=0 --tags)"

# compiler flags:
#  -g      adds debugging information to the executable file
#  -Wall   turns on most, but not all, compiler warnings
#  -Wextra enables some extra warning flags that are not enabled by -Wall
CXX_FLAGS = --std=c++17 -g -Wall -Wextra -O3 -DVERSION=\"$(GIT_VERSION)\"
OPENMP = -fopenmp

# All output target executables
TARGETS = sudoku_main

# All object files
OBJECTS = *.o *.out

DEPENDENCIES = \
	./src/SudokuBoard.cpp \
	./src/SudokuTest.cpp \
	./src/SudokuPuzzle.cpp \
	./src/SudokuPuzzle_backtracking.cpp \

all: $(TARGETS)

sudoku_main: sudoku_main.cpp $(DEPENDENCIES)
	$(CXX) $(CXX_FLAGS) $(OPENMP) -I ./inc -o $@ $^

clean:
	rm -f $(TARGETS) $(OBJECTS) solution.txt