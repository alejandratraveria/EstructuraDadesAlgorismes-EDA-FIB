/* Feu un programa que usi backtracking per escriure tots els nombres de n dígits tals que cap dels seus prefixos (ell inclòs) sigui múltiple de 
cap de m divisors prohibits donats d1, …, dm.

Per exemple, si n = 3, m = 6 i els divisors prohibits són 2, 3, 5, 7, 11 i 19, llavors 137 està permès, perquè cap dels seus tres prefixos 
1, 13 i 137 és múltiple de cap di. En canvi, 433 no està permès, perquè dels seus tres prefixos 4, 43 i 433, n’hi ha algun que és múltiple 
d’algun di (4 és múltiple de 2).

Entrada
L’entrada consisteix en diversos casos. Cada cas comença amb n i m, seguits de m enters diferents entre 2 i 1000. Podeu suposar que 1 ≤ n ≤ 9 
i 1 ≤ m ≤ 15.

Sortida
Per a cada cas, escriviu tots els nombres que tenen exactament n dígits i no tenen prefixos prohibits, un per línia i de petit a gran. 
Escriviu una línia amb 10 guions al final de cada cas.
*/
#include <iostream>
#include <vector> 
using namespace std;

typedef vector<int> VI;

bool notDiv(int m, int aux, VI& div) {
    for (int i = 0; i < m; ++i) {
        if (aux%div[i] == 0) return false;
    }
    return true;
}

void rec(int n, int m, int length, int res, VI& div) {
    if (length == n) cout << res << endl;
    else {
        for (int i = 0; i <= 9; ++i) {
            int aux = 10*res + i;
            if (notDiv(m, aux, div)) rec(n, m, length+1, aux, div);
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VI div(m);
        for (int i = 0; i < m; ++i) {
            cin >> div[i];
        }
        rec(n, m, 0, 0, div);
        cout << "----------" << endl;
    }
}
