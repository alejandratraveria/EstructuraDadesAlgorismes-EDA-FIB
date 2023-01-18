#include <iostream>
#include <map>
using namespace std;

int main() {
    map <string,int> c;
    map <string,int>::iterator it;
    string name, op; 
    while (cin >> name >> op) {
        it = c.find(name);
        if (op == "enters") {
            if (it == c.end()) c.insert(make_pair(name,0));
            else cout << name << " is already in the casino" << endl;
        } 
        else if (op == "leaves") {
            if(it == c.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << it->second << endl;
                c.erase(it);
            }
        }
        else {
            int money;
            cin >> money;
            if(it == c.end()) cout << name << " is not in the casino" << endl;
            else {
                it->second += money;
            }
        }
    }
    cout << "----------" << endl;
    it = c.begin();
    while (it != c.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}