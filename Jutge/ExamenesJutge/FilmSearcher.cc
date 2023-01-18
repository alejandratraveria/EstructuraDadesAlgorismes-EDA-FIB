/* To make the days of lockdown more bearable, Professor Oak has signed up for an Internet TV platform. As the film catalogue is immense, 
the system provides a searcher that, by means of the remote control, allows one to look for films by their title. More precisely, the 
searcher displays on the TV screen a matrix with letters and a cursor on one of them, at the beginning that on the upper left corner. 
By means of the buttons ↑, ↓, → and ← of the remote control, one can move the cursor. Some of the cells of the matrix, however, cannot 
be selected (in the image, in red; in the test cases, with an asterisk *), and then the cursor cannot move in that direction. It is not 
possible to move beyond the top, bottom, right and left borders of the matrix either. Once the cursor is on the aimed letter, the OK button 
must be pressed.

Before checking whether a film is in the catalogue, Professor Oak wants to find out how many buttons he will have to press in order to insert 
the title into the searcher. Can you help him?

To adapt the problem to Jutge.org, from now on we will assume that the cells of the matrix can contain a word (viewed as a unit) instead 
of just a single letter, and that therefore what we insert into the searcher is a sequence of words, rather than a sequence of letters.

Input
The input contains several cases. Each case begins with n the number of rows and m the number of columns of the matrix of the searcher. 
Then n lines follow with m words each, separated by blank spaces. The words consisting of a single character * represent forbidden cells 
of the matrix. Except for *, which can be repeated, the rest of the words can only appear at most once. Then a number p follows, which is 
the number of words of the sequence we want to insert into the searcher. Finally the p words of the sequence follow, each of them different 
from *. Any word in the input is formed with upper case letters of the alphabet or underscore _, or is the word *. It holds that 1 ≤ n, 
m ≤ 300, 1 ≤ p ≤ min(2 · n · m, 1000), and that for each case the upper left corner does not contain the word *.

Output
For each case, write a line with the total number of times that a button of the remote control (↑, ↓, →, ← or OK) must be pressed so as to 
insert the p words of the sequence into the searcher. If it is not possible (because a word cannot be reached, or does not appear in the matrix), 
write impossible.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
    int x;
    int y;
};

typedef vector<string> VS;
typedef vector<VS> Matrix;

typedef vector<bool> VB;
typedef vector <VB> VBB;

typedef vector<int> VI;
typedef vector<VI> VII;

const vector<Pos> DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool posOk(const Pos& p, const Matrix& Searcher) {
    return p.x >= 0 and p.x < int(Searcher.size()) and p.y >= 0 and p.y < int(Searcher[0].size());
}

int bfsFilmSearcher(int n, int m, Pos& ini, string& end, const Matrix& Searcher) {
    queue<Pos> q;
    VBB visisted(n, VB(m, false));
    VII dists(n, VI(m, 0));
    
    q.push(ini);
    visisted[ini.x][ini.y] =  true;
    while (not q.empty()) {
        Pos act = q.front();
        q.pop();
        if (Searcher[act.x][act.y] == end) {
            ini = act;
            return dists[act.x][act.y] + 1;
        }
        for (Pos d: DIRS) {
            Pos next = {act.x + d.x, act.y + d.y};
            if (posOk(next, Searcher) and not visisted[next.x][next.y] and Searcher[next.x][next.y] != "*") {
                q.push(next);
                visisted[next.x][next.y] = true;
                dists[next.x][next.y] = dists[act.x][act.y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Matrix Searcher(n, VS(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> Searcher[i][j];
            }
        }
        int p;
        cin >> p;
        VS Film(p);
        for (int i = 0; i < p; ++i) {
            cin >> Film[i];
        }

        Pos ini = {0,0};
        int totalDist = 0;
        bool ok = true;
        for (int i = 0; ok and i < p; ++i) {
            int dist = bfsFilmSearcher(n, m, ini, Film[i], Searcher);
            if (dist == -1) ok = false;
            else totalDist += dist;
        }
        if (ok) cout << totalDist << endl;
        else cout << "impossible" << endl;
    }
}