#include <iostream>
#include <vector>
using namespace std;

int fixed_points(const vector<int>& S, int a, int l, int r) {
    if (l > r) return -1;
    int m = (l+r)/2;
    if (S[m] + a < m+1) return fixed_points(S, a, m+1, r);
    else if (S[m] + a > m+1) return fixed_points(S, a, l, m-1);
    else {
        int point = fixed_points(S, a, l, m-1);
        if (point == -1) return m+1;
        return point;
    }
}

int main() {
	int n;
    int num = 1;
	while (cin >> n) {
		vector <int> S(n);
		for (int i = 0; i < n; ++i) cin >> S[i];
        int m;
		cin >> m;
		cout << "Sequence #" << num << endl;
		for (int i = 0; i < m; ++i) {
            int a;
			cin >> a;
			int fixed = fixed_points(S, a, 0, n-1);
			if (fixed != -1) cout << "fixed point for " << a << ": " << fixed << endl;
			else cout << "no fixed point for " << a << endl;
		}
		cout << endl;
		++num;
	}
}
