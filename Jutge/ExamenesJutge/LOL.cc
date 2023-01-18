/* En l’argot d’internet, LOL, l’acrònim anglès de “laughing out loud” (rient sonorament) s’utilitza freqüentment per descriure una situació 
suposadament divertida. A veure si aquest problema us sembla divertit...

Donats dos naturals n i m, cal omplir una matriu n × m amb els caràcters ‘L’ i ‘O’, de tal manera que el nombre de “LOL”s que contingui sigui 
el màxim possible, comptant totes les aparicions horizontals, verticals i diagonals. Per exemple, per a n = 3 i m = 7 la solució òptima és

LLLLLLL
OOOOOOO
LLLLLLL

amb 17 aparicions de “LOL”. Com un altre exemple, per a n = 1 i m = 2 

OL

és una de les quatre solucions possibles, totes sense cap aparició de “LOL”.

Entrada
L’entrada consisteix en diversos casos, cadascun amb n i m. Suposeu 1 ≤ n ≤ m i n · m ≤ 23.

Sortida
Per a cada cas, escriviu el màxim nombre possible de “LOL”s.

Observació
No es valorarà cap solució que no sigui de força bruta.
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

int rec(int n, int m, int Pos, int LOLs, VVC& board) {
    int i = Pos/m;
    int j = Pos%m;
    if (i == n) return LOLs;
    
    board[i][j] = 'O';
    int numO = rec(n, m, Pos+1, LOLs, board);

    board[i][j] = 'L';
    int LolAux = 0;
    if (j >= 2 and board[i][j-1] == 'O' and board[i][j-2] == 'L') ++LolAux;
    if (i >= 2 and j >= 2 and board[i-1][j-1] == 'O' and board[i-2][j-2] == 'L') ++LolAux; 
    if (i >= 2 and board[i-1][j] == 'O' and board[i-2][j] == 'L') ++LolAux;
    if (i >= 2 and j+2 < m and board[i-1][j+1] == 'O' and board[i-2][j+2] == 'L') ++LolAux;
    int numL = rec(n, m, Pos+1, LOLs + LolAux, board);

    return max(numO, numL);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVC board(n, VC(m));
        cout << rec(n, m, 0, 0, board) << endl;
    }
}