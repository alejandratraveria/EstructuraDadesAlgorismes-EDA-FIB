/* zip

There are n tasks, which have to be done one by one. Some tasks must be done before others: there are m precedence relations between tasks. 
Write a program that prints all possible ways to order the n tasks according to the m given precedences.

Input
Input consists of a natural number n ≥ 1, followed by a natural number m, followed by m different pairs x, y, 
indicating that task x must be done before task y. Suppose that the tasks are numbered from 0 to n − 1.

Output
Print, one per line and in lexicographic order, all the ways of sorting the n tasks according to the m given precedences. 
There will always be at least one solution.
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

typedef vector<int> VI;
typedef vector<bool> VB;

void write(int n, const VI& Res) {
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << Res[i];
    }
    cout << endl;
}

void topologicalOrdering(int n, int i, VI& inputDegrees, const Graph& G, VI& Res) {
    if (i == n) write(n, Res);
    else {
        for (int j = 0; j < n; ++j) {
            if (inputDegrees[j] == 0) {
                Res[i] = j;
                inputDegrees[j] = -1;
                for (int v: G[j]) --inputDegrees[v];
                topologicalOrdering(n, i+1, inputDegrees, G, Res);

                for (int v: G[j]) ++inputDegrees[v];
                inputDegrees[j] = 0;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);
    VI inputDegrees(n,0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        ++inputDegrees[y];
    }

    VI Res(n);
    topologicalOrdering(n, 0, inputDegrees, G, Res);
}