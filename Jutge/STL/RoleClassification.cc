#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

bool cmp(pair<string,int> p1, pair<string,int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    else return p1.second > p2.second;
}

int main() {
    map <string, int> players;
    set <string> connected;
    string op;
    while (cin >> op) {
        if (op == "LOGIN") {
            string name;
            cin >> name;
            auto it1 = players.find(name);
            if (it1 == players.end()) {
                players.insert({name, 1200});
                connected.insert(name);
            }
            else {
                if(connected.find(name) == connected.end()) connected.insert(name);
            }
        }
        else if (op == "LOGOUT") {
            string name;
            cin >> name;
            connected.erase(name);
        } 
        else if (op == "PLAY") {
            string p1, p2;
            cin >> p1 >> p2;
            if(connected.find(p1) == connected.end() or connected.find(p2) == connected.end()) cout << "player(s) not connected" << endl;
            else {
                players[p1] += 10;
                auto it = players.find(p2);
                if (it->second > 1200) it->second -= 10;
            }
        }
        else {
            string name;
            cin >> name;
            auto it = players.find(name);
            if(it != players.end()) cout << it->first << ' ' << it->second << endl;
        }
    }
    vector <pair<string,int>> v(players.begin(), players.end());
    sort(v.begin(), v.end(), cmp);
    cout << endl << "RANKING" << endl;
    for(auto p : v) cout << p.first << ' ' << p.second << endl;
}