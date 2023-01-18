/* Given an undirected graph, compute the number of vertices of the smallest and largest connected component.

Input
Input consists of several graphs. Each of them starts with the number of vertices n and the number of edges m, followed by m pairs x y that 
correspond to an edge between vertices x and y. It holds that 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, vertices are numbered from 0 to n−1, and there are neither 
repeated edges nor edges of the form x x.

Output
For each graph, write the minimum and maximum size of its connected components.
*/
#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef vector<bool> VB;

typedef vector<int> VI;
typedef vector<VI> VVI;

pair<int,int> dfsCC(int n, int m, const VVI& G) {
    pair<int,int> res = {inf, 0};
    stack<int> s;
    VB visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            s.push(i);
            int num = 0;
            while (not s.empty()) {
                int act = s.top();
                s.pop();
                if (not visited[act]) {
                    visited[act] = true;
                    num += 1;
                    for (int v: G[act]) {
                        if (not visited[v]) {
                            s.push(v);
                        }
                    }
                }
            }
            res.first = min(num, res.first);
            res.second = max(num, res.second);
        }
    }
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVI G(n); //graph

        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        pair<int,int> cc = dfsCC(n, m, G);
        cout << cc.first << ' ' << cc.second << endl;
    }
}