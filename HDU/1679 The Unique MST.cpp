/* 13806704	840502	1679	Accepted	324K	0MS	C++	2392B	2015-01-23 14:52:06 */
#include<bits\stdc++.h>
#define INF 2e9
#define N 105
#define M 10005
using namespace std;
struct edge{
	int a, b, w, id;
	friend bool operator<(edge x, edge y){ return x.w < y.w; }
};
edge E[M];
int P[N];
bool inMST[M];
vector<pair<int, int>> adj[N];
int Fa[N], Fb[N], toRoot[N];
int w[M], s[M], _i;
int mst;
int n, m;
int find(int x){
	return x == P[x] ? x : P[x] = find(P[x]);
}
void Kruskal(){
	for (int i = 0; i < n; i++)
		P[i] = i;
	sort(E, E + m);
	for (int i = 0; i < m; i++){
		int p = find(E[i].a);
		int q = find(E[i].b);
		if (p != q){
			P[q] = p;
			inMST[E[i].id] = true;
			adj[E[i].a].push_back(make_pair(E[i].b, E[i].id));
			adj[E[i].b].push_back(make_pair(E[i].a, E[i].id));
			mst += E[i].w;
		}
	}
}
void DFS(int u, int prev){
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i].first;
		if (v != prev)
			Fa[v] = u, Fb[v] = adj[u][i].second, DFS(v, u);
	}
}
int LCA(int a, int b){
	while (a != 0)
		toRoot[a] = _i, a = Fa[a];
	toRoot[0] = _i;
	while (toRoot[b] != _i)
		b = Fa[b];
	return b;
}
void cloze(int a, int c){
	if (!s[a] && c >= w[a])
		s[a] = c;
}
void link(int a, int b, int w){
	int p = LCA(a, b), tmp;
	while (a != p){
		cloze(Fb[a], w); 
		tmp = Fa[a], Fa[a] = p, a = tmp;
	}
	while (b != p){
		cloze(Fb[b], w); 
		tmp = Fa[b], Fb[b] = p, b = tmp;
	}
}
void state(){
	DFS(0, -1);
	for (int i = 0; i < m; i++){
		if (inMST[E[i].id])	continue;
		_i = i + 1;
		link(E[i].a, E[i].b, E[i].w);
	}
}
void init(){
	mst = 0;
	memset(s, 0, sizeof(s));
	memset(w, 0, sizeof(w));
	memset(inMST, false, sizeof(inMST));
	for (int i = 0; i < n; i++)
		adj[i].clear();
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		init();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].w), E[i].a--, E[i].b--, E[i].id = i, w[i] = E[i].w;
		Kruskal();
		state();
		int ans = INF;
		for (int i = 0; i < m; i++)
			if (inMST[i] && s[i])
				ans = min(ans, mst - w[i] + s[i]);
		if (mst < ans)
			printf("%d\n", mst);
		else
			puts("Not Unique!");
	}
	return 0;
}
/*

The Unique MST
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 21536		Accepted: 7606
Description

Given a connected undirected graph, tell if its minimum spanning tree is unique.

Definition 1 (Spanning Tree): Consider a connected, undirected graph G = (V, E). A spanning tree of G is a subgraph of G, say T = (V', E'), with the following properties:
1. V' = V.
2. T is connected and acyclic.

Definition 2 (Minimum Spanning Tree): Consider an edge-weighted, connected, undirected graph G = (V, E). The minimum spanning tree T = (V, E') of G is the spanning tree that has the smallest total cost. The total cost of T means the sum of the weights on all the edges in E'.
Input

The first line contains a single integer t (1 <= t <= 20), the number of test cases. Each case represents a graph. It begins with a line containing two integers n and m (1 <= n <= 100), the number of nodes and edges. Each of the following m lines contains a triple (xi, yi, wi), indicating that xi and yi are connected by an edge with weight = wi. For any two nodes, there is at most one edge connecting them.
Output

For each input, if the MST is unique, print the total cost of it, or otherwise print the string 'Not Unique!'.
Sample Input

2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
Sample Output

3
Not Unique!
Source

POJ Monthly--2004.06.27 srbga@POJ

*/