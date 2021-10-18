#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP


#include <vector>
#include <string>
#include <iostream>
#include <variant>
#include <set>
#include <variant>
#include <set>

using Board = std::vector<std::vector<int>>;
// Size: _BOARD_SIZE * _BOARD_SIZE

using CoverMatrix = std::vector<std::vector<int>>;
// Size: (_BOARD_SIZE * _BOARD_SIZE * _MAX_VALUE) * (_BOARD_SIZE * _BOARD_SIZE * _NUM_CONSTRAINTS)


// Size: _BOARD_SIZE * _BOARD_SIZE

class SudokuBoard
{
	friend class SudokuPuzzle;


private:
	

public:
    SudokuBoard() = default;
	SudokuBoard(const std::string& filename);
	// copy constructor
	SudokuBoard(const SudokuBoard& anotherSudokuBoard);

void set_board_data(int row, int col, int num) { _board_data[row][col] = num; }
	int get_board_data(int row, int col) const { return _board_data[row][col]; }
	Board get_board_data() const { return _board_data; }
	int at(int row, int col) const { return _board_data[row][col]; }

	int get_box_size() const { return _BOX_SIZE; }
	int get_board_size() const { return _BOARD_SIZE; }
	int get_min_value() const { return _MIN_VALUE; }
	int get_max_value() const { return _MAX_VALUE; }
	int get_init_num_empty_cells() const { return _INIT_NUM_EMPTY_CELLS; }
	int get_empty_cell_value() const { return _EMPTY_CELL_VALUE; }
	std::string get_empty_cell_character() const { return _EMPTY_CELL_CHARACTER; }

	int get_num_total_cells() const;
	int get_num_empty_cells() const;

	std::vector<int> getNumbersInRow(int indexOfRows) const;
	std::vector<int> getNumbersInCol(int indexOfColumns) const;





    Board _board_data;
	int _BOX_SIZE;
	int _BOARD_SIZE=9;
	int _MIN_VALUE = 1;
	int _MAX_VALUE = _BOARD_SIZE;
	int _NUM_CONSTRAINTS = 4;   // 4 constraints : cell, row, column, box
	int _INIT_NUM_EMPTY_CELLS;
	int _EMPTY_CELL_VALUE = 0;
	std::string _EMPTY_CELL_CHARACTER = ".";
	int _COVER_MATRIX_START_INDEX = 1;
};


#endif   // SUDOKUBOARD_HPP