/* 13917729	840502	3728	Accepted	7372K	844MS	G++	2441B	2015-02-27 23:34:50 */
#include<bits\stdc++.h>
#define N 50005
using namespace std;
int n, q;
struct Edge{
	int u, v, next;
};
struct Query{
	int u, v, lca, next;
};
struct Res{
	int n, next;
};
Edge E[5 * N];
int headE[N], totalE;
Query Q[5 * N];
int headQ[N], totalQ;
Res R[5 * N];
int headR[N], totalR;
int w[N], fa[N];
int A[N], B[N], C[N], D[N];
bool V[N];
int ans[N];
void addEdge(int u, int v){
	E[totalE].u = u, E[totalE].v = v;
	E[totalE].next = headE[u], headE[u] = totalE++;
}
void addQuery(int u, int v){
	Q[totalQ].u = u, Q[totalQ].v = v, Q[totalQ].lca = -1;
	Q[totalQ].next = headQ[u], headQ[u] = totalQ++;
}
void addRes(int u, int k){
	R[totalR].n = k, R[totalR].next = headR[u], headR[u] = totalR++;
}
int update(int x){
	if (x == fa[x])return x;
	int parent = fa[x];
	fa[x] = update(fa[x]);
	A[x] = max(A[x], max(A[parent], C[parent] - D[x]));
	B[x] = max(B[x], max(B[parent], C[x] - D[parent]));
	C[x] = max(C[x], C[parent]);
	D[x] = min(D[x], D[parent]);
	return fa[x];
}
void tarjan(int x){
	for (int i = headQ[x]; i != -1; i = Q[i].next){
		int v = Q[i].v;
		if (V[v])
			addRes(update(v), i);
	}
	V[x] = true, fa[x] = x;
	for (int i = headE[x]; i != -1; i = E[i].next){
		int v = E[i].v;
		if (!V[v]){
			tarjan(v), fa[v] = x;
		}
	}
	for (int i = headR[x]; i != -1; i = R[i].next){
		int k = R[i].n, a = Q[k].u, b = Q[k].v;
		if (k & 1)
			k ^= 1, swap(a, b);
		k /= 2;
		update(a), update(b);
		ans[k] = max(A[a], B[b]);
		ans[k] = max(ans[k], C[b] - D[a]);
	}
}
int main(){
	totalE = totalQ = totalR = 0;
	memset(headE, -1, sizeof(headE));
	memset(headQ, -1, sizeof(headQ));
	memset(headR, -1, sizeof(headR));
	memset(V, false, sizeof(V));
	memset(ans, 0, sizeof(ans));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", w + i);
		A[i] = B[i] = 0;
		C[i] = D[i] = w[i];
	}
	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		addEdge(a, b);
		addEdge(b, a);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		addQuery(a, b);
		addQuery(b, a);
	}
	tarjan(1);
	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	return 0;
}
/*

The merchant
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 3374		Accepted: 1123
Description

There are N cities in a country, and there is one and only one simple path between each pair of cities. A merchant has chosen some paths and wants to earn as much money as possible in each path. When he move along a path, he can choose one city to buy some goods and sell them in a city after it. The goods in all cities are the same but the prices are different. Now your task is to calculate the maximum possible profit on each path.

Input

The first line contains N, the number of cities.
Each of the next N lines contains wi the goods' price in each city.
Each of the next N-1 lines contains labels of two cities, describing a road between the two cities.
The next line contains Q, the number of paths.
Each of the next Q lines contains labels of two cities, describing a path. The cities are numbered from 1 to N.

1 ≤ N, wi, Q ≤ 50000

Output

The output contains Q lines, each contains the maximum profit of the corresponding path. If no positive profit can be earned, output 0 instead.

Sample Input

4
1
5
3
2
1 3
3 2
3 4
9
1 2
1 3
1 4
2 3
2 1
2 4
3 1
3 2
3 4
Sample Output

4
2
2
0
0
0
0
2
0
Source

POJ Monthly Contest – 2009.04.05, GaoYihan

*/