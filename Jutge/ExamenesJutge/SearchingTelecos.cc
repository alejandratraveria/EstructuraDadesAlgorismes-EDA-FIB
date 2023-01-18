/* Write a program to search for someone called “the telecos” on a given rectangular grid.

Input
Input has several cases. Each case begins with two numbers n and m between 1 and 100. Follow n 
lines with m characters each: a dot indicates a free cell, a ‘P’ indicates a person, a ‘#’ indicates a wall, 
and a ‘T’ indicates the telecos. The search must always begin from the upper-left cell (which never has a wall), 
and there is at most one telecos on the grid.

Output
For every case, if it is possible to reach the telecos, print the minimum number of steps to do so, and also 
the maximum number of persons that can be met in a path to the telecos with the minimum lenght. You can make 
horizontal and vertical movements, never leaving the grid. If the telecos is not in the grid, or if he is not 
reachable, tell so.
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

typedef vector<int> VI;
typedef vector<VI> VII;

const vector<Pos> DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool posOk(const Pos& p, const Board& Grid) {
    return p.x >= 0 and p.x < int(Grid.size()) and p.y >= 0 and p.y < int(Grid[0].size());
}

pair<int,int> bfsSearchTelecos(int n, int m, const Pos& ini, const Board& Grid) {
    queue<Pos> q;
    VBB visited(n, VB(m));
    VII path(n, VI(m, 0));
    VII people(n, VI(m,0));

    q.push(ini);
    visited[ini.x][ini.y];
    if (Grid[ini.x][ini.y] == 'P') people[ini.x][ini.y] = 1;
    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        if (Grid[act.x][act.y] == 'T') return {path[act.x][act.y], people[act.x][act.y]};
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            int dist = path[act.x][act.y] + 1;
            if (posOk(next, Grid) and Grid[next.x][next.y] != '#') {
                int numPeople = people[act.x][act.y] + int(Grid[next.x][next.y] == 'P');
                if (not visited[next.x][next.y]) {
                    q.push(next);
                    visited[next.x][next.y] = true;
                    path[next.x][next.y] = path[act.x][act.y] + 1;
                    people[next.x][next.y] = numPeople;
                }
                else if (path[next.x][next.y] == dist and people[next.x][next.y] < numPeople) {
                    people[next.x][next.y] = numPeople;
                }    
            }
        }
    }
    return {-1,-1};
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Board Grid(n, VC(m));
        bool exists = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> Grid[i][j];
                if (Grid[i][j] == 'T') exists = true;
            }
        }
        if (not exists) cout << "The telecos ran away." << endl;
        else {
            Pos ini = {0,0};
            
            pair<int,int> pathPeople = bfsSearchTelecos(n, m, ini, Grid);
            if (pathPeople.first != -1) cout << pathPeople.first << ' ' << pathPeople.second << endl;
            else cout << "The telecos is hidden." << endl;
        }
    }
}