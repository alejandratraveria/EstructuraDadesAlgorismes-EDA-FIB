#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

struct Pos {
    int x;
    int y;
};

const vector<Pos> DIRS = {{1,0}, {-1,0}, {0,1}, {0,-1}};
const vector<Pos> DIRS_GHOST = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

bool bfsBolet(Pos p, VVC& M) {
    queue<Pos> q;
    if (M[p.x][p.y] == 'X') return false;
    M[p.x][p.y] = 'X'; 
    q.push(p);

    while (not q.empty()) {
        Pos act = q.front(); 
        q.pop ();
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (M[next.x][next.y] == 'B' ) return true;
            if (M[next.x][next.y] != 'X') {
                M[next.x][next.y] = 'X';
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    int r, c;
    while (cin >> r >> c) {
        VVC M(r, VC(c));
        Pos p;
        queue<Pos> F;
        for (int i = 0; i < r ; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> M[i][j];
                if (M[i][j] == 'P') {
                    p.x = i;
                    p.y = j;
                }
                if (M[i][j] == 'F') F.push({i,j});
            }
        }

        while (not F.empty()) {
            int i = (F.front()).x;
            int j = (F.front()).y;
            F.pop();
            for (Pos d: DIRS_GHOST) M[i+d.x][j+d.y] = 'X';
        }

        if (bfsBolet(p,M)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}