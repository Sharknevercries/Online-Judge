/* 1045532	840502	1911	Accepted	28620 kb	1660 ms	C++/Edit	1437 B	2015-07-14 19:36:52 */
#include<bits\stdc++.h>
#define MAXN 1000005
using namespace std;
int n;
int Q[MAXN];
long long a, b, c;
long long DP[MAXN];
long long x[MAXN];
long long s[MAXN];
long long X(int t){ return 2 * a * s[t]; }
long long Y(int t){ return DP[t] + a * s[t] * s[t] - b * s[t]; }
long long DX(int a, int b){ return X(b) - X(a); }
long long DY(int a, int b){ return Y(b) - Y(a); }
int main(){
  memset(s, 0, sizeof(s));
  memset(DP, 0, sizeof(DP));
  scanf("%d", &n);
  scanf("%lld%lld%lld", &a, &b, &c);
  for (int i = 1; i <= n; i++)
    scanf("%lld", x + i);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + x[i];
  int L = 0, R = 1;
  for (int i = 1; i <= n; i++){
    while (L + 1 < R && s[i] * DX(Q[L], Q[L + 1]) <= DY(Q[L], Q[L + 1]))  L++;
    DP[i] = Y(Q[L]) - 2 * a * s[i] * s[Q[L]] + a * s[i] * s[i] + b * s[i] + c;
    while (L + 1 < R && DY(Q[R - 2], Q[R - 1]) * DX(Q[R - 1], i) >= DY(Q[R - 1], i) * DX(Q[R - 2], Q[R - 1])) R--;
    Q[R++] = i;
  }
  printf("%lld\n", DP[n]);
  return 0;
}
/*

Description

見官網

Input

見官網

Output

見官網

Sample Input

4
-1 10 -20
2 2 3 4

Sample Output

9
HINT

Source

*/