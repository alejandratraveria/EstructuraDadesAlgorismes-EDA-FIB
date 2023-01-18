/* Consider an n × n board, where n is odd. From each cell, we can move to any of its (at most) four horizontally or vertically adjacent cells. 
For each cell, we have to pay a certain positive cost when we go through it. Compute the minimum cost of going from the center of the board to 
any cell on its periphery.

Input
Input consists of several cases, each with n, followed by an n × n matrix. You can assume that n is an odd number between 1 and 499, and that 
all costs are integer numbers between 1 and 1000.

Output
For every case, print the minimum cost to go from the middle of the board to any cell on the edge of the board.
*/
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

const int inf = numeric_limits<int>::max();

struct Pos{
    int x;
    int y;
};

typedef vector<bool> VB;
typedef vector<VB> VVB;

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef vector<VI> Board; 

const vector<Pos> DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}};

struct cmpIntPos {
    bool operator()(const pair<int,Pos>& p1, const pair<int,Pos>& p2) {
        return p1.first >= p2.first;
    }
};

bool posOk(Pos& p, const Board& board) {
    return p.x >= 0 and p.x < int(board.size()) and p.y >= 0 and p.y < int(board[0].size());
}

int dijkstra(int n, Pos& start, const Board& board) {
    priority_queue<pair<int,Pos>, vector<pair<int,Pos>>, cmpIntPos> pq;
    VVB visited(n, VB(n, false));
    VVI cost(n, VI(n,inf));

    pq.push({board[start.x][start.y], start});
    cost[start.x][start.y] = board[start.x][start.y];
    while (not pq.empty()) {
        Pos act = pq.top().second;
        pq.pop();

        if (not visited[act.x][act.y]) {
            visited[act.x][act.y] = true;
            if (act.x == 0 or act.x == n-1 or act.y == 0 or act.y == n-1) return cost[act.x][act.y];
            for (Pos d: DIRS) {
                Pos next = {act.x + d.x, act.y + d.y};
                int weightNext = board[next.x][next.y];
                if (posOk(next, board) and cost[next.x][next.y] > cost[act.x][act.y] + weightNext) {
                    cost[next.x][next.y] = cost[act.x][act.y] + weightNext;
                    pq.push({cost[next.x][next.y], next});
                }
            }
        }
    }
    return inf;
}

int main() {
    int n;
    while (cin >> n) {
        Board board(n, VI(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        Pos start = {n/2, n/2};
        cout << dijkstra(n, start, board) << endl; 
    }
}