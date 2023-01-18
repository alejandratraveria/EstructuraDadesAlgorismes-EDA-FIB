/* Given a natural number x and n different coin values c1 … cn, compute in how many ways it is possible to achieve change x 
by using each value at most twice. Here, two coins with the same value are considered different.

For example, if x = 4 and the available values are 1 and 2, then there are three ways to achieve it: 1 + 1′ + 2, 1 + 1′ + 2′, and also 2 + 2′.

Input
Input consists of several cases. Every case begins with x and n, followed by c1 … cn. Assume 1 ≤ n ≤ 20, 1 ≤ ci ≤ x ≤ 1000, 
and that all ci are different.

Output
For every case print, in lexicographic order, all possible ways to exactly achieve change x by using each value at most twice. 
Print every solution with its values sorted from small to big. In doing that, assume 1 < 1′ < 2 < 2′ < …. Use “1p” to print 1′, etcetera. 
Print a line with 10 dashes at the end of every case.

Hint
A simply pruned backtracking should be enough.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;

void write(int x, int n, const VI& Coins, const VB& Used1, const VB& Used2) {
    int suma = 0;
    cout << x << " = ";
    for(int i =0; i < n; ++i) {
        if(Used1[i]) {
            suma += Coins[i];
            cout << Coins[i]; 
            if(suma != x) cout << " + ";
        }
         if(Used2[i]) {
            suma += Coins[i];
            cout << Coins[i] << 'p';
            if(suma != x) cout << " + ";
        }
    }
    cout << endl;
}

void twoCoins(int x, int n, int i, int sum, const VI& Coins, VB& Used1, VB& Used2) {
    if(x == sum) write(x,n,Coins,Used1,Used2);
    else if(sum < x and i < n) {
        if(not Used1[i]) {
            Used1[i] = true;
            twoCoins(x,n,i,sum+Coins[i],Coins,Used1,Used2);
            Used1[i] = false;
        }
        if(not Used2[i]) {
            Used2[i] = true;
            twoCoins(x,n,i+1,sum+Coins[i],Coins,Used1,Used2);
            Used2[i] = false;
        }
        twoCoins(x,n,i+1,sum,Coins,Used1,Used2);
    }
}

int main() {
    int x, n;
    while(cin >> x >> n) {
        VI Coins(n);
        for(int i = 0; i < n; ++i) cin >> Coins[i];
        sort(Coins.begin(), Coins.end());

        VB Used1(n, false);
        VB Used2(n, false);
        twoCoins(x,n,0,0,Coins,Used1,Used2);
        cout << string(10, '-') << endl;
    } 
}