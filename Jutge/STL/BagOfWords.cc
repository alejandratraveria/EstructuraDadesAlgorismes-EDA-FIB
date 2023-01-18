#include <iostream>
#include <map>
using namespace std;

int main() {
    string op; /*w;*/
    map <string,int> m;
    /*map <string,int>::iterator it;*/
    while (cin >> op) {
        if (op == "store") {
            string w;
            cin >> w;
            auto it = m.find(w);
            if (it == m.end()) m.insert(make_pair(w, 1));
            else it->second += 1; 
        }
        else if (op == "delete") {
            string w;
            cin >> w;
            auto it = m.find(w);
            if (it != m.end()) {
                /*if(it->second > 1) it->second -= 1;
                else m.erase(it);*/
                it->second--;
	            if (it->second == 0) M.erase(it);
            }
        }
        else if (op == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}