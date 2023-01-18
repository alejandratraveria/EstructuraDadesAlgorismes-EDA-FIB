/* Un cavall es troba sobre un tauler d’escacs. El cavall només es pot moure segons les regles habituals 
(és a dir, modificant en dues unitats una de les seves coordenades, i en una unitat l’altra coordenada, 
per a un total de vuit possibles moviments), sempre que no surti del tauler ni visiti cap casella amb un obstacle. 
Quin és el mínim nombre de passos que ha de fer per arribar a una pastanaga?

Entrada
L’entrada consisteix en diversos casos. Cada cas comença amb el nombre de files f i el nombre de columnes c del tauler. 
Tant f com c estan entre 3 i 200. Segueixen f files amb c caràcters cadascuna. Una ‘p’ indica una pastanaga, una ‘X’ indica un obstacle, 
i un punt indica una posició lliure. Cada cas acaba amb la posició (fila i columna) inicial del cavall. La casella més a l’esquerra de la 
primera fila és la (1, 1). La posició inicial sempre està lliure.

Sortida
Per a cada cas, si el cavall pot arribar a alguna pastanaga, escriviu el mínim nombre de passos. Altrament, escriviu “no”.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VBB;

typedef vector<int> VI;
typedef vector<VI> VII;

typedef vector<char> VC;
typedef vector<VC> Graph;

struct Pos {
    int x;
    int y;
};

const vector<Pos> DIRS = {{2,1}, {2,-1}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {-1,-2}, {-1, 2}};

bool posOk (Pos p, const Graph& G) {
    return (p.x >= 0 and p.x < int(G.size()) and p.y >= 0 and p.y < int(G[0].size()));
}

int bfs (Pos p, const Graph& G) {
    VBB visited(int(G.size()), VB(int(G[0].size()), false));
    VII dists(int(G.size()), VI(int(G[0].size()), 0));

    queue<Pos> q;

    q.push(p);
    visited[p.x][p.y] = true;
    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        if(G[act.x][act.y] == 'p') return dists[act.x][act.y];
        for(Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if(posOk(next, G) and not visited[next.x][next.y] and G[next.x][next.y] != 'X') {
                q.push(next);
                visited[next.x][next.y] = true;
                dists[next.x][next.y] = dists[act.x][act.y] + 1;
            }
        }
    }
    return -1;
}

int main () {
    int f, c;
    while(cin >> f >> c) {
        Graph G(f, VC(c));
        for(int i = 0; i < f; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> G[i][j];
            }
        }
        Pos cavall;
        cin >> cavall.x >> cavall.y;
        cavall = {cavall.x-1, cavall.y-1};
        int steps = bfs(cavall, G);
        if(steps != -1) cout << steps << endl;
        else cout << "no" << endl;
    }
}