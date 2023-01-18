/* Write a program to compute the number of ways to place n queens on an n × n chessboard so that no queen threatens another queen. 
That is, no two queens can be located on the same row, column or diagonal.
For instance, there are exactly two ways for n = 4:
    largeboard, showmover=false, label=false, maxfield=d4, setpieces=qa2,qb4,qc1,qd3 largeboard, showmover=false, 
    label=false, maxfield=d4, setpieces=qa3,qb1,qc4,qd2

Input
Input consists of a natural number n > 0.

Output
Print the number of ways to put n queens on an n × n chessboard so that no queen threatens another queen.
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
int res;

void rec(vector<int>& queens, vector<bool>& cols, vector<bool>& diags1, vector<bool>& diags2, int i) {
    if (i == n) ++res;
    else {
        for (int j = 0; j < n; ++j) {
            if (cols[j] and diags1[i + j] and diags2[n - j + i - 1]) {

                cols[j] = false;
                diags1[i + j] = false;
                diags2[n - j + i - 1] = false;
                queens[i] = j;

                rec(queens, cols, diags1, diags2, i + 1);
                
                cols[j] = true;
                diags1[i + j] = true;
                diags2[n - j + i - 1] = true;
            }
        }
    }
}

int main() {
    cin >> n;

    vector<int> queens(n);

    // aux vectors to check if placing a queen on certain i and j is valid
    vector<bool> cols(n, true);
    vector<bool> diags1(2*n - 1, true);
    vector<bool> diags2(2*n - 1, true);

    rec(queens, cols, diags1, diags2, 0);

    cout << res << endl;
}