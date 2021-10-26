#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <memory>
#include "SudokuBoard.hpp"
#include "SudokuTest.hpp"
#include "SudokuPuzzle.hpp"
#include "SudokuPuzzle_backtracking.h"

std::unique_ptr<SudokuPuzzle> CreateSudokuSolver(MODES mode, SudokuBoard& board)
{	switch (mode)
	{case MODES::SEQUENTIAL_BACKTRACKING:
		return std::make_unique<SudokuPuzzle_Backtracking>(board);

	
	default:
		std::cerr << termcolor::red << "Available options for <MODE>: " << "\n";
		std::cerr << "		- 0: sequential mode with backtracking algorithm" << "\n";
		std::cerr << "Please try again." << termcolor::reset << "\n";
		//exit(-1);
	}
}

int main (int argc, char** const argv) {

int WRITE_TO_SOLUTION_TXT = 0;

std::chrono::high_resolution_clock::time_point start, stop;
start = std::chrono::high_resolution_clock::now();
auto board = SudokuBoard(std::string(argv[1]));
SudokuTest::testBoard(board);
MODES mode = static_cast<MODES>(std::stoi(argv[2]));

std::cout << board;

auto solver = CreateSudokuSolver(mode, board);
// int NUM_THREADS = 2;
// int WRITE_TO_SOLUTION_TXT = 0;

solver->solve();


//SudokuPuzzle puzzle;
//auto puzzle = SudokuBoard();
	
//puzzle.welcome();
// 	std::vector<std::vector<int>> get2DVector(int , std::string );
// 	auto vec = get2DVector(9,"Hard.txt");// Easy input file

// 	for (size_t i = 0; i < vec.size(); i++)
// {
//     for (size_t j = 0; j < vec.size(); j++)
//     {
//         puzzle.setBoardValue(j,i,vec[i][j]);
// 		//puzzle.print();// just to check filling up the board in each iteration
//     }
// }
	// Print the board before solving.
	// puzzle.print();
	// //
	
	
	// std::cout << std::endl;

	// Now solve. If not solvable, say.
	// if (puzzle.solve()) {


	
	//   std::cout << "Here is the solution:" << std::endl;
	//   puzzle.print();
	  
	// } else {
	//   std::cout << "Puzzle is not solvable.";
	// }


stop = std::chrono::high_resolution_clock::now();
int time_in_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


// Assume all input Sudoku boards are solvable
	std::cout << "\n" << termcolor::green << "SOLVED!" << termcolor::reset << "\n";
	SudokuTest::testBoard(solver->get_solution());
	std::cout << termcolor::magenta << "************************************* OUTPUT GRID ************************************" << termcolor::reset << "\n\n";
	print_board(solver->get_solution());
	if (WRITE_TO_SOLUTION_TXT) {
		write_output(solver->get_solution());
	}
	std::cout << "\n" << termcolor::magenta << "**************************************************************************************" << termcolor::reset << "\n";



	
	std::cout << std::endl;
    std::cout << std::dec << "[Solved in " << (double)time_in_microseconds / 1e6 << " seconds.]" << "\n";
	

	// Exit normally
    return 0;
	
} // main

// 	std::vector<std::vector<int>> get2DVector(int n, std::string filename)
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



