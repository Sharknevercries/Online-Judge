/* 6978607	 2014-06-29 10:10:22	Shark	 431C - k-Tree	 GNU C++	Accepted	 15 ms	 0 KB */
#include<cstdio>
#define MOD 1e9 + 7
void add(int &a, int &b){
	a += b;
	a %= (int)MOD;
}
int main(){
	int n, k, d;
	while (scanf("%d%d%d", &n, &k, &d) == 3){
		int DP[101][2] = { 0 };
		DP[0][0] = 1;
		DP[0][1] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= k; j++){
				if (i - j < 0)	break;
				if (d > j){
					add(DP[i][0], DP[i - j][0]);
					add(DP[i][1], DP[i - j][1]);
				}
				else{
					add(DP[i][1], DP[i - j][0]);
					add(DP[i][1], DP[i - j][1]);
				}
			}
		}
		printf("%d\n", DP[n][1]);
	}
	return 0;
}
/*

C. k-Tree
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Quite recently a creative student Lesha had a lecture on trees. After the lecture Lesha was inspired and came up with the tree of his own which he called a k-tree.

A k-tree is an infinite rooted tree where:

each vertex has exactly k children;
each edge has some weight;
if we look at the edges that goes from some vertex to its children (exactly k edges), then their weights will equal 1, 2, 3, ..., k.
The picture below shows a part of a 3-tree.

As soon as Dima, a good friend of Lesha, found out about the tree, he immediately wondered: "How many paths of total weight n (the sum of all weights of the edges in the path) are there, starting from the root of a k-tree and also containing at least one edge of weight at least d?".
Help Dima find an answer to his question. As the number of ways can be rather large, print it modulo 1000000007 (109 + 7).

Input
A single line contains three space-separated integers: n, k and d (1 ≤ n, k ≤ 100; 1 ≤ d ≤ k).

Output
Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

Sample test(s)
input
3 3 2
output
3
input
3 3 3
output
1
input
4 3 2
output
6
input
4 5 2
output
7

*/