/* Consider a rectangular board r × c with r ≤ c. Write a program that prints all the ways to place r rooks on the board so that no rook threatens 
another rook.

Input
Input consists of two natural numbers r and c, with 1 ≤ r ≤ c.

Output
Print all the ways to place r rooks on the board so that no rook threatens another rook. Represent the rooks with a ‘R’, and the empty positions 
with a dot. Print an empty line after each board.

Information about the checker
You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<bool> VB;
typedef vector<VB> VVB;

void write(int r, int c, VVC& board) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << board[i][j];  
        }
        cout << endl;
    }
    cout << endl;
}

void rec(int r, int c, int i, VB& colR, VVC& board) {
    if (i == r) write(r,c,board);
    else {
        for (int j = 0; j < c; ++j) {
            if (colR[j]) {
                colR[j] = false;
                board[i][j] = 'R';
                rec(r,c,i+1,colR,board);
                board[i][j] = '.';
                colR[j] = true;
            }
        }
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    
    VVC board(r, VC(c, '.'));
    VB colR(c, true);
    rec(r,c,0,colR,board);
}