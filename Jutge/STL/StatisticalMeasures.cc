#include <iostream>
#include <map>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    map<int, int> m;
    map<int, int>::iterator it;

    string command;
    int suma = 0, cont = 0;
    while (cin >> command) {
        if (command == "number") {
            ++cont;
            int n;
            cin >> n;
            suma += n;
            it = m.find(n);
            if (it != m.end()) ++it->second;
            else m.insert({n, 1});
        }
        else if (command == "delete" and not m.empty()) {
            it = m.begin();
            --it->second;
            --cont;
            suma -= it->first;
            if (it->second == 0) m.erase(it);
        }
        if (not m.empty()) {
            cout << "minimum: " <<  m.begin()->first << ", ";
            it = m.end();
            --it;
            cout << "maximum: " << it->first << ", average: " << double(double(suma)/double(cont)) << endl;
        }
        else cout << "no elements" << endl;
    }
}