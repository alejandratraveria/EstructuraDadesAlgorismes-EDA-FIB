//Farmers
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
    int x;
    int y;
};

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<bool> VB;
typedef vector<VB> VVB;

typedef vector<Pos> VP;
typedef vector<VP> VVP;

const vector<Pos> DIRS = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int n, m;

void write(Pos k, Pos end, const VVP& path) {
    VP res;
    Pos aux = end;
    while (aux.x != -1 and aux.y != -1) {
        res.push_back(aux);
        aux = path[aux.x][aux.y];
    } 

    cout << res.size();
    for (int i = int(res.size()-1); i >= 0; --i) cout << "  " << res[i].x << ' ' << res[i].y;
    cout << endl;
}

void bfsFarmer(Pos k, VVC& M) {
    queue<Pos> q;
    VVP path(n, VP(m,{-1,-1}));
    bool found = false;

    q.push(k);
    M[k.x][k.y] = 'X';
    while (not found and not q.empty()) {
        Pos act = q.front();
        q.pop();

        for (auto d: DIRS) {
            Pos next = {act.x+d.x, act.y+d.y};
            if (not found and M[next.x][next.y] == 'F') {
                path[next.x][next.y] = act;
                write(k,next,path);
                found = true;
            }
            else if (M[next.x][next.y] != 'X') {
                q.push(next);
                M[next.x][next.y] = 'X';
                path[next.x][next.y] = act;
            }
        }
    }
    if (not found) cout << 0 << endl;
}

int main() {
    while (cin >> n >> m) {
        VVC M(n, VC(m));
        Pos k; //cavallero
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> M[i][j];
                if(M[i][j] == 'K') k = {i,j};
            }
        } 
        bfsFarmer(k,M);
    }
}