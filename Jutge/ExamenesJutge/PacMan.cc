/* Given a rectangular board with a Pac-Man, tell if Pac-man can eat any power pellet. To get there, Pac-Man can only move 
horizontally and vertically, never crossing a wall. Moreover, Pac-Man can never be too close to a ghost. 
There should always be a cell between them, either horizontally, vertically, or diagonally. Look at the input and output examples.

Input
Input consists of several cases. Every case begins with the number of rows r and the number of columns c of the board. 
Follow r rows with c characters each. A ‘P’ indicates the initial position of Pac-Man. An ‘F’ indicates the position of a ghost 
(that does not move). A ‘B’ indicates the position of a pellet. An ‘X’ indicates a wall. A dot indicates an empty position. 
Assume 3 ≤ r ≤ 100 and 3 ≤ c ≤ 100, that the rows and columns on the edge of the board only have walls, and that each board 
has exactly one ‘P’.

Output
For every case, tell if Pac-man can eat any pellet or not.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VBB;

typedef vector<char> VC;
typedef vector<VC> Graph;

struct Pos {
    int x;
    int y;
};

const vector<Pos> DIRS = {{1,0}, {-1,0}, {0,1}, {0,-1}};
const vector<Pos> DIRS_GHOST = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

bool posOk (Pos p, const Graph& G) {
    return (p.x >= 0 and p.x < int(G.size()) and p.y >= 0 and p.y < int(G[0].size()));
}

bool nearGhost (Pos p, const Graph& G) {
    for (Pos d: DIRS_GHOST) {
        Pos next = {p.x + d.x, p.y + d.y};
        if (posOk(next, G) and G[next.x][next.y] == 'F') return true; 
    }
    return false;
}

bool bfs (Pos p, const Graph& G) {
    VBB visited(int(G.size()), VB(int(G[0].size()), false));

    queue<Pos> q;
    q.push(p);
    visited[p.x][p.y] = true;
    if (nearGhost(p,G)) return false;

    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        if (G[act.x][act.y] == 'B') return true;
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (posOk(next, G) and not nearGhost(next,G) and not visited[next.x][next.y] and G[next.x][next.y] != 'X') {
                q.push(next);
                visited[next.x][next.y] = true;
            } 
        }
    }
    return false;
}

int main () {
    int r, c;
    while (cin >> r >> c) {
        Graph G(r, VC(c));
        Pos pacMan;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> G[i][j];
                if(G[i][j] == 'P') pacMan = {i,j};
            }
        }
        if (bfs(pacMan, G)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}