/* Consider the map of a country, with n cities (numbered between 0 and n−1) and m unidirectional roads that connect them. Each road has a 
certain length. We want to go from city 0 to city 1. As we travel with people prone to get carsick, and we do not want to stop halfway to 
stretch our legs, we want to follow the route such that the longest road we take is as short as possible. That is, if the route uses k roads, 
with lengths ℓ1, ⋯, ℓk, and ℓ = max(ℓ1, ⋯, ℓk), we want ℓ to be as small as possible.

Input
The input consists in several cases. Each case begins with n and m, followed by m triplets x y ℓ, with x ≠ y, indicating a road that goes 
from x to y of length ℓ. Assume 2 ≤ n ≤ 104, 1 ≤ m ≤ 10n, that there is at most one road from x to y in this order, that the lengths are 
between 1 and 105, and that there is always a route between 0 and 1.

Output
For each case, write the maximum length of the roads of the best possible route.
The second line of the example of output corresponds to the route 0 → 4 → 2 → 1, which has a road (the 0 → 4) of maximum length 80.

Hint
Consider a variant of Dijkstra’s algorithm.

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef vector<int> VI;
typedef vector<bool> VB;

typedef pair<int,int> WArc; //frist->cost, second->vertice
typedef vector<WArc> VW;
typedef vector<VW> Graph; 

int dijkstra(int n, int start, int end, const Graph& G) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    VI dist(n, inf);

    pq.push({0,start});
    dist[start] = 0;
    while (not pq.empty()) {
        WArc act = pq.top();
        pq.pop();
        int d = act.first;
        if (act.second == end) return dist[act.second];
        if (d == dist[act.second]) {
            for (WArc uv: G[act.second]) {
                int duv = uv.first;
                int l = max(d, duv);
                if (l < dist[uv.second]) {
                    dist[uv.second] = l;
                    pq.push({l,uv.second});
                }
            }
        }
    }
    return +inf;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int x, y, l;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> l;
            G[x].push_back({l, y});
        }
        cout << dijkstra(n,0,1,G) << endl;
    }
}
*/

#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int inf_down = numeric_limits<int>::min();
const int inf = numeric_limits<int>::max();

using WArc = pair<int,int>;
using VW = vector<WArc>;
using VWW = vector<VW>;

using VI = vector<int>;
using VB = vector<bool>;

int djk(const VWW& G, int start, int end, int& cost) {
    int n = G.size();
    VI dists(n,inf);
    VB vis(n,false);

    priority_queue<WArc,vector<WArc>, greater<WArc> > Q;

    Q.push({0,start});
    dists[start] = 0;
    int max_long = 0;

    while (not Q.empty()) {
        int x = Q.top().second;
        int w = Q.top().first;
        Q.pop();

        if (x == end) return max(max_long,w);
        if (not vis[x]) {
            vis[x] = true;
            max_long = max(max_long,w);
            for (auto p : G[x]) {
                Q.push(p); 
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VWW Graph(n);

        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            Graph[u].push_back({c,v});
        }

        int cost = inf;
        cout << djk(Graph,0,1,cost) << endl;
    }
}