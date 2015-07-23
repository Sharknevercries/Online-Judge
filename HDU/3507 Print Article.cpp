/* 14028832	2015-07-16 13:20:34	Accepted	3507	483MS	15244K	1181 B	C++	Shark */
#include<bits\stdc++.h>
#define MAXN 500005
using namespace std;
int n, m;
long long c[MAXN];
long long s[MAXN];
long long DP[MAXN];
int Q[MAXN];
long long X(int t){ return 2 * s[t]; }
long long Y(int t){ return DP[t] + s[t] * s[t]; }
long long DX(int a, int b){ return X(b) - X(a); }
long long DY(int a, int b){ return Y(b) - Y(a); }
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    for (int i = 1; i <= n; i++)
      scanf("%lld", c + i);
    for (int i = 1; i <= n; i++)
      s[i] = s[i - 1] + c[i];
    int L = 0, R = 1;
    for (int i = 1; i <= n; i++){
      while (L + 1 < R && DY(Q[L], Q[L + 1]) <= s[i] * DX(Q[L], Q[L + 1]))  L++;
      DP[i] = Y(Q[L]) - 2 * s[i] * s[Q[L]] + s[i] * s[i] + m;
      while (L + 1 < R && DY(Q[R - 2], Q[R - 1]) * DX(Q[R - 1], i) >= DY(Q[R - 1], i) * DX(Q[R - 2], Q[R - 1])) R--;
      Q[R++] = i;
    }
    printf("%lld\n", DP[n]);
  }
  return 0;
}
/*

Print Article

Time Limit: 9000/3000 MS (Java/Others)    Memory Limit: 131072/65536 K (Java/Others)
Total Submission(s): 6961    Accepted Submission(s): 2153

Problem Description
Zero has an old printer that doesn't work well sometimes. As it is antique, he still like to use it to print articles. But it is too old to work for a long time and it will certainly wear and tear, so Zero use a cost to evaluate this degree.
One day Zero want to print an article which has N words, and each word i has a cost Ci to be printed. Also, Zero know that print k words in one line will cost

M is a const number.
Now Zero want to know the minimum cost in order to arrange the article perfectly.

Input
There are many test cases. For each test case, There are two numbers N and M in the first line (0 ≤ n ≤ 500000, 0 ≤ M ≤ 1000). Then, there are N numbers in the next 2 to N + 1 lines. Input are terminated by EOF.

Output
A single number, meaning the mininum cost to print the article.

Sample Input
5 5
5
9
5
7
5

Sample Output
230

Author
Xnozero

Source
2010 ACM-ICPC Multi-University Training Contest（7）——Host by HIT

Recommend
zhengfeng   |   We have carefully selected several similar problems for you:  3506 3501 3504 3505 3498 

*/