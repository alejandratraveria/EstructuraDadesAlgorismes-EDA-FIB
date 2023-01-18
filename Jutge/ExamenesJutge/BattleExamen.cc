#include <iostream>
#include <vector>
using namespace std;

struct Pos {
    int x;
    int y;
};

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef vector<char> VC;
typedef vector<VC> VVC;

const vector<Pos> DIRS = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int n, s;

bool posOk(Pos p) {
    return p.x >= 0 and p.x < n and p.y >= 0 and p.y < n;
}

void write(VVC& res) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) cout << res[i][j];
            else cout << ' ' << res[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool adj(Pos p, VVC& res) {
    for (Pos d: DIRS) {
        Pos next = {p.x+d.x, p.y+d.y};
        if (posOk(next) and res[next.x][next.y] == '*') return true;
    }
    return false;
}

void rec(int i, int j, int count, VI& blocks, VI& cols, const VVI& grid, VVC& res) {
    if (i == n) write(res);
    else {
        if (cols[j] < s and blocks[grid[i][j]-1] < s and not adj({i,j}, res)) {
            cols[j] += 1;
            blocks[grid[i][j]-1] += 1;
            res[i][j] = '*';

            if (j < n-1 and count != s - 1) rec(i, j+1, count+1, blocks, cols, grid, res);
            else if (count == s -1) rec(i+1, 0, 0, blocks, cols, grid, res);

            cols[j] -= 1;
            blocks[grid[i][j]-1] -= 1;
            res[i][j] = '-';
        }
        if (j < n-1) rec(i, j+1, count, blocks, cols, grid, res);
    }
}

int main() {
    while (cin >> n >> s) {
        VVI grid(n, VI(n));
        VI blocks; //number of starts for each block;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] > int(blocks.size())) blocks.push_back(0);
            }
        }

        VI cols(n,0);
        VVC res(n, VC(n, '-'));
        rec(0,0,0,blocks,cols,grid,res);
    }
}