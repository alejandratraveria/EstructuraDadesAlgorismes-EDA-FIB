/* Consider an n × m chess board, where some cells are legal and some are prohibited. You have many small bishops, so tiny that an 
unbounded number of them fit in every cell. As expected, bishops can only move diagonally. For every given board description, tell 
if there is a way to (repeatedly) move as many bishops as needed, never passing a prohibited cell, so that eventually all the legal 
cells have the same number of bishops.

Input
Input begins with a number t ≥ 0, followed by t cases. Every case begins with the number of rows n and the number of columns m. 
Follow n lines, each with m items separated with spaces. Prohibited cells are marked with an ‘X’. For legal cells, its initial number 
of bishops is given. No cell has more than 1000 bishops. Assume 1 ≤ n, m ≤ 100.

Output
For every case, print its number followed by “yes” or “no”, depending on whether it is possible to move the bishops so that eventually 
all the legal cells have the same number.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

struct Pos{
    int x;
    int y;
};

typedef vector<string> VS;
typedef vector<VS> Board;

typedef vector<bool> VB;
typedef vector<VB> VBB;

const vector<Pos> DIRS = {{1,1}, {-1,-1}, {1,-1}, {-1,1}};

bool posOk(const Pos& p, const Board& board) {
    return p.x >= 0 and p.x < int(board.size()) and p.y >= 0 and p.y < int(board[0].size());
}

int stringToInt(const string& s) {
    int res = 0;
    int power = 0;
    for (int i = s.length() -1; i >= 0; --i) {
        res += (s[i] - '0')*pow(10, power);
        ++power;
    }
    return res;
}

bool dfsBishops(int n, int m, int bishop, Pos ini, VBB& visited, const Board& board) {
    stack<Pos> s;
    int sum = 0;
    int count = 0;

    s.push(ini);
    visited[ini.x][ini.y] = true;
    while (not s.empty()) {
        Pos act = s.top();
        s.pop();
        ++count;
        sum += stringToInt(board[act.x][act.y]);
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (posOk(next, board) and not visited[next.x][next.y] and board[next.x][next.y] != "X") {
                s.push(next);
                visited[next.x][next.y] = true;
            }
        }
    }
    return (sum%count == 0 and sum/count == bishop);
}

int main() {
    int t;
    cin >> t; 
    
    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        
        Board board(n, VS(m));
        int count = 0;
        int sumTotal = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> board[j][k];
                if (board[j][k] != "X") {
                    ++count;
                    sumTotal += stringToInt(board[j][k]);
                }
            }
        }

        if (count != 0) {
            int bishop = sumTotal/count;
            if (sumTotal%count != 0) cout << "Case " << i+1 << ": no" << endl;
            else {
                VBB visited(n, VB(m, false));
                bool equalBishops = true;
                for (int j = 0; equalBishops and j < n; ++j) {
                    for (int k = 0; equalBishops and k < m; ++k) {
                        if (board[j][k] != "X" and not visited[j][k]) {
                            equalBishops = dfsBishops(n, m, bishop, {j,k}, visited, board);
                        }
                    }
                }
                if (equalBishops) cout << "Case " << i+1 << ": yes" << endl;
                else cout << "Case " << i+1 << ": no" << endl;
            }
        }
        else cout << "Case " << i+1 << ": yes" << endl;
    }
}