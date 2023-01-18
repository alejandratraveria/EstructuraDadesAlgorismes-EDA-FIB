/* Enric has a collection of boardgames of several types. In order to keep a good mix, he always maintains a restriction on his collection: 
no single type of game can have more instances than the rest of types together.

You are given the types of games of the initial collection of Enric, and a sequence of the types of newly released games in chronological order. 
When each game is released, Enric buys it as long as the restriction would not be broken. Your task is to compute the total number of games of 
each type at the end.

Input
Input consists of several cases, each with a number n, followed by n strings with the types of the initial collection. Follow a number g, followed 
by g strings with the released types of games in order of time. All given strings are made up of between 1 and 30 lowercase letters. 
Both n and g are between 2 and 104. The initial collection fulfills the restriction of Enric.

Output
For every case, print in alphabetical order each type of game at the end, together with its number of instances. Print 20 dashes after each case.
*/
#include <iostream>
#include <map>
using namespace std;

typedef map<string,int> M;

int main() {
    int n;
    while (cin >> n) {
        M games;
        int total = n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            ++games[s];
        }
        int j;
        cin >> j;
        for (int i = 0; i < j; ++i) {
            string s;
            cin >> s;
            int quantiti = games[s];
            if (quantiti < total - quantiti) {
                ++games[s]; 
                ++total;
            }
        }
        for (auto it = games.begin(); it != games.end(); ++it) cout << it->first << ' ' << it->second << endl;
        cout << string(20, '-') << endl;
    }
}