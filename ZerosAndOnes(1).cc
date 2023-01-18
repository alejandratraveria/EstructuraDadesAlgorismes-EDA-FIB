/* Write a backtracking program to print all the combinations of z zeros and o ones such that z + o = n, for a given n.

Input
Input consists of a natural number n > 0.

Output
Print all the combinations of z zeros and o ones such that z + o = n, one per line and in lexicographical order.

Observation
Although a backtracking program is not really necessary to solve this exercise, implement it anyway for the sake of practice.
*/

#include <iostream>
#include <vector>
using namespace std;

void write(int n, const vector<int>& Res) {
    cout << Res[0];
    for(int i = 1; i < n; ++i) {
        cout << ' ' << Res[i];
    }
    cout << endl;
}

void back(int n, int i, vector<int>& Res) {
    if(i == n) write(n,Res);
    else {
        Res[i] = 0;
        back(n,i+1,Res);
        Res[i] = 1;
        back(n,i+1,Res);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>Res(n);
    back(n,0,Res);
}