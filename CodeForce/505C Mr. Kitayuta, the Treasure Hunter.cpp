/* 9475304	2015-01-19 15:02:27	Shark	505C - Mr. Kitayuta, the Treasure Hunter	GNU C++	Accepted	124 ms	71200 KB */
#include<bits/stdc++.h>
using namespace std;
int DP[30005][605];
int gem[30005];
int n, d;
int main(){
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		gem[t]++;
	}
	memset(DP, -1, sizeof(DP));
	DP[d][300] = gem[d];
	int ans = DP[d][300];
	for (int i = d; i <= 30000; i++){
		for (int j = 0; j <= 600; j++){
			if (DP[i][j] == -1) continue;
			for (int k = -1; k <= 1; k++){
				int p = d + j - 300 + k;
				if (p > 0 && i + p <= 30000 && j + k >= 0 && j + k <= 600){
					DP[i + p][j + k] = max(DP[i][j] + gem[i + p], DP[i + p][j + k]);
					ans = max(DP[i + p][j + k], ans);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*

C. Mr. Kitayuta, the Treasure Hunter
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Shuseki Islands are an archipelago of 30001 small islands in the Yutampo Sea. The islands are evenly spaced along a line, numbered from 0 to 30000 from the west to the east. These islands are known to contain many treasures. There are n gems in the Shuseki Islands in total, and the i-th gem is located on island pi.

Mr. Kitayuta has just arrived at island 0. With his great jumping ability, he will repeatedly perform jumps between islands to the east according to the following process:

First, he will jump from island 0 to island d.
After that, he will continue jumping according to the following rule. Let l be the length of the previous jump, that is, if his previous jump was from island prev to island cur, let l = cur - prev. He will perform a jump of length l - 1, l or l + 1 to the east. That is, he will jump to island (cur + l - 1), (cur + l) or (cur + l + 1) (if they exist). The length of a jump must be positive, that is, he cannot perform a jump of length 0 when l = 1. If there is no valid destination, he will stop jumping.
Mr. Kitayuta will collect the gems on the islands visited during the process. Find the maximum number of gems that he can collect.

Input
The first line of the input contains two space-separated integers n and d (1 ≤ n, d ≤ 30000), denoting the number of the gems in the Shuseki Islands and the length of the Mr. Kitayuta's first jump, respectively.

The next n lines describe the location of the gems. The i-th of them (1 ≤ i ≤ n) contains a integer pi (d ≤ p1 ≤ p2 ≤ ... ≤ pn ≤ 30000), denoting the number of the island that contains the i-th gem.

Output
Print the maximum number of gems that Mr. Kitayuta can collect.

Sample test(s)
input
4 10
10
21
27
27
output
3
input
8 8
9
19
28
36
45
55
66
78
output
6
input
13 7
8
8
9
16
17
17
18
21
23
24
24
26
30
output
4
Note
In the first sample, the optimal route is 0  →  10 (+1 gem)  →  19  →  27 (+2 gems)  → ...

In the second sample, the optimal route is 0  →  8  →  15  →  21 →  28 (+1 gem)  →  36 (+1 gem)  →  45 (+1 gem)  →  55 (+1 gem)  →  66 (+1 gem)  →  78 (+1 gem)  → ...

In the third sample, the optimal route is 0  →  7  →  13  →  18 (+1 gem)  →  24 (+2 gems)  →  30 (+1 gem)  → ...

*/