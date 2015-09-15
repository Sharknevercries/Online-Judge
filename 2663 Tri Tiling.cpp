/* 14545215	840502	2663	Accepted	152K	0MS	C++	880B	2015-08-05 00:43:48 */
#include<bits\stdc++.h>
using namespace std;
long long DP[40][10];
bool check(int state1, int state2) {
  if ((state1 | state2) != 7)  return false;
  int vertical = state1 & state2;
  if (vertical == 6 || vertical == 3 || vertical == 0)  return true;
  return false;
}
int main() {
  memset(DP, 0, sizeof(DP));
  DP[0][7] = 1;
  for (int i = 1; i <= 30; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        if (check(j, k)) {
          DP[i][j] += DP[i - 1][k];
        }
      }
    }
  }
  int n;
  while (scanf("%d", &n) == 1) {
    if (n == -1) break;
    printf("%lld\n", DP[n][7]);
  }
  return 0;
}
/*

Tri Tiling
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8518		Accepted: 4445
Description

In how many ways can you tile a 3xn rectangle with 2x1 dominoes?
Here is a sample tiling of a 3x12 rectangle.

Input

Input consists of several test cases followed by a line containing -1. Each test case is a line containing an integer 0 <= n <= 30.
Output

For each test case, output one integer number giving the number of possible tilings.
Sample Input

2
8
12
-1
Sample Output

3
153
2131
Source

Waterloo local 2005.09.24

*/