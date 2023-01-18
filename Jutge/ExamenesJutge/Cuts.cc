/* The government of a distant country is cutting as much as possible. Now they have noticed that, often, there is more than one 
path that goes from one town to another town (either a direct road, or a sequence of roads passing through other intermediate towns).
Since every road has some maintenance cost, the government has decided to eliminate several roads to save as much as possible, but 
keeping the road system connected. Can you calculate the maximum savings?

Input
Input consists of several cases. Every case begins with the number of towns (vertices) n and the number of roads (edges) m. Follow m 
triples x y c, indicating that the maintenance cost of the road between x and y is c. Towns are numbered from 0 to n − 1. Assume 1 ≤ n ≤ 104, 
n − 1 ≤ m ≤ 10 n, and 1 ≤ c ≤ 104. There may be more than one road between two towns, and even roads with x = y. Every given graph is connected.

Output
For every case, print the maximum savings achiving that there is exactly one path between every pair of towns.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> WArc;

typedef vector<WArc> VW;
typedef vector<VW> Graph;

int primMaxSavings(int n, int m, int totalSum, const Graph& G) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    vector<bool> visited(n, false);
    int res = 0;
    int count = 1;

    visited[0] = true;
    for (WArc wa: G[0]) {
        pq.push(wa);
    }

    while (count < n) {
        WArc act = pq.top();
        pq.pop();

        if (not visited[act.second]) {
            visited[act.second] = true;
            res += act.first;
            ++count;
            for (WArc wa: G[act.second]) {
                pq.push(wa);
            }
        }
    }
    return totalSum - res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int x, y, c;
        int totalSum = 0;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> c;
            G[x].push_back({c,y});
            G[y].push_back({c,x});
            totalSum += c;
        }
        int maxSavings = primMaxSavings(n, m, totalSum, G);
        cout << maxSavings << endl;
    }
}