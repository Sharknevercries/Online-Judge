/* 5354030	 Dec 5, 2013 4:45:21 PM	Shark	 18C - Stripe	 GNU C++	Accepted	 62 ms	 800 KB */
#include<stdio.h>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[100000];
		int sum[100000];
		for (int i = 0; i < n; i++)
			scanf("%d", &M[i]);
		sum[0] = M[0];
		for (int i = 1; i < n; i++)
			sum[i] = sum[i - 1] + M[i];

		int ans = 0;
		for (int i = 0; i < n - 1; i++){
			if (sum[n - 1] - sum[i] == sum[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

C. Stripe
time limit per test2 seconds
memory limit per test64 megabytes
inputstandard input
outputstandard output
Once Bob took a paper stripe of n squares (the height of the stripe is 1 square). In each square he wrote an integer number, possibly negative. He became interested in how many ways exist to cut this stripe into two pieces so that the sum of numbers from one piece is equal to the sum of numbers from the other piece, and each piece contains positive integer amount of squares. Would you help Bob solve this problem?

Input
The first input line contains integer n (1 ≤ n ≤ 105) — amount of squares in the stripe. The second line contains n space-separated numbers — they are the numbers written in the squares of the stripe. These numbers are integer and do not exceed 10000 in absolute value.

Output
Output the amount of ways to cut the stripe into two non-empty pieces so that the sum of numbers from one piece is equal to the sum of numbers from the other piece. Don't forget that it's allowed to cut the stripe along the squares' borders only.

Sample test(s)
input
9
1 5 -6 7 9 -16 0 -2 2
output
3
input
3
1 1 1
output
0
input
2
0 0
output
1

*/