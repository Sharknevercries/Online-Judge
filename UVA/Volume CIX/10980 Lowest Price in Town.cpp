/* 13896903	10980	Lowest Price in Town	Accepted	C++	0.026	2014-07-17 10:33:35 */
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
#define MAX_N 101
#define MAX_M 100
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
double DP[MAX_N];
int P[MAX_N];
double W[MAX_N];
void print(int s){
	double price = INF;
	for (int i = s; i <= MAX_N - 1; i++)
		price = min(price, DP[i]);
	printf("Buy %d for $%.2lf\n", s, price);
}
int main(){
	int n, t = 1;
	P[0] = 1;
	while (scanf("%lf%d", &W[0], &n) == 2){
		for (int i = 1; i <= n; i++)
			scanf("%d%lf", P + i, W + i);
		for (int i = 0; i <= 100; i++)
			DP[i] = INF;
		DP[0] = 0;
		for (int i = 0; i <= n; i++){
			for (int j = 1; j < P[i]; j++)
				DP[j] = min(DP[j], W[i]);
			for (int j = P[i]; j <= MAX_N - 1; j++)
				DP[j] = min(DP[j], DP[j - P[i]] + W[i]);
		}

		getchar();
		printf("Case %d:\n", t++);
		char T[10000];
		fgets(T, 10000, stdin);
		int m;
		for (int k = 0, tmp = 0;; k++){
			if (T[k] == '\0' || T[k] == '\n'){ print(tmp); break; }
			if (T[k] >= '0' && T[k] <= '9')
				tmp = tmp * 10 + T[k] - '0';
			else
				print(tmp), tmp = 0;
		}
	}
	return 0;
}
/*

Problem E: Lowest Price in Town

Time limit: 1 second

It is sometimes tricky to figure out the cheapest way to buy things, even in the supermarket where the price of all goods are listed clearly. Just consider what I saw last Saturday about the price of cooking oil: (notice the difference in the sizes of the two price tags)

Having a sharp mind (a consequence of regularly taking part in online programming contests), you should have no problem in seeing that the 'buy-1-get-1-free' scheme is preferable. But what about your Mum? It is your responsibility as her son/daughter to write her a program that computes the lowest price to buy things in the supermarket, thus helps her to save money.

Input and Output

The input consists of more than a hundred test cases, each concerning a different item. The first line of each case gives the unit price of buying an item, then a non-negative integer M (≤ 20). This is followed by M lines each containing two numbers N and P (1 < N ≤ 100), which means that you can buy N such items for $P. Finally there is a line containing a list of positive integers K (≤ 100); for each of them your program should print the lowest price you need to get K items. Note that you do not have to buy exactly K items; you may consider buying more than K items, and giving the unneeded items to your dear neighbours, if you can save money in this way.

Note that all prices P given in the input are floating-point numbers in exactly 2 decimal places, with 0 < P < 1000.

Sample Input

22.00 2
2 22.00
4 60.00
2 4
25.00 2
2 48.00
2 46.00
2
22.00 2
2 22.00
4 40.00
1 2 3
Sample Output

Case 1:
Buy 2 for $22.00
Buy 4 for $44.00
Case 2:
Buy 2 for $46.00
Case 3:
Buy 1 for $22.00
Buy 2 for $22.00
Buy 3 for $40.00
Problemsetter: Mak Yan Kei

*/