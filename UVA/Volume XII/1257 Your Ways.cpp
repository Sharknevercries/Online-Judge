/* 15360057	1257	Your Ways	Accepted	C++	0.549	2015-04-21 08:27:34 */
#include<bits\stdc++.h>
#define MOD 2552
using namespace std;
struct Block{
	pair<int, int> source;
	pair<int, int> effect;
};
int DP[1005][1005];
int newDP[1005][1005];
vector< pair<int, int> > record;
Block B[105];
bool cmp(Block A, Block B){
	return A.effect.second < B.effect.second || A.effect.second == B.effect.second && A.effect.first < B.effect.first;
}
void add(int &a, int b){
	a += b;
	a %= MOD;
}
void sub(int &a, int b){
	a -= b;
	a %= MOD;
	if (a < 0)	a += MOD;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m, k, q;
		scanf("%d%d%d", &n, &m, &k);
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i <= m; i++)
			DP[0][i] = 1;
		for (int i = 0; i <= n; i++)
			DP[i][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % MOD;
		for (int i = 0; i < k; i++){
			record.clear();
			int res = DP[n][m];
			scanf("%d", &q);
			for (int j = 0; j < q; j++){
				pair<int, int> P[2];
				for (int u = 0; u < 2; u++)
					scanf("%d%d", &P[u].first, &P[u].second);
				sort(P, P + 2);
				if (P[0].first == P[1].first){
					if (P[0].second < P[1].second)
						B[j].source = P[0], B[j].effect = P[1];
					else
						B[j].source = P[1], B[j].effect = P[0];
				}
				if (P[0].second == P[1].second){
					if (P[0].first < P[1].first)
						B[j].source = P[0], B[j].effect = P[1];
					else
						B[j].source = P[1], B[j].effect = P[0];
				}
				bool repeat = false;
				for (int u = 0; u < record.size() && !repeat; u++)
					if (record[u] == B[j].source)
						repeat = true;
				if (!repeat)
					record.push_back(B[j].source);
			}
			for (int j = 0; j < record.size(); j++)
				newDP[record[j].first][record[j].second] = DP[record[j].first][record[j].second];
			for (int a = 0; a < q; a++){
				sub(res, newDP[B[a].source.first][B[a].source.second] * (DP[n - B[a].effect.first][m - B[a].effect.second]));
				for (int b = 0; b < record.size(); b++)
					if (record[b].first >= B[a].effect.first && record[b].second >= B[a].effect.second)
						sub(res, newDP[B[a].source.first][B[a].source.second] * (DP[record[b].first - B[a].effect.first][record[b].second - B[a].effect.second]));
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
/*

You live in a small well-planned rectangular town in Phuket. The size of the central area of the town is H kilometers x W kilometers. The central area is divided into HW unit blocks, each of size 1 x 1 km2. There are H + 1 streets going in the West to East direction, and there are W + 1 avenue going in the North-South direction. The central area can be seen as a rectangle on the plane, as shown below.

\epsfbox{p4717.eps}
Figure 1. The central area for a town where H = 3, and W = 6.
We can identify each intersection by its co-ordinate on the plane. For example, on the Figure above the bottom-left corner is intersection (0,0), and the top-right corner is intersection (6,3).

Your house is at the bottom-left corner (i.e., intersection (0,0)) and you want to go to the university at the top-right corner (i.e., intersection (W, H)). More over, you only want to go to the university with wasting any efforts; therefore, you only want to walk from West-to-East and South-to-North directions. Walking this way, in the example above there are 84 ways to reach the university.

You want to go to the university for K days. Things get more complicated when each morning, the city blocks parts of streets and avenues to do some cleaning. The blocking is done in such a way that it is not possible to reach parts of the streets or avenues which is blocked from some other part which is blocked as well through any paths containing only West-to-East and South-to-North walks.

You still want to go to the university using the same West-to-East and South-to-North strategy. You want to find out for each day, how many ways you can reach the university by only walking West-to-East and South-to-North. Since the number can be very big, we only want the result modulo 2552.

Input

The first line contains an integer T, the number of test cases (1$ \le$T$ \le$5). Each test case is in the following format.

The first line of each test case contains 3 integers: W, H, and K (1$ \le$W$ \le$1, 000;1$ \le$H$ \le$1, 000;1$ \le$K$ \le$10, 000). W and H specify the size of the central area. K denotes the number of days you want to go to the university.

The next K lines describe the information on broken parts of streets and avenues. More specifically, line 1 + i, for 1$ \le$i$ \le$K, starts with an integer Qi (1$ \le$Qi$ \le$100) denoting the number of parts which are blocked. Then Qi sets of 4 integers describing the blocked parts follow. Each part is described with 4 integers, A, B, C, and D (0$ \le$A$ \le$C$ \le$W;0$ \le$B$ \le$D$ \le$H) meaning that the parts connecting intersection (A, B) and (C, D) is blocked. It is guaranteed that that part is a valid part of the streets or avenues, also C - A$ \le$1, and D - B$ \le$1, i.e., the part is 1 km long.

Output

For each test case, for each day, your program must output the number of ways to go to the university modulo 2552 on a separate line. i.e., the output for each test case must contains K lines.


A technical note to Java programmers:

The amount of I/O for this task is quite large. Therefore, when reading input, you should avoid using java.io.Scanner which is much slower than using java.io.BufferedReader.

Sample Input

2
2 2 3
1 0 0 0 1
2 1 0 2 0 0 2 1 2
1 1 1 2 1
100 150 2
1 99 150 100 150
2 99 150 100 150 100 149 100 150
Sample Output

3
4
4
1562
0

*/