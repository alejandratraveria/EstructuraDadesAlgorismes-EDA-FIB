/* Write a program that, given a directed graph with positive costs at the arcs, and two vertices x and y, computes the minimum cost to go 
from x to y, and the minimum number of steps of all the paths that go from x to y with such minimum cost.

Input
Input consists of several cases. Every case begins with the number of vertices n and the number of arcs m. Follow m triples u, v, c, 
indicating that there is an arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 104. Finally, we have x and y. Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, 
and that for every pair of vertices u and v there is at most one arc of the kind u → v. All numbers are integers. Vertices are numbered 
from 0 to n−1.

The condition for c was previously c ≤ 1000. It was updated to create new test cases.

Output
For every case, print the minimum cost to go from x to y, and the minimum number of steps to achieve this cost. If there is no path from 
x to y, state so.
*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef vector<int> VI;
typedef vector<bool> VB;

typedef pair<int,int> WArc; //first->weight, second->v
typedef vector<WArc> VW;
typedef vector<VW> Graph;

pair<int,int> dijkstra(int n, int start, int end, const Graph& G) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    VI vCost(n, inf);
    VI vSteps(n, -1);
    VB visited(n, false);

    pq.push({0,start});
    vCost[start] = 0;
    vSteps[start] = 0;
    while (not pq.empty()) {
        WArc act = pq.top();
        pq.pop();
        if (not visited[act.second]) {
            visited[act.second] = true;
            if (act.second == end) return {vCost[act.second], vSteps[act.second]};
            else {
                for (WArc uv: G[act.second]) {
                    int d = uv.first;
                    int v = uv.second;
                    if (vCost[v] > vCost[act.second] + d) {
                        vCost[v] = vCost[act.second] + d;
                        vSteps[v] = vSteps[act.second] + 1;
                        pq.push({vCost[v], v});
                    }
                    else if (vCost[v] == vCost[act.second] + d and vSteps[v] > vSteps[act.second] + 1) {
                        vSteps[v] = vSteps[act.second] + 1;
                    }
                }
            }
        }
    }
    return {-1, -1};
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
        int start, end;
        cin >> start >> end;
        pair<int, int> cs = dijkstra(n, start, end, G);
        if (cs.first == -1) cout << "no path from " << start << " to " << end << endl;
        else cout << "cost " << cs.first << ", " << cs.second << " step(s)" << endl;
    }
}