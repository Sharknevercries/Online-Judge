/* 8013930	2014-09-28 21:54:49	Shark	472D - Design Tutorial: Inverse the Problem	GNU C++	Accepted	1544 ms	68500 KB */
// C++
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 2005
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
struct edge{
	int a, b, w;
};
vector<edge> G[MAX_N];
vector<edge> E;
int T[MAX_N][MAX_N];
int LCA[MAX_N][MAX_N];
int P[MAX_N], D[MAX_N];
int n;
bool V[MAX_N];
bool cmp(edge A, edge B){
	return A.w < B.w;
}
int find(int x){
	return x == P[x] ? x : P[x] = find(P[x]);
}
void DFS(int x){
	V[x] = true;
	for (int y = 0; y < n; y++)
		if (V[y])
			LCA[x][y] = LCA[y][x] = find(y);
	for (int y = 0; y < G[x].size(); y++){
		if (V[G[x][y].b])	continue;
		D[G[x][y].b] = D[x] + G[x][y].w;
		DFS(G[x][y].b);
		P[G[x][y].b] = x; 
	}
}
int dist(int a, int b){
	return D[a] + D[b] - 2 * D[LCA[a][b]];
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", T[i] + j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (T[i][j] != T[j][i] || (i == j && T[i][j] != 0) || (i != j && T[i][j] == 0)){
				puts("NO");
				return 0;
			}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			E.push_back(edge{ i, j, T[i][j] });
	sort(E.begin(), E.end(), cmp);
	for (int i = 0; i < n; i++)	P[i] = i;
	for (int i = 0; i < E.size(); i++){
		int a = find(E[i].a);
		int b = find(E[i].b);
		if (a != b){
			G[E[i].a].push_back(edge{ E[i].a, E[i].b, E[i].w });
			G[E[i].b].push_back(edge{ E[i].b, E[i].a, E[i].w });
			P[b] = a;
		}
	}
	for (int i = 0; i < n; i++)	P[i] = i;
	D[0] = 0;
	memset(V, false, sizeof(V));
	DFS(0);
	bool res = true;
	for (int i = 0; i < n && res; i++)
		for (int j = i; j < n && res; j++)
			if (T[i][j] != dist(i, j))
				res = false;
	puts(res ? "YES" : "NO");
	return 0;
}
/*

D. Design Tutorial: Inverse the Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is an easy way to obtain a new task from an old one called "Inverse the problem": we give an output of the original task, and ask to generate an input, such that solution to the original problem will produce the output we provided. The hard task of Topcoder Open 2014 Round 2C, InverseRMQ, is a good example.

Now let's create a task this way. We will use the task: you are given a tree, please calculate the distance between any pair of its nodes. Yes, it is very easy, but the inverse version is a bit harder: you are given an n × n distance matrix. Determine if it is the distance matrix of a weighted tree (all weights must be positive integers).

Input
The first line contains an integer n (1 ≤ n ≤ 2000) — the number of nodes in that graph.

Then next n lines each contains n integers di, j (0 ≤ di, j ≤ 109) — the distance between node i and node j.

Output
If there exists such a tree, output "YES", otherwise output "NO".

Sample test(s)
input
3
0 2 7
2 0 9
7 9 0
output
YES
input
3
1 2 7
2 0 9
7 9 0
output
NO
input
3
0 2 2
7 0 9
7 9 0
output
NO
input
3
0 1 1
1 0 1
1 1 0
output
NO
input
2
0 0
0 0
output
NO
Note
In the first example, the required tree exists. It has one edge between nodes 1 and 2 with weight 2, another edge between nodes 1 and 3 with weight 7.

In the second example, it is impossible because d1, 1 should be 0, but it is 1.

In the third example, it is impossible because d1, 2 should equal d2, 1.

*/