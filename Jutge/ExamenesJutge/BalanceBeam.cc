/* A gymnast is at the midpoint of a balance beam of length m. The gymnast must jump n times forward or backward, never leaving the bar. 
The i-th jump has length ℓi. Write a program to compute all the positions where the gymnast can finish her exercise. The gymnast cannot skip any 
jump, nor change the order of the jumps.

Input
Input consist of the length m, the number n, and the lengths ℓ1, …, ℓn. Assume 2 ≤ m ≤ 109, that m is even, 0 ≤ n ≤ 18, and 1 ≤ ℓi ≤ 108.

Output
Assuming that the initial position is 0 (hence, the valid positions belong to [−m/2, m/2]), print all the positions where the gymnast can finish. 
Every position must occur as many times as combinations of jumps make it possible.

Information about the checker
You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

int m,n;

void rec(int i, int res, VI& lentgh) {
    if (res <= m/2 and res >= (-1)*(m/2)) {
        if (i == n) cout << res << endl;
        else {
            rec(i+1, res+lentgh[i], lentgh);
            rec(i+1, res-lentgh[i], lentgh);
        }
    }
}

int main() {
    cin >> m >> n;

    VI length(n);
    for (int i = 0; i < n; ++i) cin >> length[i];

    rec(0,0,length);
}