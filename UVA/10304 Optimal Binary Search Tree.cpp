/* 13930542	10304	Optimal Binary Search Tree	Accepted	C++	0.182	2014-07-23 08:20:22 */
/*

Template By Shark

*/
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
#define MAX_N 300
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int W[MAX_N];
int DP[MAX_N][MAX_N];
int record[MAX_N][MAX_N];
int sum[MAX_N];
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		memset(W, 0, sizeof(W));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
			scanf("%d", W + i);
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + W[i];
		memset(DP, 0, sizeof(DP));
		for (int i = 1; i <= n; i++)
			DP[i][i] = W[i], record[i][i] = i;
		for (int j = 2; j <= n; j++){
			for (int i = j - 1; i >= 1; i--){
				DP[i][j] = INF;
				for (int k = record[i][j - 1]; k <= record[i + 1][j]; k++)
					if (DP[i][k - 1] + DP[k + 1][j] < DP[i][j])
						DP[i][j] = DP[i][k - 1] + DP[k + 1][j], record[i][j] = k;
				DP[i][j] += sum[j] - sum[i - 1];
			}
		}
		printf("%d\n", DP[1][n] - sum[n]);
	}
	return 0;
}
/*

Problem E
Optimal Binary Search Tree
Input: standard input
Output: standard output
Time Limit: 30 seconds
Memory Limit: 32 MB
Given a set S = (e1, e2, ..., en) of n distinct elements such that e1 < e2 < ... < en and considering a binary search tree (see the previous problem) of the elements of S, it is desired that higher the query frequency of an element, closer will it be to the root.

The cost of accessing an element ei of S in a tree (cost(ei)) is equal to the number of edges in the path that connects the root with the node that contains the element. Given the query frequencies of the elements of S, (f(e1), f(e2, ..., f(en)), we say that the total cost of a tree is the following summation:

f(e1)*cost(e1) + f(e2)*cost(e2) + ... + f(en)*cost(en)

In this manner, the tree with the lowest total cost is the one with the best representation for searching elements of S. Because of this, it is called the Optimal Binary Search Tree.

Input
The input will contain several instances, one per line.

Each line will start with a number 1 <= n <= 250, indicating the size of S. Following n, in the same line, there will be n non-negative integers representing the query frequencies of the elements of S: f(e1), f(e2), ..., f(en). 0 <= f(ei) <= 100.  Input is terminated by end of file.

Output
For each instance of the input, you must print a line in the output with the total cost of the Optimal Binary Search Tree.

Sample Input
1 5
3 10 10 10
3 5 10 20

Sample Output
0
20
20
(The Joint Effort Contest, Problem setter: Rodrigo Malta Schmidt)

*/