/* Given a connected, undirected graph, a spanning tree of that graph is a subgraph which is a tree and connects all the vertices together. 
On a weighted graph, the weight of a spanning tree is the sum of the weights of its edges. A minimum spanning tree is a spanning tree with 
weight less than or equal to the weight of every other spanning tree.

Input
Input consists of different weighted, connected, undirected graphs. For each graph, the following integers are given: First, n ≥ 1 
represents the number of vertices on the graph. Then, m represents the number of edges on the graph. Finally, a set of m weighted edges 
u,v,w is given by specifying its two end points u and v and its weight w ≥ 1. Vertices are numbered starting from 1. There are no edges 
connecting a vertex to itself, but there may be more than two edges connecting the same pair of vertices. Every given graph is connected. 
All weights are strictly positive integers.

Output
For every graph in the input, write the weight of its minimum spanning tree.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<double, int> WArc; //first = weight, second = vertice

typedef vector<WArc> VW;
typedef vector<VW> Graph;

int prim(int n, int m, const Graph& G) {
    vector<bool> visited(n, false);
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    int res = 0;
    int count = 1;

    visited[0] = true;
    for (WArc wa: G[0]) {
        pq.push(wa);
    }

    while (count < n) {
        WArc act = pq.top();
        pq.pop();
        if (not visited[act.second]) {
            visited[act.second] = true;
            res += act.first;
            ++count;
            for (WArc wa: G[act.second]) {
                pq.push(wa);
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int u, v;
        double w;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            G[u-1].push_back({w, v-1});
            G[v-1].push_back({w, u-1});
        }
        int sum = prim(n, m, G);
        cout << sum << endl;
    }
}