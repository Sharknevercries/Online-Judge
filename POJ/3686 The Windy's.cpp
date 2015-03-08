/* 13884121	840502	3686	Accepted	1360K	16MS	G++	1904B	2015-02-12 16:08:06 */
#include<bits\stdc++.h>
#define N 55
#define INF 1e9
using namespace std;
int n, m;
int T[N][N], w[N*N][N*N];
int lx[N*N], ly[N*N], match[N*N], slack[N*N];
bool vx[N*N], vy[N*N];
bool DFS(int u){
	vx[u] = true;
	for (int v = 0; v < m; v++){
		if (vy[v])continue;
		int t = lx[u] + ly[v] - w[u][v];
		if (t == 0){
			vy[v] = true;
			if (match[v] == -1 || DFS(match[v])){
				match[v] = u;
				return true;
			}
		}
		else
			slack[v] = min(slack[v], t);
	}
	return false;
}
double KM(){
	memset(match, -1, sizeof(match));
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			lx[i] = max(lx[i], w[i][j]);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			slack[j] = INF;
		while (true){
			memset(vx, false, sizeof(vx));
			memset(vy, false, sizeof(vy));
			if (DFS(i))break;
			int d = INF;
			for (int j = 0; j < m; j++)
				if (!vy[j])
					d = min(d, slack[j]);
			for (int j = 0; j < n; j++)
				if (vx[j])
					lx[j] -= d;
			for (int j = 0; j < m; j++)
				if (vy[j])
					ly[j] += d;
				else
					slack[j] -= d;
		}
	}
	double res = 0;
	for (int i = 0; i < m; i++)
		if (match[i] != -1)
			res += w[match[i]][i];
	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &T[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 1; k <= n; k++)
					w[i][j + (k - 1)*m] = -T[i][j] * k;
		m = n*m;
		printf("%.6f\n", -KM() / (n*1.0));
		// try to use %f to get AC in G++
	}
	return 0;
}
/*

Description

The Windy's is a world famous toy factory that owns M top-class workshop to make toys. This year the manager receives N orders for toys. The manager knows that every order will take different amount of hours in different workshops. More precisely, the i-th order will take Zij hours if the toys are making in the j-th workshop. Moreover, each order's work must be wholly completed in the same workshop. And a workshop can not switch to another order until it has finished the previous one. The switch does not cost any time.

The manager wants to minimize the average of the finishing time of the N orders. Can you help him?

Input

The first line of input is the number of test case. The first line of each test case contains two integers, N and M (1 ≤ N,M ≤ 50).
The next N lines each contain M integers, describing the matrix Zij (1 ≤ Zij ≤ 100,000) There is a blank line before each test case.

Output

For each test case output the answer on a single line. The result should be rounded to six decimal places.

Sample Input

3

3 4
100 100 100 1
99 99 99 1
98 98 98 1

3 4
1 100 100 100
99 1 99 99
98 98 1 98

3 4
1 100 100 100
1 99 99 99
98 1 98 98
Sample Output

2.000000
1.000000
1.333333

Source

POJ Founder Monthly Contest – 2008.08.31, windy7926778

*/