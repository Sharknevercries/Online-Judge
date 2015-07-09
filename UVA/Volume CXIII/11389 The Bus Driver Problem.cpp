/* 13976362	11389	The Bus Driver Problem	Accepted	C++	0.012	2014-08-01 12:47:33 */
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
#define MAX_N 101
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
// function
const double PI = 2.0 * acos(0.0);
// main
int n, d, r;
int main(){
	while (scanf("%d%d%d", &n, &d, &r) == 3){
		if (n == 0 && d == 0 && r == 0)break;
		int A[MAX_N], B[MAX_N];
		for (int i = 0; i < n; i++)
			scanf("%d", A + i);
		for (int i = 0; i < n; i++)
			scanf("%d", B + i);
		sort(A, A + n);
		sort(B, B + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += (A[i] + B[n - i - 1]) - d > 0 ? (A[i] + B[n - i - 1]) - d : 0;
		printf("%d\n", ans * r);
	}
	return 0;
}
/*

I I U C   O N L I N E   C O N T E S T   2 0 0 8
Problem E: The Bus Driver Problem
Input: standard input
Output: standard output

In a city there are n bus drivers. Also there are n morning bus routes & n afternoon bus routes with various lengths. Each driver is assigned one morning route & one evening route. For any driver, if his total route length for a day exceeds d, he has to be paid overtime for every hour after the first d hours at a flat r taka / hour. Your task is to assign one morning route & one evening route to each bus driver so that the total overtime amount that the authority has to pay is minimized.

Input
The first line of each test case has three integers n, d and r, as described above. In the second line, there are n space separated integers which are the lengths of the morning routes given in meters. Similarly the third line has n space separated integers denoting the evening route lengths. The lengths are positive integers less than or equal to 10000. The end of input is denoted by a case with three 0 s.

Output
For each test case, print the minimum possible overtime amount that the authority must pay.

Constraints
-           1 ≤ n ≤ 100
-           1 ≤ d ≤ 10000
-           1 ≤ r ≤ 5

Sample Input
Output for Sample Input
2 20 5
10 15
10 15
2 20 5
10 10
10 10
0 0 0
50
0

Problem setter: Mohammad Mahmudur Rahman

*/