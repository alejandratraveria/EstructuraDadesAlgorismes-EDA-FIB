#include <iostream>
#include <string>
using namespace std;
/*
void par_compensades(int i, string& sol, int n, int na, int nb) {
	if (i == n) cout << sol << endl;
	else {
		if (abs(na+1-nb) <= 2) {
			sol[i] = 'a';
			par_compensades(i+1, sol, n, na+1, nb);
		}
		
		if (abs(na-(nb+1)) <= 2) {
			sol[i] = 'b';
			par_compensades(i+1, sol, n, na, nb+1);
		}
	}
}
*/
void par_compensades(int i, string& sol, int n, int na, int nb) {
	if (abs(na-nb) > 2) return;
	if (i == n) cout << sol << endl;
	else {
		sol[i] = 'a';
		par_compensades(i+1, sol, n, na+1, nb);
		
		sol[i] = 'b';
		par_compensades(i+1, sol, n, na, nb+1);
	}
}

int main() {
	int n;
	cin >> n;
	string sol(n, ' ');
	par_compensades(0, sol, n, 0, 0);
}
