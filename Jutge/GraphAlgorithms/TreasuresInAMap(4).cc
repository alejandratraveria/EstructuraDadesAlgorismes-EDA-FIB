/* Write a program that, given a map with treasures and obstacles, computes the distance from a given initial position 
to the furthest accessible treasure. The allowed movements are horizontal or vertical, but not diagonal. 
If needed, passing over the treasures is allowed.

Input begins with the number of rows n > 0 and the number of columns m > 0 of the map. Follow n rows with m characters each. 
A dot indicates an empty position, an ‘X’ indicates an obstacle, and a ‘t’ indicates a treasure. 
Finally, two numbers r and c indicate the initial row and column (both of them starting at 1) where we must start looking for treasures. 
You can assume that r is between 1 and n, that c is between 1 and m, and that the initial position is always empty.

Print the minimum number of steps to reach the furthest treasure from the initial position. If no treasure is accessible, tell so.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Board;
typedef pair<int, int> pos;
typedef pair<pos,int> DP;

vector<pos> dir = {{-1,0},{0,1},{1,0},{0,-1}};

bool valid_pos(int i, int j, int n, int m) {
  return (i >= 0 and j >=0 and i < n and j < m);
}

int bfs_treasure(Board& b, int n, int m, int r, int c) {
    queue<DP> Q;
    Q.push({{r,c}, 0});
    int dist_max = 0; 
    
    while(not Q.empty()) {
        DP act = Q.front();
        Q.pop();
        for(int i = 0; i < 4; ++i) {
            int x_seg = act.first.first + dir[i].first;
            int y_seg = act.first.second + dir[i].second;

            if(valid_pos(x_seg, y_seg, n, m) and b[x_seg][y_seg] != 'X') {
                if(b[x_seg][y_seg] == 't') {
                    if(dist_max < act.second + 1) dist_max = act.second + 1;
                }
                b[x_seg][y_seg] = 'X';
                Q.push({{x_seg, y_seg}, act.second + 1});
            }
        }
    }
    return dist_max; 
}

int main() {
    int n, m;
    cin >> n >> m;
    Board b(n, vector<char>(m));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> b[i][j];

    int r, c;
    cin >> r >> c;
    int dist = bfs_treasure(b, n, m,r-1,c-1);
    
    if(dist == 0) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << dist << endl;
}
