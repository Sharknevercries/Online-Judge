/* 13880572	840502	2396	Accepted	2872K	94MS	G++	3676B	2015-02-11 15:27:38 */
#include<bits\stdc++.h>
#define N 25
#define M 205
#define INF 1e9
#define NONE -1
using namespace std;
struct Edge{
	int v, cap, rev;
	bool mark;
	Edge(){}
	Edge(int v, int cap, int rev, bool mark) :v(v), cap(cap), rev(rev), mark(mark){}
};
vector<Edge> G[N*M];
void addEdge(int u, int v, int cap){
	G[u].push_back(Edge(v, cap, G[v].size(), true));
	G[v].push_back(Edge(u, 0, G[u].size() - 1, false));
}
int level[N*M], iter[N*M];
void BFS(int s){
	memset(level, NONE, sizeof(level));
	queue<int> Q;
	level[s] = 0;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front();	Q.pop();
		for (int i = 0; i < G[u].size(); i++){
			Edge &e = G[u][i];
			if (e.cap > 0 && level[e.v] == NONE)
				level[e.v] = level[u] + 1, Q.push(e.v);
		}
	}
}
int DFS(int u, int t, int flow){
	if (u == t)	return flow;
	for (int &i = iter[u]; i < G[u].size(); i++){
		Edge &e = G[u][i];
		if (e.cap > 0 && level[u] < level[e.v]){
			int d = DFS(e.v, t, min(flow, e.cap));
			if (d > 0){
				e.cap -= d;
				G[e.v][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int maxFlow(int s, int t){
	int flow = 0;
	while (true){
		BFS(s);
		if (level[t] == NONE)
			return flow;
		memset(iter, 0, sizeof(iter));
		while (true){
			int tmp = DFS(s, t, INF);
			if (tmp <= 0)	break;
			flow += tmp;
		}
	}
}
int n, m;
int s, t;
int a[M], b[N], w[N + M];
int L[N*M][N*M], R[N*M][N*M];
int sumRow, sumCol;
bool init(){
	int p;
	scanf("%d%d", &m, &n);
	s = 0, t = n + m + 1;
	sumCol = sumRow = 0;
	for (int i = 1; i <= m; i++){
		scanf("%d", a + i);
		sumRow += a[i];
		w[i] = a[i];
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", b + i);
		sumCol += b[i];
		w[i + m] = -b[i];
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			R[i][j] = min(a[i], b[j]), L[i][j] = 0;
	scanf("%d", &p);
	while (p--){
		int u, v, x;
		char com;
		int L1, L2, R1, R2;
		scanf("%d %d %c %d", &u, &v, &com, &x);
		L1 = R1 = u, L2 = R2 = v;
		if (u == 0)L1 = 1, R1 = m;
		if (v == 0)L2 = 1, R2 = n;
		for (u = L1; u <= R1; u++)
			for (v = L2; v <= R2; v++)
				switch (com){
				case '>':	L[u][v] = max(L[u][v], x + 1);	break;
				case '=':	R[u][v] = min(R[u][v], x), L[u][v] = max(L[u][v], x);	break;
				case '<':	R[u][v] = min(R[u][v], x - 1);	break;
			}
	}
	if (sumCol != sumRow)
		return false;
	for (int i = 0; i <= t; i++)
		G[i].clear();
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (L[i][j] > R[i][j])	return false;
			addEdge(i, j + m, R[i][j] - L[i][j]);
			w[i] -= L[i][j], w[j + m] += L[i][j];
		}
	}
	for (int i = 1; i <= n + m; i++){
		if (w[i] > 0)addEdge(s, i, w[i]);
		if (w[i] < 0)addEdge(i, t, -w[i]);
	}
	return true;
}
bool solve(){
	int ans[M][N];
	maxFlow(s, t);
	for (int i = 0; i <= n + m + 1 + 1 + 1; i++){
		for (int j = 0; j < G[i].size(); j++){
			Edge e = G[i][j];
			if (!e.mark)	continue;
			if (i != 0 && i <= m && e.v > m && e.v <= m + n)
				ans[i][e.v - m] = G[e.v][e.rev].cap;
			else if (i == s && e.cap)
				return false;
		}
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (j != 1)	putchar(' ');
			printf("%d", ans[i][j] + L[i][j]);
		}
		putchar('\n');
	}
	return true;

}
int main(){
	int c;
	scanf("%d", &c);
	while (c--){
		if (!init() || !solve())
			puts("IMPOSSIBLE");
		if (!c)
			putchar('\n');
	}
	return 0;
}
/*

Description

We are supposed to make a budget proposal for this multi-site competition. The budget proposal is a matrix where the rows represent different kinds of expenses and the columns represent different sites. We had a meeting about this, some time ago where we discussed the sums over different kinds of expenses and sums over different sites. There was also some talk about special constraints: someone mentioned that Computer Center would need at least 2000K Rials for food and someone from Sharif Authorities argued they wouldn't use more than 30000K Rials for T-shirts. Anyway, we are sure there was more; we will go and try to find some notes from that meeting.

And, by the way, no one really reads budget proposals anyway, so we'll just have to make sure that it sums up properly and meets all constraints.
Input

The first line of the input contains an integer N, giving the number of test cases. The next line is empty, then, test cases follow: The first line of each test case contains two integers, m and n, giving the number of rows and columns (m <= 200, n <= 20). The second line contains m integers, giving the row sums of the matrix. The third line contains n integers, giving the column sums of the matrix. The fourth line contains an integer c (c < 1000) giving the number of constraints. The next c lines contain the constraints. There is an empty line after each test case.

Each constraint consists of two integers r and q, specifying some entry (or entries) in the matrix (the upper left corner is 1 1 and 0 is interpreted as "ALL", i.e. 4 0 means all entries on the fourth row and 0 0 means the entire matrix), one element from the set {<, =, >} and one integer v, with the obvious interpretation. For instance, the constraint 1 2 > 5 means that the cell in the 1st row and 2nd column must have an entry strictly greater than 5, and the constraint 4 0 = 3 means that all elements in the fourth row should be equal to 3.
Output

For each case output a matrix of non-negative integers meeting the above constraints or the string "IMPOSSIBLE" if no legal solution exists. Put one empty line between matrices.
Sample Input

2

2 3
8 10
5 6 7
4
0 2 > 2
2 1 = 3
2 3 > 2
2 3 < 5

2 2
4 5
6 7
1
1 1 > 10
Sample Output

2 3 3
3 3 4

IMPOSSIBLE

Source

Tehran 2003 Preliminary

*/