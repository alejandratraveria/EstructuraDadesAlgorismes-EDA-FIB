/* Consider n different species. Some may be incompatible, in the sense that they must be kept separated. For example, if the species were human, 
lion, gorilla, buffalo and antelope, then the list of incompatibilities might be: we cannot put a human next to a lion, nor a human next to a 
buffalo, nor a lion next to a buffalo, nor a lion next to a antelope.

Write a program that reads the incompatibilities between species, and writes all the ways to put in a row an individual of every species, so that 
two incompatible species are never one beside the other.

Input
Input begins with a number n between 1 and 52, followed by n letters, each identifying a different species. Then comes a number m, followed by m 
different pairs of letters, each indicating an incompatibility between two of the n given species.

The first sample input corresponds to the example given above. “HL” means that we cannot put a human next to a lion, etc. Note that “LH” would mean exactly the same.

Output

Print all the ways of placing n individuals in a row, one of each species, so that incompatible species are not together.
Information about the checker

You can print the solutions to this exercise in any order. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef map <char, int>MI;
typedef vector <bool>VB;
typedef vector <char>VC;
typedef vector <VB>VVB;

MI conv;
VC v;
VVB mat;
VB done;

void backtracking(string sol, int ant) {
	if (sol.length() == v.size()) cout << sol << endl;
	else {
		for (int i = 0; i < mat.size(); i++) {
			if (!done[i] and mat[ant][i]) {
				done[i] = true;
				backtracking(sol+v[i], i);
				done[i] = false;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	v = VC(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		conv[v[i]] = i;
	}
	cin >> m;
	mat = VVB(n, VB(n, true));
	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;
		int na = conv[a];
		int nb = conv[b];
		mat[nb][na] = mat[na][nb] = false;
	}
	done = VB(n, false);
	for (int i = 0; i < n; i++) {
		string sol = "";
		sol += v[i];
		done[i] = true;
		backtracking(sol, i);
		done[i] = false;
	}
}
