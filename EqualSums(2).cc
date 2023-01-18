#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp (int a, int b) {
    return a > b;
}

void write(const vector<int>& v, const vector<bool>& vist) {
    cout << "{";
    bool first = true;
    for (int i = 0; i < vist.size(); ++i) {
        if (vist[i]) {
            if (first) {
                first = false;
                cout << v[i];
            }
            else cout << "," << v[i];
        }
    }
    cout << "}" << endl;
}

void rec(const vector<int>& v, vector<bool>& vist, bool& trb, int s, int n, int i, int cont) {
    if (i == n) {
        if (s == cont) {
            trb = true;
            write(v,vist);
        }
    }    
    else {
        vist[i] = true;
        rec(v,vist,trb,s,n,i+1,cont+v[i]);
        if (not trb) {
            vist[i] = false;
            rec(v,vist,trb,s,n,i+1,cont);
        }
    }
}


int main() {
    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    vector<bool> vist(n, false);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    
    bool tr = false;
    rec(v, vist, tr, s, n, 0, 0);
    if (not tr) cout << "no solution" << endl;
}