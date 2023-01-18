/* Write program that prints all the permutations of { 1, …, n } for a given n.

Input
Input consists of a natural number n > 0.

Output
Print all the permutations of { 1, …, n } in lexicographical order.
*/

#include <iostream>
#include <vector>
using namespace std;

void write(int n, const vector<int>& Res) {
    cout << '(' << Res[0];
    for(int i = 1; i < n; ++i) cout << ',' << Res[i];
    cout << ')' << endl;
}

void back(int i, int n, vector<int>& Res, vector<bool>& Used) {
    if(i == n) write(n,Res);
    else {
        for(int j = 0; j < n; ++j) {
            if(not Used[j]) {
                Used[j] = true;
                Res[i] = j+1;
                back(i+1,n,Res,Used);
                Used[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>Res(n);
    vector<bool>Used(n,false);
    back(0,n,Res,Used);
}