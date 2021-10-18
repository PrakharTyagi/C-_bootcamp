#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include "SudokuPuzzle.h"
#include "SudokuBoard.hpp"



int main (int argc, char * const argv[]) {
    
	
	
	/*
	 * Create board below. For each initial
	 * value on the board, specify using:
	 * 
	 * puzzle.setBoardValue(int x-cord, y-cord, val);
	 *
	 * Where:
	 *   x-cord: X coordinate on the Sudoku field.
     *   y-cord: Y coordinate on the Sudoku field.
	 *   val:    The value to place on the board.
	 *
	 * Use the following to determine x- and y- 
	 * coordinates:
	 *
	 *       X
	 *        0  1  2   3  4  5   6  7  8
	 *      -------------------------------
	//  * Y 0  | .  .  . | .  .  . | .  .  . |
	 *   1  | .  .  . | .  .  . | .  .  . |
	 *   2  | .  .  . | .  .  . | .  .  . |
	 *      -------------------------------
	 *   3  | .  .  . | .  .  . | .  .  . |
	 *   4  | .  .  . | .  .  . | .  .  . |
	 *   5  | .  .  . | .  .  . | .  .  . |
	 *      -------------------------------
	 *   6  | .  .  . | .  .  . | .  .  . |
	 *   7  | .  .  . | .  .  . | .  .  . |
	 *   8  | .  .  . | .  .  . | .  .  . |
	 *      -------------------------------
	 *
	 */


std::chrono::high_resolution_clock::time_point start, stop;
start = std::chrono::high_resolution_clock::now();

	SudokuPuzzle puzzle;
	//auto puzzle = SudokuBoard();
	
	puzzle.welcome();
	std::vector<std::vector<int>> get2DVector(int , std::string );
	auto vec = get2DVector(9,"Hard.txt");// Easy input file

	for (size_t i = 0; i < vec.size(); i++)
{
    for (size_t j = 0; j < vec.size(); j++)
    {
        puzzle.setBoardValue(j,i,vec[i][j]);
		//puzzle.print();// just to check filling up the board in each iteration
    }
}
	// Print the board before solving.
	puzzle.print();
	//
	
	
	std::cout << std::endl;

stop = std::chrono::high_resolution_clock::now();
int time_in_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

	// Now solve. If not solvable, say.
	if (puzzle.solve()) {


	
	  std::cout << "Here is the solution:" << std::endl;
	  puzzle.print();
	  
	} else {
	  std::cout << "Puzzle is not solvable.";
	}

	
	std::cout << std::endl;
    std::cout << std::dec << "[Solved in " << (double)time_in_microseconds / 1e6 << " seconds.]" << "\n";
	

	// Exit normally
    return 0;
	
} // main

	std::vector<std::vector<int>> get2DVector(int n, std::string filename)
{
    std::vector<std::vector<int>> result(n);

    std::ifstream input(filename);

    std::string s;
    for (int i = 0; i < n; i++)
    {
        std::getline(input, s);
        std::istringstream iss(s);
        std::string num;
        while (std::getline(iss, num, ','))
            result[i].push_back(std::stoi(num));
    }

    return result;
}



