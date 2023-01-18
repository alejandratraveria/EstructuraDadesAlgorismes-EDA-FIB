#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main() {
    string w;
    while(getline(cin,w)) {
        set<int> s;
        int size = w.size();

        istringstream iss(w);
        int i;
        while(iss >> i) s.insert(i); //transforma el primer caracter del string en int y lo inserta en el set

        int seq = 0;
        bool parity; //true par, false impar

        auto it = s.begin();
        while(it != s.end()) {
            if(it == s.begin()) {
                ++seq;
                parity = (*it%2 == 0); 
            }
            else if(parity and *it%2 != 0) {
                ++seq;
                parity = false;
            }
            else if(not parity and *it%2 == 0) {
                ++seq;
                parity = true;
            }
            ++it;
        }
        cout << seq << endl;
    }
}