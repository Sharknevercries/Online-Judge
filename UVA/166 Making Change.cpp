/* 13953006	166	Making Change	Accepted	C++	0.009	2014-07-27 09:08:22 */
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
	int W[6] = { 5, 10, 20, 50, 100, 200 }, S[6], cost;
	int customer[MAX_N];
	int clerk[MAX_N];

	for (int i = 0; i < MAX_N; i++)
		clerk[i] = INF;
	clerk[0] = 0;
	for (int i = 0; i < 6; i++)
		for (int j = W[i]; j < MAX_N; j += 5)
			clerk[j] = min(clerk[j], clerk[j - W[i]] + 1);

	while (scanf("%d%d%d%d%d%d", &S[0], &S[1], &S[2], &S[3], &S[4], &S[5]) == 6){
		if (!S[0] && !S[1] && !S[2] && !S[3] && !S[4] && !S[5])	break;
		double tmp;
		scanf("%lf", &tmp);
		cost = (tmp + 1e-6) * 100;

		for (int i = 0; i < MAX_N; i++)
			customer[i] = INF;
		customer[0] = 0;
		for (int i = 0; i < 6; i++)
			for (int k = 0; k < S[i]; k++)
				for (int j = MAX_N - 5; j >= W[i]; j -= 5)
					customer[j] = min(customer[j], customer[j - W[i]] + 1);

		int ans = INF;
		for (int i = cost; i < MAX_N; i += 5)
			ans = min(ans, customer[i] + clerk[i - cost]);
		printf("%3d\n", ans);
	}
	return 0;
}
/*

Making Change

Given an amount of money and unlimited (almost) numbers of coins (we will ignore notes for this problem) we know that an amount of money may be made up in a variety of ways. A more interesting problem arises when goods are bought and need to be paid for, with the possibility that change may need to be given. Given the finite resources of most wallets nowadays, we are constrained in the number of ways in which we can make up an amount to pay for our purchases--assuming that we can make up the amount in the first place, but that is another story.

The problem we will be concerned with will be to minimise the number of coins that change hands at such a transaction, given that the shopkeeper has an adequate supply of all coins. (The set of New Zealand coins comprises 5c, 10c, 20c, 50c, $1 and $2.) Thus if we need to pay 55c, and we do not hold a 50c coin, we could pay this as 2*20c + 10c + 5c to make a total of 4 coins. If we tender $1 we will receive 45c in change which also involves 4 coins, but if we tender $1.05 ($1 + 5c), we get 50c change and the total number of coins that changes hands is only 3.

Write a program that will read in the resources available to you and the amount of the purchase and will determine the minimum number of coins that change hands.

Input

Input will consist of a series of lines, each line defining a different situation. Each line will consist of 6 integers representing the numbers of coins available to you in the order given above, followed by a real number representing the value of the transaction, which will always be less than $5.00. The file will be terminated by six zeroes (0 0 0 0 0 0). The total value of the coins will always be sufficient to make up the amount and the amount will always be achievable, that is it will always be a multiple of 5c.

Output

Output will consist of a series of lines, one for each situation defined in the input. Each line will consist of the minimum number of coins that change hands right justified in a field 3 characters wide.

Sample input

2 4 2 2 1 0  0.95
2 4 2 0 1 0  0.55
0 0 0 0 0 0
Sample output

2
3

*/