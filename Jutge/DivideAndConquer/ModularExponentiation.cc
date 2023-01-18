  #include <iostream>
using namespace std;

int modexp(int n, int k, int m) {
    if (k == 0) return 1;
    else {
        int y = modexp(n, k/2, m);
        if (k%2 == 0) return (y%m * y%m);
        else return ((y%m * n%m) * y%m);
    }
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) cout << modexp(n, k, m) << endl;
}