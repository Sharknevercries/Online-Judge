/* 6607904	 May 13, 2014 9:52:41 AM	Shark	 429B - Working out	 GNU C++	Accepted	 217 ms	 35300 KB */
#include<cstdio>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
unsigned long long A[1002][1002];
unsigned long long B[1002][1002];
unsigned long long C[1002][1002];
unsigned long long D[1002][1002];
int S[1002][1002];
int n, m;
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &S[i][j]);
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(C, 0, sizeof(C));
		memset(D, 0, sizeof(D));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				unsigned long long max = 0;
				max = MAX(max, S[i][j] + A[i - 1][j]);
				max = MAX(max, S[i][j] + A[i][j - 1]);
				A[i][j] = max;
			}
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 1; j--){
				unsigned long long max = 0;
				max = MAX(max, S[i][j] + B[i - 1][j]);
				max = MAX(max, S[i][j] + B[i][j + 1]);
				B[i][j] = max;
			}
		for (int i = n; i >= 1; i--)
			for (int j = 1; j <= m; j++){
				unsigned long long max = 0;
				max = MAX(max, S[i][j] + C[i + 1][j]);
				max = MAX(max, S[i][j] + C[i][j - 1]);
				C[i][j] = max;
			}
		for (int i = n; i >= 1; i--)
			for (int j = m; j >= 1; j--){
				unsigned long long max = 0;
				max = MAX(max, S[i][j] + D[i + 1][j]);
				max = MAX(max, S[i][j] + D[i][j + 1]);
				D[i][j] = max;
			}

		unsigned long long ans = 0;
		for (int i = 2; i <= n - 1; i++)
			for (int j = 2; j <= m - 1; j++){
				unsigned long long max = 0;
				max = MAX(max, A[i - 1][j] + D[i + 1][j] + B[i][j + 1] + C[i][j - 1]);
				max = MAX(max, B[i - 1][j] + C[i + 1][j] + D[i][j + 1] + A[i][j - 1]);
				if (ans < max)
					ans = max;
			}
		printf("%llu\n", ans);
	}
	return 0;
}
/*

B. Working out
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Summer is coming! It's time for Iahub and Iahubina to work out, as they both want to look hot at the beach. The gym where they go is a matrix a with n lines and m columns. Let number a[i][j] represents the calories burned by performing workout at the cell of gym in the i-th line and the j-th column.

Iahub starts with workout located at line 1 and column 1. He needs to finish with workout a[n][m]. After finishing workout a[i][j], he can go to workout a[i + 1][j] or a[i][j + 1]. Similarly, Iahubina starts with workout a[n][1] and she needs to finish with workout a[1][m]. After finishing workout from cell a[i][j], she goes to either a[i][j + 1] or a[i - 1][j].

There is one additional condition for their training. They have to meet in exactly one cell of gym. At that cell, none of them will work out. They will talk about fast exponentiation (pretty odd small talk) and then both of them will move to the next workout.

If a workout was done by either Iahub or Iahubina, it counts as total gain. Please plan a workout for Iahub and Iahubina such as total gain to be as big as possible. Note, that Iahub and Iahubina can perform workouts with different speed, so the number of cells that they use to reach meet cell may differs.

Input
The first line of the input contains two integers n and m (3 ≤ n, m ≤ 1000). Each of the next n lines contains m integers: j-th number from i-th line denotes element a[i][j] (0 ≤ a[i][j] ≤ 105).

Output
The output contains a single number — the maximum total gain possible.

Sample test(s)
input
3 3
100 100 100
100 1 100
100 100 100
output
800
Note
Iahub will choose exercises a[1][1] → a[1][2] → a[2][2] → a[3][2] → a[3][3]. Iahubina will choose exercises a[3][1] → a[2][1] → a[2][2] → a[2][3] → a[1][3].

*/