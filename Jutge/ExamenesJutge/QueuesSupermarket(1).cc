/* Simulate the behavior of the queues of a supermarket. Initially, there are n queues (1, 2, …, n), each one with some customers. Afterwards, 
two events can happen:
    A costumer arrives to a queue: If the queue is between 1 and n, the customer goes to the end of that queue. Otherwise, the event is ignored.
    A customer leaves a queue: If the queue is between 1 and n, and that queue is not empty, the first customer of that queue leaves it. Otherwise, 
    the event is ignored. 

Input
Input starts with the number of queues n (a strictly positive natural number). Follow n lines, one per queue, each one with its customers (
a word), in the order in which they arrived to que queue. Follow an empty line and the description of several events, one per line: 
the word “ENTERS” followed by the customer (a word) and the queue (an integer number); or the word “LEAVES” followed by the queue (an integer 
number).

Output
First, print the name of the customers that leave the queues, in the order that they departed. Afterwards, print the final content of the 
n queues, using the order in which the customers would leave. Follow the format of the example.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

typedef queue<string> Qs;
typedef vector<Qs> VQs;

bool posOk(int n, int Q) {
    return Q <= n and Q > 0;
}

void readQueues(int n, VQs& vq) {
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        istringstream read(s); 
        string name;
        while (read >> name) vq[i].push(name);
    }
}

void writeQueues(int n, VQs& vq) {
    for (int i = 0; i < n; ++i) {
        cout << "queue " << i+1 << ':';
        while (not vq[i].empty()) {
            cout << ' ' << vq[i].front();
            vq[i].pop();
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    VQs vq(n);
    readQueues(n, vq);
    
    cout << "DEPARTS" << endl << string(7, '-') << endl;

    string op;
    int Q;
    while (cin >> op) {
        if(op == "ENTERS") {
            string name;
            cin >> name >> Q;
            if (posOk(n, Q)) vq[Q-1].push(name);
        }
        else { //op == "LEAVES"
            cin >> Q;
            if (posOk(n, Q) and not vq[Q-1].empty()) {
                cout << vq[Q-1].front() << endl;
                vq[Q-1].pop();
            }
        }
    }
    cout << endl << "FINAL CONTENTS" << endl << string(14, '-') << endl;
    writeQueues(n, vq);
}