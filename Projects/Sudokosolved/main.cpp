#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
   Sudoku::init();
   string line;
   while (getline(cin, line)) {
      if (auto S = solve(unique_ptr<Sudoku>(new Sudoku(line)))) {
         S->write(cout);
      } else {
         cout << "No solution";
      }
      cout << endl;
   }
}