/* 7249820	2014-07-26 16:11:19	Shark	451C - Predict Outcome of the Game	GNU C++	Accepted	109 ms	0 KB */
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
bool check(lli game, lli a, lli b, lli c, lli avg){
	if (avg < a || avg < b || avg < c)	return	false;
	lli left = game - (avg * 3 - a - b - c);
	if (left >= 0 && left % 3 == 0)	return true;
	else	return false;
}
bool solve(lli n, lli k, lli a, lli b){
	if (a > b)	swap(a, b);
	if (n % 3 != 0)	return false;
	if (k >= a + b && (k - a - b) % 3 == 0 && check(n - k, a, b, 0, n / 3 - (k - a - b) / 3))	return true;
	if (k >= a + a + b && (k - a - a - b) % 3 == 0 && check(n - k, a, a + b, 0, n / 3 - (k - a - a - b) / 3))	return true;
	if (k >= a + b + b && (k - a - b - b) % 3 == 0 && check(n - k, b, a + b, 0, n / 3 - (k - a - b - b) / 3))	return true;
	if (k >= b + b - a && (k - b - b + a) % 3 == 0 && check(n - k, b - a, b, 0, n / 3 - (k - b - b + a) / 3))	return true;
	return false;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		lli n, k, a, b;
		bool ok = true;
		scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
		printf("%s\n", solve(n, k, a, b) ? "yes" : "no");
	}
	return 0;
}
/*

The first line of the input contains a single integer corresponding to number of test cases t (1 ≤ t ≤ 105).

Each of the next t lines will contain four space-separated integers n, k, d1, d2 (1 ≤ n ≤ 1012; 0 ≤ k ≤ n; 0 ≤ d1, d2 ≤ k) — data for the current test case.

Output
For each test case, output a single line containing either "yes" if it is possible to have no winner of tournament, or "no" otherwise (without quotes).

Sample test(s)
input
5
3 0 0 0
3 3 0 0
6 4 1 0
6 3 3 0
3 3 3 2
output
yes
yes
yes
no
no
Note
Sample 1. There has not been any match up to now (k = 0, d1 = 0, d2 = 0). If there will be three matches (1-2, 2-3, 3-1) and each team wins once, then at the end each team will have 1 win.

Sample 2. You missed all the games (k = 3). As d1 = 0 and d2 = 0, and there is a way to play three games with no winner of tournament (described in the previous sample), the answer is "yes".

Sample 3. You missed 4 matches, and d1 = 1, d2 = 0. These four matches can be: 1-2 (win 2), 1-3 (win 3), 1-2 (win 1), 1-3 (win 1). Currently the first team has 2 wins, the second team has 1 win, the third team has 1 win. Two remaining matches can be: 1-2 (win 2), 1-3 (win 3). In the end all the teams have equal number of wins (2 wins).

*/