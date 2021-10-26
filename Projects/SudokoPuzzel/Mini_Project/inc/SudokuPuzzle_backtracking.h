#ifndef SUDOKUPUZZLEBACKTRACKING__HPP
#define SUDOKUPUZZLEBACKTRACKING__HPP


#include "SudokuBoard.hpp"
#include "SudokuPuzzle.hpp"


class SudokuPuzzle_Backtracking : public SudokuPuzzle
{
public:
	SudokuPuzzle_Backtracking(SudokuBoard& board);

	// Solves the given Sudoku board using  backtracking algorithm
    virtual void solve() { solve_kernel(); }
	bool solve_kernel();
};


#endif   // SUDOKUPUZZLEBACKTRACKING__HPP