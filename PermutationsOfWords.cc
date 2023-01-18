/* Write a program that, given n different words s1, …, sn, prints all the permutations that can be made up with the words.

Input
Input consists of a number n > 0, followed by s1, …, sn.

Output
Print all the permutations that can be made up with s1, …, sn.
Information about the checker

You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> Words;
vector<bool> Used;
vector<int> Res;

void write(int n) {
    cout << '(' << Words[Res[0]];
    for(int i = 1; i < n; ++i) {
        cout << ',' << Words[Res[i]];
    }
    cout << ')' << endl;
}

void permutations(int n, int i) {
    if(i == n)  write(n);
    else {
        for(int j = 0; j < n; ++j) {
            if(not Used[j]) {
                Used[j] = true;
                Res[i] = j;
                permutations(n,i+1);
                Used[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    Words = vector<string>(n);
    for(int i = 0; i < n; ++i) cin >> Words[i];
    Used = vector<bool>(n);
    Res = vector<int>(n);
    permutations(n,0);
}