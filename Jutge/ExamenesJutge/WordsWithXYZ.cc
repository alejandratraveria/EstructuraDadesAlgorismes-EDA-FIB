#include <iostream>
#include <vector>
using namespace std;

vector<char> letters = {'x', 'y', 'z'};

void writeWords (int n, int c, vector<char>& partialSol, int consec, int k) {
    if (k == n) {
        for (char aux: partialSol) cout << aux;
        cout << endl;
    }
    else {
        for (int i = 0; i < 3; ++i) {
            bool repeated = (k > 0 and partialSol[k-1] == letters[i]);
            int newConsec = (repeated ? consec + 1 : 1);
            if (newConsec <= c) {
                partialSol[k] = letters[i];
                writeWords(n,c,partialSol,newConsec,k+1);
            }
        }
    }
}

int main () {
    int n, c;
    while (cin >> n >> c) {
        vector<char> partialSol(n);
        writeWords(n,c,partialSol,0,0);
        cout << string(20, '-') << endl;
    }
}