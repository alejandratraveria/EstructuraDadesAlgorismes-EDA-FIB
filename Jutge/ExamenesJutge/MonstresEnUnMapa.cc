/* Feu un programa que, donats un mapa amb monstres, i unes posicions inicial i final, digui si és possible anar de l’una a 
l’altra només amb moviments horitzontals i verticals, i mantenint sempre una casella de distància amb els monstres.

Entrada
L’entrada consisteix en diversos casos. Cadascun comença amb el nombre de files n > 0 i el nombre de columnes m > 0 del mapa. 
Segueixen n files amb m caràcters cadascuna. Un punt indica una posició buida. Una ‘M’ indica un monstre. La posició inicial 
s’indica amb ‘I’, y la posició final amb ‘F’. Sempre n’hi ha exactament una de cada, i en posicions no amenaçades per cap monstre.

Sortida
Per a cada cas, escriviu “SI” o “NO” depenent de si és possible o no arribar a la posició final des de la posició inicial.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
    int x;
    int y;
};

typedef vector<char> VC;
typedef vector<VC> Board;

typedef vector<bool> VB;
typedef vector<VB> VBB;

const vector<Pos> DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool posOk(const Pos& p, const Board& Map) {
    return p.x >= 0 and p.x < int(Map.size()) and p.y >= 0 and p.y < int(Map[0].size());
}

bool monsters(const Pos& act, const Board& Map) {
    for (Pos d: DIRS) {
        Pos next = {act.x + d.x, act.y + d.y};
        if (posOk(next, Map) and Map[next.x][next.y] == 'M') return true;
    }
    return false;
}

bool bfsPath(int n, int m, const Pos& ini, const Board& Map) {
    VBB visited(n, VB(m));
    queue<Pos> q;
    q.push(ini);
    visited[ini.x][ini.y] = true;

    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        if (Map[act.x][act.y] == 'F') return true;
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (posOk(next, Map) and not monsters(next, Map) and not visited[next.x][next.y] and Map[next.x][next.y] != 'M') {
                q.push(next);
                visited[next.x][next.y] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Board Map(n, VC(m));
        Pos ini;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> Map[i][j];
                if (Map[i][j] == 'I') ini = {i,j};
            }
        }
        if(bfsPath(n, m, ini, Map)) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}