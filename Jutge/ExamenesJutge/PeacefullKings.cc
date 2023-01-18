/* Write a program that prints all the ways to place k kings on a n × n board so that no king threatens another king. Remember that a king 
threatens all the surrounding cells, either horizontally, vertically, or diagonally.

For instance, these are some ways to place 3 kings on a 4 × 4 board:
showmover=false, label=false, maxfield=d4, setpieces=ka2,kb4,kc1 showmover=false, label=false, maxfield=d4, setpieces=ka3,kc4,kd2 showmover=false, 
label=false, maxfield=d4, setpieces=ka1,kc4,kd1 showmover=false, label=false, maxfield=d4, setpieces=ka1,kb3,kd4

Input
Input consists of two natural numbers n > 0 and 0 ≤ k ≤ n2.

Output
Print all the ways to place k kings on a n × n board so that no king threatens another king. Mark the kings with a ‘K’, and the empty cells with 
a dot. Print a line with ten hyphens after every board.

Information about the checker
You can print the solutions to this exercise in any order.

Observation
The test cases of this problem do not require a very clever algorithm.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Pos{
    int x;
    int y;
};

const vector<Pos> DIRS = {{1,0}, {0,1}, {1,1}, {-1,0}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}};

typedef vector<bool> VB;
typedef vector<VB> VVB;

typedef vector<char> VC;
typedef vector<VC> Board;

bool posOk(const Pos& p, const Board& board) {
    return p.x >= 0 and p.x < int(board.size()) and p.y >= 0 and p.y < int(board[0].size());
} 

bool King(int n, const Pos& p, const Board& board) {
    for (Pos d: DIRS) {
        Pos next = {p.x + d.x, p.y + d.y};
        if (posOk(next, board) and board[next.x][next.y] == 'K') return true;  
    }
    return false;
}

void write(int n, Board& board) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void rec(int n, int k, int i, int j, int count, Board& board) {
    if (count == k) write(n, board);
    else {
        if (i < n) {
            if (not King(n, {i,j}, board)) {
                if (j < n-1) {
                    board[i][j] = 'K';
                    rec(n, k, i, j+1, count+1, board);
                }
                else {
                    board[i][j] = 'K';
                    rec(n, k, i+1, 0, count+1, board);
                }
            }
            if (j < n-1) {
                board[i][j] = '.';
                rec(n, k, i, j+1, count, board);
            }
            else {
                board[i][j] = '.';
                rec(n, k, i+1, 0, count, board);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    Board board(n, VC(n, '.'));
    rec(n, k, 0, 0, 0, board);
}
