/* 10141498	2015-03-04 10:01:59	Shark	E - A and B and Lecture Rooms	GNU C++	Accepted	139 ms	18392 KB */
#include<bits\stdc++.h>
using namespace std;
int n, q;
vector<int> G[100005];
int an[100005][20];
int tin[100005], tout[100005], t;
int dist[100005], size[100005];
void DFS(int cur, int prev){
	tin[cur] = t++;
	size[cur] = 1;
	an[cur][0] = cur, an[cur][1] = prev;
	for (int i = 2; (1 << (i - 1)) <= n; i++)
		an[cur][i] = an[an[cur][i - 1]][i - 1];
	for (int i = 0; i < G[cur].size(); i++){
		int next = G[cur][i];
		if (next != prev){
			dist[next] = dist[cur] + 1;
			DFS(next, cur);
			size[cur] += size[next];
		}
	}
	tout[cur] = t++;
}
bool ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int findLCA(int a, int b){
	if (ancestor(a, b))	return a;
	if (ancestor(b, a))	return b;
	for (int i = log((double)n) / log(2.0); i >= 1; i--)
		if (!ancestor(an[a][i], b) && an[a][i] != 0)
			a = an[a][i];
	return an[a][1];
}
int findKthAncenstor(int a, int k){
	for (int i = log((double)n) / log(2.0); k > 0; i--)
		if (k - (1 << (i - 1)) >= 0)
			k -= (1 << (i - 1)), a = an[a][i];
	return a;
}
int query(int a, int b){
	if (a == b)	return n;
	if (dist[a] < dist[b])
		swap(a, b);
	if ((dist[a] - dist[b]) % 2 != 0)
		return 0;
	int lca = findLCA(a, b);
	if (dist[a] == dist[b]){
		int res = n;
		for (int i = log((double)n) / log(2.0); i >= 1; i--){
			int d = dist[an[a][i]] - dist[lca];
			if (d >= 1)
				a = an[a][i];
			if (d == 1)
				break;
		}
		for (int i = log((double)n) / log(2.0); i >= 1; i--){
			int d = dist[an[b][i]] - dist[lca];
			if (d >= 1)
				b = an[b][i];
			if (d == 1)
				break;
		}
		return res - size[a] - size[b];
	}
	else{
		int d = dist[a] + dist[b] - dist[lca] * 2;
		return size[findKthAncenstor(a, d / 2)] - size[findKthAncenstor(a, d / 2 - 1)];
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	t = 0;
	dist[1] = 0;
	DFS(1, 0);
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a, b));
	}
	return 0;
}
/*

E. A and B and Lecture Rooms
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A and B are preparing themselves for programming contests.

The University where A and B study is a set of rooms connected by corridors. Overall, the University has n rooms connected by n - 1 corridors so that you can get from any room to any other one by moving along the corridors. The rooms are numbered from 1 to n.

Every day А and B write contests in some rooms of their university, and after each contest they gather together in the same room and discuss problems. A and B want the distance from the rooms where problems are discussed to the rooms where contests are written to be equal. The distance between two rooms is the number of edges on the shortest path between them.

As they write contests in new rooms every day, they asked you to help them find the number of possible rooms to discuss problems for each of the following m days.

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of rooms in the University.

The next n - 1 lines describe the corridors. The i-th of these lines (1 ≤ i ≤ n - 1) contains two integers ai and bi (1 ≤ ai, bi ≤ n), showing that the i-th corridor connects rooms ai and bi.

The next line contains integer m (1 ≤ m ≤ 105) — the number of queries.

Next m lines describe the queries. The j-th of these lines (1 ≤ j ≤ m) contains two integers xj and yj (1 ≤ xj, yj ≤ n) that means that on the j-th day A will write the contest in the room xj, B will write in the room yj.

Output
In the i-th (1 ≤ i ≤ m) line print the number of rooms that are equidistant from the rooms where A and B write contest on the i-th day.

Sample test(s)
input
4
1 2
1 3
2 4
1
2 3
output
1
input
4
1 2
2 3
2 4
2
1 2
1 3
output
0
2
Note
in the first sample there is only one room at the same distance from rooms number 2 and 3 — room number 1.

*/