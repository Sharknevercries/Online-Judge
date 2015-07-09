/* 14002226	12455	Bars	Accepted	C++	0.016	2014-08-07 07:02:32 */
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
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		int W[20];
		bool DP[MAX_N + 1] = { false };
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d", W + i);
		DP[0] = true;
		for (int i = 0; i < m; i++)
			for (int j = n; j - W[i] >= 0; j--)
				DP[j] |= DP[j - W[i]];
		printf("%s\n", DP[n] ? "YES" : "NO");
	}
	return 0;
}
/*

B: Bars
Background

Some things grow if you put them together.

The Problem

We have some metallic bars, theirs length known, and, if necessary, we want to solder some of them in order to obtain another one being exactly a given length long. No bar can be cut up. Is it possible?

The Input

The first line of the input contains an integer, t, 0 ≤ t ≤ 50, indicating the number of test cases. For each test case, three lines appear, the first one contains a number n, 0 ≤ n ≤ 1000, representing the length of the bar we want to obtain. The second line contains a number p, 1 ≤ p ≤ 20, representing the number of bars we have. The third line of each test case contains p numbers, representing the length of the p bars.

The Output

For each test case the output should contain a single line, consists of the string YES or the string NO, depending on whether solution is possible or not.

Sample Input

4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567
Sample Output

NO
YES
NO
YES
OMP'12
Facultad de Informatica
Universidad de Murcia (SPAIN)

*/