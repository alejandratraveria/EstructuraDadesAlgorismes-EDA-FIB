#include <iostream>
#include <vector>
using namespace std;

bool resistant_search_rec(double x, const vector<double>& v, int l, int r) {
    if (l > r) return false;
    int m = (l+r)/2;
    if (v[m] == x) return true;
    else if (v[m] < x) {
        if (m-1 >= 0 and v[m-1] == x) return true;
        return resistant_search_rec(x, v, m+1, r);
    }
    else { //v[m] > x
        if (m+1 <= r and v[m+1] == x) return true;
        return resistant_search_rec(x, v, l, m-1);
    }
}

bool resistant_search(double x, const vector<double>& v) {
    return resistant_search_rec(x, v, 0, v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}