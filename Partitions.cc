/* Write a program that, given n different words s1, …, sn and a number p, prints all the ways to share the words between p subsets.

Input
Input consists of a natural number n > 0, followed by s1, …, sn, followed by a natural number p > 0.

Output
Print all the ways to share the words between p subsets. The elements of each set must appear in the same order than in the input. 
Print an empty line after each partition.

Observation
Strictly speaking, a partition cannot have empty subsets, but we forget about that restriction in this exercise.
Information about the checker

You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
using namespace std;

void write(int n, int p, const vector<string>& Words, const vector<int>& Res) {
    for(int i = 0; i < p; ++i) {
        cout << "subset " << i+1 << ": {";
        bool first = true;
        for(int j = 0; j < n; ++j) {
            if(Res[j] == i) {
                if(first) first = false;
                else cout << ',';
                cout << Words[j];
            }
        }
        cout << '}' << endl;
    }
    cout << endl;
}

void partitions(int n, int p, int i, const vector<string>& Words, vector<int>& Res) {
    if(i == n) write(n,p,Words,Res);
    else {
        for(int j = 0; j < p; ++j) {
            Res[i] = j;
            partitions(n,p,i+1,Words,Res);
        }
    }
}

int main() {
    int n, p;
    cin >> n;
    vector<string> Words(n);
    for(int i = 0; i < n; ++i) cin >> Words[i];
    cin >> p;

    vector<int> Res(n);
    partitions(n,p,0,Words,Res);
}