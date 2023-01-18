/* Write a program that, given a directed graph with positive costs at the arcs, and two vertices x and y, 
prints the path of minimum cost that goes from x to y.

Input consists of several cases. Every case begins with the number of vertices n and the number of arcs m. 
Follow m triples u, v, c, indicating that there is an arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 1000. Finally, we have x and y. 
Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, and that for every pair of vertices u and v there is at most one arc of the kind u → v. 
All numbers are integers. Vertices are numbered from 0 to n−1. If y is reachable from x, you have the guarantee that there is a unique path.

For every case, print the path of minimum cost that goes from x to y. If there is no path from x to y, state so.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef pair<int,int> WArc;

typedef vector<WArc> VW;
typedef vector<VW> Graph;


void write_path(const vector<int>& path) {
    bool first = true;
    for (int i = int(path.size()-1); i >= 0; --i) {
        if (first) {
            cout << path[i];
            first = false;
        }
        else cout << ' ' << path[i];
    }
}

void dijkstra(const Graph& G, int start, int end, vector<int>& prev, vector<int>& dist) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    vector<bool> visited(int(G.size()), false);

    pq.push({0,start});
    dist[start] = 0;
    while (not pq.empty()) {
        WArc act = pq.top();
        pq.pop();

        if (not visited[act.second]) {
            visited[act.second] = true;
            if (act.second == end) return;
            for (WArc uv: G[act.second]) {
                int d = uv.first;
                int v = uv.second;

                if (dist[v] > dist[act.second] + d) {
                    dist[v] = dist[act.second] + d;
                    pq.push({dist[v], v});
                    prev[v] = act.second;
                }
            }
        }
    }
}

int main() {
    int n, m;
    
    while(cin >> n >> m) {
        Graph G(n);
        for(int i = 0; i < m; ++i) {
            int x, y, dist;
            cin >> x >> y >> dist;
            G[x].push_back({dist, y});
        }
        int start, end;
        cin >> start >> end;

        vector<int> prev(n, -1);
        vector<int> dist(n, inf);
        dijkstra(G, start, end, prev, dist);
        if(dist[end] != inf) {
            vector<int> path;
            int aux = end;
            while (aux != start) {
                path.push_back(aux);
                aux = prev[aux];
            }
            path.push_back(start);
            write_path(path);
            cout << endl;
        }
        else cout << "no path from " << start << " to " << end << endl;
    }
}
