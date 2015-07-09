/* 13970874	10718	Bit Mask	Accepted	C++	0.009	2014-07-31 11:12:54 */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	lli n, L, R;
	while (scanf("%lld%lld%lld", &n, &L, &R) == 3){
		lli ans = 0;
		for (lli i = (1LL << 35); i > 0; i >>= 1){
			lli tmp = ans | i;
			if (tmp > R)	continue;
			else if (tmp <= L)	ans = tmp;
			else if ((n&i) > 0)	continue;
			else ans = tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem A

Bit Mask

Time Limit

1 Second

In bit-wise expression, mask is a common term. You can get a certain bit-pattern using mask. For example, if you want to make first 4 bits of a 32-bit number zero, you can use 0xFFFFFFF0 as mask and perform a bit-wise AND operation. Here you have to find such a bit-mask.

Consider you are given a 32-bit unsigned integer N. You have to find a mask M such that L ≤ M ≤ U and N OR M is maximum. For example, if N is 100 and L = 50, U = 60 then M will be 59 and N OR M will be 127 which is maximum. If several value of M satisfies the same criteria then you have to print the minimum value of M.

Input
Each input starts with 3 unsigned integers N, L, U where L ≤ U. Input is terminated by EOF.

Output
For each input, print in a line the minimum value of M, which makes N OR M maximum.

Look, a brute force solution may not end within the time limit.

Sample Input

Output for Sample Input

100 50 60
100 50 50
100 0 100
1 0 100
15 1 15

59
50
27
100
1

Problem setter: Md. Kamruzzaman
Member of Elite Problemsetters' Panel

*/