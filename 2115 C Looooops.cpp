/* 14519780	840502	2115	Accepted	124K	0MS	C++	940B	2015-07-31 21:10:34 */
#include<bits\stdc++.h>
using namespace std;
void exgcd(long long x, long long y, long long &g, long long &a, long long &b) {
  if (y == 0)
    g = x, a = 1, b = 0;
  else
    exgcd(y, x%y, g, b, a), b -= (x / y)*a;
}
int main() {
  long long A, B, C, K, G, ta, tb;
  while (scanf("%lld%lld%lld%lld", &A, &B, &C, &K) == 4) {
    if (A == 0 && B == 0 && C == 0 && K == 0)  break;
    long long D = B - A;
    K = (1LL << K);
    D %= K;
    if (D < 0) D += K;
    if (D == 0) { puts("0");   continue; }
    exgcd(C, K, G, ta, tb);
    if (D%G != 0) { puts("FOREVER");  continue; }
    C /= G, K /= G, D /= G;
    ta = ta * D % K;
    if (ta < 0)  ta += K;
    printf("%lld\n", ta);
  }
  return 0;
}
/*

C Looooops
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 19896		Accepted: 5315
Description

A Compiler Mystery: We are given a C-language style for loop of type
for (variable = A; variable != B; variable += C)

statement;

I.e., a loop which starts by setting variable to value A and while variable is not equal to B, repeats statement followed by increasing the variable by C. We want to know how many times does the statement get executed for particular values of A, B and C, assuming that all arithmetics is calculated in a k-bit unsigned integer type (with values 0 <= x < 2k) modulo 2k.

Input

The input consists of several instances. Each instance is described by a single line with four integers A, B, C, k separated by a single space. The integer k (1 <= k <= 32) is the number of bits of the control variable of the loop and A, B, C (0 <= A, B, C < 2k) are the parameters of the loop.

The input is finished by a line containing four zeros.
Output

The output consists of several lines corresponding to the instances on the input. The i-th line contains either the number of executions of the statement in the i-th instance (a single integer number) or the word FOREVER if the loop does not terminate.
Sample Input

3 3 2 16
3 7 2 16
7 3 2 16
3 4 2 16
0 0 0 0
Sample Output

0
2
32766
FOREVER
Source

CTU Open 2004

*/