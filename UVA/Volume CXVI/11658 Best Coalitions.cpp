/* 14188616	11658	Best Coalitions	Accepted	C++	0.026	2014-09-12 06:54:26 */
// C++
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 105
#define MAX_M 10000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n && m){
		int S[MAX_N];
		bool DP[MAX_M + 1] = { false };
		for (int i = 1; i <= n; i++){
			double tmp;
			scanf("%lf", &tmp);
			S[i] = tmp * 100 + 1e-9;
		}
		DP[S[m]] = true;
		for (int i = 1; i <= n; i++){
			if (i == m)continue;
			for (int j = MAX_M; j - S[i] >= S[m]; j--)
				DP[j] |= DP[j - S[i]];
		}
		for (int i = MAX_M / 2 + 1; i <= MAX_M; i++){
			if (DP[i]){
				printf("%.2lf\n", (double)S[m] / i * 100 + 1e-9);
				break;
			}
		}
	}
	return 0;
}
/*


Best Coalitions
Envy Inc. is a joint stock company, that is, a company in which every stockholder legally owns shares of stock that account for some percentage of the total shares of stock of the company. Due to the global economic crisis, the management rules of Envy Inc. define a particular way for distributing last year's profit: if a stockholder owns more than half of the shares of stock, he/she wins the total profit. Nothing fancy so far in this wild world!
Nevertheless, there are situations in which no stockholder owns more than 50% of the shares of stock of the company. So, in order to gain some profit, stockholders are allowed to form coalitions, i.e., groups of stockholders. The participation of the coalition, share-wise, is equivalent to the sum of its stockholders' percentile participation. Hence, if a coalition has more than half of the shares of stock, its members win the totality of last years profit. Then, the members of the coalition receive a part of the profit proportional to their individual participation in the coalition.

For instance, let us assume there are 5 stockholders: A, B, C, D and E, owning 20%, 12%, 14%, 29% and 25% of the stock of the company, respectively. The stockholder E could form several winning coalitions. For example, if E were to form a coalition with A and B, he/she would get 43.86% of last year's profit. If E were to form a coalition with B and C instead, he/she would get 49.02% of last year's profit. On the other hand, E could not form a winning coalition with only A.

Your problem is, given a distribution of shares of stock of Envy Inc., and a stockholder, to determine the maximum percentage of the last year's profit that the given stockholder may win.

Input

The input consists of several test cases, each one defining a percentile distribution of shares of stock, and the index of a stockholder to determine his/her optimal participation. More precisely, each test case is defined by several input lines:

the first line contains two integer values n ( 1 $ \leq$ n $ \leq$ 100) and x ( 1 $ \leq$ x $ \leq$ n), separated by a blank, representing the number of stockholders in Envy Inc. and the index of a stockholder to determine his/her optimal participation, respectively;
each one of the following n lines has a single floating point value pi, rounded to 2 decimal places, which represents the percentage of stock ownership of stockholder i ( 1 $ \leq$ i $ \leq$ n). The floating point delimiter is `.' (i.e. the dot). You can assume that p1 +...+ pn = 100.
The end of the input is indicated by n = x = 0, an artificial case that must be ignored.

Output

For each given case, output a single line with the corresponding answer. The answer should be formatted and approximated to two decimal places. The floating point delimiter must be `.' (i.e. the dot). The rounding applies towards the nearest neighbor unless both neighbors are equidistant, in which case the result is rounded up (e.g. 78.312 is rounded to 78.31; 78.566 is rounded to 78.57; 78.345 is rounded to 78.35, etc.).

Sample Input

5 5
20.00
12.00
29.00
14.00
25.00
2 1
56.87
43.13
2 2
56.87
43.13
3 1
10.00
45.00
45.00
0 0
Sample Output

49.02
100.00
43.13
18.18

*/