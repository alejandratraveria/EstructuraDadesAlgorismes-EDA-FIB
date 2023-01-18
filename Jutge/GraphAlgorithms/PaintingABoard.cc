/* Write a program to paint several zones of an n × m board. Here, a zone is defined as a maximal set of adjoining cells, 
both horizontally and vertically.

Input consists of several cases. Every case begins with the dimensions n and m, followed by n lines with m characters each. 
A character ‘#’ indicates a wall. A dot indicates an empty cell. A lowercase or uppercase letter indicates what must be used to fill that zone. 
Every zone has at most one letter. Suppose 3 ≤ n ≤ 30, 3 ≤ m ≤ 30, and that the borders of the board only have walls.

For every case, print the result of painting the board, followed by an empty line. 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

bool pos_ok (const vector<vector<char>>& T, int f, int c) {
  return (f >= 0 and c >=0 and f < int(T.size()) and c < int(T[0].size()));
}

void dfs (vector<vector<char>>& T, int f, int c, char lletra) {
  if (T[f][c] == '.') {
    T[f][c] = lletra;
    for (auto& d : dirs){
      int nf = f+d.first;
      int nc = c+d.second;
      if (pos_ok(T,nf,nc)) dfs(T,nf,nc,lletra);
    }
  }
}

int main() {
  int n, m;

  while (cin >> n >> m) {
    vector<vector<char>> T(n,vector<char>(m));
    vector<pair<int,int>> inicials;
    // Reading board
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	    cin >> T[i][j];
	    if (T[i][j] != '.' and T[i][j] != '#') inicials.push_back({i,j});
      }   
    } 
    // Painting board
    for (auto p :  inicials) {
      // DFS from p
      int f = p.first;
      int c = p.second;
      char lletra = T[f][c];
      T[f][c] = '.';
      dfs(T,f,c,lletra);
    }
    // Writing board
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	    cout << T[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
}
