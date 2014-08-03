/* 5347973	 Dec 4, 2013 5:43:21 PM	Shark	 118D - Caesar's Legions	 GNU C++	Accepted	 30 ms	 100 KB */
#include<stdio.h>
#include<string.h>
#define MOD 100000000
int DP[101][101][2]; // DP[i][j][0] use i horse and j footman ,last place horse
int main(){
	int n, m, k1, k2;
	while (scanf("%d%d%d%d", &n, &m, &k1, &k2) == 4){
		memset(DP, 0, sizeof(DP));
		DP[0][0][0] = DP[0][0][1] = 1;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				for (int k = 1; k <= k1&&k <= i; k++){
					DP[i][j][0] += DP[i - k][j][1]; // 
					DP[i][j][0] %= MOD;
				}
				for (int k = 1; k <= k2&&k <= j; k++){
					DP[i][j][1] += DP[i][j - k][0];
					DP[i][j][0] %= MOD;
				}
			}
		}
		printf("%d\n", (DP[n][m][0] + DP[n][m][1]) % MOD);
	}
	return 0;
}
/*

D. Caesar's Legions
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Gaius Julius Caesar, a famous general, loved to line up his soldiers. Overall the army had n1 footmen and n2 horsemen. Caesar thought that an arrangement is not beautiful if somewhere in the line there are strictly more that k1 footmen standing successively one after another, or there are strictly more than k2 horsemen standing successively one after another. Find the number of beautiful arrangements of the soldiers.

Note that all n1 + n2 warriors should be present at each arrangement. All footmen are considered indistinguishable among themselves. Similarly, all horsemen are considered indistinguishable among themselves.

Input
The only line contains four space-separated integers n1, n2, k1, k2 (1 ≤ n1, n2 ≤ 100, 1 ≤ k1, k2 ≤ 10) which represent how many footmen and horsemen there are and the largest acceptable number of footmen and horsemen standing in succession, correspondingly.

Output
Print the number of beautiful arrangements of the army modulo 100000000 (108). That is, print the number of such ways to line up the soldiers, that no more than k1 footmen stand successively, and no more than k2 horsemen stand successively.

Sample test(s)
input
2 1 1 10
output
1
input
2 3 1 2
output
5
input
2 4 1 1
output
0
Note
Let's mark a footman as 1, and a horseman as 2.

In the first sample the only beautiful line-up is: 121

In the second sample 5 beautiful line-ups exist: 12122, 12212, 21212, 21221, 22121

*/