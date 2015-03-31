/* 14007101	840502	3254	Accepted	1180K	110MS	G++	1260B	2015-03-25 20:44:17 */
#include<bits\stdc++.h>
using namespace std;
int T[15][15];
long long int DP[4500][15];
int n, m;
bool check(int state1, int state2, int row){
	int mask = 3;
	for (int j = state1; j > 0; j >>= 1)
		if ((j & mask) == 3)
			return false;
	for (int i = 0, j = state1; i < m && j > 0; i++, j >>= 1)
		if (!(T[row][i] == 1 || !(j & 1)))
			return false;
	if (state1 & state2)
		return false;
	return true;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &T[i][j]);
		for (int i = 0; i < (1 << m); i++)
			if (check(i, 0, 0))
				DP[i][0] = 1;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < (1 << m); j++)
				for (int k = 0; k < (1 << m); k++)
					if (check(j, k, i))
						DP[j][i] = (DP[j][i] + DP[k][i - 1]) % 100000000;
		long long int ans = 0;
		for (int i = 0; i < (1 << m); i++)
			ans += DP[i][n - 1];
		printf("%lld\n", ans % 100000000);
	}
	return 0;
}
/*

Corn Fields
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 8815		Accepted: 4701
Description

Farmer John has purchased a lush new rectangular pasture composed of M by N (1 ≤ M ≤ 12; 1 ≤ N ≤ 12) square parcels. He wants to grow some yummy corn for the cows on a number of squares. Regrettably, some of the squares are infertile and can't be planted. Canny FJ knows that the cows dislike eating close to each other, so when choosing which squares to plant, he avoids choosing squares that are adjacent; no two chosen squares share an edge. He has not yet made the final choice as to which squares to plant.

Being a very open-minded man, Farmer John wants to consider all possible options for how to choose the squares for planting. He is so open-minded that he considers choosing no squares as a valid option! Please help Farmer John determine the number of ways he can choose the squares to plant.

Input

Line 1: Two space-separated integers: M and N
Lines 2..M+1: Line i+1 describes row i of the pasture with N space-separated integers indicating whether a square is fertile (1 for fertile, 0 for infertile)
Output

Line 1: One integer: the number of ways that FJ can choose the squares modulo 100,000,000.
Sample Input

2 3
1 1 1
0 1 0
Sample Output

9
Hint

Number the squares as follows:
1 2 3
4

There are four ways to plant only on one squares (1, 2, 3, or 4), three ways to plant on two squares (13, 14, or 34), 1 way to plant on three squares (134), and one way to plant on no squares. 4+3+1+1=9.
Source

USACO 2006 November Gold

*/