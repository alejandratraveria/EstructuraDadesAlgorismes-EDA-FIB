/* A sequence of numbers has a well if it contains three consecutive numbers such that that the endpoints add up more than twice the one in the 
middle. Formally, (x1, x2 , … , xn) has a well if it exists at least an i with 1 ≤ i < n − 1 such that xi + xi+2 > 2· xi+1.

Write a program that, given an integer n ≥ 1, writes all sequences with no well that can be obtained by reordering the sequence (1, 2, … , n).

Input
The input consists of an integer n ≥ 1.

Output
Write all sequences with no well that can be obtained by reordering the sequence (1, 2, …, n). You can write the sequences in any order.
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

void write(int n, VI& res) {
    cout << '(' << res[0];
    for(int i = 1; i < n; ++i) cout << ',' << res[i];
    cout << ')' << endl;
}

bool well(int i, int j, VI& res) {
    if (i < 2) return false;
    return res[i-2] + j > 2*res[i-1];
}

void rec(int n, int i, VB& vis, VI& res) {
    if (i == n) write(n, res);
    else {
        for (int j = 1; j <= n; ++j) {
            if (not vis[j-1] and not well(i,j,res)) {
                res[i] = j;
                vis[j-1] = true;
                rec(n,i+1,vis,res);
                vis[j-1] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    VI res(n);
    VB vis(n, false);
    rec(n,0,vis,res);
}