/* 13860386	10564	Paths through the Hourglass	Accepted	C++	0.172	2014-07-10 08:00:34 */
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
typedef long long int lli;
typedef unsigned long long ull;
#define MAX_N 50
#define MAX_M 600
const double PI = 2.0 * acos(0.0);

int S[MAX_N][MAX_N];
lli DP[MAX_N][MAX_N][MAX_M];
int main(){
	//freopen("output.txt", "w", stdout);
	int n, s;
	while (scanf("%d%d", &n, &s) == 2){
		if (n == 0 && s == 0)	break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n - i + 1; j++)
				scanf("%d", &S[i][j]);
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= i; j++)
				scanf("%d", &S[i + n - 1][j]);
		memset(DP, 0, sizeof(DP));
		for (int i = 1; i <= n; i++)
			DP[2 * n - 1][i][S[2 * n - 1][i]] = 1;
		for (int i = 2 * n - 2; i >= 1; i--){
			if (i < n){
				for (int j = 1; j <= n - i + 1; j++)
					for (int k = s; k >= S[i][j]; k--)
						DP[i][j][k] = DP[i + 1][j][k - S[i][j]] + DP[i + 1][j - 1][k - S[i][j]];
			}
			else{
				for (int j = 1; j <= i - n + 1; j++)
					for (int k = s; k >= S[i][j]; k--)
						DP[i][j][k] = DP[i + 1][j][k - S[i][j]] + DP[i + 1][j + 1][k - S[i][j]];
			}
		}
		lli res = 0;
		for (int i = 1; i <= n; i++)
			res += DP[1][i][s];
		printf("%lld\n", res);
		if (res > 0){
			int ptr = 0;
			for (int i = 1; i <= n && ptr == 0; i++)
				if (DP[1][i][s] > 0)
					ptr = i;
			printf("%d ", ptr - 1);
			for (int i = 1, j = ptr, k = s; i <= 2 * n - 2; i++){
				if (i < n){
					if (DP[i + 1][j - 1][k - S[i][j]] > 0)
						putchar('L'), k -= S[i][j], j--;
					else
						putchar('R'), k -= S[i][j];
				}
				else{
					if (DP[i + 1][j][k - S[i][j]] > 0)
						putchar('L'), k -= S[i][j];
					else
						putchar('R'), k -= S[i][j], j++;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
/*

Problem F
Paths through the Hourglass
Input: Standard Input
Output: Standard Output
Time Limit: 2 Seconds
In the hourglass to the right a path is marked. A path always starts at the first row and ends at the last row. Each cell in the path (except the first) should be directly below to the left or right of the cell in the path in the previous row. The value of a path is the sum of the values in each cell in the path.
A path is described with an integer representing the starting point in the first row (the leftmost cell being 0) followed by a direction string containing the letters L and R, telling whether to go to the left or right. For instance, the path to the right is described as 2 RRRLLRRRLR.

Given the values of each cell in an hourglass as well as an integer S, calculate the number of distinct paths with value S. If at least one path exist, you should also print the path with the lowest starting point. If several such paths exist, select the one which has the lexicographically smallest direction string.

Input
The input contains several cases. Each case starts with a line containing two integers N and S (2≤N≤20, 0≤S<500), the number of cells in the first row of the hourglass and the desired sum. Next follows 2N-1 lines describing each row in the hourglass. Each line contains a space separated list of integers between 0 and 9 inclusive. The first of these lines will contain N integers, then N-1, ..., 2, 1, 2, ..., N-1, N.

The input will terminate with N=S=0. This case should not be processed. There will be less than 30 cases in the input.

Output
For each case, first output the number of distinct paths. If at least one path exist, output on the next line the description of the path mentioned above. If no path exist, output a blank line instead.

Sample Input                             Output for Sample Input
6 41
6 7 2 3 6 8
1 8 0 7 1
2 6 5 7
3 1 0
7 6
8
8 8
6 5 3
9 5 9 5
6 4 4 1 3
2 6 9 4 3 8
2 7
3 1
2
3 5
5 26
2 8 7 2 5
3 6 0 2
1 3 4
2 5
3
7 2
2 9 3
1 0 4 4
4 8 7 2 3
0 0

1
2 RRRLLRRRLR
0

5
2 RLLRRRLR

Problemsetter: Jimmy Mårdell, Member of Elite Problemsetters' Panel

*/