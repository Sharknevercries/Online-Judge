/* 7135158	 2014-07-17 19:27:25	Shark	 448C - Painting Fence	 GNU C++	Accepted	 30 ms	 200 KB */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int H[5001];
int solve(int L, int R, int h){
	if (R < L)	return 0;
	if (L == R)	return 1;
	int m = INF, res;
	int LL = L, RR;
	for (int i = L; i <= R; i++)
		if (m > H[i] && H[i] > h)
			m = H[i];
	res = m - h;
	while (LL <= R){
		for (; LL <= R && H[LL] <= m; LL++);
		for (RR = LL; RR <= R; RR++){
			if (H[RR] <= m){
				res += solve(LL, RR - 1, m);
				break;
			}
		}
		if (RR > R)
			res += solve(LL, RR - 1, m);
		LL = RR + 1;
	}
	return min(res, R - L + 1);
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 1; i <= n; i++)
			scanf("%d", H + i);
		printf("%d\n", solve(1, n, 0));
	}
	return 0;
}
/*

C. Painting Fence
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Bizon the Champion isn't just attentive, he also is very hardworking.

Bizon the Champion decided to paint his old fence his favorite color, orange. The fence is represented as n vertical planks, put in a row. Adjacent planks have no gap between them. The planks are numbered from the left to the right starting from one, the i-th plank has the width of 1 meter and the height of ai meters.

Bizon the Champion bought a brush in the shop, the brush's width is 1 meter. He can make vertical and horizontal strokes with the brush. During a stroke the brush's full surface must touch the fence at all the time (see the samples for the better understanding). What minimum number of strokes should Bizon the Champion do to fully paint the fence? Note that you are allowed to paint the same area of the fence multiple times.

Input
The first line contains integer n (1 ≤ n ≤ 5000) — the number of fence planks. The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print a single integer — the minimum number of strokes needed to paint the whole fence.

Sample test(s)
input
5
2 2 1 2 1
output
3
input
2
2 2
output
2
input
1
5
output
1
Note
In the first sample you need to paint the fence in three strokes with the brush: the first stroke goes on height 1 horizontally along all the planks. The second stroke goes on height 2 horizontally and paints the first and second planks and the third stroke (it can be horizontal and vertical) finishes painting the fourth plank.

In the second sample you can paint the fence with two strokes, either two horizontal or two vertical strokes.

In the third sample there is only one plank that can be painted using a single vertical stroke.

*/