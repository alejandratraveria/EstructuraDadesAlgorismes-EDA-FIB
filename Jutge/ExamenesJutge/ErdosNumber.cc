/* Paul Erdős was one of the most prolific mathematicians in history. He wrote so many works, and with so many coauthors, that there is the 
tradition to compute the so called “Erdős number”, defined as follows: Erdős has Erdős number 0. Each of his collaborators has Erdős number 1. 
Those who collaborated with the direct collaborators of Erdős (but did not collaborate with Erdős himself) have Erdős number 2, etc. People with 
no connection with Erdős have an undefined Erdős number.

Given the information of the authorship of the w works of a group of n mathematicians, can you compute the Erdős number of each one, according to 
the known information?

Input
Input consists of several cases. Every case begins with n and w, followed by the information of the works: for each one, the number of coauthors 
(between 1 and n), followed by those coauthors (all different, in any order). Assume that the mathematicians are numbered from 0 to n − 1, that 
Erdős corresponds to 0, and that there is at least one publication by Erdős.

Output
For every case, print the Erdős number of every mathematician, or “no” if it is undefined. Print a line with 10 dashes at the end of every case.
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

const int UND = -1;

int main() {
    int n, t ;
    while (cin >> n >> t) {
        vector<unordered_set<int>> g(n);
        while (--t >= 0) {
            int s;
            cin >> s;
            vector<int> pub(s);
            for (int i = 0; i < s; ++i) cin >> pub[i];
            for (int i = 0; i < s; ++i) {
                for (int j = i+1; j < s; ++j) {
                    int u = pub[i];
                    int v = pub[j];
                    g[u].insert(v);
                    g[v].insert(u);
                }
            }
        }
        vector<int> dst(n, UND);
        queue<int> q;
        dst[0] = 0;
        q.push(0);
        while (not q.empty()) {
            int u = q.front();
            q.pop ();
            for (int v : g[u]) {
                if (dst[v] == UND) {
                    dst[v] = dst[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            cout << u << " : ";
            if ( dst[u] == UND) cout << "no";
            else cout << dst[u];
            cout << endl;
        }
        for (int k = 0; k < 10; ++k) cout << "-";
        cout << endl;
    }
}