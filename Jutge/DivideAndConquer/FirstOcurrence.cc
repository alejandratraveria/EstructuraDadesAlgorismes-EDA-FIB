#include <vector>
#include <iostream>
using namespace std;
/*
int first_occurrence_rec(double x, const vector <double>& v, int l, int r) {
	int pos = (l+r) / 2;
	if (l > r) return -1;
	if (x < v[pos]) return first_occurrence_rec(x, v, l, pos-1);
	else if (x > v[pos]) return first_occurrence_rec(x, v, pos+1, r);
	else {
		if (pos-1 >= 0) {
			int pos1 = first_occurrence_rec(x, v, l, pos-1);
			if (pos1 != -1) return pos1;
		}
		return pos;
	}
}


int first_occurrence(double x, const vector <double>& v) {
	if (v.empty() or x < v[0] or v[v.size()-1] < x) return -1;
	else return first_occurrence_rec(x, v, 0, v.size()-1);
}
*/

//RESPUESTA ACADEMIA

int first_occurrence_rec(double x, const vector<double>& v, int l, int r) {
	if (l > r) return -1;
	int m = (l+r)/2;
	if (x > v[m]) return first_occurrence_rec(x, v, m+1, r);
	else if (x < v[m]) return first_occurrence_rec(x, v, l, m-1);
	else {
		if (m >= 0 and v[m-1] != x) return m;
		return first_occurrence_rec(x, v, l, m-1);
	}
}

int first_occurrence(double x, const vector <double>& v) {
	return first_occurrence_rec(x, v, 0, v.size()-1);
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
            cout << first_occurrence(x, V) << endl;
        }
    }
}