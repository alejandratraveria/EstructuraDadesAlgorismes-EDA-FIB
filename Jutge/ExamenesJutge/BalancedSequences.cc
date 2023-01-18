/* A sequence of numbers is d-balanced if the absolute value of the difference between any two consecutive numbers is at most d. Formally 
(x1, x2, … , xn) is d-balanced if for all 1 ≤ i < n it holds that | xi − xi+1 | ≤ d.

Write a program that, given an integer n≥ 1 and an integer d ≥ 0, writes all d-balanced sequences that can be obtained by reordering the sequence 
(1, 2, … , n).

Input
The input consists of an integer n ≥ 1 followed by another integer d ≥ 0.

Output
Write all d-balanced sequences that can be obtained by reordering the sequence (1, 2, … , n). You can write the sequences in any order.
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

bool compatible (int left , int right , int d) {
    return abs(left - right) <= d;
}

void iWriteBalancedPermutations(int n, int d, vector<int>& partialSol, vector<bool>& used) {
    if (int(partialSol.size()) == n) {
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (i == 0) cout << partialSol [i];
            else cout << ',' << partialSol[i];
        }
        cout << ')' << endl;
    }
    else {
        for (int k = 1; k <= n; ++k) {
            if (not used[k]) {
                if (partialSol.size() == 0 or compatible(partialSol.back(), k, d)){
                    partialSol.push_back(k);
                    used[k] = true;

                    iWriteBalancedPermutations(n, d, partialSol, used);

                    used[k] = false ;
                    partialSol.pop_back();
                }
            }
        }
    }
}

void writeBalancedPermutations(int n, int d) {
    vector<bool> used(n+1,false);
    vector<int> partialSol;
    iWriteBalancedPermutations(n, d, partialSol, used);
}

int main(){
    int n, d;
    cin >> n >> d;
    writeBalancedPermutations(n,d);
}