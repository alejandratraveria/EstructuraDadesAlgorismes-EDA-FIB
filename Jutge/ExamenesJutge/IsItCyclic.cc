/* Write a program that, given a directed graph, determines whether the graph has any cycle or not.

Input
Input consists of several cases. Every case begins with the number of vertices n and the number of arcs m. Follow m pairs u, v, 
indicating that there is an arc u → v, where u ≠ v. Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, and that for every pair of vertices u and v 
there is at most one arc of the kind u → v. Vertices are numbered from 0 to n−1.

Output
For every case, print “yes” or “no” depending on whether the graph has any cycle or not.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;

bool isCyclic(int n, VI& dg, const Graph& G) {
    priority_queue<int, VI, greater<int>> PQ;
    for (int i = 0; i < int(dg.size()); ++i) {
        if (dg[i] == 0) PQ.push(i);
    }
    if (PQ.empty()) return true;
    int count = 0;
    while (not PQ.empty()) {
        int act = PQ.top();
        PQ.pop();
        ++count;
        for (int i = 0; i < int(G[act].size()); ++i) {
            --dg[G[act][i]];
            if (dg[G[act][i]] == 0) PQ.push(G[act][i]);
        }
    }
    if(count != n) return true;
    else return false;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        VI dg(n, 0);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            dg[v] += 1;
        }
        bool cyclic = isCyclic(n, dg, G);
        if (cyclic) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}