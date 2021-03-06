#include "SudokuPuzzle.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
#include "helper.hpp"
#include "SudokuPuzzle_backtracking.h"
/*
 * Constructor. Initializes puzzle board to zeros, which signify that a value
 * has not been found yet.
 */
// SudokuPuzzle::SudokuPuzzle() {

// 	// Set to true to turn on tracers
// 	debug = false;

// 	// Initialize board
// 	for (int y=0; y<9; y++) {
// 		for (int x=0; x<9; x++) {
// 			board[x][y] = 0;
// 		}
// 	}
	
// } // Constructor

// /*
//  * Print out current state of board. E.g., here's an unsolved puzzle:
//  * -------------------------------
//  * | 1  .  . | .  .  7 | .  9  . |
//  * | .  3  . | .  2  . | .  .  8 |
//  * | .  .  9 | 6  .  . | 5  .  . |
//  * -------------------------------
//  * | .  .  5 | 3  .  . | 9  .  . |
//  * | .  1  . | .  8  . | .  .  2 |
//  * | 6  .  . | .  .  4 | .  .  . |
//  * -------------------------------
//  * | 3  .  . | .  .  . | .  1  . |
//  * | .  4  . | .  .  . | .  .  7 |
//  * | .  .  7 | .  .  . | 3  .  . |
//  * -------------------------------
//  *
//  * And here's the same puzzle, solved:
//  * -------------------------------
//  * | 1  6  2 | 8  5  7 | 4  9  3 |
//  * | 5  3  4 | 1  2  9 | 6  7  8 |
//  * | 7  8  9 | 6  4  3 | 5  2  1 |
//  * -------------------------------
//  * | 4  7  5 | 3  1  2 | 9  8  6 |
//  * | 9  1  3 | 5  8  6 | 7  4  2 |
//  * | 6  2  8 | 7  9  4 | 1  3  5 |
//  * -------------------------------
//  * | 3  5  6 | 4  7  8 | 2  1  9 |
//  * | 2  4  1 | 9  3  5 | 8  6  7 |
//  * | 8  9  7 | 2  6  1 | 3  5  4 |
//  * -------------------------------
//  */
// void SudokuPuzzle::print() {
// 	// For each row
// 	for (int y=0; y<9; y++) {
// 	    // Draw horizontal lines between blocks
// 	    if (y % 3== 0) {
// 			std::cout << "-------------------------------" << std::endl;
// 		}
		
// 		// For each cell in row
// 		for (int x=0; x<9; x++) {
// 			if (x % 3 == 0) {
// 				std::cout << "|";
// 			}
		
// 		    if (board[x][y] != 0) {
// 				std::cout << " " << board[x][y] << " ";
// 			} else {
// 				std::cout << " . ";
// 			}
			
// 		}
		
// 		// Draw columns between blocks
// 		std::cout << "|" << std::endl;
// 	}
// 	std::cout << "-------------------------------" << std::endl;
	
// } // SudokuPuzzle::print()

// /*
//  * Set a value on the board. This happens under two conditions:
//  * i) When caller function is laying out the initial board
//  * ii) Found a value we're testing as part of the solution
//  *
//  * Note that if you set a test value and it doesn't work,
//  * you should set value back to zero so that solution algorithm
//  * doesn't mistakenly treat wrong value as part of board.
//  *
//  * Parameters:
//  *   x_cord: The x-coordinate on the board. Should be between 0 
//  *           and 8, inclusive
//  *   y_cord: The y-coordinate on the board. Should be between 0 
//  *           and 8, inclusive.
//  *   value:  The value to try, or (when creating board) the initial
//  *           value of the board
//  */
// void SudokuPuzzle::setBoardValue(int x_cord, int y_cord, int value) {
//   board[x_cord][y_cord] = value;
// } // SudokuPuzzle::setBoardValue(int, int, int)

// /*
//  * Solve the Sudoku puzzle. Uses whatever state the current board
//  * is in to solve.
//  *
//  * Return:
//  *   True if solved, false if unsolvable. If solved, the puzzle's
//  *   current state is solved. You can print the puzzle to see
//  *   the solution.
//  */
// bool SudokuPuzzle::solve() {
//   return solve(0,0);
// } // SudokuPuzzle::solve()

// int SudokuPuzzle::getBoardValue(int x_cord, int y_cord) {
// 	return board[x_cord][y_cord];
// } // SudokuPuzzle::getBoardValue(int, int)

// /* 
//  * Internal method that recursively solves the puzzle.
//  *
//  * Parameters:
//  *   x_cord: The x-coordinate on the board. Should be between 0 
//  *           and 8, inclusive
//  *   y_cord: The y-coordinate on the board. Should be between 0 
//  *           and 8, inclusive.
//  *
//  * Return:
//  *   True if solved, false if unsolvable. If solved, the puzzle's
//  *   current state is solved. You can print the puzzle to see
//  *   the solution.
//  */
// bool SudokuPuzzle::solve(int x_cord, int y_cord) {

//   // Only solve piece if not already solved (given)
//   if (board[x_cord][y_cord] != 0) {
  
//     // If value works, on to next
//     if (verifyValue(x_cord,y_cord)) {
	
// 		// If last piece, puzzle solved!
// 		if (x_cord == 8 && y_cord == 8) {
// 			return true;
// 		}
	
// 	    // Find next slot on this row
// 		int next_x = x_cord+1;
// 		int next_y = y_cord;
		
// 		// If at end of row, start next
// 		if (next_x >= 9) {
// 			next_x = 0;
// 			next_y++;
// 		}
		
// 		// Move on to next piece
// 		return solve(next_x, next_y);
// 	} 
	
// 	// Value doesn't work. Early guess is bad
// 	else {
// 		return false;
// 	}
	
//   } // If value already defined
  
//   // There isn't a value already for position.
//   // Guess all the values until one works
// // check possiblity value hypthesis like 4567  then check if then verify on those set if yes or check for next hypothesis. 
// 	int vset[] ={1,2,3,4,5,6,7,8,9};
//   for (int i=0; i<9; i++) {
	
// 	setBoardValue(x_cord, y_cord, vset[i]);

// 	//printTracerTryingValue(x_cord, y_cord);

	
// 	// If value works, on to next
//     if (verifyValue(x_cord,y_cord)) {
	
// 		// If last piece, puzzle solved!
// 		if (x_cord == 8 && y_cord == 8) {
// 			return true;
// 		}
	
// 		// Find next slot on this row
// 		int next_x = x_cord+1;
// 		int next_y = y_cord;
		
// 		// If at end of row, start next
// 		if (next_x >= 9) {
// 			next_x = 0;
// 			next_y++;
// 		}
		
// 		// Move on to next piece
// 		//return solve(next_x, next_y);
// 		if (solve(next_x, next_y)) {
// 		  return true;
// 		}
// 	}
//   }//
  
//   // Remove value. Going to backtrack. If value remained,
//   // then would think its part of solution.
//   board[x_cord][y_cord] = 0;
  
//   // If gets here, must backtrack. No solution
//   // for path.
//   return false;
  
// } // SudokuPuzzle::solve(int, int)

// /*
//  * Verifies that a value set at a particular location follows
//  * all the Sudoku rules.
//  *
//  * Parameters:
//  *   x_cord: The x-coordinate on the board. Should be between 0 
//  *           and 8, inclusive
//  *   y_cord: The y-coordinate on the board. Should be between 0 
//  *           and 8, inclusive.
//  *
//  * Return:
//  *   True if valid (follows all the rules), false otherwise.
//  */
// bool SudokuPuzzle::verifyValue(int x_cord, int y_cord) {

//   printTracerTryingValue(x_cord, y_cord);
//   int value = board[x_cord][y_cord];

//   // Make sure no vertical collision
//   for (int x_verify=0; x_verify<9; x_verify++) {
//     // Skip self.
//     if (x_verify == x_cord) {
// 	  continue;
// 	}
	
// 	// If same value, failed
// 	int verifyValue = board[x_verify][y_cord];
// 	if (verifyValue == value) {
// 	  return false;
// 	}
//   }
  
//   // Make sure no horizontal collision
//   for (int y_verify=0; y_verify<9; y_verify++) {
//     // Skip self.
//     if (y_verify == y_cord) {
// 	  continue;
// 	}
	
// 	// If same value, failed
// 	int verifyValue = board[x_cord][y_verify];
// 	if (verifyValue == value) {
// 	  return false;
// 	}
//   }
  
//   // Make sure no collision in box
//   int box_x = x_cord / 3; // If this box 0, 1, 2 on x-cord
//   int box_y = y_cord / 3; // Is this box 0, 1, 2 on y-cord
  
//   // For each y in the same box
//   for (int y_verify=box_y * 3; y_verify < box_y * 3 + 3; y_verify++) {
// 	// For each x in the same box
// 	for (int x_verify=box_x * 3; x_verify < box_x * 3 + 3; x_verify++) {
// 		// Skip self.
// 		if (x_verify == x_cord && y_verify == y_cord) {
// 			continue;
// 		}
		
// 		// If same value, failed
// 		int verifyValue = board[x_verify][y_verify];
// 		if (verifyValue == value) {
// 			return false;
// 		}
// 	}
//   }
  
//   // Passed all of the tests, so valid
//   return true;
  
// } // SudokuPuzzle::verifyValue(int, int)

// /* 
//  * Prints tracers for every attempt while recursively solving the
//  * puzzle on if debug is set to true in the constructor.
//  * 
//  * Parameters:
//  *   x_cord: The x-coordinate on the board. Should be between 0 
//  *           and 8, inclusive
//  *   y_cord: The y-coordinate on the board. Should be between 0 
//  *           and 8, inclusive.
//  */
// void SudokuPuzzle::printTracerTryingValue(int x_cord, int y_cord) {
//   if (true) {//change debug to true
//     // Indent for easier reading
// 	for (int i=0; i<x_cord+y_cord; i++) {
// 	  std::cout << " ";
// 	}
	
// 	std::cout << "Trying value " << board[x_cord][y_cord] << " at board[" << x_cord << "][" << y_cord << "]" << std::endl;
//   }
  
// } 

// void SudokuPuzzle::welcome(){
// 	printf("----------------------------------------------------\n");
// 	printf("|===================== SUDOKU =====================|\n");
// 	printf("|                                                  |\n");
// 	printf("|             Welcome to Sudoku Solver             |\n");
// 	printf("|                                                  |\n");
// 	printf("----------------------------------------------------\n\n\n");

// 	printf("----------------------------------------------------\n");
// 	printf("|================== About Sudoku ==================|\n");
// 	printf("----------------------------------------------------\n");
// 	printf("|                                                  |\n");
// 	printf("| 1. Board of Sudoku is of size nxn, where n should|\n");
// 	printf("|    be a perfect square.                          |\n");
// 	printf("| 2. In each row of length n all numbers from 1 to |\n");
// 	printf("|    n should be present once.                     |\n");
// 	printf("| 3. In each column of length n all numbers from   |\n");
// 	printf("|    1 to n should be present once.                |\n");
// 	printf("| 4. In each sub-square of size n(or of side length|\n");
// 	printf("|    sqrt(n)) all numbers from 1 to n should be    |\n");
// 	printf("|    present once.                                 |\n");
// 	printf("----------------------------------------------------\n\n");

// }

SudokuPuzzle::SudokuPuzzle(SudokuBoard& board)
	: _board(board)
{ }

bool SudokuPuzzle::checkIfAllFilled(const SudokuBoard& board) const
{
    for (int i = 0; i < board.get_board_size(); ++i)
	{
        for (int j = 0; j < board.get_board_size(); ++j)
		{
            if (isEmpty(board, i, j))
			{
                return false;
			}
        }
    }
    return true;
}
bool SudokuPuzzle::checkIfRowFilled(const SudokuBoard& board, int indexOfRows) const
{
	for (int j = 0; j < board.get_board_size(); ++j)
	{
		if (isEmpty(board, indexOfRows, j)) { return false; }
	}

    return true;
}
const std::pair<int, int> SudokuPuzzle::find_empty(const SudokuBoard& board)
{
	Position empty_cell;
	bool stop = false;

	for (int i = 0; i < board.get_board_size(); ++i)
	{
		for (int j = 0; j < board.get_board_size(); ++j)
		{
			if (isEmpty(board, i, j))
			{
				empty_cell = std::make_pair(i, j);
				stop = true;
				break;
			}
		}
		if (stop) { break; }
	}
	
	return empty_cell;  // (row, col)
}

bool SudokuPuzzle::isEmpty(const SudokuBoard& board, int i, int j) const
{
	 if(board.at(i, j) == board._EMPTY_CELL_VALUE){
		 return true;
	}else{return false;
	}
}


int SudokuPuzzle::find_empty_from_row(const SudokuBoard& board, int indexOfRows) const
{
	int empty_cell_col_index = -1;

	for (int j = 0; j < board.get_board_size(); ++j)
	{
		if (isEmpty(board, indexOfRows, j))
		{
			empty_cell_col_index = j;
			return empty_cell_col_index;
		}
	}

	return empty_cell_col_index;
}

bool SudokuPuzzle::isValid(const SudokuBoard& board, int num, Position pos) const
{
    return isValidRow(board, num, pos) && isValidColumn(board, num, pos) && isValidBox(board, num, pos);
}

bool SudokuPuzzle::isValidRow(const SudokuBoard& board, int num, Position pos) const
{
    for (int i = 0; i < board.get_board_size(); ++i)
	{
        if ( (i != pos.second) && (board.at(pos.first, i) == num) ) { return false; }
	}

	return true;
}

bool SudokuPuzzle::isValidColumn(const SudokuBoard& board, int num, Position pos) const
{
	for (int i = 0; i < board.get_board_size(); ++i)
	{
        if ( (i != pos.first) && (board.at(i, pos.second) == num) ) { return false; }
	}
	
	return true;
}

bool SudokuPuzzle::isValidBox(const SudokuBoard& board, int num, Position pos) const
{
	int BOX_SIZE = board.get_box_size();

	int box_x = std::floor(pos.first / board.get_box_size());
    int box_y = std::floor(pos.second / board.get_box_size());

    for (int i = box_x * BOX_SIZE; i < box_x * BOX_SIZE + BOX_SIZE; ++i)
	{
        for (int j = box_y * BOX_SIZE; j < box_y * BOX_SIZE + BOX_SIZE; ++j)
		{
            if ( (i != pos.first && j != pos.second) && (board.at(i, j) == num) ) { return false; }
        }
    }

	return true;
}

bool SudokuPuzzle::isUnique(const SudokuBoard& board, int num, Position pos) const
{
	int local_row = pos.first % board.get_box_size();
	int local_col = pos.second % board.get_box_size();

	int box_x = std::floor(pos.first / board.get_box_size());
    int box_y = std::floor(pos.second / board.get_box_size());

	for (int i = ( (local_row == 0) ? 1 : 0 ); i < board.get_box_size(); ++i)
	{
		if (i == local_row) { continue; }
		std::vector<int> numbersInRow = board.getNumbersInRow(box_x * board.get_box_size() + i);
		if (std::find(numbersInRow.begin(), numbersInRow.end(), num) == numbersInRow.end())
		{
			return false;
		}
	}

	for (int j = ( (local_col == 0) ? 1 : 0 ); j < board.get_box_size(); ++j)
	{
		if (j == local_col) { continue; }
		std::vector<int> numbersInCol = board.getNumbersInCol(box_y * board.get_box_size() + j);
		if (std::find(numbersInCol.begin(), numbersInCol.end(), num) == numbersInCol.end())
		{
			return false;
		}
	}

	return true;
}



// bool SudokuPuzzle::eliminate(int x_cord, int y_cord,int val) {
// 	if()
// }

// SudokuPuzzle::printTracerTryingValue

// void SudokuPuzzle::input(){
// 		std::vector<std::vector<int>> get2DVector(int n, std::string filename)
// {
//     std::vector<std::vector<int>> result(n);

//     std::ifstream input(filename);

//     std::string s;
//     for (int i = 0; i < n; i++)
//     {
//         std::getline(input, s);
//         std::istringstream iss(s);

//         std::string num;
//         while (std::getline(iss, num, ','))
//             result[i].push_back(std::stoi(num));
//     }

//     return result;
// }
// 	auto vec = get2DVector(9, "Easy.txt");// Assuming it is a 9*9 input sudoku
// 	for (auto& v : vec)
//     {
//         for (int i : v)
//             std::cout << i << ' ';
//         std::cout << '\n';
// 		//puzzle.setBoardValue(0,0,1);

//     }

// 	for (int i = 0; i < vec.size(); i++)
// {
//     for (int j = 0; j < vec[i].size(); j++)
//     {
//         puzzle.setBoardValue(i,j,vec[i][j]);
//     }
// }}

