#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>>matrix;

matrix multmat(const matrix& m1, const matrix& m2, int mod) {
    matrix aux(2, vector<int>(2));
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m2.size(); ++k) {
                aux[i][j] += m1[i][k]*m2[k][j];
            }
            aux[i][j] %= mod;
        }
    }
    return aux;
}

matrix powmat(const matrix& m, int n, int mod) {
    if (n == 0) return {{1,0},{0,1}};
    else {
        matrix m1 = powmat(m, n/2, mod);
        if (n%2 == 0) return (multmat(m1, m1, mod));
        else return (multmat(multmat(m, m1, mod), m1, mod));
    }
}

int main() {
    matrix m(2, vector<int>(2));
    m = {{1,1}, {1,0}};
    int n, mod;
    while (cin >> n >> mod) {
        matrix m1(2, vector<int>(2));
        m1 = powmat(m, n, mod);
        cout << m1[0][1] << endl;
    }
}