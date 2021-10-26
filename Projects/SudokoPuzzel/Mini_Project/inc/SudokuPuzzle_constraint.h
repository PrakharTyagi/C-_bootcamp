#ifndef SUDOKUPUZZLECONSTRAINT__HPP
#define SUDOKUPUZZLECONSTRAINT__HPP


#include "SudokuBoard.hpp"
#include "SudokuPuzzle.hpp"


class SudokuPuzzle_constraint : public SudokuPuzzle
{
private:
	StateMatrix _stateMatrix;
public:
	SudokuPuzzle_constraint(SudokuBoard& board); 
    virtual void solve() override { solve_kernel(_stateMatrix); }
    bool solve_kernel(StateMatrix& stateMatrix);
};


#endif   // 