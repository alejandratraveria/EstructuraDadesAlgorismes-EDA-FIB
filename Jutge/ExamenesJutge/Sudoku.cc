/* Sudoku is a phenomenon all over the world. This addictive logic game, originated in the U.K. and popularized in Japan, has spread across the 
globe. The puzzles are now syndicated daily in newspapers in Australia, Germany, Scandinavia, …even Mireia is addicted to it!

The rules are easy: You are given a 9× 9 grid with some numbers in it, and you should fill in the grid so that every row, every column and every 
3×3 box contains the numbers from 1 to 9. 

Write a program to solve Sudoku puzzles. Your program will be tested against Sudokus that have appeared in some newspapers. These are guaranteed 
to have a unique solution.

Input
Input begins with a line with a number n ≥ 1. Follow n Sudokus, each one consisting of nine lines, each one with nine space-separated characters, 
which are digits from 1 to 9 and dots. The latter indicate cells that are still empty. There is a blank line before every puzzle.

Output
Print the solutions using the same format as in the input: First, print n on a line. For each puzzle, print nine lines, each with nine digits 
separated by spaces. Print a blank line before every solution.
*/
#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VVE = vector<VE>;
using VVVE = vector<VVE>;


VVE M(9, VE(9));
VVE fila, colu;
VVVE quad;


void print() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j)
      cout << (j ? " " : "") << M[i][j];
    cout << endl;
  }
}


bool f(int i, int j) {
  if (i == 9) {
    print();
    return true;
  }

  if (j == 9) return f(i + 1, 0);

  if (M[i][j] != 0) return f(i, j + 1);

  for (int d = 1; d <= 9; ++d)
    if (not fila[i][d] and not colu[j][d] and not quad[i/3][j/3][d]) {
      fila[i][d] = colu[j][d] = quad[i/3][j/3][d] = true;
      M[i][j] = d;
      if (f(i, j + 1)) return true;
      M[i][j] = 0;
      fila[i][d] = colu[j][d] = quad[i/3][j/3][d] = false;
    }
  return false;
}


int main() {
  int n;
  cin >> n;
  cout << n << endl;
  while (n--) {
    cout << endl;
    fila = colu = VVE(9, VE(10, false));
    quad = VVVE(3, VVE(3, VE(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.') M[i][j] = 0;
        else {
          int d = c - '0';
          M[i][j] = d;
          fila[i][d] = colu[j][d] = quad[i/3][j/3][d] = true;
        }
      }

     f(0, 0);
  }
}