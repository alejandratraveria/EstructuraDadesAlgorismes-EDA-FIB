#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> q;
    char op;
    while(cin >> op) {
        if(op == 'S') {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(op == 'A') {
            if(q.empty()) cout << "error!" << endl;
            else cout << q.top() << endl;
        }
        else if(op == 'I' or op == 'D') {
            int x;
            cin >> x;
            if(not q.empty()) {
                if(op == 'D') x = -x;
                int aux = q.top() + x;
                q.pop();
                q.push(aux);
            }
            else cout << "error!" << endl;
        }
        else {
            if(q.empty()) cout << "error!" << endl;
            else q.pop();
        }
    } 
}