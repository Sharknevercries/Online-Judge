/* 14527822	840502	2407	Accepted	268K	0MS	C++	1178B	2015-08-02 16:10:01 */
#include<bits\stdc++.h>
#define MAXN 50005
#define MOD 100000000711LL
using namespace std;
bool sieve[MAXN] = { false };
vector<int> prime;
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}
void makePrime() {
  for (int i = 2; i <= MAXN; i++) {
    if (!sieve[i]) prime.push_back(i);
    for (int j = 0; i *prime[j] < MAXN; j++) {
      sieve[i * prime[j]] = true;
      if (i % prime[j] == 0)  break;
    }
  }
}
long long makePhi(int x) {
  long long ans = 1;
  for (int i = 0, j = 0; i < prime.size(); i++) {
    if (x % prime[i] == 0) {
      j = 0;
      while (x % prime[i] == 0) j++, x /= prime[i];
      for (int k = 1; k < j; k++)  ans = ans * prime[i] % MOD;
      ans = ans * (prime[i] - 1) % MOD;
      if (x == 1)  break;
    }
  }
  if (x > 1) ans = ans * (x - 1) % MOD;
  return ans;
}
int main() {
  makePrime();
  int n;
  while (scanf("%d", &n) == 1 && n) {
    printf("%d\n", makePhi(n));
  }
  return 0;
}
/*

Relatives
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 12172		Accepted: 5955
Description

Given n, a positive integer, how many positive integers less than n are relatively prime to n? Two integers a and b are relatively prime if there are no integers x > 1, y > 0, z > 0 such that a = xy and b = xz.
Input

There are several test cases. For each test case, standard input contains a line with n <= 1,000,000,000. A line containing 0 follows the last case.
Output

For each test case there should be single line of output answering the question posed above.
Sample Input

7
12
0
Sample Output

6
4
Source

Waterloo local 2002.07.01

*/