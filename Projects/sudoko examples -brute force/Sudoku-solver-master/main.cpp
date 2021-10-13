#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "SudokuPuzzle.h"

/*
 * Create and solve a Sudoku puzzle. Will print
 * the board, then try to solve. If solves, will
 * print the solution. If unsolvable, will display
 * message.
 */
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
	


    
	SudokuPuzzle puzzle;
	puzzle.welcome();
	std::vector<std::vector<int>> get2DVector(int , std::string );
	auto vec = get2DVector(9,"Hard.txt");// Easy input file

	for (size_t i = 0; i < vec.size(); i++)
{
    for (size_t j = 0; j < vec.size(); j++)
    {
        puzzle.setBoardValue(j,i,vec[i][j]);
    }
}
	// Print the board before solving.
	puzzle.print();
	
	std::cout << std::endl;
	
	// Now solve. If not solvable, say.
	if (puzzle.solve()) {
	
	  std::cout << "Here is the solution:" << std::endl;
	  puzzle.print();
	  
	} else {
	  std::cout << "Puzzle is not solvable.";
	}
	
	std::cout << std::endl;
	
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



