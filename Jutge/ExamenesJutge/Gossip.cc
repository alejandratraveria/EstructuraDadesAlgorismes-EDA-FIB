/* Write a program to maintain basic information for the gossip magazines: who is a couple of who. There are two kinds of orders: “info” and 
“affair” x y. The first asks for a list of all the information at that moment. The second indicates that x and y are a couple now. If some 
person z was a couple of x or a couple of y, then z becomes single.

Input
Input consists of several orders. For every “affair” x y order, both x and y are words made up of only lowercase letters, such that x and y 
are different, and such that x and y do not have an affair at that moment.

Output
Print as many lists as “info” orders, finishing each with a line with 10 dashes. Print the couples in alphabetical order, and also the couples 
among them. Print the alone people in alphabetical order as well.

Observation
In the private test cases, most orders are of the “affair” kind.
*/
#include <iostream>
#include <map>
using namespace std;

typedef map<string,string> M;

int main() {
    string op;
    M gossip;
    while (cin >> op) {
        if (op == "affair") {
            string name1, name2;
            cin >> name1 >> name2;

            if (gossip[name1] != "") gossip[gossip[name1]] = "";
            gossip[name1] = name2;
            if (gossip[name2] != "") gossip[gossip[name2]] = "";
            gossip[name2] = name1;
            
        }
        else {
            cout <<  "COUPLES:" << endl;
            for (auto it = gossip.begin(); it != gossip.end(); ++it) {
                if (it->second != "" and it->first < it->second)  cout << it->first << ' ' << it->second << endl;
            } 
            cout << "ALONE:" << endl;
            for (auto it = gossip.begin(); it != gossip.end(); ++it) {
                if (it->second == "")  cout << it->first << endl;
            } 

            cout << string(10, '-') << endl;
        }
    }
}