/* 14266075	11396	Claw Decomposition	Accepted	C++	0.019	2014-09-26 03:15:44 */
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
#define MAX_N 305
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
vector<int> G[MAX_N];
int color[MAX_N];
bool DFS(int s, int paint){
	color[s] = paint;
	for (int i = 0; i < G[s].size(); i++){
		int target = G[s][i];
		if (color[target] == NONE && !DFS(target, !paint))
			return false;
		else if (color[target] != NONE && color[target] == paint)
			return false;
	}
	return true;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i <= n; i++)
			G[i].clear();
		int a, b;
		while (scanf("%d%d", &a, &b) == 2 && a && b){
			G[a].push_back(b);
			G[b].push_back(a);
		}
		memset(color, NONE, sizeof(color));
		bool res = true;
		for (int i = 1; i <= n && res; i++)
			if (color[i] == NONE)
				res &= DFS(i, 0);
		if (res)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

Problem B
Claw Decomposition
Input: Standard Input
Output: Standard Output

A claw is defined as a pointed curved nail on the end of each toe in birds, some reptiles, and some mammals. However, if you are a graph theory enthusiast, you may understand the following special class of graph as shown in the following figure by the word claw.

If you are more concerned about graph theory terminology, you may want to define claw as K1,3.

Let¡¦s leave the definition for the moment & come to the problem. You are given a simple undirected graph in which every vertex has degree 3. You are to figure out whether the graph can be decomposed into claws or not.

Just for the sake of clarity, a decomposition of a graph is a list of subgraphs such that each edge appears in exactly one subgraph in the list.

Input

There will be several cases in the input file. Each case starts with the number of vertices in the graph, V (4<=V<=300). This is followed by a list of edges. Every line in the list has two integers, a & b, the endpoints of an edge (1<=a,b<=V). The edge list ends with a line with a pair of 0. The end of input is denoted by a case with V=0. This case should not be processed.

Output

For every case in the input, print YES if the graph can be decomposed into claws & NO otherwise.

Sample Input                                                  Output for Sample Input
4
1 2
1 3
1 4
2 3
2 4
3 4
0 0
6
1 2
1 3
1 6
2 3
2 5
3 4
4 5
4 6
5 6
0 0
0
NO
NO


Problemsetter: Mohammad Mahmudur Rahman
Special Thanks to: Manzurur Rahman Khan

*/