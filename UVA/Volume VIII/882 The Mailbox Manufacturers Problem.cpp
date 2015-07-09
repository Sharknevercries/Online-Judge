/* 13865783	882	The Mailbox Manufacturers Problem	Accepted	C++	0.042	2014-07-11 08:56:39 */
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
#define MAX_N 15
#define MAX_M 105
#define INF 2e9
const double PI = 2.0 * acos(0.0);
int DP[MAX_N][MAX_M][MAX_M];
int main(){
	for (int k = 0; k < MAX_N; k++)
		for (int i = 0; i < MAX_M; i++)
			for (int j = 0; j < MAX_M; j++)
				DP[k][i][j] = i == j ? 0 : INF;
	for (int i = 1; i < MAX_N; i++){
		for (int j = 0; j < MAX_M; j++){
			for (int k = 0; k + j < MAX_M; k++){
				int res = DP[i][k][k + j];
				for (int p = k + 1; p <= k + j; p++)
					res = min(res, p + max(DP[i - 1][k][p - 1], DP[i][p][k + j]));
				DP[i][k][k + j] = res;
			}
		}
	}
	int k, m, t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &k, &m);
		printf("%d\n", DP[k][0][m]);
	}
	return 0;
}
/*

The Mailbox Manufacturers Problem

In the good old days when Swedish children were still allowed to blow up their fingers with fire-crackers, gangs of excited kids would plague certain smaller cities during Easter time, with only one thing in mind: To blow things up. Small boxes were easy to blow up, and thus mailboxes became a popular target. Now, a small mailbox manufacturer is interested in how many fire-crackers his new mailbox prototype can withstand without exploding and has hired you to help him. He will provide you with k (1<=  k<=10) identical mailbox prototypes each fitting up to m (1<=m<=100)  crackers. However, he is not sure of how many fire-crackers he needs to provide you with in order for you to be able to solve his problem, so he asks you. You think for a while and then say: ¡¨Well, if I blow up a mailbox I can¡¦t use it again, so if you would provide me with only k = 1 mailboxes, I would have to start testing with 1 cracker, then 2 crackers, and so on until it finally exploded. In the worst case, that is if it does not blow up even when filled with m crackers, I would need 1 + 2 + 3 + ... + m = m * (m + 1)/2 crackers. If m = 100 that would mean more than 5000 fire-crackers!¡¨. ¡¨That¡¦s too many¡¨, he replies. ¡¨What if I give you more than k = 1 mailboxes? Can you find a strategy that requires less crackers?¡¨

Can you? And what is the minimum number of crackers that you should ask him to provide you with?
You may assume the following:

1. If a mailbox can withstand x fire-crackers, it can also withstand x-1 fire-crackers.
2. Upon an explosion, a mailbox is either totally destroyed (blown up) or unharmed, which means that it can be reused in another test explosion.
Note: If the mailbox can withstand a full load of m fire-crackers, then the manufacturer will of course be satisfied with that answer. But otherwise he is looking for the maximum number of crackers that his mailboxes can withstand.

Input specifications
The input starts with a single integer N(1<=N<=10) indicating the number of test cases to follow. Each test case is described by a line containing two integers: k and m, separated by a single space.

Output specifications
For each test case print one line with a single integer indicating the minimum number of fire-crackers that is needed, in the worst case, in order to figure out how many crackers the mailbox prototype can withstand.

Sample input
4
1 10
1 100
3 73
5 100

Output for sample input
55
5050
382
495

*/