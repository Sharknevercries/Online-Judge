/* 14528253	840502	2249	Accepted	148K	0MS	C++	627B	2015-08-02 17:27:36 */
#include<bits\stdc++.h>
using namespace std;
long long C(int n, int k) {
  if (k == 0 || k == n)  return 1;
  long long ans = 1;
  if (n - k < k) k = n - k;
  for (int i = n, j = 1; j <= k; i--, j++)
    ans = ans * i / j;
  return ans;
}
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    if (n == 0 && k == 0)  break;
    printf("%lld\n", C(n, k));
  }
  return 0;
}
/*

Binomial Showdown
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 18601		Accepted: 5687
Description

In how many ways can you choose k elements out of n elements, not taking order into account?
Write a program to compute this number.
Input

The input will contain one or more test cases.
Each test case consists of one line containing two integers n (n>=1) and k (0<=k<=n).
Input is terminated by two zeroes for n and k.
Output

For each test case, print one line containing the required number. This number will always fit into an integer, i.e. it will be less than 231.
Warning: Don't underestimate the problem. The result will fit into an integer - but if all intermediate results arising during the computation will also fit into an integer depends on your algorithm. The test cases will go to the limit.
Sample Input

4 2
10 5
49 6
0 0
Sample Output

6
252
13983816
Source

Ulm Local 1997

*/