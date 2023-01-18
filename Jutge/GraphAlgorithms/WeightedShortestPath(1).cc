/* Write a program that, given a directed graph with positive costs at the arcs, and two vertices x and y, computes the minimum cost 
to go from x to y.

Input
Input consists of several cases. Every case begins with the number of vertices n and the number of arcs m. Follow m triples u, v, c, 
indicating that there is an arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 104. Finally, we have x and y. Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, 
and that for every pair of vertices u and v there is at most one arc of the kind u → v. All numbers are integers. Vertices are numbered 
from 0 to n−1.

The condition for c was previously c ≤ 1000. It was updated to create new test cases.

Output
For every case, print the minimum cost to go from x to y, if this is possible. If there is no path from x to y, state so.
*/
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef pair<int,int> WArc;

typedef vector<WArc> VW;
typedef vector<VW> Graph;

int dijkstra(int n, int m, int start, int end, const Graph& G) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    vector<bool> visited(n, false);
    vector<int> dist(n, inf);
    
    pq.push({0,start});
    dist[start] = 0;
    while (not pq.empty()) {
        WArc act = pq.top();
        pq.pop();
        if (not visited[act.second]) {
            visited[act.second] = true;
            if (act.second == end) return dist[act.second];
            for (WArc wa: G[act.second]) {
                if (dist[wa.second] > dist[act.second] + wa.first) {
                    dist[wa.second] = dist[act.second] + wa.first;
                    pq.push({dist[wa.second], wa.second});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int u, v, c; 
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            G[u].push_back({c, v});
        }
        int x, y;
        cin >> x >> y;
        int cost = dijkstra(n, m, x, y, G);
        if (cost != -1) cout << cost << endl;
        else cout << "no path from " << x << " to " << y << endl;
    }
}