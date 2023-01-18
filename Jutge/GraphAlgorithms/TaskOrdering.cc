/* There are n tasks to be done, but some tasks must be done before others. 
Given the names of the tasks and the direct dependencies among them, print the lexicographically smallest ordering of the tasks.

Input consists of several cases. Each case begins with n, followed by n names of tasks. 
Follow the number of direct dependencies m, followed by m pairs of names x y, to indicate that x must be done before y. 
Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 10n, that the names are made up of between one and six lowercase letters, 
that no name is a prefix of another name (in particular, this excludes equal names), that there are no repeated dependencies,
and that there are no dependencies of the kind x x.

For every case, print the alphabetically smaller string that can be produced by concatening a valid ordering of the tasks. 
If there is no valid ordering, tell so.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef vector<vector<int>> Graph;
typedef vector<string> VS;
typedef vector<int> VI;

void task_ordering(const Graph& g, VI& ge, map<string,int> pos_name, const VS& name, VS& order) {
    priority_queue<string, vector<string>, greater<string>> PQ; //PQ smaller -> bigger
    int n = g.size();

    for(int i = 0; i < n; ++i) {
        if(ge[i] == 0) PQ.push(name[i]);
    }
    //now the PQ has the tasks that can already be done (ordered lexicographically)
    while(not PQ.empty()) {
        string u = PQ.top();
        PQ.pop();
        order.push_back(u);
        for (int v: g[pos_name[u]]) {
            --ge[v];
            if(ge[v] == 0) PQ.push(name[v]);
        }
    }
}

int main() {
    int n;
    
    while (cin >> n) {
        VS name(n); //vertices
        map<string,int> pos_name; //associates a number to each vertice
        string x;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            name[i] = x;
            pos_name.insert({x,i}); //pos_name[s] = i
        }

        int m;
        cin >> m;
        Graph g(n);
        string y;
        VI ge(n,0); //grados de entrada

        for(int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[pos_name[x]].push_back(pos_name[y]);
            ++ge[pos_name[y]];
        }

        VS order;
        task_ordering(g, ge, pos_name, name, order);

        if (int(order.size()) != n) cout << "NO VALID ORDERING" << endl;
        else {
            for(string s: order) cout << s;
            cout << endl;
        }
    }
}