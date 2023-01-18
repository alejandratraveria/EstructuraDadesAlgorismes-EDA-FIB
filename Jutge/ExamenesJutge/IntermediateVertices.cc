/* Given a directed graph and two different vertices u and v, compute how many vertices x different from u and v there are such that there exists 
some path from u to v passing through x.

Input
The input consists in several cases. Each case begins with n, u, v and m, followed by m different pairs x y, with x ≠ y, which indicate an arc 
that goes from x to y. Assume 2 ≤ n ≤ 104, 0 ≤ m ≤ 10n, and that the vertices are numbered between 0 and n − 1.

Output
For each case, write the number of vertices that can be visited when going from u to v following some path.

Hint
For each case, essentially the expected solution only makes two traversals, each on the right graph.
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef vector<bool> VB;

void dfs(int u, VB& vis, const VVI& G) {
    if (not vis[u]) {
        vis[u] = true;
        for (int v: G[u]) dfs(v,vis,G);
    }
}

int main() {
    int n, u, v, m;
    while (cin >> n >> u >> v >> m) {
        VVI G(n);
        VVI invG(n);

        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            invG[y].push_back(x);
        }

        VB vis(n, false);
        dfs(u,vis,G);
        if (not vis[v]) cout << 0 << endl;
        else {
            VB visInv(n, false);
            dfs(v,visInv,invG);

            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (vis[i] and visInv[i] and i != u and i != v) ++count;
            }
            cout << count << endl;
        }
    }

}