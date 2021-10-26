#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;


class Sudoku {
  // vector<Possible> _cells;
   static vector< vector<int> > _group, _neighbors, _groups_of;

   bool     eliminate(int k, int val);
public:
   Sudoku(string s);
   static void init();

   //Possible possible(int k) const { return _cells[k]; }
   bool     is_solved() const;
   bool     assign(int k, int val);
   int      least_count() const;
   void     write(ostream& o) const;
};


vector< vector<int> > 
Sudoku::_group(27), Sudoku::_neighbors(81), Sudoku::_groups_of(81);

void Sudoku::init() {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         const int k = i*9 + j;
         const int x[3] = {i, 9 + j, 18 + (i/3)*3 + j/3};
         for (int g = 0; g < 3; g++) {
            _group[x[g]].push_back(k);
				std::cout << " " << x[g] << " ";
                if (g  == 2) {
				std::cout << "|";
			}
            //_groups_of[k].push_back(x[g]);
         }
      }
   }
   for (int k = 0; k < _neighbors.size(); k++) {
      for (int x = 0; x < _groups_of[k].size(); x++) {
         for (int j = 0; j < 9; j++) {
            int k2 = _group[_groups_of[k][x]][j];
            if (k2 != k) _neighbors[k].push_back(k2);
         }
      }
   }
}

int main() {
   Sudoku::init();
//    string line;
//    while (getline(cin, line)) {
//       if (auto S = solve(unique_ptr<Sudoku>(new Sudoku(line)))) {
//          S->write(cout);
//       } else {
//          cout << "No solution";
//       }
//       cout << endl;
//    }
}