/* 7248281	2014-07-26 12:40:01	Shark	450B - Jzzhu and Sequences	GNU C++	Accepted	31 ms	0 KB */
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
#define MOD 1000000007
const double PI = 2.0 * acos(0.0);
void mul(lli A[][2], lli B[][2], lli res[][2]){
	res[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
	res[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
	res[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
	res[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
}
void power(lli res[][2], int n){
	lli T[2][2] = { 1, -1, 1, 0 };
	while (n > 0){
		lli tmp[2][2];
		if (n % 2 == 1){
			mul(T, res, tmp);
			memcpy(res, tmp, sizeof(tmp));
		}
		mul(T, T, tmp);
		memcpy(T, tmp, sizeof(tmp));
		n >>= 1;
	}
}
int solve(int x, int y, int n){
	int res;
	if (n == 1)	res = x % MOD;
	if (n == 2)	res = y % MOD;
	if (n >= 3){
		lli G[2][2] = { 1, 0, 0, 1 };
		power(G, n - 2);
		res = (G[0][0] * y + G[0][1] * x) % MOD;
	}
	if (res < 0)
		return MOD - abs(res);
	else
		return res;
}
int main(){
	int x, y, n;
	while (scanf("%d%d%d", &x, &y, &n) == 3){
		printf("%d\n", solve(x, y, n));
	}
	return 0;
}
/*

B. Jzzhu and Sequences
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jzzhu has invented a kind of sequences, they meet the following property:

You are given x and y, please calculate fn modulo 1000000007 (109 + 7).

Input
The first line contains two integers x and y (|x|, |y| ≤ 109). The second line contains a single integer n (1 ≤ n ≤ 2·109).

Output
Output a single integer representing fn modulo 1000000007 (109 + 7).

Sample test(s)
input
2 3
3
output
1
input
0 -1
2
output
1000000006
Note
In the first sample, f2 = f1 + f3, 3 = 2 + f3, f3 = 1.

In the second sample, f2 =  - 1;  - 1 modulo (109 + 7) equals (109 + 6).

*/