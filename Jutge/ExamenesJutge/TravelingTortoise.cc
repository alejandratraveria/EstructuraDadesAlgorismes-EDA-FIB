/* Find all the paths that a tortoise can travel from an initial position to a final position. The ground has n × m paving stones, each 
one with a letter painted on it. The tortoise can only make horizontal and vertical movements, and it cannot pass by the same position twice.

Input
Input begins with n and m, followed by n lines with m letters each. Follow a pair of natural numbers indicating the initial row and column, 
and a pair of naturals numbers indicating the final row and column. The upper-left corner corresponds to the position (0, 0).

Output
Print all the paths from the initial position to the final position.
Information about the checker

You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Pos {
    int x;
    int y;
};

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<bool> VB;
typedef vector<VB> VVB;

const vector<Pos> DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void write(VC& res) {
    for (char c: res) cout << c;
    cout << endl;
}

bool posOk(int n, int m, Pos& p) {
    return p.x >= 0 and p.x < n and p.y >= 0 and p.y < m;
}

void rec(int n, int m, Pos act, const Pos end, VVB& visited, VC& res, const VVC& board) {
    if (act.x == end.x and act.y == end.y) write(res); 
    else {
        for (Pos d: DIRS) {
            Pos next = {act.x+d.x, act.y+d.y};
            if (posOk(n,m,next) and not visited[next.x][next.y]) {
                res.push_back(board[next.x][next.y]);
                visited[next.x][next.y] = true;
                rec(n,m,next,end,visited,res,board);
                res.pop_back();
                visited[next.x][next.y] = false;
            } 
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    VVC board(n, VC(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    Pos start, end;
    cin >> start.x >> start.y >> end.x >> end.y;

    VC res;
    VVB visited(n, VB(m, false));
    visited[start.x][start.y] = true;
    res.push_back(board[start.x][start.y]);
    rec(n, m, start, end, visited, res, board);
}