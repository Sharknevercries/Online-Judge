/* 7928953	2014-09-23 20:26:33	Shark	468B - Two Sets	GNU C++	Accepted	124 ms	4900 K */
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
#define MAX_N 100005
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
int S[MAX_N], G[MAX_N], P[MAX_N], Q[MAX_N];
map<int, int> T;
int find(int x){
	return G[x] == x ? x : G[x] = find(G[x]);
}
int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++)
		scanf("%d", S + i), G[i] = i;
	for (int i = 0; i < n; i++)
		T[S[i]] = i;
	for (int i = 0; i < n; i++){
		if (T.count(a - S[i]))	G[find(T[a - S[i]])] = find(i), P[i] |= 1;
		if (T.count(b - S[i]))	G[find(T[b - S[i]])] = find(i), P[i] |= 2;
	}
	for (int i = 0; i < n; i++)
		Q[i] = 3;
	for (int i = 0; i < n; i++)
		Q[find(i)] &= P[i];
	bool res = true;
	for (int i = 0; i < n && res; i++)
		if (Q[i] == 0)
			res = false;
	if (res){
		puts("YES");
		for (int i = 0; i < n; i++){
			int m = Q[find(i)];
			if (i > 0)putchar(' ');
			putchar('0' + ((m & 1) == 0));
		}
	}
	else
		puts("NO");
	return 0;
}
/*

B. Two Sets
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little X has n distinct integers: p1, p2, ..., pn. He wants to divide all of them into two sets A and B. The following two conditions must be satisfied:

If number x belongs to set A, then number a - x must also belong to set A.
If number x belongs to set B, then number b - x must also belong to set B.
Help Little X divide the numbers into two sets or determine that it's impossible.

Input
The first line contains three space-separated integers n, a, b (1 ≤ n ≤ 105; 1 ≤ a, b ≤ 109). The next line contains n space-separated distinct integers p1, p2, ..., pn (1 ≤ pi ≤ 109).

Output
If there is a way to divide the numbers into two sets, then print "YES" in the first line. Then print n integers: b1, b2, ..., bn (bi equals either 0, or 1), describing the division. If bi equals to 0, then pi belongs to set A, otherwise it belongs to set B.

If it's impossible, print "NO" (without the quotes).

Sample test(s)
input
4 5 9
2 3 4 5
output
YES
0 0 1 1
input
3 3 4
1 2 4
output
NO
Note
It's OK if all the numbers are in the same set, and the other one is empty.

*/