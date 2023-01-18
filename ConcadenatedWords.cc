/* Given n words, print all the ways to concatenate them so that there are no two equal adjacent letters.

Input
Input consists of an n between 1 and 8, followed by n words, each one made up of between 1 and 10 lowercase letters. No word has two 
adjacent equal letters.

Output
Print all the correct ways to concatenate the n words, one per line.
Information about the checker

You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> VS;

void write(vector<string>& res) {
    for (int i = 0; i < int(res.size()); ++i) {
        cout << res[i];
    }
    cout << endl;
}

bool equal(string s1, string s2) {
    return s1[int(s1.length()-1)] == s2[0];
}

void rec(vector<string>& res, vector<bool>& visited) {
    if (int(res.size()) == n) write(res);
    else {
        for (int i = 0; i < n; ++i) {
            if (not visited[i] and (int(res.size() == 0) or (int(res.size()) > 0 and not equal(res[int(res.size())-1],VS[i])))) {
                visited[i] = true;
                res.push_back(VS[i]);
                rec(res, visited);
                visited[i] = false;
                res.pop_back();
            }
        }
    }
}

int main() {
    cin >> n;
    VS = vector<string>(n);
    for (int i = 0; i < n; ++i) {
        cin >> VS[i];
    }
    
    vector<string> res;
    vector<bool> visited(n,false);
    rec(res, visited);
}