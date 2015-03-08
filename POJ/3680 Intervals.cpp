/* 13881546	840502	3680	Accepted	1164K	1079MS	G++	2686B	2015-02-11 20:19:37 */
#include<bits\stdc++.h>
#define N 505
#define M 1005
#define INF 1e9
using namespace std;
struct segment{
	int L, R, w;
	segment(){}
	segment(int L, int R, int w) :L(L), R(R), w(w){}
};
struct Edge{
	int v, cap, cost, rev;
	bool mark;
	Edge(){}
	Edge(int v, int cap, int cost, int rev, bool mark) :v(v), cap(cap), cost(cost), rev(rev), mark(mark){}
};
vector<Edge> G[N];
vector<segment> seg;
int A[N], B[100005];
int n, m, ptr;
void addEdge(int u, int v, int cap, int cost){
	G[u].push_back(Edge(v, cap, cost, G[v].size(), true));
	G[v].push_back(Edge(u, 0, -cost, G[u].size() - 1, false));
}
int minCostMaxFlow(int s, int t, int &min_cost){
	int dist[N];
	int pre_vtx[N];
	int pre_edge[N];
	queue <int> Q;
	min_cost = 0;
	int max_flow = 0;
	while (true){
		for (int i = 0; i < ptr; i++)
			dist[i] = INF;
		dist[s] = 0;
		bool inqueue[N] = { false };
		inqueue[s] = true;
		Q.push(s);
		while (!Q.empty()){
			int u = Q.front();
			for (size_t i = 0; i < G[u].size(); i++){
				Edge &e = G[u][i];
				if (e.cap && dist[u] + e.cost<dist[e.v]){
					dist[e.v] = dist[u] + e.cost;
					pre_vtx[e.v] = u;
					pre_edge[e.v] = i;
					if (!inqueue[e.v]){
						Q.push(e.v);
						inqueue[e.v] = true;
					}
				}
			}
			Q.pop();
			inqueue[u] = false;
		}
		if (dist[t] == INF)
			break;
		int tmp_flow = INF;
		for (int v = t; v != s; v = pre_vtx[v])
			tmp_flow = min(tmp_flow, G[pre_vtx[v]][pre_edge[v]].cap);
		for (int v = t; v != s; v = pre_vtx[v]){
			Edge &e = G[pre_vtx[v]][pre_edge[v]];
			e.cap -= tmp_flow;
			G[v][e.rev].cap += tmp_flow;
		}
		max_flow += tmp_flow;
		min_cost += tmp_flow*dist[t];
	}
	return max_flow;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		seg.clear(), ptr = 1;
		for (int i = 1; i <= n; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			seg.push_back(segment(a, b, w));
			A[ptr++] = a;
			A[ptr++] = b;
		}
		sort(A + 1, A + ptr);
		int k = 1;
		for (int i = 2; i < ptr; i++)
			if (A[k] != A[i])
				A[++k] = A[i];
		ptr = k + 1;
		for (int i = 0; i <= ptr; i++)
			G[i].clear();
		addEdge(0, 1, m, 0);
		for (int i = 1; i < ptr; i++)
			B[A[i]] = i, addEdge(i, i + 1, m, 0);
		for (int i = 0; i < seg.size(); i++)
			addEdge(B[seg[i].L], B[seg[i].R], 1, -seg[i].w);
		int ans;
		minCostMaxFlow(0, ptr - 1, ans);
		printf("%d\n", -ans);
	}
	return 0;
}
/*

Description

You are given N weighted open intervals. The ith interval covers (ai, bi) and weighs wi. Your task is to pick some of the intervals to maximize the total weights under the limit that no point in the real axis is covered more than k times.

Input

The first line of input is the number of test case.
The first line of each test case contains two integers, N and K (1 ≤ K ≤ N ≤ 200).
The next N line each contain three integers ai, bi, wi(1 ≤ ai < bi ≤ 100,000, 1 ≤ wi ≤ 100,000) describing the intervals.
There is a blank line before each test case.

Output

For each test case output the maximum total weights in a separate line.

Sample Input

4

3 1
1 2 2
2 3 4
3 4 8

3 1
1 3 2
2 3 4
3 4 8

3 1
1 100000 100000
1 2 3
100 200 300

3 2
1 100000 100000
1 150 301
100 200 300
Sample Output

14
12
100000
100301
Source

POJ Founder Monthly Contest – 2008.07.27, windy7926778 

*/