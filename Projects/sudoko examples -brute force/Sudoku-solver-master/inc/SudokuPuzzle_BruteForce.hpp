#ifndef SUDOKUPUZZLEBRUTEFORCE__HPP
#define SUDOKUPUZZLEBRUTEFORCE__HPP


#include "SudokuBoard.hpp"
#include "SudokuPuzzle.hpp"


class SudokuPuzzle_Bruteforce : public SudokuPuzzle
{
public:
	SudokuPuzzle_Bruteforce(SudokuBoard& board);
	// Solves the given Sudoku board using sequential brute force algorithm
    virtual void solve() override {	solve_kernel(0, 0); }
	void solve_kernel(int row, int col);
};


#endif   // 