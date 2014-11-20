/* 8204754	2014-10-12 19:36:42	Shark	477A - Dreamoon and Sums	GNU C++	Accepted	265 ms	0 KB */
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
#define MAX_N 1000
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
int main(){
	lli a, b;
	lli ans = 0;
	scanf("%lld%lld", &a, &b);
	for (int i = 1; i <= a; i++){
		lli tmp1 = (i * b + 1) % MOD;
		lli tmp2 = (b * (b - 1) / 2) % MOD;
		ans = (ans + (tmp1 * tmp2) % MOD) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
/*

C. Dreamoon and Sums
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dreamoon loves summing up something for no reason. One day he obtains two integers a and b occasionally. He wants to calculate the sum of all nice integers. Positive integer x is called nice if  and , where k is some integer number in range [1, a].

By  we denote the quotient of integer division of x and y. By  we denote the remainder of integer division of x and y. You can read more about these operations here: http://goo.gl/AcsXhT.

The answer may be large, so please print its remainder modulo 1 000 000 007 (109 + 7). Can you compute it faster than Dreamoon?

Input
The single line of the input contains two integers a, b (1 ≤ a, b ≤ 107).

Output
Print a single integer representing the answer modulo 1 000 000 007 (109 + 7).

Sample test(s)
input
1 1
output
0
input
2 2
output
8
Note
For the first sample, there are no nice integers because  is always zero.

For the second sample, the set of nice integers is {3, 5}.

*/