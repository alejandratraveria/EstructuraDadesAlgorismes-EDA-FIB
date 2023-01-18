/* Ali Baba is hidden in the cave of the treasure, watching how the forty thieves leave jewels and take away jewels all the time. 
When the thieves depart, Ali Baba will fill his bag with the most valuable jewels, but he will have to make it quickly, so that the thieves 
cannot catch him. Therefore, at every moment he wants to know which are the jewels that he will have to take if he has the chance. Help him!

Input
Input begins with the number of jewels that fit in the bag (a number between 1 and 10^5). Follow the actions of the thieves: If they leave 
a jewel, there is the word “leave” followed by the value of the jewel. If they take a jewel, there is the word “take” followed by the value 
of the jewel. The values are natural numbers, all different.

Output
For every action of the thieves, print the maximum value of the jewels that Ali Baba could take if the thieves left at that moment.
*/
#include <iostream>
#include <set>
using namespace std;

typedef long long int lint;

int main() {
    int n;
    cin >> n;
    lint sum = 0;
    set<lint> bag;
    set<lint> thief;
    
    string op;
    int x;
    while (cin >> op >> x) {
        if (op == "leave") {
            if (int(bag.size()) < n) {
                bag.insert(x);
                sum += x;
            }
            else {
                int min = *(bag.begin());
                if (min < x) {
                    bag.erase(min);
                    bag.insert(x);
                    sum = sum + x - min;
                    thief.insert(min);
                }
                else thief.insert(x);
            }
        }
        if (op == "take") {
            int min = *(bag.begin());
            if (min <= x) {
                bag.erase(x);
                sum -= x;
                if (thief.size() > 0) {
                    auto it = thief.end();
                    --it;
                    bag.insert(*(it));
                    sum += *(it);
                    thief.erase(it);
                }
            }
            else thief.erase(x);
        }
        cout << sum << endl;
    }
}


