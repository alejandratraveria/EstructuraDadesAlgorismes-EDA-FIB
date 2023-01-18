/* Consider a chess board with n rows (indexed 0, 1, …, n−1 from top to bottom) and m columns (indexed 0, 1, …, m−1 from left to right). 
Each position of the board is determined by a pair (r, c), where r is the index of the row and c is the index of the column.

Let us define the following game. We begin with a knight (see the figure to recall how it moves) at the upper left corner. Given a sequence 
of goal positions of the board p1, p2, ..., pk, we have to move the knight to goal position p1 doing knight jumps; from there we have to get 
to goal position p2, doing knight jumps; and so on until getting to the last goal position pk. For each goal we reach, we get W points. 
But for each knight jump we do, we lose L points. The match is over when the next goal position cannot be reached, or we decide to stop moving. 
What is the maximum score that we can get if we play optimally?

Input
Input contains different cases, only with integer numbers. Each case starts with n and m, followed by W and L. Finally, we have k and the k 
goal positions represented by pairs of integers ri ci separated by blank spaces, where 0 ≤ ri < n and 0 ≤ ci < m. It holds that 2 ≤ n, m ≤ 5000, 
that n · m ≤ 104, that 1 ≤ W, L ≤ 100 and that 1 ≤ k ≤ min(n · m, 1000).

Output
For each case, write in a line the maximum score that can be achieved if we play optimally.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
    int x;
    int y;
};

typedef vector<bool> VB;
typedef vector<VB> VBB;

typedef vector<int> VI;
typedef vector<VI> VII;

const vector<Pos> DIRS = {{2,1}, {2,-1}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {-1,-2}, {-1, 2}};

bool posOk(int n, int m, const Pos& p) {
    return p.x >= 0 and p.x < n and p.y >= 0 and p.y < m;
}

int bfsKnightGame (int n, int m, const Pos& ini, Pos& end) {
    queue<Pos> q;
    VII dists(n,VI(m, 0));
    VBB visited(n, VB(m, false));

    q.push(ini);
    visited[ini.x][ini.y] = true;
    while (not q.empty()){
        Pos act = q.front ();
        q.pop ();
        if (act.x == end.x and act.y == end.y) return dists[act.x][act.y];
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (posOk(n, m, next) and not visited[next.x][next.y]) {
                q.push(next);
                dists[next.x][next.y] = dists[act.x][act.y] + 1;
                visited[next.x][next.y] = true;
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int W, L, p;
        cin >> W >> L >> p;
        vector<Pos> pos(p+1);
        pos[0] = {0,0};
        for (int i = 1; i <= p; ++i) {
            int r, c;
            cin >> r >> c;
            pos[i] = {r, c};
        }
        
        int points = 0;
        int bestPoints = 0;
        bool stop = false ;
        for (int i = 0; not stop and i < p; ++i) {
            int dist = bfsKnightGame(n, m, pos[i], pos[i+1]);
            if (dist == -1) stop = true;
            else {
                points += W;
                points -= L*dist ;
                if (points > bestPoints) bestPoints = points ;
            }
        }
        cout << bestPoints << endl;
    }
}
