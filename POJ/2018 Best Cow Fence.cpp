/* 14381526	840502	2018	Accepted	1084K	157MS	C++	1060B	2015-07-12 22:45:02 */
#include<bits\stdc++.h>
using namespace std;
int n, k;
int w[100005];
int sum[100005];
int Q[100005];
long long cross(int a, int b, int c){
  return (sum[c] - sum[a - 1]) * (c - b + 1) - (sum[c] - sum[b - 1]) * (c - a + 1);
}
int main(){
  while (scanf("%d%d", &n, &k) == 2){
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
      scanf("%d", w + i);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + w[i];
    long long ans = 0;
    int L = 0, R = 0;
    for (int i = k; i <= n; i++){
      int j = i - k;
      while (L + 1 < R && cross(Q[R - 2], Q[R - 1], j) >= 0) R--;
      Q[R++] = j + 1;
      while (L + 1 < R && cross(Q[L], Q[L + 1], i) <= 0) L++;
      ans = max(ans, (long long)1000 * (sum[i] - sum[Q[L] - 1]) / (i - Q[L] + 1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
/*

Best Cow Fences
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 9886		Accepted: 3199
Description

Farmer John's farm consists of a long row of N (1 <= N <= 100,000)fields. Each field contains a certain number of cows, 1 <= ncows <= 2000.

FJ wants to build a fence around a contiguous group of these fields in order to maximize the average number of cows per field within that block. The block must contain at least F (1 <= F <= N) fields, where F given as input.

Calculate the fence placement that maximizes the average, given the constraint.
Input

* Line 1: Two space-separated integers, N and F.

* Lines 2..N+1: Each line contains a single integer, the number of cows in a field. Line 2 gives the number of cows in field 1,line 3 gives the number in field 2, and so on.
Output

* Line 1: A single integer that is 1000 times the maximal average.Do not perform rounding, just print the integer that is 1000*ncows/nfields.
Sample Input

10 6
6
4
2
10
3
8
5
9
4
1
Sample Output

6500
Source

USACO 2003 March Green

*/