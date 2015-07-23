/* 14014507	2015-07-15 01:48:46	Accepted	3401	608MS	17372K	1751 B	C++	Shark */
#include<bits\stdc++.h>
#define MAXN 2005
using namespace std;
int T, P, W;
int ap[MAXN], bp[MAXN];
int as[MAXN], bs[MAXN];
int DP[MAXN][MAXN];
int Q[MAXN];
int F1(int i, int j){ return DP[i - W - 1][j] + ap[i] * j; }
int F2(int i, int j){ return DP[i - W - 1][j] + bp[i] * j; }
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%d%d%d", &T, &P, &W);
    for (int i = 1; i <= T; i++)
      scanf("%d%d%d%d", ap + i, bp + i, as + i, bs + i);
    for (int i = 0; i <= T; i++)
      for (int j = 0; j <= P; j++)
        DP[i][j] = -1e9;
    for (int i = 1; i <= W + 1; i++)
      for (int j = 0; j <= as[i]; j++)
        DP[i][j] = -ap[i] * j;
    int L, R;
    for (int i = 2; i <= T; i++){
      for (int j = 0; j <= P; j++)
        DP[i][j] = max(DP[i][j], DP[i - 1][j]);
      if (i <= W + 1) continue;
      L = 1, R = 0;
      for (int j = 0; j <= P; j++){
        while (L <= R && F1(i, j) >= F1(i, Q[R])) R--;
        Q[++R] = j;
        while (L <= R && j - Q[L] > as[i])  L++;
        DP[i][j] = max(DP[i][j], F1(i, Q[L]) - j * ap[i]);
      }
      L = 1, R = 0;
      for (int j = P; j >= 0; j--){
        while (L <= R && F2(i, j) >= F2(i, Q[R])) R--;
        Q[++R] = j;
        while (L <= R && Q[L] - j > bs[i])  L++;
        DP[i][j] = max(DP[i][j], F2(i, Q[L]) - j * bp[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i <= P; i++)
      ans = max(ans, DP[T][i]);
    printf("%d\n", ans);
  }
  return 0;
}
/*

Trade

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 3888    Accepted Submission(s): 1253


Problem Description
Recently, lxhgww is addicted to stock, he finds some regular patterns after a few days' study.
He forecasts the next T days' stock market. On the i'th day, you can buy one stock with the price APi or sell one stock to get BPi.
There are some other limits, one can buy at most ASi stocks on the i'th day and at most sell BSi stocks.
Two trading days should have a interval of more than W days. That is to say, suppose you traded (any buy or sell stocks is regarded as a trade)on the i'th day, the next trading day must be on the (i+W+1)th day or later.
What's more, one can own no more than MaxP stocks at any time.

Before the first day, lxhgww already has infinitely money but no stocks, of course he wants to earn as much money as possible from the stock market. So the question comes, how much at most can he earn?


Input
The first line is an integer t, the case number.
The first line of each case are three integers T , MaxP , W .
(0 <= W < T <= 2000, 1 <= MaxP <= 2000) .
The next T lines each has four integers APi¡ABPi¡AASi¡ABSi( 1<=BPi<=APi<=1000,1<=ASi,BSi<=MaxP), which are mentioned above.


Output
The most money lxhgww can earn.


Sample Input
1
5 2 0
2 1 1 1
2 1 1 1
3 2 1 1
4 3 1 1
5 4 1 1


Sample Output
3


Author
lxhgww


Source
HDOJ Monthly Contest ¡V 2010.05.01


Recommend
lcy   |   We have carefully selected several similar problems for you:  3400 3403 3404 3402 3415 

*/