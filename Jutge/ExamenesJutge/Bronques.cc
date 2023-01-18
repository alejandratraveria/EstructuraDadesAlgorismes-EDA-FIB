/* La Laura està organitzant alguna activitat a la FME, ja sigui del Club d’Esports, de la Sortida de la Dele, de Festes FME, etc. Per descomptat, 
hi ha n persones que no hi estan d’acord, així que cadascú formula una proposta, i s’organitza un sistema de vots perquè tothom pugui votar sobre 
totes les propostes. Si algú no vota una proposta voldrà dir que li és indiferent, i si algú vota una mateixa proposta dos o més cops només se li 
computarà l’últim vot sobre la proposta.

La Laura implementarà les propostes que tinguin estrictament més SIs que NOs, ignorant els indiferents. Podeu dir quines propostes seran?

Entrada
L’entrada consisteix en diversos casos. Cada cas comença amb n, seguida d’n parells amb un nom i una proposta. Tots són strings diferents entre si 
formats només amb ‘_’ i lletres minúscules. Segueix el nombre de vots m, seguit d’m triplets nom, SI/NO, proposta. Tant el nom com la proposta 
existeixen. Podeu suposar 1 ≤ n ≤ 100 i 1 ≤ m ≤ 1000.

Sortida
Per a cada cas, escriviu en ordre lexicogràfic les propostes que s’implementaran, junt amb els vots obtinguts. Escriviu una línia amb 10 guions 
al final de cada cas.
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        map<string,string> authorProposal;
        for (int i = 0; i < n; ++i) {
            string person, proposal;
            cin >> person >> proposal;
            authorProposal[proposal] = person;
        }
        
        int m;
        cin >> m;
        map<pair<string,string>,bool> allVotes; // pair is (person,proposal)
        for (int i = 0; i < m; ++i) {
            string name, vote, proposal;
            cin >> name >> vote >> proposal;
            if (vote == "SI") allVotes[{name,proposal}] = true;
            else if (vote == "NO") allVotes[{name,proposal}] = false;
        }

        map<string,pair<int,int>> votesProposal; // pair is (votes SI,votes NO)
        for (auto elem: allVotes ) {
            if (elem.second) ++votesProposal[elem.first.second].first;
            else ++votesProposal[elem.first.second].second;
        }

        for (auto p: votesProposal ) {
            if (p.second.first > p.second.second) {
                cout << p.first << ", de " << authorProposal[p.first] << ", que ha guanyat " << p.second.first << "-" << p.second.second << endl;
            }
        }
        cout << string(10, '-') << endl;
    }
}