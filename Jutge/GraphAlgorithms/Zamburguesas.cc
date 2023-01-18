/* The Lake of the Dragon God is one of the most mythical challenges of the contest. A river must be crossed by jumping from rock to rock, 
but be careful! Some rocks are fake and sink!

There are n true rocks, all round, with centre (xi, yi) and radius ri. The maximum distance that a contestant can jump is d (measuring it 
from the border of the rocks). Your task is to compute the minimum number of jumps to go from the first rock to the last one without falling 
into the water. If it is impossible, state so.

Input
Input consists of several cases. Each case starts with the number of rocks n ≥ 2 and the jump distance d > 0. Follow n triples of real 
numbers xi, yi and ri, describing each rock.

Output
For each case of the input, print in a line the minimum number of jumps to go from the first of the given rocks to the last one, by making 
jumps non larger than d, or “Xof!” if it is impossible.

Observations
The test cases will never contain overlapped rocks, nor any exact jump that could cause an error because of precision issues.
The picture shows the rocks of the sample test cases.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Rock{
    double x;
    double y;
    double r; 
};

typedef vector<int> VI;
typedef vector<Rock> Lake;

bool jumpOk(const Rock& a, const Rock& b, double d) {
    return sqrt((pow(b.x - a.x, 2)) + (pow(b.y -a.y, 2))) - a.r - b.r <= d;
}

int bfsZamburguesas(int n, double d, Lake& lake) {
    queue<int> q;
    VI jump(n, -1);

    q.push(0);
    jump[0] = 0;
    while (not q.empty()) {
        int act = q.front();
        q.pop();
        if (act == n-1) return jump[act];
        for (int i = 0; i < n; ++i) {
            if (jump[i] == -1 and jumpOk(lake[i], lake[act], d)) {
                q.push(i);
                jump[i] = jump[act] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    double d;
    while (cin >> n >> d) {
        Lake lake(n);
        for (int i = 0; i < n; ++i) {
            Rock r;
            cin >> r.x >> r.y >> r.r;
            lake[i] = r;
        }
        int jumps = bfsZamburguesas(n, d, lake);
        if (jumps == -1) cout << "Xof!" << endl;
        else cout << jumps << endl;
    }
}