/* Write a program that, given an undirected graph, tells if we can paint all vertices with only two colors, 
in such a way that no two neighboring vertices have the same color.

Input consists of several cases, each with the number of vertices n and the number of edges m, followed by m 
pairs x y indicating an edge between x and y. Suppose 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, that vertices are numbered from 0 to n − 1, x ≠ y, 
and that there is no more than one edge between any pair x y.

For every case, print “yes” if the graph is two-colorable, and “no” otherwise.
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

bool paint(const Graph& g, int i, vector<int>& colors, int color) {
    if(colors[i] == -1) {
        colors[i] = color;
        for(int v: g[i]) { //adjacent vertices
            if(not paint(g, v, colors, 1 - color)) return false;
        }
        return true;
    }
    else return (colors[i] == color);
}

bool two_colorable(const Graph& g) {
    int n = g.size();
    // -1: not colored --> not visited, colors 0 and 1
    vector<int> colors(n, -1);

    //could be a not connected graph
    for(int i = 0; i < n; ++i) { 
        if(colors[i] == -1) {
            if(not paint(g, i, colors, 0)) return false;

        }
    } 
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int x, y;
        Graph g(n);
 
        for(int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << (two_colorable(g) ? "yes" : "no") << endl;
    }
}