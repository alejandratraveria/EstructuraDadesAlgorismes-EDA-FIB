/* Professor Obokaman and Professor Oak go to buy something cheap for lunch. As usual, Prof. Obokaman has no cash at hand, so he asks some coins 
to Prof. Oak.

“No problem”, says Prof. Oak. “I lend you 5 euros. Since you are a good friend of mine, I will only charge you 1 euro per day until you return 
the coins to me.”

Prof. Obokaman looks a bit puzzled by this offer, so Prof. Oak adds: “You see, now banks charge a daily interest rate of 0.013368%, right?”

Prof. Obokaman knows that banks charge 5% every year. Since he is a bright mathematician, he has no problems to mentally check that this is indeed 
true (assuming 365 days per year): 1.00013368365 ≃ 1.05. “Yes, but…” he tries to say.

“Therefore”, Prof. Oak interrupts, “if you wait enough days before returning the coins to me, let’s see… 71589 days or more, to be precise, 
then my deal is better than the banks’ offer.”

Prof. Obokaman agrees that this reasoning is correct, but he is too polite to say that he will very likely return the coins sooner than that, 
losing a lot of money…

Input
Input consists of several test cases. Each test case consists of three real numbers: the amount of money m of the coins generously lent by Prof. 
Oak, the fixed amount of money f charged daily to Prof. Obokaman, and the % daily interest rate r offered by the banks. You can assume 0.1 ≤ m ≤ 
1000, 0.1 ≤ f ≤ 1000, and 0.001 ≤ r ≤ 10.

Output
For every test case, print the minimum number of days d that Prof. Obokaman should wait before returning the money to get a deal that is better 
than the banks’ offer. Assume that the test cases have no precision issues, and that every solution d will be between 1 and 107. */

#include <iostream>
using namespace std;

double power(double a, int n) {
  if (n == 0) return 1;

  double x = power(a, n / 2);
  if (n % 2 == 0) return (x * x);
  else return (x * x * a);
}

int num_days(double m, double f, double i, int l, int u) {
  if (l <= u) {
    int mid = (u + l) / 2;
    double mBank = power(i, mid) * m;
    double mPers = f * mid + m;
    if (mPers > mBank) return num_days(m, f, i, mid + 1, u);
    if (mPers < mBank) return num_days(m, f, i, l, mid - 1);
    return mid;
  }

  return l;
}

int main(){
  double m, f, r;
  while(cin >> m >> f >> r)
    cout << num_days(m, f, (r / 100 + 1), 1, 100000000) << endl;
}