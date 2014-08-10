/* 13919589	10313	Pay the Price	Accepted	C++	0.132	2014-07-21 11:51:54 */
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
#define MAX_N 301
#define MAX_M 1001
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int A[3], ptr;
lli DP[MAX_M][MAX_N];
void input(char S[]){
	ptr = 0;
	int tmp = 0;
	for (int i = 0; S[i] != '\0'; i++)
		if (S[i] != ' ')
			tmp = tmp * 10 + S[i] - '0';
		else
			A[ptr++] = tmp, tmp = 0;
	A[ptr++] = tmp;
}
int main(){
	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;
	for (int j = 1; j <= MAX_N - 1; j++)
		for (int i = 1; i <= MAX_M - 1; i++)
			for (int k = MAX_N - 1; k >= j; k--)
				DP[i][k] += DP[i - 1][k - j];
	char S[10000];
	while (gets(S)){
		lli ans = 0;
		input(S);
		if (ptr == 1)
			for (int i = 0; i <= MAX_M - 1; i++)
				ans += DP[i][A[0]];
		else if (ptr == 2)
			for (int i = 0; i <= A[1]; i++)
				ans += DP[i][A[0]];
		else
			for (int i = A[1]; i <= A[2]; i++)
				ans += DP[i][A[0]];
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem B
Pay the Price
Input: standard input
Output: standard output
Time Limit: 2 seconds
Memory Limit: 32 MB

In ancient days there was a country whose people had very interesting habits. Some of them were lazy, some were very rich, some were very poor and some were miser. Obviously, some of the rich were miser (A poor was never miser as he had little to spend) and lazy but the poor were lazy as well (As the poor were lazy they remained poor forever). The following things were true for that country

a)      As the rich were miser, no things price was more than 300 dollars (Yes! their currency was dollar).
b)      As all people were lazy, the price of everything was integer (There were no cents and so beggars always earned at least one dollar)
c)      The values of the coins were from 1 to 300 dollars, so that the rich (who were idle) could pay any price with a single coin.

Your job is to find out in how many ways one could pay a certain price using a limited number of coins (Note that the number of coins paid is limited but not the value or source. I mean there was infinite number of coins of all values). For example, by using three coins one can pay six dollars in 3 ways, 1+1+4, 1+2+3, and 2+2+2. Similarly, one can pay 6 dollars using 6 coins or less in 11 ways.

Input
The input file contains several lines of input. Each line of input may contain 1, 2 or 3 integers. The first integer is always N (0<=N<=300), the dollar amount to be paid. All other integers are less than 1001 and non-negative.

Output
For each line of input you should output a single integer.

When there is only one integer N as input, you should output in how many ways N dollars can be paid.

When there are two integers N and L1 as input, then you should output in how many ways N dollars can be paid using L1 or less coins.

When there are three integers N, L1 and L2 as input, then you should output in how many ways N dollars can be paid using L1, L1+1 ¡K, L2 coins (summing all together). Remember that L1 is not greater than L2.

Sample Input
6
6 3
6 2 5
6 1 6

Sample Output
11
7
9
11
(The Decider Contest, Problem setter: Shahriar Manzoor)

*/