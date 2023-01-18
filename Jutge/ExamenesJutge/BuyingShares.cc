/* You have c coins, and you must make n stock transactions. Each transaction involves buying or selling a share. All shares are worth one coin 
each. You can only buy if you have a coin, and can only sell if you have a share.

Given n and c, print all possible sequences of operations.

Input
Input consists of n and c. Suppose 1 ≤ c ≤ n ≤ 16.

Output
Print in alphabetical order all possible sequences of n operations when we start with c coins. Use ‘b’ to buy and ‘s’ to sell.
*/
#include <iostream>
#include <string>
using namespace std;

void rec(int n, int c, int shares, string& res) {
    if (res.length() == n) cout << res << endl;
    else {
        if (c > 0) {
            res.push_back('b');
            rec(n, c-1, shares+1, res);
            res.pop_back();
        }
        if (shares > 0) {
            res.push_back('s');
            rec(n, c+1, shares-1, res);
            res.pop_back();
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    
    string res;
    rec(n, c, 0, res);
}