/* 10339430	2015-03-18 18:13:11	Shark	527D - Clique Problem	GNU C++	Accepted	93 ms	3100 KB */
#include<bits\stdc++.h>
using namespace std;
int n;
pair<int, int> P[200005];
pair<int, int> LIS[200005];
int size;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &P[i].first, &P[i].second);
	sort(P, P + n);
	size = 0;
	for (int i = 0; i < n; i++){
		if (size == 0)
			LIS[++size] = P[i];
		else{
			int L = 1, R = size;
			while (R >= L){
				int mid = (L + R) / 2;
				if (P[i].first - LIS[mid].first >= P[i].second + LIS[mid].second)
					L = mid + 1;
				else
					R = mid - 1;
			}
			if (L > size)
				LIS[++size] = P[i];
			else if (P[i].first - LIS[L].first < LIS[L].second - P[i].second)
				LIS[L] = P[i];
			// first => x, second => w
		}
	}
	printf("%d\n", size);
	return 0;
}
/*

D. Clique Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The clique problem is one of the most well-known NP-complete problems. Under some simplification it can be formulated as follows. Consider an undirected graph G. It is required to find a subset of vertices C of the maximum size such that any two of them are connected by an edge in graph G. Sounds simple, doesn't it? Nobody yet knows an algorithm that finds a solution to this problem in polynomial time of the size of the graph. However, as with many other NP-complete problems, the clique problem is easier if you consider a specific type of a graph.

Consider n distinct points on a line. Let the i-th point have the coordinate xi and weight wi. Let's form graph G, whose vertices are these points and edges connect exactly the pairs of points (i, j), such that the distance between them is not less than the sum of their weights, or more formally: |xi - xj| ≥ wi + wj.

Find the size of the maximum clique in such graph.

Input
The first line contains the integer n (1 ≤ n ≤ 200 000) — the number of points.

Each of the next n lines contains two numbers xi, wi (0 ≤ xi ≤ 109, 1 ≤ wi ≤ 109) — the coordinate and the weight of a point. All xi are different.

Output
Print a single number — the number of vertexes in the maximum clique of the given graph.

Sample test(s)
input
4
2 3
3 1
6 1
0 2
output
3
Note
If you happen to know how to solve this problem without using the specific properties of the graph formulated in the problem statement, then you are able to get a prize of one million dollars!

The picture for the sample test.

*/