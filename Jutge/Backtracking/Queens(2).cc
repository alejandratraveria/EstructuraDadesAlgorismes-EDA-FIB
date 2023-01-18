/* Write a program to print all the ways to place n queens on an n × n chessboard so that no queen threatens another queen.

Input
Input consists of a natural number n > 0.

Output
Print all the ways to put n queens on an n × n chessboard so that no queen threatens another queen. The queens must be marked with a ‘Q’, 
and the empty positions with a dot. Print an empty line after each board.

Information about the checker
You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

typedef vector<char> VC;
typedef vector<VC> Board;

void write(int n, Board& board) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void rec(int n, int i, VB& cols, VB& d1, VB& d2, Board& board) {
    if (i == n) write(n, board);
    else {
        for (int j = 0; j < n; ++j) {
            if (cols[j] and d1[i+j] and d2[n-j+i-1]) {
                cols[j] = false;
                d1[i+j] = false;
                d2[n-j+i-1] = false;
                board[i][j] = 'Q';
                
                rec(n, i+1, cols, d1, d2, board);

                cols[j] = true;
                d1[i+j] = true;
                d2[n-j+i-1] = true;
                board[i][j] = '.';
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    VB cols(n, true);
    VB d1(2*n-1, true);
    VB d2(2*n-1, true);
    Board board(n, VC(n, '.'));
    rec(n, 0, cols, d1, d2, board);
}