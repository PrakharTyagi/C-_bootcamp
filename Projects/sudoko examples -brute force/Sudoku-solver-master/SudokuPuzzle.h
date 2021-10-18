#ifndef _SUDOKU_PUZZLE_H
#define _SUDOKU_PUZZLE_H

#include "SudokuBoard.hpp"
using Position = std::pair<int, int>;
class SudokuPuzzle {
  private:
	// Represents the boards state. 0 means "no value set yet", and 1-9 are valid values.
	short int board[9][9];
	
	// Set to true to turn on tracers
	bool debug;
	
	// Print tracer: print trying value
	void printTracerTryingValue(int x_cord, int y_cord);
	
	// Recursive method that solves board one block at time
	bool solve(int x_cord, int y_cord);
	
	// Verifies that set value at certain coordinate is valid
	bool verifyValue(int x_cord, int y_cord);
	
	// Finds the first empty cell on the given Sudoku board
	const std::pair<int, int> find_empty(const SudokuBoard& board);

	// int hypothesis(int x[]);

	// int eliminate(int x);

	protected:
	SudokuBoard _board;
	SudokuBoard _solution;
	int _recursionDepth = 0;
	bool _solved =false;
	

  public:
    // Constructor
	  SudokuPuzzle();
  
    // Print puzzle in current state
    void print();

	// //Input value from the file
	// void input();
	
	// Set a value on the board. Used for laying out board and solving
	void setBoardValue(int x_cord, int y_cord, int value);
  
        // Get a value on the board.
	int getBoardValue(int x_cord, int y_cord);
	
	// Solve the puzzle. Returns true if in solved state, returns false if unsolvable.
	bool solve();

	bool solve_kernel();
	
	void welcome();
	// Checks if a given number can be inserted at a given cell position
	bool isValid(const SudokuBoard& board, int num, Position pos) const;

	// Checks if num already exists in the given row
	bool isValidRow(const SudokuBoard& board, int num, Position pos) const;

	// Checks if num already exists in the given column
	bool isValidColumn(const SudokuBoard& board, int num, Position pos) const;

	// Checks if num already exists in the given box (subgrid)
	bool isValidBox(const SudokuBoard& board, int num, Position pos) const;


	bool checkIfAllFilled(const SudokuBoard& board) const;
	// Checks if the given cell position is empty


	bool isEmpty(const SudokuBoard& board, int i, int j) const;


	bool isUnique(const SudokuBoard& board, int num, Position pos) const;
	// Checks the uniqueness of a given valid number by seeing the occurrence of pairs of that number
	// within the neighboring rows and columns in the same box




	//bool eliminate(int x_cord, int y_cord, int value);
};


#endif
