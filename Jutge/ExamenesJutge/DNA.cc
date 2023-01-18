/* Write a backtracking program that prints all the combinations of length n that can be made with the letters ‘A’, ‘C’, ‘G’, ‘T’ for a given n.

Input
The input consists of a natural number n > 0.

Output
Print all the combinations of n letters ‘A’, ‘C’, ‘G’, ‘T’ in lexicographical order. 
*/
#include <iostream>
#include <string>
using namespace std;

const string ADN = "ACGT";

void recADN(int n, string& res) {
    if (res.length() == n) cout << res << endl;
    else {
        for (int i = 0; i < 4; ++i) {
            res.push_back(ADN[i]);
            recADN(n, res);
            res.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    string res;
    recADN(n, res);
}