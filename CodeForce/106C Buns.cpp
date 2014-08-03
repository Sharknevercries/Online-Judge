/* 5518403	 Dec 25, 2013 3:24:27 PM	Shark	 106C - Buns	 GNU C++	Accepted	30 ms	0 KB */
#include<cstdio>
int main(){
	int n, m, p, q;
	while (scanf("%d%d%d%d", &n, &m, &p, &q) == 4){
		int DP[1001] = { 0 };
		for (int i = 0; i < m; i++){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			for (int j = 1; j <= a / b; j++){
				for (int k = n; k - c >= 0; k--){
					if (DP[k - c] + d>DP[k])
						DP[k] = DP[k - c] + d;
				}
			}
		}
		for (int i = 1; i <= n / p; i++){
			for (int j = n; j - p >= 0; j--){
				if (DP[j - p] + q > DP[j])
					DP[j] = DP[j - p] + q;
			}
		}
		printf("%d\n", DP[n]);
	}
	return 0;
}
/*

C. Buns
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lavrenty, a baker, is going to make several buns with stuffings and sell them.

Lavrenty has n grams of dough as well as m different stuffing types. The stuffing types are numerated from 1 to m. Lavrenty knows that he has ai grams left of the i-th stuffing. It takes exactly bi grams of stuffing i and ci grams of dough to cook a bun with the i-th stuffing. Such bun can be sold for di tugriks.

Also he can make buns without stuffings. Each of such buns requires c0 grams of dough and it can be sold for d0 tugriks. So Lavrenty can cook any number of buns with different stuffings or without it unless he runs out of dough and the stuffings. Lavrenty throws away all excess material left after baking.

Find the maximum number of tugriks Lavrenty can earn.

Input
The first line contains 4 integers n, m, c0 and d0 (1 ≤ n ≤ 1000, 1 ≤ m ≤ 10, 1 ≤ c0, d0 ≤ 100). Each of the following m lines contains 4 integers. The i-th line contains numbers ai, bi, ci and di (1 ≤ ai, bi, ci, di ≤ 100).

Output
Print the only number — the maximum number of tugriks Lavrenty can earn.

Sample test(s)
input
10 2 2 1
7 3 2 100
12 3 1 10
output
241
input
100 1 25 50
15 5 20 10
output
200
Note
To get the maximum number of tugriks in the first sample, you need to cook 2 buns with stuffing 1, 4 buns with stuffing 2 and a bun without any stuffing.

In the second sample Lavrenty should cook 4 buns without stuffings.

*/