/* Write a program that, given a directed graph with positive costs at the arcs, and two vertices x and y, computes the minimum cost to 
go from x to y, and the number of ways of going from x to y with such minimum cost.

Input
Input consists of several cases. Every case begins with the number of vertices n and the number of arcs m. Follow m triples u, v, c, 
indicating that there is an arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 104. Finally, we have x and y. Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, 
and that for every pair of vertices u and v there is at most one arc of the kind u → v. All numbers are integers. Vertices are numbered 
from 0 to n−1.

The condition for c was previously c ≤ 1000. It was updated to create new test cases.

Output
For every case, print the minimum cost to go from x to y, and the number of different paths that achieve this cost. This number will never 
exceed 109. If there is no path from x to y, state so.
*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef vector<int> VI;
typedef vector<bool> VB;

typedef pair<int,int> WArc;
typedef vector<WArc> VW;
typedef vector<VW> Graph;

pair<int, int> dijkstra(int n, int start, int end, const Graph& G) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    VI vCost(n, inf);
    VI vWays(n, 0);
    VB visited(n, false);

    pq.push({0,start});
    vCost[start] = 0;
    vWays[start] = 1;
    while (not pq.empty()) {
        WArc act = pq.top();
        pq.pop();
        if (not visited[act.second]) {
            visited[act.second] = true;
            if (act.second == end) return {vCost[act.second], vWays[act.second]};
            for (WArc uv: G[act.second]) {
                int d = uv.first;
                if (vCost[uv.second] > vCost[act.second] + d) {
                    vCost[uv.second] = vCost[act.second] + d;
                    vWays[uv.second] = vWays[act.second];
                    pq.push({vCost[uv.second], uv.second});
                }
                else if(vCost[uv.second] == vCost[act.second] + d) {
                    vWays[uv.second] += vWays[act.second];
                }
            }
        }
    }
    return{-1, -1};
} 

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back({c, v});
        }
        int start, end;
        cin >> start >> end;
        pair<int,int> cw = dijkstra(n, start, end, G);
        if (cw.first == -1) cout << "no path from " << start << " to " << end << endl;
        else cout << "cost " << cw.first << ", " << cw.second << " way(s)" << endl;
    }
}