/* 14248377	11518	Dominos 2	Accepted	C++	0.039	2014-09-23 01:29:26 */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 10005
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
vector<int> G[MAX_N];
bool fall[MAX_N];
void push(int x){
	if (fall[x])return;
	fall[x] = true;
	for (int i = 0; i < G[x].size(); i++)
		push(G[x][i]);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m, l;
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 0; i <= n; i++)
			G[i].clear();
		memset(fall, false, sizeof(fall));
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
		}
		for (int i = 0; i < l; i++){
			int a;
			scanf("%d", &a);
			push(a);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (fall[i])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
/*

Problem D: Dominos 2

Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line. However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Given a set of dominos that are knocked down by hand, your task is to determine the total number of dominos that fall.

Input Specification

The first line of input contains one integer specifying the number of test cases to follow. Each test case begins with a line containing three integers n, m, l no larger than 10 000, followed by m+l additional lines. The first integer n is the number of domino tiles. The domino tiles are numbered from 1 to n. Each of the m lines after the first line contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well. Each of the following l lines contains a single integer z indicating that the domino numbered z is knocked over by hand.
Sample Input

1
3 2 1
1 2
2 3
2
Output Specification

For each test case, output a line containing one integer, the total number of dominos that fall over.
Output for Sample Input

2
Ondřej Lhoták

*/