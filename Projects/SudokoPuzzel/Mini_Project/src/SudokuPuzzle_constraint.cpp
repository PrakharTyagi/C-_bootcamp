#include "SudokuPuzzle_constraint.h"
#include <iostream>
#include "helper.hpp"
#include <algorithm>
#include <variant>
#include <vector>

SudokuPuzzle_constraint::SudokuPuzzle_constraint(SudokuBoard& board)
	: SudokuPuzzle(board)
{
	board.createStateMatröäix(_stateMatrix);
	board.convertToStateMatrix(_stateMatrix);
}

bool SudokuPuzzle_constraint::solve_kernel(StateMatrix& stateMatrix)
{
	if(_solved)
	{
		return _solved;
	}

    	if (checkIfAllFilled(_board))   // base case
    {
        _solved = true;
		_solution = _board;
		return _solved;
    }
}
