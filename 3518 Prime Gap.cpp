/* 14510806	840502	3518	Accepted	6936K	47MS	C++	997B	2015-07-30 15:48:57 */
#include<bits\stdc++.h>
#define MAXN 1300000
using namespace std;
bool sieve[MAXN + 1000];
int ans[MAXN + 1000];
vector<int> prime;
int main() {
  memset(sieve, false, sizeof(sieve));
  for (int i = 2; i <= MAXN + 100; i++) {
    if (!sieve[i]) prime.push_back(i);
    for (int j = 0; i*prime[j] <= MAXN + 100; j++) {
      sieve[i*prime[j]] = true;
      if (i % prime[j] == 0)  break;
    }
  }
  for (int i = 2, j = 0; i <= MAXN; i++) {
    if (!sieve[i])
      ans[i] = 0;
    else {
      int p = lower_bound(prime.begin(), prime.end(), i) - prime.begin();
      while (i < prime[p])
        ans[i++] = prime[p] - prime[p - 1];
      i--;
    }
  }
  int k;
  while (scanf("%d", &k) == 1 && k != 0) {
    printf("%d\n", ans[k]);
  }
  return 0;
}
/*

Prime Gap
Time Limit: 5000MS		Memory Limit: 65536K
Total Submissions: 9076		Accepted: 5284
Description

The sequence of n ? 1 consecutive composite numbers (positive integers that are not prime and not equal to 1) lying between two successive prime numbers p and p + n is called a prime gap of length n. For example, ?24, 25, 26, 27, 28? between 23 and 29 is a prime gap of length 6.

Your mission is to write a program to calculate, for a given positive integer k, the length of the prime gap that contains k. For convenience, the length is considered 0 in case no prime gap contains k.

Input

The input is a sequence of lines each of which contains a single positive integer. Each positive integer is greater than 1 and less than or equal to the 100000th prime number, which is 1299709. The end of the input is indicated by a line containing a single zero.

Output

The output should be composed of lines each of which contains a single non-negative integer. It is the length of the prime gap that contains the corresponding positive integer in the input if it is a composite number, or 0 otherwise. No other characters should occur in the output.

Sample Input

10
11
27
2
492170
0
Sample Output

4
0
6
0
114
Source

Japan 2007

*/
