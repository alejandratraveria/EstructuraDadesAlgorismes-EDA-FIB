/* Verilog is a hardware description language to model digital circuits that is standardized by IEEE. Write a program that, given the 
description of a digital circuit in a simplified version of Verilog and a sequence of truth assignments for the inputs to the circuit, 
outputs the result of evaluating the circuit on those assignments.

Input
Input starts with a sequence of output cable identifiers, followed by a sequence of input cable identifiers, then a sequence of AND, OR 
or NOT gate specifications, and finally a sequence of cases. Each case is a truth-value assignment to the input cables of the circuit in 
the same order as given in the description of the circuit. Each cable of the circuit is identified by a unique sequence of lower-case 
letters and digits. The truth values are T and F for TRUE and FALSE, respectively.

Follow the format of the examples. You may assume that the input describes a correct circuit; that is, input and output cables are disjoint, 
all cables are reachable from the inputs, and the circuit does not contain cycles (in particular, no input cable is the output of a gate).

Output
Output is the sequence of truth values that the circuit generates at its output cables with each assignment, in the same order as given 
in the description of the circuit, one per line.
*/
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;

typedef map<string,int> MSI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<VI> VVI;

int noutputs, ninputs;
VVI gdir, ginv;
MSI s2v;
VS v2s;

int string2vertex (const string& s) {
    auto it = s2v.find(s);
    if (it != s2v.end()) return it->second;
    else {
        int v = v2s.size();
        v2s.push_back(s);
        s2v.insert(make_pair(s, v));
        return v;
    }
}
int main() {
noutputs = ninputs = 0;
    string token;
    cin >> token;
    assert( token == "OUTPUT");
    while (cin >> token and token != "END") {
        ++noutputs;
        string2vertex(token);
    }
    cin >> token;
    assert ( token == "INPUT");
    while (cin >> token and token != "END") {
        ++ninputs;
        string2vertex(token);
    }
    while (cin >> token and token != "END") {
        string s ;
        cin >> s;
        int ov = string2vertex (s);
        if (ov+1 > int(gdir.size())) gdir.resize (ov+1);
        cin >> s;
        int iv1 = string2vertex(s);
        if (iv1 + 1 > int(ginv.size())) ginv.resize(iv1 + 1);
        if (token == "NOT") {
            gdir [ov].push_back(iv1);
            ginv[iv1].push_back(ov);
        }
        else {
            cin >> s;
            int iv2 = string2vertex (s);
            if (iv2 + 1 > int(ginv.size())) ginv.resize(iv2 + 1);
            if ( token == "AND") {
                gdir[ov].push_back(min(iv1, iv2));
                gdir[ov].push_back(max(iv1,iv2));
            }
            else {
                gdir[ov].push_back(max(iv1,iv2));
                gdir[ov].push_back(min(iv1, iv2));
            }
            ginv[iv1].push_back(ov);
            ginv[iv2].push_back(ov);
        }
    }
    int n = gdir.size();
    VI ddir (n, 0);
    for (int v = 0; v < n; ++v) ddir[v] = gdir[v].size();
    VI bag;
    for (int v = noutputs; v < ninputs + noutputs; ++v) bag.push_back(v);
    VI ord;
    while (not bag.empty()) {
        int v = bag.back();
        ord.push_back(v);
        bag.pop_back();
        for (auto w : ginv[v]) {
            --ddir[w];
            if (ddir[w] == 0) bag.push_back(w);
        }
    }
    VB val(n);
    while (cin >> token) {
        val[noutputs] = (token == "T");
        for (int v = noutputs+1; v < ninputs + noutputs ; ++v) {
            cin >> token;
            val[v] = (token == "T");
        }
        for (auto v: ord) {
            if (gdir[v].size() == 1) {
                val[v] = not val[gdir[v][0]];
            }
            else if (gdir[v].size() == 2) {
                int iv1 = gdir[v][0];
                int iv2 = gdir[v][1];
                if (iv1 < iv2) val[v] = val[iv1] and val[iv2];
                else val[v] = val[iv1] or val[iv2 ];
            }
        }
        cout << (val[0] ? 'T' : 'F' );
        for (int v = 1; v < noutputs; ++v)
        cout << ' ' << (val[v] ? 'T' : 'F' );
        cout << endl;
    }
}