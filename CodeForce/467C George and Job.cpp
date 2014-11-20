/* 7843008	2014-09-18 21:59:48	Shark	C - George and Job	GNU C++	Accepted	93 ms	196172 KB */
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
#define MAX_N 5005
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
lli DP[MAX_N][MAX_N] = { 0 };
lli S[MAX_N];
lli sum[MAX_N] = { 0 };
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", S + i);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + S[i];
	for (int i = m; i <= n; i++)
		for (int j = k; j >= 1; j--)
			DP[i][j] = max(DP[i - 1][j], DP[i - m][j - 1] + sum[i] - sum[i - m]);
	printf("%lld\n", DP[n][k]);
	return 0;
}
/*

C. George and Job
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The new ITone 6 has been released recently and George got really keen to buy it. Unfortunately, he didn't have enough money, so George was going to work as a programmer. Now he faced the following problem at the work.

Given a sequence of n integers p1, p2, ..., pn. You are to choose k pairs of integers:

[l1, r1], [l2, r2], ..., [lk, rk] (1 ≤ l1 ≤ r1 < l2 ≤ r2 < ... < lk ≤ rk ≤ n; ri - li + 1 = m), 
in such a way that the value of sum  is maximal possible. Help George to cope with the task.

Input
The first line contains three integers n, m and k (1 ≤ (m × k) ≤ n ≤ 5000). The second line contains n integers p1, p2, ..., pn (0 ≤ pi ≤ 109).

Output
Print an integer in a single line — the maximum possible value of sum.

Sample test(s)
input
5 2 1
1 2 3 4 5
output
9
input
7 1 3
2 10 7 18 5 33 0
output
61

*/