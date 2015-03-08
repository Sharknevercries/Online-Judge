/* 13929806	840502	1160	Accepted	1428K	47MS	G++	932B	2015-03-05 02:10:35 */
#include<bits\stdc++.h>
using namespace std;
int n, m, d[305];
int DP[305][305];
int r[305][305];
int dist[305][305];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", d + i);
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int mid = (i + j) / 2;
			dist[i][j] = 0;
			for (int k = i; k <= j; k++)
				dist[i][j] += abs(d[k] - d[mid]);
		}
	}
	memset(DP, 0x3f, sizeof(DP));
	DP[0][0] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			for (int k = i; k <= j; k++)
				DP[i][j] = min(DP[i][j], DP[i - 1][k - 1] + dist[k][j]);
	printf("%d\n", DP[m][n]);
	return 0;
}
/*

Post Office
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 16435		Accepted: 8908
Description

There is a straight highway with villages alongside the highway. The highway is represented as an integer axis, and the position of each village is identified with a single integer coordinate. There are no two villages in the same position. The distance between two positions is the absolute value of the difference of their integer coordinates.

Post offices will be built in some, but not necessarily all of the villages. A village and the post office in it have the same position. For building the post offices, their positions should be chosen so that the total sum of all distances between each village and its nearest post office is minimum.

You are to write a program which, given the positions of the villages and the number of post offices, computes the least possible sum of all distances between each village and its nearest post office.
Input

Your program is to read from standard input. The first line contains two integers: the first is the number of villages V, 1 <= V <= 300, and the second is the number of post offices P, 1 <= P <= 30, P <= V. The second line contains V integers in increasing order. These V integers are the positions of the villages. For each position X it holds that 1 <= X <= 10000.
Output

The first line contains one integer S, which is the sum of all distances between each village and its nearest post office.
Sample Input

10 5
1 2 3 6 7 9 11 22 44 50
Sample Output

9
Source

IOI 2000

*/