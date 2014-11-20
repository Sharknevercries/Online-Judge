/* 8124548	2014-10-07 05:49:23	Shark	474D - Flowers	GNU C++	Accepted	77 ms	2400 KB */
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
lli DP[MAX_N][2];
lli sum[MAX_N];
int main(){
	int t, k;
	scanf("%d%d", &t, &k);
	DP[0][0] = 1;
	for (int i = 1; i <= 100000; i++){
		DP[i][0] += DP[i - 1][0] + DP[i - 1][1];
		if (i - k >= 0)
			DP[i][1] += DP[i - k][0] + DP[i - k][1];
		DP[i][0] %= MOD;
		DP[i][1] %= MOD;
		sum[i] = (sum[i - 1] + DP[i][0] + DP[i][1]) % MOD;
	}
	while (t--){
		int a, b;
		scanf("%d%d", &a, &b);
		lli resA = sum[a - 1];
		lli resB = sum[b];
		if (resB - resA < 0)
			printf("%lld\n", resB - resA + MOD);
		else
			printf("%lld\n", resB - resA);
	}
	return 0;
}
/*

D. Flowers
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We saw the little game Marmot made for Mole's lunch. Now it's Marmot's dinner time and, as we all know, Marmot eats flowers. At every dinner he eats some red and white flowers. Therefore a dinner can be represented as a sequence of several flowers, some of them white and some of them red.

But, for a dinner to be tasty, there is a rule: Marmot wants to eat white flowers only in groups of size k.

Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could be very large, print it modulo 1000000007 (109 + 7).

Input
Input contains several test cases.

The first line contains two integers t and k (1 ≤ t, k ≤ 105), where t represents the number of test cases.

The next t lines contain two integers ai and bi (1 ≤ ai ≤ bi ≤ 105), describing the i-th test.

Output
Print t lines to the standard output. The i-th line should contain the number of ways in which Marmot can eat between ai and bi flowers at dinner modulo 1000000007 (109 + 7).

Sample test(s)
input
3 2
1 3
2 3
4 4
output
6
5
5
Note
For K = 2 and length 1 Marmot can eat (R).
For K = 2 and length 2 Marmot can eat (RR) and (WW).
For K = 2 and length 3 Marmot can eat (RRR), (RWW) and (WWR).
For K = 2 and length 4 Marmot can eat, for example, (WWWW) or (RWWR), but for example he can't eat (WWWR).

*/