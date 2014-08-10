/* 13965843	10440	Ferry Loading II	Accepted	C++	0.019	2014-07-30 06:52:03 */
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
#define MAX_N 1455
#define MAX_M 500
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int DP[MAX_N];
int C[MAX_N];
int T[MAX_N];
int main(){
	int c;
	scanf("%d", &c);
	while (c--){
		int n, t, m;
		scanf("%d%d%d", &n, &t, &m);
		for (int i = 1; i <= m; i++)
			scanf("%d", T + i);
		for (int i = 1; i <= m; i++)
			DP[i] = INF, C[i] = INF;
		DP[0] = C[0] = 0;
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n && i - j >= 0; j++){
				if (DP[i] > max(DP[i - j], T[i]) + 2 * t){
					DP[i] = max(DP[i - j], T[i]) + 2 * t;
					C[i] = C[i - j] + 1;
				}
				else if (DP[i] == max(DP[i - j], T[i]) + 2 * t)
					C[i] = min(C[i], C[i - j] + 1);
			}
		}
		printf("%d %d\n", DP[m] - t, C[m]);
	}
	return 0;
}
/*

Problem B: Ferry Loading II

Before bridges were common, ferries were used to transport cars across rivers. River ferries, unlike their larger cousins, run on a guide line and are powered by the river's current. Cars drive onto the ferry from one end, the ferry crosses the river, and the cars exit from the other end of the ferry.
There is a ferry across the river that can take n cars across the river in t minutes and return in t minutes. m cars arrive at the ferry terminal by a given schedule. What is the earliest time that all the cars can be transported across the river? What is the minimum number of trips that the operator must make to deliver all cars by that time?

The first line of input contains c, the number of test cases. Each test case begins with n, t, m. m lines follow, each giving the arrival time for a car (in minutes since the beginning of the day). The operator can run the ferry whenever he or she wishes, but can take only the cars that have arrived up to that time. For each test case, output a single line with two integers: the time, in minutes since the beginning of the day, when the last car is delivered to the other side of the river, and the minimum number of trips made by the ferry to carry the cars within that time.

You may assume that 0 < n, t, m < 1440. The arrival times for each test case are in non-decreasing order.

Sample input

2
2 10 10
0
10
20
30
40
50
60
70
80
90
2 10 3
10
30
40
Output for sample input

100 5
50 2

*/