/* Write a program that, given a map with treasures and obstacles, computes the number of treasures that can be reached from a 
given initial position. The allowed movements are horizontal or vertical, but not diagonal. If needed, passing over the treasures is allowed.

Input
Input begins with the number of rows n > 0 and the number of columns m > 0 of the map. Follow n rows with m characters each. 
A dot indicates an empty position, an ‘X’ indicates an obstacle, and a ‘t’ indicates a treasure. Finally, two numbers r and c 
indicate the initial row and column (both of them starting at 1) where we must start looking for treasures. You can assume that 
r is between 1 and n, that c is between 1 and m, and that the initial position is always empty.

Output
Print the number of accessible treasures from the initial position.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
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

int bfsNumTreasures(int n, int m, const Pos& ini, const Board& Map) {
    int num = 0;
    queue<Pos> q;
    VBB visited(n, VB(m, false));

    q.push(ini);
    visited[ini.x][ini.y] = true;

    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        if (Map[act.x][act.y] == 't') ++num;
        
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (posOk(next, Map) and not visited[next.x][next.y] and Map[next.x][next.y] != 'X') {
                q.push(next);
                visited[next.x][next.y] = true;
            }
        }
    }
    return num;
}

int main() {
    int n, m;
    cin >> n >> m;

    Board Map(n, VC(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> Map[i][j];
        }
    }

    Pos ini;
    cin >> ini.x >> ini.y;
    ini = {ini.x - 1, ini.y - 1};
    int numTreasures = bfsNumTreasures(n, m, ini, Map);
    cout << numTreasures << endl;
}