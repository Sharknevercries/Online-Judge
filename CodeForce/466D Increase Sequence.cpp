/* 7808315	2014-09-16 15:07:33	Shark	466D - Increase Sequence	GNU C++	Accepted	31 ms	31500 KB */
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
#define MAX_N 2005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MOD 1000000007
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
lli DP[MAX_N][MAX_N];
void plus_mod(lli &a, lli b){
	a = (a + b) % MOD;
}
int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		int S[MAX_N];
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);
		memset(DP, 0, sizeof(DP));
		DP[1][0] = S[1] == k || S[1] + 1 == k ? 1 : 0;
		DP[1][1] = S[1] + 1 == k ? 1 : 0;
		for (int i = 2; i <= n; i++){
			for (int opened = max(0, k - S[i] - 1); opened <= min(k - S[i], i); opened++){
				if (S[i] + opened == k){
					if (opened > 0)
						plus_mod(DP[i][opened], DP[i - 1][opened - 1]);
					plus_mod(DP[i][opened], DP[i - 1][opened]);
				}
				if(S[i] + opened + 1 == k){
					plus_mod(DP[i][opened], DP[i - 1][opened + 1] * (opened + 1));
					plus_mod(DP[i][opened], DP[i - 1][opened]);
					plus_mod(DP[i][opened], DP[i - 1][opened] * opened);
				}
			}
		}
		printf("%lld\n", DP[n][0]);
	}
	return 0;
}
/*

D. Increase Sequence
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Peter has a sequence of integers a1, a2, ..., an. Peter wants all numbers in the sequence to equal h. He can perform the operation of "adding one on the segment [l, r]": add one to all elements of the sequence with indices from l to r (inclusive). At that, Peter never chooses any element as the beginning of the segment twice. Similarly, Peter never chooses any element as the end of the segment twice. In other words, for any two segments [l1, r1] and [l2, r2], where Peter added one, the following inequalities hold: l1 ≠ l2 and r1 ≠ r2.

How many distinct ways are there to make all numbers in the sequence equal h? Print this number of ways modulo 1000000007 (109 + 7). Two ways are considered distinct if one of them has a segment that isn't in the other way.

Input
The first line contains two integers n, h (1 ≤ n, h ≤ 2000). The next line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 2000).

Output
Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).

Sample test(s)
input
3 2
1 1 1
output
4
input
5 1
1 1 1 1 1
output
1
input
4 3
3 2 1 1
output
0

*/