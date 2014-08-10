/* 13923957	10690	Expression Again	Accepted	C++	1.892	2014-07-22 07:22:12 */
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
#define MAX_N 51
#define MAX_M 7000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define ZERO 3000
const double PI = 2.0 * acos(0.0);
bool DP[MAX_N][MAX_M];
int S[MAX_M];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		memset(DP, false, sizeof(DP));
		DP[0][ZERO] = true;
		int sum = 0;
		for (int i = 0; i < n + m; i++)
			scanf("%d", S + i), sum += S[i];
		for (int i = 0; i < n + m; i++)
			for (int j = max(n, m); j >= 1; j--)
				for (int k = MAX_M - 1; k >= 0; k--)
					if (k - S[i] >= 0 && k - S[i] < MAX_M)
						DP[j][k] |= DP[j - 1][k - S[i]];
		int ans1 = -INF, ans2 = INF;
		for (int i = 0; i <= MAX_M; i++){
			if (DP[n][i]){
				ans1 = max(ans1, (i - ZERO) * (sum - (i - ZERO)));
				ans2 = min(ans2, (i - ZERO) * (sum - (i - ZERO)));
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
/*

Problem C
Expression Again
Input: standard input
Output: standard output
Time Limit: 6 seconds
You are given an algebraic expression of the form (x1+x2+x3+.....+xn)*(y1+y2+.........+ym) and (n+m) integers. You have to find the maximum and minimum value of the expression using the given integers. For example if you are given (x1+x2)*(y1+y2) and you are given 1, 2, 3 and 4. Then maximum value is (1+4)*(2+3) = 25 whereas minimum value is (4+3)*(2+1) = 21.

Input

Each input set starts with two positive integers N, M (less than 51). Next line follows (N+M) integers which are in the range of -50 to 50. Input is terminated by end of file. There will be atmost 110 testcases.

Output

Output is one line for each case, maximum value followed by minimum value.

Sample Input                           Output for Sample Input
2 2
1 2 3 4
3 1
1 2 3 4
2 2
2 2 2 2

25 21
24 9
16 16

Problem setter: Md Kamruzzaman, Member of Elite Problemsetters' Panel
Special Thanks: Monirul Hasan, Md. Sajjad Hossain

*/