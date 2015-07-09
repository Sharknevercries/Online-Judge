/* 13897637	10898	Combo Deal	Accepted	C++	1.125	2014-07-17 13:50:31 */
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
#define MAX_N 1000000
#define MAX_M 15
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
struct combo{
	int amount[MAX_M];
	int cost;
};
combo M[MAX_M];
int DP[MAX_N + 1];
int n, m, f;
bool check(int s, int t){
	bool res = true;
	int k = n - 1;
	for (int i = 0; i < n; i++){
		res &= (M[t].amount[k] <= s % 10);
		k--, s /= 10;
	}
	return res;
}
int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < MAX_M; i++)
			for (int j = 0; j < MAX_M; j++)
				M[i].amount[j] = M[i].cost = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &M[i].cost), M[i].amount[i] = 1;
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++)
				scanf("%d", &M[i + n].amount[j]);
			scanf("%d", &M[i + n].cost);
		}
		for (int i = 0; i <= MAX_N; i++)
			DP[i] = INF;
		DP[0] = 0;
		for (int i = 0; i < n + m; i++){
			for (int j = 1; j <= MAX_N; j++){
				if (!check(j, i))	continue;
				int prev = j;
				for (int k = n - 1, q = 1; k >= 0; k--, q *= 10)
					prev -= M[i].amount[k] * q;
				DP[j] = min(DP[j], DP[prev] + M[i].cost);
			}
		}
		scanf("%d", &f);
		for (int i = 0; i < f; i++){
			int ask = 0, tmp;
			for (int j = 0; j < n; j++)
				scanf("%d", &tmp), ask = ask * 10 + tmp;
			printf("%lld\n", DP[ask]);
		}
	}
	return 0;
}
/*

D: Combo Deal
A fast food store offers a series of ``combo meal deals" in addition to individually priced items. For example, the menu at the store may look like this:

Hamburger 							 $3.49

Fries 								 $0.99

Pop 								 $1.09

Ice Cream 							 $2.19

Value Meal (1 Hamburger, 1 Fries, 1 Pop) 			 $4.79

Lovers-Only (2 Hamburgers, 2 Fries, 2 Pops, 1 Ice Cream)	 $9.99

Buying a combo is cheaper than buying its items individually.

A parent of many kids (or a coach of many students) face this recurring problem: I need to get, say, 9 hamburgers, 6 fries, and 8 pops. How do I fit this into the menu, using the combo deals optimally, so as to pay as little as possible? Note that I am a conservativist, so I don't buy more food than I need.

Input

The input contains several test cases, each of them with a menu and several orders.
Menu: Individual items, then combos.
(a)
Individual items: number of items $I \le 6$, then their prices (at most $10 each).
(b)
Combos: number of combos (at most 8), then for each combo, its composition as an $I$-tuple of quantities and its price.
Example: the sample input below encodes the menu above.

Orders: number of orders (at most 10), then for each order, an $I$-tuple of the wanted quantities. Each element in the tuples is at most 9.
All prices are integers in cents.

Output

For each order of each case, output the minimum payment in cents on its own line.
Sample Input

4 349 99 109 219
2
1 1 1 0 479
2 2 2 1 999
2
9 6 8 0
9 6 8 5
Sample Output

4139
4700

*/