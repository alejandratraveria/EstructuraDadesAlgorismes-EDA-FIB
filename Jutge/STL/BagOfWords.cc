#include <iostream>
#include <map>
using namespace std;

int main() {
    string op, w;
    map <string,int> m;
    map <string,int>::iterator it;
    while (cin >> op) {
        if (op == "store") {
            cin >> w;
            it = m.find(w);
            if (it == m.end()) m.insert(make_pair(w, 1));
            else it->second += 1; 
        }
        else if (op == "delete") {
            cin >> w;
            it = m.find(w);
            if (it != m.end()) {
                if(it->second > 1) it->second -= 1;
                else m.erase(it);
            }
        }
        else if (op == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}
