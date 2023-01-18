/* We have collected abundant information about the local roads and accommodations in a region that we will traverse. Our plan is to go from 
city A to city B and we would like to spend the least possible money. For each road connecting two cities u and v we know the cost ω(u,v)=ω(v,u) 
to travel along that road (tolls, fuel, meals during the journey, …). Every time we go from a city u to one of its neighbors v we must stop at 
v and spend there one night; we know the cost ω′(v) of stopping at each city v (the cost added by A and B to our route is 0, since they are our 
initial and final points). All costs, of vertices and of edges, are positive. Thus the cost of the route P = [A, v1, …, vn, B] is
cost(P) = ω(A,v1) + ω(v1,v2) + … + ω(vn,B)  + ω′(v1)+…+ω′(vn).

Write a program in C++ which, given an undirected weighted graph with positive costs at the vertices and at the edges, and two vertices A and B, 
returns the cost of the cheapest route to go from A to B, or an indication that not such route exists.

Input 
All data in the input are positive integers. The input starts with two integers 2≤n≤10000 and m, 0≤m≤20n. After that, a sequence of positive 
integers ω′(0), …, ω′(n−1) of the weights ω′(u) of the n vertices of the graph. Then the input contains a sequence of the m edges in the graph 
as triplets of the form ⟨u,v,ω(u,v)⟩. Vertices u and v are integers in {0,…,n−1} and the weights ω(u,v) are positive integers. No weight, 
of edges or vertices, is larger than 100000.

You can assume that there are no two different edges connecting the same pair of vertices nor any edge connecting a vertex to itself. Finally, 
there is a sequence of pairs ⟨Ai, Bi⟩, with each Ai and Bi denoting vertices of the graph (0≤Ai,Bi<n).

Output 
For each pair ⟨Ai, Bi⟩ in the input sequence the program writes the cost δ of the cheapest route between Ai and Bi. with the format c(Ai,Bi) = δ. 
If no route exists between Ai and Bi the program writes c(Ai,Bi) = +oo. The ouput for each case is ended with a newline (endl).
*/
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int inf = numeric_limits<int>::max();

typedef map<int,int> M;

typedef vector<int> VI; 
typedef vector<bool> VB;

typedef pair<int,int> WArc; //first->cost, second->vertice
typedef vector<WArc> VW;
typedef vector<VW> Graph;

int dijkstra(int n, int start, int end, M& vertices, const Graph& G) {
    priority_queue<WArc, vector<WArc>, greater<WArc>> pq;
    VB visited(n, false);
    VI dist(n, inf);

    pq.push({0,start});
    dist[start] = 0;
    while (not pq.empty()) {
        WArc act = pq.top();
        pq.pop();

        if (not visited[act.second]) {
            visited[act.second] = true;
            if (act.second == end) {
                auto it = vertices.find(act.second);
                int wact = it->second;
                if (dist[act.second] - wact < 0) return 0;
                else return dist[act.second] - wact;
            }
            for (WArc next: G[act.second]) {
                auto it = vertices.find(next.second);
                int w = it->second;
                int d = next.first;
                if (dist[next.second] > dist[act.second] + d + w) {
                    dist[next.second] = dist[act.second] + d + w;
                    pq.push({dist[next.second], next.second});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    M vertices; //key->vertice, second->weight
    //se podia usar un vector de costes donde i era el vertice y v[i] el coste!!
    //al usar un map podrian restarme por eficiencia
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        vertices[i] = w;
    }
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        G[x].push_back({c, y});
        G[y].push_back({c, x});
    }
    int start, end;
    while (cin >> start >> end) {
        int cost = dijkstra(n, start, end, vertices, G);
        if (cost != -1) cout << "c(" << start << ',' << end << ") = " << cost << endl;
        else cout << "c(" << start << ',' << end << ") = +oo" << endl;
    }
}

