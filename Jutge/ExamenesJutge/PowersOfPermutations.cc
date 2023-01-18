/* Given an n, a permutation of {0, 1, … n−1} is a sequence where each of the numbers 0, 1, … n−1 occurs exactly once. For example, if n = 3, 
the sequences (1 2 0), (2 0 1) and (0 1 2) are permutations of {0, 1, 2}.

Given two permutations σ = (σ0, …, σn−1) and τ = (τ0, …, τn−1) of {0, 1, … n−1 }, their product σ ∘ τ is defined as the permutation 
ρ = (ρ0, …, ρn−1) such that ρi = στi. For example, if n = 3, σ = (1 2 0) and τ = (2 0 1), then σ ∘ τ = (0 1 2), since:

    τ0 = 2 and σ2 = 0,
    τ1 = 0 and σ0 = 1, and
    τ2 = 1 and σ1 = 2. 

Make a program that, given a permutation σ and a natural k, computes the power of σ raised to k: σk = σ ∘ … ∘ σk). By convention, 
σ0 = (0, 1, …, n−1).

Input
The input includes several cases. Each case consists in the number n (1 ≤ n ≤ 104), followed by n numbers between 1 and n that describe the 
permutation σ, followed by the number k (0 ≤ k ≤ 109).

Output
Write the permutation σk.

Observation
The expected solution to this problem has cost O(n · logk). The solutions that have cost Ω(n · k) can get at most 3 points over 10.
You can add (few) lines of comments explaining what you intend to do.
If needed, you can use that the product of permutations is associative.
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

void permutation(int n,const VI& v1, const VI& v2, VI& res) {
    for (int i = 0; i < n; ++i) {
        res[i] = v1[v2[i]];
    }
}

void fastExp(int n, int k, const VI& v, VI& res) {
    if (k == 0) {
        for (int i = 0; i < n; ++i) res[i] = i;
    }
    else {
        VI aux(n);
        fastExp(n,k/2,v,aux);
        permutation(n,aux,aux,res);
        if (k%2 != 0) permutation(n,v,res,res);
    }
}

int main() {
    int n;
    while (cin >> n) {
        VI v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        
        int k;
        cin >> k;
        VI res(n);
        fastExp(n,k,v,res);

        cout << res[0];
        for (int i = 1; i < n; ++i) cout << ' ' << res[i];
        cout << endl;
    }
}