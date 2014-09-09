/* 7669408	2014-09-02 21:15:34	Shark	461B - Appleman and Tree	GNU C++	Accepted	46 ms	9700 KB */
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
#define MAX_N 100005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MOD 1000000007
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
vector<int> E[MAX_N];
int color[MAX_N];
lli DP[MAX_N][2];
bool V[MAX_N];
void DFS(int u, int parent){
	DP[u][color[u]] = 1;
	for (int i = 0; i < E[u].size(); i++){
		int v = E[u][i];
		if (parent == v)continue;
		DFS(v, u);
		int t0 = DP[u][0], t1=DP[u][1];
		DP[u][0] = t0 * (DP[v][0] + DP[v][1]) % MOD;
		DP[u][1] = (t0*DP[v][1] + t1*(DP[v][0] + DP[v][1])) % MOD;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int v;
		scanf("%d", &v);
		E[i].push_back(v);
		E[v].push_back(i);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", color + i);
	DFS(0, NONE);
	printf("%lld\n", DP[0][1] % MOD);
	while (true);
	return 0;
}
/*

B. Appleman and Tree
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Appleman has a tree with n vertices. Some of the vertices (at least one) are colored black and other vertices are colored white.

Consider a set consisting of k (0 ≤ k < n) edges of Appleman's tree. If Appleman deletes these edges from the tree, then it will split into (k + 1) parts. Note, that each part will be a tree with colored vertices.

Now Appleman wonders, what is the number of sets splitting the tree in such a way that each resulting part will have exactly one black vertex? Find this number modulo 1000000007 (109 + 7).

Input
The first line contains an integer n (2  ≤ n ≤ 105) — the number of tree vertices.

The second line contains the description of the tree: n - 1 integers p0, p1, ..., pn - 2 (0 ≤ pi ≤ i). Where pi means that there is an edge connecting vertex (i + 1) of the tree and vertex pi. Consider tree vertices are numbered from 0 to n - 1.

The third line contains the description of the colors of the vertices: n integers x0, x1, ..., xn - 1 (xi is either 0 or 1). If xi is equal to 1, vertex i is colored black. Otherwise, vertex i is colored white.

Output
Output a single integer — the number of ways to split the tree modulo 1000000007 (109 + 7).

Sample test(s)
input
3
0 0
0 1 1
output
2
input
6
0 1 1 0 4
1 1 0 0 1 0
output
1
input
10
0 1 2 1 4 4 4 0 8
0 0 0 1 0 1 1 0 0 1
output
27

*/