/* Write a program to print the lexicographically smallest way to place n queens on an n × n chessboard so that no queen threatens another queen.

Input
Input consists of a natural number n > 0.

Output
Mark the queens with a ‘Q’, and the empty positions with a dot. Print the lexicographically smallest way (by rows, from top to bottom, 
and assuming that a ‘Q’ is smaller than a dot) to place n queens on an n × n chessboard so that no queen threatens another queen. 
If there is no solution, print “NO SOLUTION”.
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Board;

typedef vector<bool> VB;

int diag1(int n, int r, int c) {
    return n-c-1+r;
}

int diag2(int r, int c) {
    return r+c;
}

void write(int n, const Board& Res) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Res[i][j];
        }
        cout << endl;
    }
}

bool queens(int n, int i, Board& Res, VB& col, VB& d1, VB& d2) {
    if (i == n) return true;
    else {
        for (int j = 0; j < n; ++j) {
            if (not col[j] and not d1[diag1(n,i,j)] and not d2[diag2(i,j)]) {
                Res[i][j] = 'Q';
                col[j] = true;
                d1[diag1(n,i,j)] = true;
                d2[diag2(i,j)] = true;

                if (queens(n, i+1, Res, col, d1, d2)) return true;

                col[j] = false;
                d1[diag1(n,i,j)] = false;
                d2[diag2(i,j)] = false;
                Res[i][j] = '.';
            }
        }
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    Board Res(n, VC(n, '.'));
    VB col(n, false);
    VB d1(2*n-1, false);
    VB d2(2*n-1, false);
    bool found = queens(n, 0, Res, col, d1, d2);

    if (found) write(n, Res);
    else cout << "NO SOLUTION" << endl;
}