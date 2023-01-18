/* In this problem, we say that a vector with n integer numbers v [0.. n − 1] is bi-increasing if n ≥ 2, v[0] > v[n − 1], and there exists an 
index j between 0 and n − 2 such that:
  • v[0] ≤ . . . ≤ v[j − 1] ≤ v[j],
  • v[j + 1] ≤ v[j + 2] ≤ . . . ≤ v[n − 1].
For instance, the vector [12, 12, 15, 20, 1, 3, 3, 5, 9] is bi-increasing (with j = 3).

Implement an efficient function
      bool search (int x, const vector <int>& v);

such that, given an integer number x and a bi-increasing vector v, returns if x is in v or not. You can use and implement auxiliary functions 
if you need them.

Precondition
The vector v is bi-increasing.

Observation
You only need to submit the required procedure; your main program will be ignored.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool iSearch(int x, int l, int r, const vector<int>& v) {
    if (l+1 == r) return v[l] == x or v[r] == x;
    int m = (l+r)/2;
    if (v[m] >= v[l]) {
        if (v[l] <= x and v[m] >= x) return binary_search(v.begin()+l, v.begin()+m+1, x);
        else return iSearch(x, m, r, v);
    }
    else {
        if (v[m] <= x and v[r] >= x) return binary_search(v.begin()+m, v.begin()+r+1, x);
        else return iSearch(x,l,m,v);
    }
}

bool search(int x, const vector<int>& v) {
    return iSearch(x, 0, int(v.size())-1, v);
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}