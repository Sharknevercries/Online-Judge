/* 5902343	 Feb 5, 2014 1:28:44 PM	Shark	 D - George and Interesting Graph	 GNU C++	Accepted	31 ms	232 KB */
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int E[10000][2];
int P[500];
bool visited[500];
vector<int> G[500];
int n, m;
bool DFS(int start){
	visited[start] = true;
	for (int i = 0; i < G[start].size(); i++){
		int end = G[start][i];
		if (P[end] == -1 || (!visited[P[end]] && DFS(P[end]))){
			P[end] = start;
			return true;
		}
	}
	return false;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 0; i < m; i++){
			scanf("%d%d", &E[i][0], &E[i][1]);
			E[i][0]--, E[i][1]--;
		}
		int ans = 2e9;
		for (int i = 0; i < n; i++){ // 窮舉每個頂點
			int res = 0, convertex = 0, other = 0, fix = 0;
			for (int j = 0; j < n; j++)
				G[j].clear(), P[j] = -1;
			for (int j = 0; j < m; j++){
				if (E[j][0] == i || E[j][1] == i)
					convertex++;
				else{
					other++;
					G[E[j][0]].push_back(E[j][1]);
				}
			}
			for (int j = 0; j < n; j++){
				memset(visited, false, sizeof(visited));
				DFS(j);
			}
			for (int j = 0; j < n; j++){
				if (P[j] != -1)
					fix++;
			}
			res = 2 * (n - 1) + 1 - convertex + other - fix + (n - 1) - fix;
			// 以 i 為頂點, 先將所有點與 i 作雙向鏈結, 再將其餘點形成一個或數個環, 再檢查哪些邊重複
			if (res < ans)
				ans = res;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

D. George and Interesting Graph
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
George loves graphs. Most of all, he loves interesting graphs. We will assume that a directed graph is interesting, if it meets the following criteria:

The graph doesn't contain any multiple arcs;
There is vertex v (we'll call her the center), such that for any vertex of graph u, the graph contains arcs (u, v) and (v, u). Please note that the graph also contains loop (v, v).
The outdegree of all vertexes except for the center equals two and the indegree of all vertexes except for the center equals two. The outdegree of vertex u is the number of arcs that go out of u, the indegree of vertex u is the number of arcs that go in u. Please note that the graph can contain loops.
However, not everything's that simple. George got a directed graph of n vertices and m arcs as a present. The graph didn't have any multiple arcs. As George loves interesting graphs, he wants to slightly alter the presented graph and transform it into an interesting one. In one alteration he can either remove an arbitrary existing arc from the graph or add an arbitrary arc to the graph.

George wonders: what is the minimum number of changes that he needs to obtain an interesting graph from the graph he's got as a present? Help George and find the answer to the question.

Input
The first line contains two space-separated integers n and m (2 ≤ n ≤ 500, 1 ≤ m ≤ 1000) — the number of vertices and arcs in the presented graph.

Each of the next m lines contains two space-separated integers ai, bi (1 ≤ ai, bi ≤ n) — the descriptions of the graph's arcs. Pair (ai, bi) means that the graph contains an arc from vertex number ai to vertex number bi. It is guaranteed that the presented graph doesn't contain multiple arcs.

Assume that the grah vertices are numbered 1 through n.

Output
Print a single integer — the answer to George's question.

Sample test(s)
input
3 7
1 1
2 2
3 1
1 3
3 2
2 3
3 3
output
0
input
3 6
1 1
2 2
3 1
3 2
2 3
3 3
output
1
input
3 1
2 2
output
6
Note
For more information about directed graphs, please visit: http://en.wikipedia.org/wiki/Directed_graph

In the first sample the graph already is interesting, its center is vertex 3.

*/