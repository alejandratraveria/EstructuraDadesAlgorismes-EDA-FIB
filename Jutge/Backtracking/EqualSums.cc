
/* Write a program that, given an integer number s and n integer numbers x1, …, xn, prints all the subsets 
(maybe with repeated numbers, but using every xi at most once) whose sum is exactly s.

Input
Input consists of an integer number s, followed by a number n > 0, followed by x1, …, xn.

Output
Print all the subsets whose sum is s that can be made up with x1, …, xn. 

Information about the checker
You can print in any order both the solutions and the elements inside each solution.

Hint
For this exercise, simple backtracking solutions are accepted. No optimizations are required.
*/

#include <iostream>
#include <vector>
using namespace std;

void write(int n, const vector<int>& VI, const vector<int>& Res) {
    cout << '{';
    bool first = true;
    for(int i = 0; i < n; ++i) {
        if(Res[i] == 1) {
            if(first) first = false;
            else cout << ',';
            cout << VI[i];
        }
    }
    cout << '}' << endl;
}

void equalSums(int s, int n, int sum, int i, const vector<int>& VI, vector<int>& Res) {
    if(i == n) {
        if(sum == s) write(n,VI,Res);
    }
    else {
        Res[i] = 0;
        equalSums(s,n,sum,i+1,VI,Res);
        Res[i] = 1;
        equalSums(s,n,sum+VI[i],i+1,VI,Res);
    }
}

int main() {
    int s, n;
    cin >> s >> n;

    vector<int> VI(n);
    for(int i = 0; i < n; ++i) cin >> VI[i];

    vector<int> Res(n);
    equalSums(s,n,0,0,VI,Res);
}