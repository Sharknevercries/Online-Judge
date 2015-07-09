/* 15619692	459	Graph Connectivity	Accepted	C++	0.000	2015-06-12 11:35:35 */
#include<bits\stdc++.h>
using namespace std;
int n;
vector<int> G[30];
bool V[30];
void DFS(int cur){
	V[cur] = true;
	for (int i = 0; i < G[cur].size(); i++){
		int target = G[cur][i];
		if (!V[target])
			DFS(target);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	getchar();
	getchar();
	while (t--){
		char str[5];
		gets(str);
		n = str[0] - 'A' + 1;
		for (int i = 1; i <= n; i++)
			G[i].clear();
		while (gets(str) && str[0]!='\0'){
			int a = str[0] - 'A' + 1;
			int b = str[1] - 'A' + 1;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int ans = 0;
		memset(V, false, sizeof(V));
		for (int i = 1; i <= n; i++)
			if (!V[i])
				DFS(i), ans++;
		printf("%d\n", ans);
		if (t)
			putchar('\n');
	}
	return 0;
}
/*


Graph Connectivity
Consider a graph G formed from a large number of nodes connected by edges. G is said to be connected if a path can be found in 0 or more steps between any pair of nodes in G. For example, the graph below is not connected because there is no path from A to C.

picture22

This graph contains, however, a number of subgraphs that are connected, one for each of the following sets of nodes: {A}, {B}, {C}, {D}, {E}, {A,B}, {B,D}, {C,E}, {A,B,D}

A connected subgraph is maximal if there are no nodes and edges in the original graph that could be added to the subgraph and still leave it connected. There are two maximal connected subgraphs above, one associated with the nodes {A, B, D} and the other with the nodes {C, E}.

Write a program to determine the number of maximal connected subgraphs of a given graph.

Input and Output

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.

The first line of each input set contains a single uppercase alphabetic character. This character represents the largest node name in the graph. Each successive line contains a pair of uppercase alphabetic characters denoting an edge in the graph. The sample input section contains a possible input set for the graph pictured above.

Input is terminated by a blank line.

For each test case, the output the number of maximal connected subgraphs. The outputs of two consecutive cases will be separated by a blank line.

Sample Input

1

E
AB
CE
DB
EC
Sample Output

2

*/