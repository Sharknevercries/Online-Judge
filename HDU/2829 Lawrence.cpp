/* 14031426	2015-07-16 16:27:11	Accepted	2829	624MS	9540K	1472 B	C++	Shark */
#include<bits\stdc++.h>
#define MAXN 1005
using namespace std;
int n, m;
long long a[MAXN];
long long s[MAXN];
long long w[MAXN];
long long DP[MAXN][MAXN];
int Q[MAXN];
long long X(int t){ return s[t]; }
long long Y(int i, int t){ return DP[i - 1][t] + s[t] * s[t] - w[t]; }
long long DX(int a, int b){ return X(b) - X(a); }
long long DY(int i, int a, int b){ return Y(i, b) - Y(i, a); }
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    if (n == 0 && m == 0) break;
    memset(s, 0, sizeof(s));
    memset(w, 0, sizeof(w));
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= n; i++)
      scanf("%lld", a + i);
    for (int i = 1; i <= n; i++){
      s[i] = s[i - 1] + a[i];
      w[i] = w[i - 1] + a[i] * s[i - 1];
      DP[0][i] = w[i];
    }
    for (int i = 1; i <= m; i++){
      int L = 0, R = 0;
      for (int j = 1; j <= n; j++){
        while (L < R && DY(i, Q[L], Q[L + 1]) <= s[j] * DX(Q[L], Q[L + 1]))  L++;
        DP[i][j] = Y(i, Q[L]) - s[Q[L]] * s[j] + w[j];
        while (L < R && DY(i, Q[R - 1], Q[R]) * DX(Q[R], j) >= DY(i, Q[R], j) * DX(Q[R - 1], Q[R])) R--;
        Q[++R] = j;
      }
    }
    printf("%lld\n", DP[m][n]);
  }
  return 0;
}

/*

Lawrence

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2678    Accepted Submission(s): 1193

Problem Description
T. E. Lawrence was a controversial figure during World War I. He was a British officer who served in the Arabian theater and led a group of Arab nationals in guerilla strikes against the Ottoman Empire. His primary targets were the railroads. A highly fictionalized version of his exploits was presented in the blockbuster movie, "Lawrence of Arabia".

You are to write a program to help Lawrence figure out how to best use his limited resources. You have some information from British Intelligence. First, the rail line is completely linear---there are no branches, no spurs. Next, British Intelligence has assigned a Strategic Importance to each depot---an integer from 1 to 100. A depot is of no use on its own, it only has value if it is connected to other depots. The Strategic Value of the entire railroad is calculated by adding up the products of the Strategic Values for every pair of depots that are connected, directly or indirectly, by the rail line. Consider this railroad:

Its Strategic Value is 4*5 + 4*1 + 4*2 + 5*1 + 5*2 + 1*2 = 49.

Now, suppose that Lawrence only has enough resources for one attack. He cannot attack the depots themselves---they are too well defended. He must attack the rail line between depots, in the middle of the desert. Consider what would happen if Lawrence attacked this rail line right in the middle:

The Strategic Value of the remaining railroad is 4*5 + 1*2 = 22. But, suppose Lawrence attacks between the 4 and 5 depots:


The Strategic Value of the remaining railroad is 5*1 + 5*2 + 1*2 = 17. This is Lawrence's best option.

Given a description of a railroad and the number of attacks that Lawrence can perform, figure out the smallest Strategic Value that he can achieve for that railroad.

Input
There will be several data sets. Each data set will begin with a line with two integers, n and m. n is the number of depots on the railroad (1≤n≤1000), and m is the number of attacks Lawrence has resources for (0≤m<n). On the next line will be n integers, each from 1 to 100, indicating the Strategic Value of each depot in order. End of input will be marked by a line with n=0 and m=0, which should not be processed.

Output
For each data set, output a single integer, indicating the smallest Strategic Value for the railroad that Lawrence can achieve with his attacks. Output each integer in its own line.

Sample Input
4 1
4 5 1 2
4 2
4 5 1 2
0 0

Sample Output
17
2

Source
2009 Multi-University Training Contest 2 - Host by TJU


Recommend
gaojie   |   We have carefully selected several similar problems for you:  2830 2832 2828 2827 2833 

*/