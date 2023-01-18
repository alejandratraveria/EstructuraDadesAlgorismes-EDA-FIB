/* A forest is a graph without cycles, and each of its connected components is a tree. Given an undirected graph, is it a forest? 
In case it is, how many trees does it have? 

Input consists of several graphs. Every graph starts with its number of vertices n and its number of edges m, 
followed by m pairs x y indicating an edge between vertices x and y. Assume 1 ≤ n ≤ 104, 0 ≤ m < n, 
that vertices are numbered from 0 to n−1, and that there are neither repeated edges nor edges of the type x x.

For every graph, if it is a forest print the number of trees it has. Otherwise, print “no”.
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

bool cycle(const Graph& g, int i, vector<bool>& visit, int ant) {
    if(visit[i]) return true; //cycle
    visit[i] = true;
    for(int v: g[i]) { //for(int j = 0; j < int(g[i].size()); ++j) v = g[i][j]
        //searching for cycles starting at vertex 'i'
        if (v != ant and cycle(g, v, visit, i)) return true; 
    }
    return false;
}

int forest(const Graph& g) {
    int num_f = 0;
    int n = g.size();
    vector<bool> visit(n, false);

    for(int i = 0; i < n; ++i) {
        //checking if vertex 'i' has been visited before
        if (not visit[i]) {
            //searching for any cycles
            if (cycle(g, i, visit, -1)) return -1; 
            else ++num_f;
        }
    }
    return num_f;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        int x, y;
        Graph g(n);

        for(int i = 0; i < m; ++i) {
            cin >> x >> y;
            //adding edges between vertices
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int num_f = forest(g); //if not forest -1
        if (num_f == -1) cout << "no" << endl;
        else cout << num_f << endl;
    }
}