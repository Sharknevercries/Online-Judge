/* 14170614	10943	How do you add?	Accepted	C++	0.415	2014-09-09 07:25:21 */
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
#define MAX_N 105
#define MAX_M 1000
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
	int n, k;
	while (scanf("%d%d", &n, &k) == 2 && n && k){
		lli DP[MAX_N][MAX_N] = { 0 };
		for (int i = 0; i <= k; i++)DP[0][i] = 1;
		for (int i = 1; i <= n; i++)
			for (int t = 1; t <= k; t++)
				for (int j = 0; i - j >= 0; j++)
					DP[i][t] = (DP[i][t] + DP[i - j][t - 1]) % 1000000;
		printf("%lld\n", DP[n][k]);
	}
	return 0;
}
/*

Problem A: How do you add?

Larry is very bad at math - he usually uses a calculator, which worked well throughout college. Unforunately, he is now struck in a deserted island with his good buddy Ryan after a snowboarding accident. They're now trying to spend some time figuring out some good problems, and Ryan will eat Larry if he cannot answer, so his fate is up to you!

It's a very simple problem - given a number N, how many ways can K numbers less than N add up to N?

For example, for N = 20 and K = 2, there are 21 ways:
0+20
1+19
2+18
3+17
4+16
5+15
...
18+2
19+1
20+0


Input

Each line will contain a pair of numbers N and K. N and K will both be an integer from 1 to 100, inclusive. The input will terminate on 2 0's.
Output

Since Larry is only interested in the last few digits of the answer, for each pair of numbers N and K, print a single number mod 1,000,000 on a single line.

Sample Input

20 2
20 2
0 0
Sample Output

21
21

*/