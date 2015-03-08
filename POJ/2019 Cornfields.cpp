/* 13918597	840502	2019	Accepted	27876K	766MS	G++	2263B	2015-02-28 15:11:08 */
#include<bits\stdc++.h>
using namespace std;
int DPmin[255][255][9][9];
int DPmax[255][255][9][9];
int w[255][255];
int n, b, k;
void build(){
	for (int i = 0; (1 << i) <= n; i++){
		for (int j = 0; (1 << j) <= n; j++){
			if (i == 0 && j == 0)	continue;
			for (int p = 1; p + (1 << i) - 1 <= n; p++){
				for (int q = 1; q + (1 << j) - 1 <= n; q++){
					if (i == 0){
						DPmin[p][q][i][j] = min(DPmin[p][q][i][j - 1], DPmin[p][q + (1 << (j - 1))][i][j - 1]);
						DPmax[p][q][i][j] = max(DPmax[p][q][i][j - 1], DPmax[p][q + (1 << (j - 1))][i][j - 1]);
					}
					else{
						DPmin[p][q][i][j] = min(DPmin[p][q][i - 1][j], DPmin[p + (1 << (i - 1))][q][i - 1][j]);
						DPmax[p][q][i][j] = max(DPmax[p][q][i - 1][j], DPmax[p + (1 << (i - 1))][q][i - 1][j]);
					}
				}
			}
		}
	}
}
int query(int x1, int y1, int x2,int y2){
	int kx = (int)(log((double)x2 - x1 + 1) / log(2.0));
	int ky = (int)(log((double)y2 - y1 + 1) / log(2.0));
	int tmp1[4], tmp2[4], minValue = 2e9, maxValue = -2e9;
	tmp1[0] = DPmax[x1][y1][kx][ky];
	tmp1[1] = DPmax[x2 - (1 << kx) + 1][y1][kx][ky];
	tmp1[2] = DPmax[x1][y2 - (1 << ky) + 1][kx][ky];
	tmp1[3] = DPmax[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
	tmp2[0] = DPmin[x1][y1][kx][ky];
	tmp2[1] = DPmin[x2 - (1 << kx) + 1][y1][kx][ky];
	tmp2[2] = DPmin[x1][y2 - (1 << ky) + 1][kx][ky];
	tmp2[3] = DPmin[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
	for (int i = 0; i < 4; i++)
		maxValue = max(maxValue, tmp1[i]);
	for (int i = 0; i < 4; i++)
		minValue = min(minValue, tmp2[i]);
	return maxValue - minValue;
}
int main(){
	scanf("%d%d%d", &n, &b, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &w[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			DPmin[i][j][0][0] = DPmax[i][j][0][0] = w[i][j];
	build();
	for (int i = 0; i < k; i++){
		int r, c;
		scanf("%d%d", &r, &c);
		printf("%d\n", query(r, c, r + b - 1, c + b - 1));
	}
	return 0;
}
/*

Cornfields
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 5618		Accepted: 2764
Description

FJ has decided to grow his own corn hybrid in order to help the cows make the best possible milk. To that end, he's looking to build the cornfield on the flattest piece of land he can find.

FJ has, at great expense, surveyed his square farm of N x N hectares (1 <= N <= 250). Each hectare has an integer elevation (0 <= elevation <= 250) associated with it.

FJ will present your program with the elevations and a set of K (1 <= K <= 100,000) queries of the form "in this B x B submatrix, what is the maximum and minimum elevation?". The integer B (1 <= B <= N) is the size of one edge of the square cornfield and is a constant for every inquiry. Help FJ find the best place to put his cornfield.
Input

* Line 1: Three space-separated integers: N, B, and K.

* Lines 2..N+1: Each line contains N space-separated integers. Line 2 represents row 1; line 3 represents row 2, etc. The first integer on each line represents column 1; the second integer represents column 2; etc.

* Lines N+2..N+K+1: Each line contains two space-separated integers representing a query. The first integer is the top row of the query; the second integer is the left column of the query. The integers are in the range 1..N-B+1.
Output

* Lines 1..K: A single integer per line representing the difference between the max and the min in each query.
Sample Input

5 3 1
5 1 2 6 3
1 3 5 2 7
7 2 4 6 1
9 9 8 6 5
0 6 9 3 9
1 2
Sample Output

5
Source

USACO 2003 March Green

*/