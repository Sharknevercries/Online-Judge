/* 14002436	193	Graph Coloring	Accepted	C++	0.022	2014-08-07 07:53:59 */
/* Template By Shark */
// C++
#include<iostream>
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
// const variable
#define MAX_N 105
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define WHITE 0
#define BLACK 1
const double PI = 2.0 * acos(0.0);
// main
vector<int> C[MAX_N];
int color[MAX_N];
vector<int> ans;
vector<int> tmp;
int n, m;
bool hasBlack(int cur){
	for (int i = 0; i < C[cur].size(); i++)
		if (color[C[cur][i]] == BLACK)
			return true;
	return false;
}
void DFS(int cur){
	if (cur >= n + 1){
		if (tmp.size() > ans.size())
			ans = tmp;
		return;
	}
	if (tmp.size() + n - cur + 1 < ans.size())	return;
	if (!hasBlack(cur)){
		color[cur] = BLACK;
		tmp.push_back(cur);
		DFS(cur + 1);
		tmp.pop_back();
	}
	color[cur] = WHITE;
	DFS(cur + 1);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		for (int i = 1; i < MAX_N; i++)
			C[i].clear();
		memset(color, NONE, sizeof(color));
		ans.clear(), tmp.clear();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			C[a].push_back(b);
			C[b].push_back(a);
		}
		DFS(1);
		printf("%d\n", ans.size());
		if (ans.size()){
			printf("%d", ans[0]);
			for (int i = 1; i < ans.size(); i++)
				printf(" %d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}
/*

Graph Coloring

You are to write a program that tries to find an optimal coloring for a given graph. Colors are applied to the nodes of the graph and the only available colors are black and white. The coloring of the graph is called optimal if a maximum of nodes is black. The coloring is restricted by the rule that no two connected nodes may be black.

figure22
Figure: An optimal graph with three black nodes
Input and Output

The graph is given as a set of nodes denoted by numbers  tex2html_wrap_inline33 ,  tex2html_wrap_inline35 , and a set of undirected edges denoted by pairs of node numbers  tex2html_wrap_inline37 ,  tex2html_wrap_inline39 . The input file contains m graphs. The number m is given on the first line. The first line of each graph contains n and k, the number of nodes and the number of edges, respectively. The following k lines contain the edges given by a pair of node numbers, which are separated by a space.

The output should consists of 2m lines, two lines for each graph found in the input file. The first line of should contain the maximum number of nodes that can be colored black in the graph. The second line should contain one possible optimal coloring. It is given by the list of black nodes, separated by a blank.

Sample Input

1
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6
Sample Output

3
1 4 5

*/