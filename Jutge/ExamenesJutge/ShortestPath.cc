/* Write a program that, given a directed graph with n vertices (numbered from 0 to n−1) and m arcs, prints the shortest way to go from 0 
to n−1.

Input
Input consists of several cases. Every case begins with n and m. Follow m pairs x y to indicate an arc from x to y. There are no repeated 
arcs nor of the kind x x. There is always a path between 0 and n−1. You can assume 2 ≤ n ≤ 104 and 1 ≤ m ≤ 5n.

Output
For every case, print the vertices of the shortest path between 0 and n−1 separated by spaces. If there is more than one shortest path, 
print the smallest in lexicographical order.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> Graph;

typedef vector<bool> VB;

void bfs(int n, int m, const Graph& G) {
    queue<int> q;
    VB visited(n, false);
    VI path(n);

    q.push(0);
    visited[0] = true;
    while (not q.empty()) {
        int act = q.front();
        q.pop();

        if (act == n-1) {
            int aux = act;
            vector<int> revPath;
            
            while (aux != 0) {
                revPath.push_back(aux);
                //cout << aux << endl;
                aux = path[aux];
            }

            revPath.push_back(0);

            for (int i = int(revPath.size())-1; i >= 0; --i) {
                cout << revPath[i];
                if (i != 0) cout << ' ';
            }
            cout << endl;
        }
        
        for (int p : G[act]) {
            if (not visited[p]) {
                q.push(p);
                visited[p] = true;
                path[p] = act;
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;

            G[x].push_back(y);
        }
        for (int i = 0; i < n; ++i) {
            sort(G[i].begin(), G[i].end());
        }
        bfs(n, m, G);
    }
}