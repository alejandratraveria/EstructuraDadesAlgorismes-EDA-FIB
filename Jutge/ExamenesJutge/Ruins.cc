/* Recent excavations have revealed an ancient extinct language. Thanks to the ruins found, experts have deduced that there were vowels 
and consonants, and that all words could be formed, with one sole exception: a word could not have two or more consecutive vowels. For example, 
with the two vowels a and e, and consonant b, 11 words with three letters could be formed: aba, abb, abe, bab, bba, bbb, bbe, beb, eba, ebb, ebe.

Which words of size n could be formed with m given letters?

Input
Input consists of several cases, each with n and m, followed by m different lowercase letter. It holds that n ≥ 1, 2 ≤ m ≤ 26, and that each 
case has at least one vowel and one consonant.

Output
For each case, write in lexicographical order all words of length n that can be built with the m given letters. Write a line with 10 hyphens 
after each case.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<char> VC;

void write(int n, VC& res) {
    for (int i = 0; i < n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

bool vowel(char c1, char c2) {
    if ((c1 == 'a' or c1 == 'i' or c1 == 'u' or c1 == 'e' or c1 == 'o') and (c2 == 'a' or c2 == 'i' or c2 == 'u' or c2 == 'e' or c2 == 'o')) return true;
    else return false;
}

void rec(int n, int m, VC& letters, VC& res) {
    if (int(res.size()) == n) write(n, res);
    else {
        for (int i = 0; i < m; ++i) {
            if (res.size() == 0 or (res.size() != 0 and not vowel(res[res.size()-1], letters[i]))) {
                res.push_back(letters[i]);
                rec(n, m, letters, res);
                res.pop_back();
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VC letters(m);
        for (int i = 0; i < m; ++i) {
            cin >> letters[i];
        }
        sort(letters.begin(), letters.end());
        VC res;
        rec(n, m, letters, res);
        cout << "----------" << endl;
    }
}