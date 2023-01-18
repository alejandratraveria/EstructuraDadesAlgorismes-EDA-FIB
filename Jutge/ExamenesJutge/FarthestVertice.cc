/* Given an undirected graph, compute the vertex which is farthest from vertex 0.

Input
Input consists of several graphs. Each graph starts with the number of vertices n and the number of edges m, followed by m pairs x y that 
correspond to and edge between vertices x and y. It holds that 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, vertices are numbered from 0 to n−1, and there are 
neither repeated edges nor edges of the form x x.

Output
For each graph, write the vertex which is farthest from vertex 0. In case of a tie, choose the smallest vertex. Ignore vertices that are not 
reachable from 0.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<bool> VB;

typedef vector<int> VI;
typedef vector<VI> VVI;

int bfs(int n, int m, const VVI& G) {
    int distMax = 0;
    int maxVertice = 0;
    queue<int> q;
    VI dist(n, -1);

    q.push(0);
    dist[0] = 0;
    while (not q.empty()) {
        int act = q.front();
        q.pop();

        for (int v: G[act]) {
            if (dist[v] == -1) {
                dist[v] = dist[act] + 1;
                q.push(v);
                if (dist[v] > distMax) {
                    distMax = dist[v];
                    maxVertice = v;
                }
            }
            if (dist[v] == distMax and v < maxVertice) {
                maxVertice = v;
            }
        } 
    }
    return maxVertice;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVI G(n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        cout << bfs(n,m,G) << endl;
    }
}