#include <iostream>
#include <set>
using namespace std;

struct compare {
	bool operator()(const string& a, const string& b) {
		if (a.length() == b.length()) return a < b;
		return a.length() < b.length();
	}
};

int main() {
	set <string> has;
	set <string, compare> had;
	string w;
	int game = 1;
	bool quit = false, first = true;
	cin >> w;
	while (not quit) {
		while (not (w == "END" or w == "QUIT")) {
			auto it = has.find(w);
			if (it != has.end()) {
				has.erase(w);
				had.insert(w);
			}
            else {
				has.insert(w);
				had.erase(w);
			}
			cin >> w;
		}

		if (not first) cout << endl;
		first = false;

		cout << "GAME #" << game << endl << "HAS:" << endl;
		for (auto w : has) cout << w << endl;
		cout << endl << "HAD:" << endl;
		for (auto w : had) cout << w << endl;

		++game;
		has.clear();
		had.clear();

		if (w == "QUIT") quit = true;
		else cin >> w;
	}
}
