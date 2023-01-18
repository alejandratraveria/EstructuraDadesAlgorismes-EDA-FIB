/* Write a program that, given a number n, prints all the words that are a permutation of the first n lowercase letters, with one restriction: 
there cannot be two letters x and y such that y is immediately to the right of x in the word and y is the letter following x in the alphabet.

Input
Input consists of a natural number n between 1 and 9.

Output
Print in order and one per line all the words that satisfy the restriction.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<bool> VB;

int n;

void rec(int i, VB& visited, string& res) {
    if (i == n) cout << res << endl;
    else {
        for (int j = 0; j < n; ++j) {
            if (not visited[j] and (i== 0 or res[i-1] + 1 != 'a' + j)) {
                res[i] = 'a' + j;
                visited[j] = true;
                rec(i+1, visited, res);
                visited[j] = false;
            }
        }
    }
}


int main() {
    cin >> n;

    string res(n, 'a');
    VB visited(n, false);
    rec(0, visited, res);
}