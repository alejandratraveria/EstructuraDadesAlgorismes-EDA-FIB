/* Write a program that reads n consonants and n vowels, and prints all the words that can be made up by using each letter exactly once. 
The words must begin with a consonant, and alternate consonants and vowels. In this exercise, we will assume that ‘y’ is a vowel.

Input
Input consists of a natural number n between 1 and 6, followed by n different consonants and n different vowels. 
Both consonants and vowels are given in alphabetical order.

Output
Print the words that can be made up with the 2n given letters, starting with a consonant and always alternating consonants and vowels. 
Print the words in alphabetical order, one per line.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<bool> VB;

void write() {

}

void consonantsVowels(int n, int i, const string& cons, const string& vow, VB& UsedC, VB& UsedV, string& Res) {
    if (i == 2*n) cout << Res << endl;
    else {
        for(int j = 0; j < n; ++j) {
            if (i%2 == 0 and not UsedC[j]) {
                Res[i] = cons[j];
                UsedC[j] = true;
                consonantsVowels(n, i+1, cons, vow, UsedC, UsedV, Res);
                UsedC[j] = false;
            }
            else if (not UsedV[j]) {
                Res[i] = vow[j];
                UsedV[j] = true;
                consonantsVowels(n, i+1, cons, vow, UsedC, UsedV, Res);
                UsedV[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    string cons, vow;
    cin >> cons >> vow;

    string Res(2*n, ' ');
    VB UsedC(n, false);
    VB UsedV(n, false);
    consonantsVowels(n, 0, cons, vow, UsedC, UsedV, Res);
}