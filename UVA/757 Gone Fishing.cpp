/* 13937247	757	Gone Fishing	Accepted	C++	0.036	2014-07-24 09:04:13 */
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
int main(){
	int n, h, t = 0;
	while (scanf("%d", &n) == 1 && n){
		int F[MAX_N], D[MAX_N], T[MAX_N] = { 0 };
		int cost[MAX_N] = { 0 }, maxFish = -1;
		scanf("%d", &h);
		for (int i = 0; i < n; i++)
			scanf("%d", F + i);
		for (int i = 0; i < n; i++)
			scanf("%d", D + i);
		for (int i = 0; i < n - 1; i++)
			scanf("%d", T + i);
		for (int i = 0; i < n; i++){
			int left = h * 60, fish = 0;
			int S[MAX_N], C[MAX_N] = { 0 };
			for (int j = 0; j < i; j++)
				left -= T[j] * 5;
			for (int j = 0; j < n; j++)
				S[j] = F[j];
			while (left > 0){
				int max = -1, pos = -1;
				for (int j = 0; j <= i; j++)
					if (max < S[j])
						max = S[j], pos = j;
				C[pos] += 5;
				left -= 5;
				fish += max;
				S[pos] -= D[pos];
				if (S[pos] < 0)	S[pos] = 0;
			}
			if (maxFish < fish){
				maxFish = fish;
				for (int i = 0; i < n; i++)
					cost[i] = C[i];
			}
		}
		if (t++)	putchar('\n');
		printf("%d", cost[0]);
		for (int i = 1; i < n; i++)
			printf(", %d", cost[i]);
		putchar('\n');
		printf("Number of fish expected: %d\n", maxFish);
	}
	return 0;
}
/*

Gone Fishing
John is going on a fishing trip. He has h hours available (  $1 \leŸ h \leŸ 16$), and there are n lakes in the area (  $2 \leŸ n \leŸ 25$) all reachable along a single, one-way road. John starts at lake 1, but he can finish at any lake he wants. He can only travel from one lake to the next one, but he does not have to stop at any lake unless he wishes to. For each  $i = 1, \dots, n- 1$, the number of 5-minute intervals it takes to travel from lake i to lake i + 1 is denoted ti (  $0 < t_i \leŸ 192$). For example, t3 = 4 means that it takes 20 minutes to travel from lake 3 to lake 4.

To help plan his fishing trip, John has gathered some information about the lakes. For each lake i, the number of fish expected to be caught in the initial 5 minutes, denoted fi (  $f_i \ge– 0$), is known. Each 5 minutes of fishing decreases the number of fish expected to be caught in the next 5-minute interval by a constant rate of di (  $d_i \ge– 0$). If the number of fish expected to be caught in an interval is less than or equal to di, there will be no more fish left in the lake in the next interval. To simplify the planning, John assumes that no one else will be fishing at the lakes to affect the number of fish he expects to catch.

Write a program to help John plan his fishing trip to maximize the number of fish expected to be caught. The number of minutes spent at each lake must be a multiple of 5.

Input

You will be given a number of cases in the input. Each case starts with a line containing n. This is followed by a line containing h. Next, there is a line of n integers specifying fi (  $1 \leŸ i \leŸ n$), then a line of n integers di (  $1 \leŸ i \leŸ n$), and finally, a line of n - 1 integers ti ( $1 \leŸ i Ÿ\le n - 1$). Input is terminated by a case in which n = 0.
Output

For each test case, print the number of minutes spent at each lake, separated by commas, for the plan achieving the maximum number of fish expected to be caught (you should print the entire plan on one line even if it exceeds 80 characters). This is followed by a line containing the number of fish expected. If multiple plans exist, choose the one that spends as long as possible at lake 1, even if no fish are expected to be caught in some intervals. If there is still a tie, choose the one that spends as long as possible at lake 2, and so on. Insert a blank line between cases.
Sample Input

2
1
10 1
2 5
2
4
4
10 15 20 17
0 3 4 3
1 2 3
4
4
10 15 50 30
0 3 4 3
1 2 3
0
Sample Output

45, 5
Number of fish expected: 31

240, 0, 0, 0
Number of fish expected: 480

115, 10, 50, 35
Number of fish expected: 724

Miguel A. Revilla
2000-02-09

*/