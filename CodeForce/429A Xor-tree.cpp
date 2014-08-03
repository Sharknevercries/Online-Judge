/* 6605252	 May 12, 2014 8:34:53 PM	Shark	 429A - Xor-tree	 GNU C++	Accepted	 93 ms	 4900 KB */
#include<cstdio>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;
vector<int> E[100000];
vector<int> ans;
int A[100000];
int B[100000];
bool V[100000];
bool M[100000];
int n;

void BFS(){
	ans.clear();
	queue<int> Q;
	Q.push(0);
	V[0] = true;

	while (!Q.empty()){
		int cur = Q.front();
		bool flip = M[cur];
		Q.pop();
		if ((A[cur] != B[cur] && !flip) || (A[cur] == B[cur] && flip))
			ans.push_back(cur), flip = !flip;
		for (int i = 0; i < E[cur].size(); i++){
			if (!V[E[cur][i]]){
				for (int j = 0; j < E[E[cur][i]].size(); j++){
					M[E[E[cur][i]][j]] = flip;
				}
				Q.push(E[cur][i]);
				V[E[cur][i]] = true;
			}
		}
	}
}
int main(){
	while (scanf("%d", &n) == 1){
		memset(V, false, sizeof(V));
		memset(M, false, sizeof(M));
		for (int i = 0; i < n; i++)
			E[i].clear();
		for (int i = 0; i < n - 1; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			E[b].push_back(a);
			E[a].push_back(b);
		}
		for (int i = 0; i < n; i++)
			scanf("%d", A + i);
		for (int i = 0; i < n; i++)
			scanf("%d", B + i);

		BFS();
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d\n", ans[i] + 1);
	}
	return 0;
}
/*

A. Xor-tree
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Iahub is very proud of his recent discovery, propagating trees. Right now, he invented a new tree, called xor-tree. After this new revolutionary discovery, he invented a game for kids which uses xor-trees.

The game is played on a tree having n nodes, numbered from 1 to n. Each node i has an initial value initi, which is either 0 or 1. The root of the tree is node 1.

One can perform several (possibly, zero) operations on the tree during the game. The only available type of operation is to pick a node x. Right after someone has picked node x, the value of node x flips, the values of sons of x remain the same, the values of sons of sons of x flips, the values of sons of sons of sons of x remain the same and so on.

The goal of the game is to get each node i to have value goali, which can also be only 0 or 1. You need to reach the goal of the game by using minimum number of operations.

Input
The first line contains an integer n (1 ≤ n ≤ 105). Each of the next n - 1 lines contains two integers ui and vi (1 ≤ ui, vi ≤ n; ui ≠ vi) meaning there is an edge between nodes ui and vi.

The next line contains n integer numbers, the i-th of them corresponds to initi (initi is either 0 or 1). The following line also contains n integer numbers, the i-th number corresponds to goali (goali is either 0 or 1).

Output
In the first line output an integer number cnt, representing the minimal number of operations you perform. Each of the next cnt lines should contain an integer xi, representing that you pick a node xi.

Sample test(s)
input
10
2 1
3 1
4 2
5 1
6 2
7 5
8 6
9 8
10 5
1 0 1 1 0 1 0 1 0 1
1 0 1 0 0 1 1 1 0 1
output
2
4
7

*/