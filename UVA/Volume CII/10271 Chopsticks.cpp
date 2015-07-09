/* 15388635	10271	Chopsticks	Accepted	C++	0.592	2015-04-26 13:46:06 */
#include<bits\stdc++.h>
using namespace std;
long long w[5005];
long long DP[5005][1005];
long long square(long long a){
	return a*a;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int k, n;
		scanf("%d%d", &k, &n);
		// C >= B >= A
		for (int i = n; i >= 1; i--)
			scanf("%lld", w + i);
		k += 8;
		memset(DP, 0x7f, sizeof(DP));
		for (int i = 0; i <= n; i++)
			DP[i][0] = 0;
		for (int i = 3; i <= n; i++){
			for (int j = 1; j <= k; j++){
				DP[i][j] = min(DP[i][j], DP[i - 1][j]);
				if (j * 3 <= i && (j - 1) * 3 <= i - 2)
					DP[i][j] = min(DP[i][j], DP[i - 2][j - 1] + square(w[i - 1] - w[i]));
			}
		}
			
		printf("%lld\n", DP[n][k]);
	}
	return 0;
}
/*

In China, people use a pair of chopsticks to get food on the table, but Mr. L is a bit different. He uses
a set of three chopsticks – one pair, plus an EXTRA long chopstick to get some big food by piercing
it through the food. As you may guess, the length of the two shorter chopsticks should be as close as
possible, but the length of the extra one is not important, as long as it’s the longest. To make things
clearer, for the set of chopsticks with lengths A, B, C (A ≤ B ≤ C), (A − B)
2
is called the “badness”
of the set.
It’s December 2nd, Mr.L’s birthday! He invited K people to join his birthday party, and would like
to introduce his way of using chopsticks. So, he should prepare K + 8 sets of chopsticks(for himself,
his wife, his little son, little daughter, his mother, father, mother-in-law, father-in-law, and K other
guests). But Mr.L suddenly discovered that his chopsticks are of quite different lengths! He should find
a way of composing the K + 8 sets, so that the total badness of all the sets is minimized.
Input
The first line in the input contains a single integer T, indicating the number of test cases (1 ≤ T ≤ 20).
Each test case begins with two integers K, N (0 ≤ K ≤ 1000, 3K + 24 ≤ N ≤ 5000), the number of
guests and the number of chopsticks.
There are N positive integers Li on the next line in non–decreasing order indicating the lengths of
the chopsticks (1 ≤ Li ≤ 32000).
Output
For each test case in the input, print a line containing the minimal total badness of all the sets.
Note: For the sample input, a possible collection of the 9 sets is:
8,10,16; 19,22,27; 61,63,75; 71,72,88; 81,81,84; 96,98,103; 128,129,148; 134,134,139; 157,157,160
Sample Input
1
1 40
1 8 10 16 19 22 27 33 36 40 47 52 56 61 63 71 72 75 81 81 84 88 96 98
103 110 113 118 124 128 129 134 134 139 148 157 157 160 162 164
Sample Output
23

*/