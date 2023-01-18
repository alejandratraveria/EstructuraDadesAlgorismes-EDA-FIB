#include <iostream>
#include <vector>

using namespace std;

int num_inversions(vector<int>& v, int l, int m, int r) {
    vector<int> aux(r-l+1);
    int i = l, j = m+1, k = 0, count = 0;
    while (i <= m and j <= r) {
        if (v[i] <= v[j]) aux[k++] = v[i++]; //aux[k] = v[i]; ++i; ++k
        else {
            aux[k++] = v[j++];
            count += m-i+1;
        } 
    }
    while (i <= m) aux[k++] = v[i++];
    while (j <= r) aux[k++] = v[j++];
    for (int i = 0; i < r-l+1; ++i) v[l+i] = aux[i];
    return count;
}

int inversions(vector<int>& v, int l, int r) {
    if (l >= r) return 0;
    int m = (l+r)/2;
      return (inversions(v, l, m) + inversions(v, m+1, r) + num_inversions(v, l, m, r));
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        cout << inversions(v, 0, n-1) << endl;
    }
}