/* Write a program that, given a map with treasures and obstacles, tells if it is possible to reach some treasure from a given initial position. 
The allowed movements are horizontal or vertical, but not diagonal.

Input begins with the number of rows n > 0 and the number of columns m > 0 of the map. 
Follow n rows with m characters each. A dot indicates an empty position, an ‘X’ indicates an obstacle, and a ‘t’ indicates a treasure. 
Finally, two numbers r and c indicate the initial row and column (both of them starting at 1) where we must start looking for treasures. 
You can assume that r is between 1 and n, that c is between 1 and m, and that the initial position is always empty.

Print “yes” or “not” depending on whether it possible or not to reach any treasure.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Board;
typedef pair<int,int> pos;

vector<pos> dir = {{-1,0}, {1,0}, {0,1},{0,-1}}; //down, up, right, left

bool valid_pos(const pos& p, const Board& b) {
  return (p.first >= 0 and p.second >=0 and p.first < int(b.size()) and p.second < int(b[0].size()));
}

bool treasure_found(const Board& b, vector<vector<bool>>& visit, int r, int c) {
    if(not visit[r][c]) {
        visit[r][c] = true;
        if(b[r][c] == 't') return true;
        else if(b[r][c] != 'X') {
            for(pos v: dir) {
                if (valid_pos({r + v.first, c + v.second}, b) and treasure_found(b,visit,r + v.first,c + v.second)) return true;
            }
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    Board b(n, vector<char>(m));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> b[i][j];
    
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> visit(n,vector<bool>(m));
    cout << (treasure_found(b,visit, r-1, c-1) ? "yes" : "no") << endl;
}

