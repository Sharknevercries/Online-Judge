/* 1047776	840502	1492	Accepted	6296 kb	1496 ms	C++/Edit	2455 B	2015-07-17 02:40:13 */
#include<bits\stdc++.h>
#define MAXN 100005
#define EPS 1e-9
using namespace std;
int n;
double s, a[MAXN], b[MAXN], rate[MAXN], DP[MAXN];
double A[MAXN], B[MAXN];
double X(int t){ return A[t]; }
double Y(int t){ return B[t]; }
double DX(int a, int b){ return X(b) - X(a); }
double DY(int a, int b){ return Y(b) - Y(a); }
double query(vector<int> &Q, int k){
  double ans = -1e30;
  int L = 0, R = Q.size() - 1;
  while (R - L > 2){
    int mid1 = L + (R - L) / 3, mid2 = R - (R - L) / 3;
    if (a[k] * A[Q[mid1]] + b[k] * B[Q[mid1]] > a[k] * A[Q[mid2]] + b[k] * B[Q[mid2]])
      R = mid2;
    else
      L = mid1;
  }
  for (int i = L; i <= R; i++)
    ans = max(ans, a[k] * A[Q[i]] + b[k] * B[Q[i]]);
  return ans;
}
vector<int> CDQ(int L, int R){
  vector<int> Q;
  if (L == R){
    DP[L] = max(DP[L - 1], DP[L]);
    B[L] = DP[L] / (rate[L] * a[L] + b[L]);
    A[L] = B[L] * rate[L];
    Q.push_back(L);
    return Q;
  }
  vector<int> LQ, RQ;
  int mid = (L + R) / 2;
  LQ = CDQ(L, mid);
  for (int i = mid + 1; i <= R; i++)
    DP[i] = max(DP[i], max(DP[i - 1], query(LQ, i)));
  RQ = CDQ(mid + 1, R);
  vector<int> tmp;
  int Lptr, Rptr;
  for (Lptr = 0, Rptr = 0; Lptr < LQ.size() && Rptr < RQ.size();)
    if (A[LQ[Lptr]] < A[RQ[Rptr]] || A[LQ[Lptr]] == A[RQ[Rptr]] && B[LQ[Lptr]] < B[RQ[Rptr]])
      tmp.push_back(LQ[Lptr++]);
    else
      tmp.push_back(RQ[Rptr++]);
  while (Lptr < LQ.size())  tmp.push_back(LQ[Lptr++]);
  while (Rptr < RQ.size())  tmp.push_back(RQ[Rptr++]);
  for (int i = 0; i < tmp.size(); i++){
    while (Q.size() > 1 && DX(Q.back(), tmp[i]) * DY(Q[Q.size() - 2], tmp[i]) <= EPS + DY(Q.back(), tmp[i]) * DX(Q[Q.size() - 2], tmp[i]))
      Q.pop_back();
    Q.push_back(tmp[i]);
  }
  return Q;
}
int main(){
  scanf("%d%lf", &n, &s);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf%lf", a + i, b + i, rate + i);
  DP[0] = s;
  CDQ(1, n);
  printf("%.3lf\n", DP[n]);
  return 0;
}
/*

1492: [NOI2007]货币兑换Cash

Time Limit: 5 Sec  Memory Limit: 64 MB
Submit: 2340  Solved: 1040
[Submit][Status][Discuss]
Description

Input

第一行两个正整数N、S，分别表示小Y 能预知的天数以及初始时拥有的钱数。 接下来N 行，第K 行三个实数AK、BK、RateK，意义如题目中所述
Output

只有一个实数MaxProfit，表示第N 天的操作结束时能够获得的最大的金钱 数目。答案保留3 位小数。
Sample Input

3 100

1 1 1

1 2 2

2 2 3
Sample Output

225.000
HINT

测试数据设计使得精度误差不会超过10-7。
对于40%的测试数据，满足N ≤ 10；
对于60%的测试数据，满足N ≤ 1 000；
对于100%的测试数据，满足N ≤ 100 000；
Source

*/