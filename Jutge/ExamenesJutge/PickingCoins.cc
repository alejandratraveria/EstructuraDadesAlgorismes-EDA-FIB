/* In a n × m board there are golden coins and some traps. There are also some pieces: bishops and knights, which move according to chess rules. 
The pieces can move as many times as you wish, and can cross any square that does not have a trap, even if occupied by another piece. 
Coins dissapear when some piece picks them up.

Write a program that prints the total number of coins that can be picked up.

Input
Input includes several cases. Each case consists of a line with n and m, followed by n lines with m characteres each one. A ‘B’ indicates a 
bishop. A ‘K’ indicates a knight. A ‘T’ indicates a trap. A dot indicates an empty square. A digit indicates a number of golden coins. Both n and m are between 1 and 200.

Output
For each case, print a line with the number of golden coins that can be picked up.
*/
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

const vector<Pos> DIRS_B = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};
const vector<Pos> DIRS_K = {{1,2}, {2,1}, {-1,2}, {-2,1}, {1,-2}, {2,-1}, {-1,-2}, {-2,-1}};

bool posOk(int n, int m, Pos p) {
    return p.x >= 0 and p.x < n and p.y >= 0 and p.y < m;
}

int bfsPickCoins(int n, int m, Pos& ini, VVC& board, VVB& visited, bool knight) {
    if (visited[ini.x][ini.y]) return 0;
    int sum = 0;
    queue<Pos> q;
    
    q.push(ini);
    visited[ini.x][ini.y] = true;
    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        
        if (board[act.x][act.y] >= '0' and board[act.x][act.y] <= '9') {
            sum += (board[act.x][act.y] - '0');
            board[act.x][act.y] = '.';
        }

        vector<Pos> DIRS;

        if (knight) DIRS = DIRS_K;
        else DIRS = DIRS_B;

        for (Pos d: DIRS) {
            Pos next = {act.x+d.x, act.y+d.y};
            if (posOk(n,m,next) and not visited[next.x][next.y] and board[next.x][next.y] != 'T') {
                q.push(next);
                visited[next.x][next.y] = true;
            }
        }
    }
    return sum;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVC board(n, VC(m));
        vector<Pos> bishops;
        vector<Pos> knights;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
                if (board[i][j] == 'B') bishops.push_back({i,j});
                if (board[i][j] == 'K') knights.push_back({i,j});
            }
        }

        VVB visitedB(n, VB(m, false));
        int sumB = 0;
        for (Pos b: bishops) {
            sumB += bfsPickCoins(n, m, b, board, visitedB, false);
        }
        VVB visitedK(n, VB(m, false));
        int sumK = 0;
        for (Pos k: knights) {
            sumK += bfsPickCoins(n, m, k, board, visitedK, true);
        }
        cout << sumB+sumK << endl;
    }
}