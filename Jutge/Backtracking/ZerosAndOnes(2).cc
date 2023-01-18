/* Write a program to print all the combinations of n − o zeros and o ones, for some given n and o.

Input
Input consists of n and o, two natural numbers such that n > 0 and 0 ≤ o ≤ n.

Output
Print all the combinations of n − o zeros and o ones, one per line and in lexicographical order.Write a backtra
*/

#include <iostream>
#include <vector>
using namespace std;

void write(int n,const vector<int>& Res) {
    cout << Res[0];
    for(int i = 1; i < n; ++i) {
        cout << ' ' << Res[i];
    }
    cout << endl;
}

void back(int n, int i, int no, int o, vector<int>& Res) {
    if(i == n) write(n,Res);
    else {
        if(i-no < n-o) {
            Res[i] = 0;
            back(n,i+1,no,o,Res);
        }
        if(no < o) {
            Res[i] = 1,
            back(n,i+1,no+1,o,Res);
        }
    }
}
/* same as back, but you cut the answers you don't want first
void backPoda(int n, int i, int no, int o, vector<int>& Res) {
    if(i-no > n-no or no > o) return;
    if(i == n) write(n,Res);
    else {
        Res[i] = 0;
        back(n,i+1,no,o,Res);
        Res[i] = 1,
        back(n,i+1,no+1,o,Res);
    }
}
*/

int main() {
    int n, o; 
    cin >> n >> o;
    vector<int>Res(n);
    back(n,0,0,o,Res);
}