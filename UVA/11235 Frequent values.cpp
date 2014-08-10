/* 13995192	11235	Frequent values	Accepted	C++	0.322	2014-08-05 17:43:24 */
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
#define MAX_N 100000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define LEFT_CHILD(x) (x<<1)
#define RIGHT_CHILD(x) (x<<1) + 1
const double PI = 2.0 * acos(0.0);
// main
struct node{
	int L, R, F;
	bool leaf;
	node(){}
	node(int a, int b){ L = a, R = b, F = b - a; }
	node(node a, node b){ L = a.L, R = b.R, F = max(a.F, b.F); }
};
int S[MAX_N + 5];
node T[MAX_N + 5];
node Q[4 * MAX_N + 5];
int ptr;
void build(int L, int R, int x){
	if (R == L)
		Q[x] = node(T[L].L, T[L].R), Q[x].leaf = true;
	else{
		int mid = (L + R) / 2;
		build(L, mid, LEFT_CHILD(x));
		build(mid + 1, R, RIGHT_CHILD(x));
		Q[x] = node(Q[LEFT_CHILD(x)], Q[RIGHT_CHILD(x)]);
		Q[x].leaf = false;
	}
}
int query(int L, int R, int x){
	if (Q[x].L == L && Q[x].R == R)
		return Q[x].F;
	else if (Q[x].leaf)
		return R - L;
	else{
		int LC = LEFT_CHILD(x);
		int RC = RIGHT_CHILD(x);
		int ans = -1;
		if (Q[LC].R > L && Q[RC].L <= R){
			ans = max(ans, query(L, Q[LC].R, LEFT_CHILD(x)));
			ans = max(ans, query(Q[RC].L, R, RIGHT_CHILD(x)));
		}
		else if (Q[LC].R > R)
			ans = max(ans, query(L, R, LEFT_CHILD(x)));
		else
			ans = max(ans, query(L, R, RIGHT_CHILD(x)));
		return ans;
	}
}
void init(){
	for (int i = 0; i < 2 * MAX_N + 5; i++)
		free(&Q[i]);
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n){
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);
		ptr = 1;
		int prev = 1;
		for (int i = 2; i <= n; i++){
			if (S[i] != S[i - 1])
				T[ptr++] = node(prev, i), prev = i;
		}
		T[ptr++] = node(prev, n + 1);
		ptr--;
		build(1, ptr, 1);
		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", query(a, b + 1, 1));
		}
	}
	return 0;
}
/*

2007/2008 ACM International Collegiate Programming Contest
University of Ulm Local Contest
Problem F: Frequent values

You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input Specification

The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the query.

The last test case is followed by a line containing a single 0.

Output Specification

For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Sample Input

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output

1
4
3
A naive algorithm may not run in time!

*/