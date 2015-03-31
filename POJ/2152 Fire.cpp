/* 13958458	840502	2152	Accepted	8700K	875MS	G++	1783B	2015-03-13 19:58:17
 */
#include<bits\stdc++.h>
#define N 1005
using namespace std;
struct Edge{
	int v, d;
	Edge(){}
	Edge(int v, int d) :v(v), d(d){}
};
int n;
int w[N];
int limit[N];
int dist[N][N];
int DP[N][N];
int res[N];
vector<Edge> G[N];
void DFS1(int source, int cur, int prev, int d){
	dist[source][cur] = dist[cur][source] = d;
	for (int i = 0; i < G[cur].size(); i++){
		Edge &next = G[cur][i];
		if (next.v == prev)	continue;
		DFS1(source, next.v, cur, d + next.d);
	}
}
void DFS2(int cur, int prev){
	for (int i = 0; i < G[cur].size(); i++){
		Edge &next = G[cur][i];
		if (next.v != prev)
			DFS2(next.v, cur);
	}
	for (int i = 1; i <= n; i++){
		if (dist[cur][i] <= limit[cur]){
			DP[cur][i] = w[i];
			for (int j = 0; j < G[cur].size(); j++){
				Edge &next = G[cur][j];
				if (next.v == prev)	continue;
				DP[cur][i] += min(DP[next.v][i] - w[i], res[next.v]);
			}
			res[cur] = min(res[cur], DP[cur][i]);
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", w + i);
		for (int i = 1; i <= n; i++)
			scanf("%d", limit + i);
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 0; i < n - 1; i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			G[a].push_back(Edge(b, d));
			G[b].push_back(Edge(a, d));
		}
		for (int i = 1; i <= n; i++)
			DFS1(i, i, i, 0);
		memset(DP, 0x7f, sizeof(DP));
		memset(res, 0x7f, sizeof(res));
		DFS2(1, 1);
		printf("%d\n", res[1]);
	}
	return 0;
}
/*

Fire
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 1145		Accepted: 581
Description

Country Z has N cities, which are numbered from 1 to N. Cities are connected by highways, and there is exact one path between two different cities. Recently country Z often caught fire, so the government decided to build some firehouses in some cities. Build a firehouse in city K cost W(K). W for different cities may be different. If there is not firehouse in city K, the distance between it and the nearest city which has a firehouse, can¡¦t be more than D(K). D for different cities also may be different. To save money, the government wants you to calculate the minimum cost to build firehouses.
Input

The first line of input contains a single integer T representing the number of test cases. The following T blocks each represents a test case.

The first line of each block contains an integer N (1 < N <= 1000). The second line contains N numbers separated by one or more blanks. The I-th number means W(I) (0 < W(I) <= 10000). The third line contains N numbers separated by one or more blanks. The I-th number means D(I) (0 <= D(I) <= 10000). The following N-1 lines each contains three integers u, v, L (1 <= u, v <= N¡A0 < L <= 1000), which means there is a highway between city u and v of length L.
Output

For each test case output the minimum cost on a single line.
Sample Input

5
5
1 1 1 1 1
1 1 1 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5
1 1 1 1 1
2 1 1 1 2
1 2 1
2 3 1
3 4 1
4 5 1
5
1 1 3 1 1
2 1 1 1 2
1 2 1
2 3 1
3 4 1
4 5 1
4
2 1 1 1
3 4 3 2
1 2 3
1 3 3
1 4 2
4
4 1 1 1
3 4 3 2
1 2 3
1 3 3
1 4 2
Sample Output

2
1
2
2
3
Source

POJ Monthly,Lou Tiancheng

*/