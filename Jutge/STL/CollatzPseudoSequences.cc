#include <iostream>
#include <map>
using namespace std;


int main() {
    int x, y, n;
    while(cin >> x >> y >> n) {
        bool found = false;
        map <int,int> seq;
        map <int,int>::iterator it;
        int pos = 1;
        seq[n] = 0;
        while(n <= 100000000 and not found) {
            if(n%2 == 0) n = n/2 + x;
            else n = 3*n + y;
            it = seq.find(n);
            if(it == seq.end()) seq[n] = pos;
            else {
                found = true;
                n = pos - seq[n];
            }
            ++pos;
        }
        cout << n << endl;
        seq.clear();
    }
}