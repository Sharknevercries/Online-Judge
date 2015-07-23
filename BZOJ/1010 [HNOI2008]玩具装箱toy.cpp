/* 1043758	840502	1010	Accepted	2644 kb	152 ms	C++/Edit	1533 B	2015-07-13 16:32:39 */
#include<bits\stdc++.h>
#define MAXN 50005
using namespace std;
int n, m, C;
long long c[MAXN];
long long s[MAXN];
long long DP[MAXN];
int Q[MAXN];
long long square(long long x){ return x*x; }
long long F(int t){ return s[t] + t; }
long long X(int t){ return 2 * F(t); }
long long Y(int t){ return DP[t] + square(F(t) + C); }
long long DX(int a, int b){ return X(b) - X(a); }
long long DY(int a, int b){ return Y(b) - Y(a); }
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    memset(s, 0, sizeof(s));
    memset(Q, 0, sizeof(Q));
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= n; i++)
      scanf("%lld", c + i);
    for (int i = 1; i <= n; i++)
      s[i] = s[i - 1] + c[i];
    int L = 0, R = 1;
    C = m + 1;
    for (int i = 1; i <= n; i++){
      while (L + 1 < R && DY(Q[L], Q[L + 1]) <= F(i) * DX(Q[L], Q[L + 1]))  L++;
      DP[i] = DP[Q[L]] + square(F(i) - F(Q[L]) - C);
      while (L + 1 < R && DY(Q[R - 2], Q[R - 1]) * DX(Q[R - 1], i) >= DY(Q[R - 1], i) * DX(Q[R - 2], Q[R - 1]))  R--;
      Q[R++] = i;
    }
    printf("%lld\n", DP[n]);
  }
  return 0;
}
/*

Description

P教授要去看奥运，但是他舍不下他的玩具，于是他决定把所有的玩具运到北京。他使用自己的压缩器进行压缩，其可以将任意物品变成一堆，再放到一种特殊的一维容器中。P教授有编号为1...N的N件玩具，第i件玩具经过压缩后变成一维长度为Ci.为了方便整理，P教授要求在一个一维容器中的玩具编号是连续的。同时如果一个一维容器中有多个玩具，那么两件玩具之间要加入一个单位长度的填充物，形式地说如果将第i件玩具到第j个玩具放到一个容器中，那么容器的长度将为 x=j-i+Sigma(Ck) i<=K<=j 制作容器的费用与容器的长度有关，根据教授研究，如果容器长度为x,其制作费用为(X-L)^2.其中L是一个常量。P教授不关心容器的数目，他可以制作出任意长度的容器，甚至超过L。但他希望费用最小.

Input

第一行输入两个整数N，L.接下来N行输入Ci.1<=N<=50000,1<=L,Ci<=10^7

Output

输出最小费用

Sample Input

5 4
3
4
2
1
4

Sample Output

1
HINT

Source

*/
