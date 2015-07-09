/* 15573506	10802	Lex Smallest Drive	Accepted	C++	0.014	2015-06-04 04:11:04 */
#include<bits\stdc++.h>
using namespace std;
int n, m, source;
bool G[105][105];
int path[135], step;
bool DFS(int cur, int prev, int target){
	if (cur == target)	return true;
	if (step >= 130)	return false;
	for (int i = 0; i < n; i++){
		if (i == prev || !G[cur][i])	continue;
		path[step++] = i;
		if (DFS(i, cur, target))
			return true;
		if (step >= 130)
			return false;
		step--;
	}
	return false;
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &source);
		memset(G, false, sizeof(G));
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			G[a][b] = G[b][a] = true;
		}
		printf("Case #%d:\n", c++);
		for (int i = 0; i < n; i++){
			step = 0;
			path[step++] = source;
			if (DFS(source, -1, i)){
				printf("%d", path[0]);
				for (int j = 1; j < step; j++)
					printf(" %d", path[j]);
				putchar('\n');
			}
			else
				puts("No drive.");
		}
		putchar('\n');
	}
	return 0;
}
/*

Problem ?
Lex Smallest Drive
Time Limit: 2 seconds
"OK. Let's go right."
Bartholomew Furrow

A graph, G, consists of a finite set of vertices, V, and a set of edges, E, where each edge is a set of 2 vertices {u, v}. A walk in G is a finite sequence of vertices (v1, v2, ..., vk), such that for each pair (vi-1, vi) for i in [2, k], {vi-1, vi} is in E. This is called a "walk from v1 to vk". If V is a set of integers, then any two walks in G can be compared lexicographically; for example, the walk (3, 5, 6, 2, 8) is smaller than the walk (3, 5, 6, 5, 7). A walk, W, from a to b is lexicographically smallest if there is no other walk from a to b in G that is smaller than W. A drive is a walk (v1, v2, ..., vk), where no edge is used twice consecutively. That is, for all i from 2 up to k-1, vi-1 is not equal to vi+1.

Given G and a start vertex, s, your task is to find the lexicographically smallest drives from s to each vertex in G.

Input
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a line containing the integers n, m and s. (0 <= n <= 100, 0 <= m <= 4950). The next m lines will list the edges of G. V is the set {0, 1, ..., n-1}. s is in V.

Output
For each test case, output the line "Case #x:", where x is the number of the test case. Then print n lines, line i listing the lexicographically smallest drive from s to i using single spaces to separate consecutive vertices. If there is no such drive, print "No drive." Put an empty line after each test case.

Sample Input	Sample Output
2
6 4 5
5 0
2 5
4 0
3 1
4 4 0
0 1
1 2
0 2
0 3
Case #1:
5 0
No drive.
5 2
No drive.
5 0 4
5

Case #2:
0
0 1
0 1 2
No drive.

Problemsetter: Igor Naverniouk
Alternate solutions: Yury Kholondyrev, Bartholomew Furrow

*/