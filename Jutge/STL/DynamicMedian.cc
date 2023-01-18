#include <iostream>
#include <set>
using namespace std;

int main() {
    string w;
    cin >> w;
    set <string> s;
    set <string>::iterator it = s.begin();
    set <string>::iterator mid;
    if (w != "END") {
        it = s.insert(it, w); //inserta la palabra justo detras de donde apunta el it
        cout << w << endl;
        mid = s.begin();
        while (cin >> w and w != "END") {
			s.insert(it, w);
			if (w < *mid and s.size() % 2 == 0) --mid;
			else if (w > *mid and s.size() % 2 != 0) ++mid;
			cout << *mid << endl;
		}
    }
}