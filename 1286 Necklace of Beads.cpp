/* 14532729	840502	1286	Accepted	148K	0MS	C++	1186B	2015-08-03 14:23:29 */
#include<bits\stdc++.h>
using namespace std;
int w[30], n;
long long power(long long a, long long b) {
  if (b == 0)  return 1;
  long long tmp = power(a, b >> 1);
  if (b & 1)
    return a * tmp * tmp;
  else
    return tmp * tmp;
}
long long getLoop() {
  bool V[30] = { false };
  long long res = 0;
  for (int i = 1, j; i <= n; i++) {
    if (V[i])  continue;
    res++;
    j = i;
    do {
      V[j] = true;
      j = w[j];
    } while (!V[j]);
  }
  return res;
}
long long solve() {
  if (n == 0)  return 0;
  long long ans = 0;
  memset(w, 0, sizeof(w));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++)
      w[j] = (j + i) % n + 1;
    ans += power(3LL, getLoop());
    for (int j = 1; j <= n / 2; j++)
      swap(w[j], w[n + 1 - j]);
    ans += power(3LL, getLoop());
  }
  return ans / (2 * n);
}
int main() {
  while (scanf("%d", &n) == 1) {
    if (n == -1) break;
    printf("%lld\n", solve());
  }
  return 0;
}
/*

Necklace of Beads
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 7215		Accepted: 2996
Description

Beads of red, blue or green colors are connected together into a circular necklace of n beads ( n < 24 ). If the repetitions that are produced by rotation around the center of the circular necklace or reflection to the axis of symmetry are all neglected, how many different forms of the necklace are there?


Input

The input has several lines, and each line contains the input data n.
-1 denotes the end of the input file.
Output

The output should contain the output data: Number of different forms, in each line correspondent to the input data.
Sample Input

4
5
-1
Sample Output

21
39
Source

Xi'an 2002

*/