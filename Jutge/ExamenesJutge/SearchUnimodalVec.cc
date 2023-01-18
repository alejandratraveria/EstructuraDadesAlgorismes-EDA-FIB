/* In this problem, we say that a vector with n integer numbers v[0..n−1] is unimodal if n ≥ 1, and there exists an index j such that 0 ≤ j ≤ n−1 
and satisfying:

    v[0] < … < v[j−1] < v[j], and
    v[j] > v[j+1] > v[j+2] > … > v[n−1]. 

For instance, the vector [0, 2, 5, 7, 6, 5, 4, 3, 1] is unimodal (with j = 3).
Note that vectors with n ≤ 2 different elements are unimodal. In general, note that any strictly increasing vector is also unimodal (and in all 
cases j = n−1), and analogously, any strictly decreasing vector is also unimodal (and then j = 0).

Implement an efficient function
     bool search(int x, const vector<int>& v);

such that, given an integer number x and a unimodal vector v, returns true if x appears in v, and false otherwise. You can use and implement 
auxiliary functions if you need them.

Precondition
The vector v is unimodal.

Observation You only need to submit the required procedure; your main program will be ignored. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int top(const vector<int>& v, int l , int r) {
    if (l + 1 >= r) {
        if (v[l] < v[r]) return r; 
        else return l;
    }

    int m = (l+r)/2;
    if (v[m-1] > v[m]) return top(v, l , m-1);
    if (v[m+1] > v[m]) return top(v, m+1, r);
    return m;
}

bool binSearch (bool inc, const vector<int>& v, int l , int r , int x) {
    if (l == r) return v[l] == x;

    int m = (l+r)/2;
    bool cond;
    if (inc) cond = (x <= v[m]);
    else cond = (x >= v[m]);
    if (cond) return binSearch(inc, v, l, m, x);
    else return binSearch(inc, v, m+1, r, x);
}

bool search (int x, const vector<int>& v) {
    int n = v. size ();
    int t = top (v, 0, n-1);
    return binSearch(true, v, 0, t , x) or binSearch (false , v, t , n-1, x);
}