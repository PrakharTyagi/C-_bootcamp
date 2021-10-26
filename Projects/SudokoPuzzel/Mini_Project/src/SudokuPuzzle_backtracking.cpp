#include "SudokuPuzzle_backtracking.h"
#include <iostream>

SudokuPuzzle_Backtracking::SudokuPuzzle_Backtracking(SudokuBoard& board)
	: SudokuPuzzle(board)
{

}
bool SudokuPuzzle_Backtracking::solve_kernel()
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
	Position empty_cell_pos = find_empty(_board);
	int row = empty_cell_pos.first;
	int col = empty_cell_pos.second;
	for (int num = _board.get_min_value(); num <= _board.get_max_value(); ++num)
	{	
		if (isValid(_board, num, empty_cell_pos))
		{
			_board.set_board_data(row, col, num);
			if (isUnique(_board, num, empty_cell_pos)) 
			{ num = _board.get_board_size() + 1; 
			}
			// try the next cell in recusression
			if (solve_kernel()) 
			{ _solved = true; return _solved;
			 }
			else { 
				_board.set_board_data(row, col, _board.get_empty_cell_value());
				 }  
				 	}
	}
	_recursionDepth++;
		// None of the values solved the Sudoku
	_solved = false;
	return _solved;
}// Last in first out