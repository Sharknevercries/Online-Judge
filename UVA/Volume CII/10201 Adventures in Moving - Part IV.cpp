/* 13961589	10201	Adventures in Moving - Part IV	Accepted	C++	0.022	2014-07-29 08:01:18 */
/*

Template By Shark

*/
// C++
#include<iostream>
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
// const variable
#define MAX_N 200
#define MAX_M 10000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
lli DP[MAX_N + 1][MAX_N + 1];
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int D[MAX_N], W[MAX_N];
		char S[MAX_N];
		int n = 0, goal;
		scanf("%d", &goal);
		(void)getchar();
		D[n] = 0, W[n++] = INF;
		while (gets(S) && S[0] != '\0')
			sscanf(S, "%d%d", &D[n], &W[n]), n++;
		D[n] = goal, W[n++] = INF;
		for (int i = 0; i <= MAX_N; i++)
			for (int j = 0; j <= MAX_N; j++)
				DP[i][j] = INF;
		DP[0][100] = 0;
		for (int i = 1; i < n; i++){
			int dist = D[i] - D[i - 1];
			for (int j = dist; j <= 200; j++)
				DP[i][j - dist] = min(DP[i][j - dist], DP[i - 1][j]);
			for (int j = 1; j <= 200; j++)
				DP[i][j] = min(DP[i][j], DP[i][j - 1] + W[i]);
		}
		lli ans = INF;
		for (int i = 100; i <= 200; i++)
			ans = min(ans, DP[n - 1][i]);
		if (ans == INF)
			puts("Impossible");
		else
			printf("%lld\n", ans);
		if (t)	putchar('\n');
	}
	return 0;
}
/*

Problem A: Adventures in Moving - Part IV

To help you move from Waterloo to the big city, you are considering renting a moving truck. Gas prices being so high these days, you want to know how much the gas for such a beast will set you back.
The truck consumes a full litre of gas for each kilometre it travels. It has a 200 litre gas tank. When you rent the truck in Waterloo, the tank is half full. When you return it in the big city, the tank must be at least half full, or you'll get gouged even more for gas by the rental company. You would like to spend as little as possible on gas, but you don't want to run out along the way.

Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
Input is all integers. The first integer is the distance in kilometres from Waterloo to the big city, at most 10000. Next comes a set of up to 100 gas station specifications, describing all the gas stations along your route, in non-decreasing order by distance. Each specification consists of the distance in kilometres of the gas station from Waterloo, and the price of a litre of gas at the gas station, in tenths of a cent, at most 2000.

Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
Output is the minimum amount of money that you can spend on gas to get you from Waterloo to the big city. If it is not possible to get from Waterloo to the big city subject to the constraints above, print "Impossible".

Sample Input

1

500
100 999
150 888
200 777
300 999
400 1009
450 1019
500 1399

Output for Sample Input

450550

*/