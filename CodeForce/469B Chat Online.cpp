/* 7870659	2014-09-20 17:18:43	Shark	B - Chat Online	GNU C++	Accepted	31 ms	20 KB */
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
#define MAX_N 1005
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
struct segment{
	int L, R;
};
segment A[MAX_N], B[MAX_N];
int main(){
	int p, q, L, R;
	scanf("%d%d%d%d", &p, &q, &L, &R);
	for (int i = 0; i < p; i++)
		scanf("%d%d", &A[i].L, &A[i].R);
	for (int i = 0; i < q; i++)
		scanf("%d%d", &B[i].L, &B[i].R);
	int ans = 0;
	for (int i = L; i <= R; i++){
		bool res = false;
		for (int j = 0; j < p; j++)
			for (int k = 0; k < q; k++)
				if (!(A[j].L > B[k].R + i || A[j].R < B[k].L + i))
					res = true;
		if (res)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
/*

B. Chat Online
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little X and Little Z are good friends. They always chat online. But both of them have schedules.

Little Z has fixed schedule. He always online at any moment of time between a1 and b1, between a2 and b2, ..., between ap and bp (all borders inclusive). But the schedule of Little X is quite strange, it depends on the time when he gets up. If he gets up at time 0, he will be online at any moment of time between c1 and d1, between c2 and d2, ..., between cq and dq (all borders inclusive). But if he gets up at time t, these segments will be shifted by t. They become [ci + t, di + t] (for all i).

If at a moment of time, both Little X and Little Z are online simultaneosly, they can chat online happily. You know that Little X can get up at an integer moment of time between l and r (both borders inclusive). Also you know that Little X wants to get up at the moment of time, that is suitable for chatting with Little Z (they must have at least one common moment of time in schedules). How many integer moments of time from the segment [l, r] suit for that?

Input
The first line contains four space-separated integers p, q, l, r (1 ≤  p, q ≤ 50; 0 ≤ l ≤ r ≤ 1000).

Each of the next p lines contains two space-separated integers ai, bi (0 ≤ ai < bi ≤ 1000). Each of the next q lines contains two space-separated integers cj, dj (0 ≤ cj < dj ≤ 1000).

It's guaranteed that bi < ai + 1 and dj < cj + 1 for all valid i and j.

Output
Output a single integer — the number of moments of time from the segment [l, r] which suit for online conversation.

Sample test(s)
input
1 1 0 4
2 3
0 1
output
3
input
2 3 0 20
15 17
23 26
1 4
7 11
15 17
output
20

*/