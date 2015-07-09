/* 14222391	11026	A Grouping Problem	Accepted	C++	0.222	2014-09-18 06:27:25 */
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
lli DP[MAX_N][MAX_N];
lli S[MAX_N];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n&&m){
		for (int i = 1; i <= n; i++)
			scanf("%lld", S + i);
		memset(DP, 0, sizeof(DP));
		for (int i = 1; i <= n; i++)
			DP[i][1] = (DP[i - 1][1] + S[i]) % m;
		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= i; j++)
				if (i > j)
					DP[i][j] = (DP[i][j] + DP[i - 1][j] + DP[i - 1][j - 1] * S[i]) % m;
				else
					DP[i][j] = (DP[i][j] + DP[i - 1][j - 1] * S[i]) % m;
		lli ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, DP[n][i]);
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem F
A Grouping Problem
Input: Standard Input
Output: Standard Output

You are given a set of N integers.  You can take K different elements from them to make a group. Two groups will be different if there is at least one element which is not common to both. For example, if there are 4 elements ¡V a, b, c, d and you are asked to take two elements then ab, ad, bc, cd are all valid and different groups. A grouping system is complete if for a particular K, number of different groups is the maximum. In the former case, {ab, bc, cd, bd, ad, ac} is a complete grouping system.

For a particular complete grouping system, the fitness is calculated in the following way ¡V
Each group of a grouping system contributes a part ¡V the multiplication of all numbers of that group
Contribution from all groups are added
The fitness is equivalent to Total Contribution mod M, M is the bounding parameter
In our example, for K = 2, the fitness is F2 = (ab+bc+cd+bd+ad+ac) mod M. If K = 1, then fitness is F1 = (a+b+c+d) mod M.

Here, in this problem you have to find the complete grouping system with maximum fitness.

Input
Each test case starts with two positive integer N (2<=N<=1000) and M (1<=M<231). In next few lines there will be N positive integers. Each integer will be at best 1000. Input will be terminated by a case where N=M=0.

Output
For each test case, print in a line the maximum fitness possible for a grouping system.

Sample Input                             Output for Sample Input
4 10
1 2 3 4
4 100
1 2 3 4
4 6
1 2 3 4
0 0

5
50
5

Problem setter: Md. Kamruzzaman, EPS

*/