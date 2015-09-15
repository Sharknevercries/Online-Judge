/* 15878512	10910	Marks Distribution	Accepted	C++	0.154	2015-08-04 17:01:39 */
#include<bits\stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, t, p;
    long long DP[100][100] = { 0 };
    scanf("%d%d%d", &n, &t, &p);
    for (int i = p; i <= t; i++)
      DP[1][i] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = p; j <= t; j++) {
        for (int k = p; j - k >= p; k++) {
          DP[i][j] += DP[i - 1][j - k];
        }
      }
    }
    printf("%lld\n", DP[n][t]);
  }
  return 0;
}
/*

In an examination one student appeared in N subjects and has got total T marks. He has passed in
all the N subjects where minimum mark for passing in each subject is P. You have to calculate the
number of ways the student can get the marks. For example, if N = 3, T = 34 and P = 10 then the
marks in the three subject could be as follows.
Subject 1 Subject 2 Subject 3
1 14 10 10
2 13 11 10
3 13 10 11
4 12 11 11
5 12 10 12
6 11 11 12
7 11 10 13
8 10 11 13
9 10 10 14
10 11 12 11
11 10 12 12
12 12 12 10
13 10 13 11
14 11 13 10
15 10 14 10
So there are 15 solutions. So F(3, 34, 10) = 15.
Input
In the first line of the input there will be a single positive integer K followed by K lines each containing
a single test case. Each test case contains three positive integers denoting N, T and P respectively.
The values of N, T and P will be at most 70. You may assume that the final answer will fit in a
standard 32-bit integer.
Output
For each input, print in a line the value of F(N, T, P).
Sample Input
2
3 34 10
3 34 10
Sample Output
15
15

*/