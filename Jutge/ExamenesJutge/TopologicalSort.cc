/* We must perform n tasks, one at a time. Furthermore, some tasks must be done before others: there are m precedence relations between tasks. 
Write a program to print a way to sort the n tasks satisfying the m given precedences.

Input
Input consists of several cases. Every case begins with n, followed by m, followed by m distinct pairs x y that indicate that task x must 
be done before task y. You can assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 10n, and that the tasks are numbered from 0 to n − 1.

Output
For every case, print the lexicographically smallest order of the n tasks that fulfills the m given precedences. There will always be, 
at least, one solution.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;

void topologicalSort(int n, VI& dg, const Graph& G) {
    priority_queue<int, VI, greater<int>> PQ;
    for (int i = 0; i < int(dg.size()); ++i) {
        if (dg[i] == 0) PQ.push(i);
    }
    bool first = true;
    while (not PQ.empty()) {
        int act = PQ.top();
        PQ.pop();
        if (first) {
            first = false;
            cout << act;
        }
        else cout << ' ' << act;
        for (int i = 0; i < int(G[act].size()); ++i) {
            --dg[G[act][i]];
            if (dg[G[act][i]] == 0) PQ.push(G[act][i]);
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        VI dg(n, 0);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            dg[y] += 1;
        }
        topologicalSort(n, dg, G);
    }
}