/* 13821619	10497	Sweet Child Makes Trouble	Accepted	C++	0.055	2014-07-02 09:10:39 */
/*

S[n] = (S[n-1] + S[n-2])*(n-1)

*/
#include<cstdio>
#include<string.h>
#define MOD 1000000
#define N 800
long long int DP[1000][400];
int last[1000];
void solve(){
	DP[1][0] = 0, last[1] = 1;
	DP[2][0] = 1, last[2] = 1;
	for (int i = 3; i <= N; i++){
		for (int j = 0; j < last[i - 1]; j++){
			DP[i][j] += (DP[i - 1][j] + DP[i - 2][j])*(i - 1);
			DP[i][j + 1] += DP[i][j] / MOD;
			DP[i][j] %= MOD;
		}
		last[i] = last[i - 1] + 1;
		for (int j = last[i - 1] + 1; DP[i][j] == 0; j--)
			last[i] = j;
	}
}
int main(){
	solve();
	int n;
	while (scanf("%d", &n) == 1){
		if (n == -1)
			break;
		printf("%lld", DP[n][last[n] - 1]);
		for (int i = last[n] - 2; i >= 0; i--)
			printf("%06lld", DP[n][i]);
		putchar('\n');
	}

	return 0;
}
/*

Problem F
Sweet Child Makes Trouble
Input: standard input
Output: standard output
Time Limit: 8 seconds

Children are always sweet but they can sometimes make you feel bitter. In this problem, you will see how Tintin, a five year’s old boy, creates trouble for his parents. Tintin is a joyful boy and is always busy in doing something. But what he does is not always pleasant for his parents. He likes most to play with household things like his father’s wristwatch or his mother’s comb. After his playing he places it in some other place. Tintin is very intelligent and a boy with a very sharp memory. To make things worse for his parents, he never returns the things he has taken for playing to their original places.

Think about a morning when Tintin has managed to ‘steal’ three household objects. Now, in how many ways he can place those things such that nothing is placed in their original place. Tintin does not like to give his parents that much trouble. So, he does not leave anything in a completely new place; he merely permutes the objects.

Input

There will be several test cases. Each will have a positive integer less than or equal to 800 indicating the number of things Tintin has taken for playing. Each integer will be in a line by itself. The input is terminated by a –1 (minus one) in a single line, which should not be processed.

Output

For each test case print an integer indicating in how many ways Tintin can rearrange the things he has taken.

Sample Input

2
3
4
-1
Sample Output

1
2
9
Problemsetter: Tanveer Ahsan (Idea from Shamsul Alam)

*/