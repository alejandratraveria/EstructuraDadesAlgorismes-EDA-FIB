/* Escriviu una funció eficient

     int first_occurrence(double x, const vector<double>& v);

que retorni la posició de la primera aparició de x dins del vector v. Si x no apareix a v, retorneu un -1.

Precondició
El vector v està “quasi ordenat” en ordre no decreixent, en el sentit que hi pot haver com a molt un parell d’índexos i i j tals que 
0 ≤ i < j < n i V[i] > V[j].

Observació Podeu definir funcions auxiliars si us calen.
Observació Només cal enviar el procediment demanat; el programa principal serà ignorat. 
*/
#include <iostream>
#include <vector>
using namespace std;

int firstOcurrencei(double x, int l, int r, const vector<double>& v) {
    if (l > r) return -1;
    int m = (l+r)/2;
    if (v[m] < x) {
        if (l < m and v[m-1] == x) return m-1;
        return firstOcurrencei(x, m+1, r, v);
    }
    else {
        int p = firstOcurrencei(x,l,m-1,v);
        if (p == -1 and v[m] == x) return m;
        if (m < r and v[m+1] == x and p == -1) return m+1;
        return p;
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return firstOcurrencei(x,0,v.size()-1,v);
}