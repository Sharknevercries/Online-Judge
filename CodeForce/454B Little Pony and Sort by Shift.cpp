/* 7339194	2014-08-03 19:40:52	Shark	454B - Little Pony and Sort by Shift	GNU C++	Accepted	31 ms	800 KB */
/* Template By Shark */
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
#define MAX_N 100000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int S[MAX_N], T[MAX_N];;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i), T[i] = S[i];
		sort(T, T + n);
		int ans = INF;
		for (int i = 0; i < n; i++){
			if (S[i] != T[n - 1])	continue;
			for (; i + 1 < n && S[i] == S[i + 1]; i++);
			int count = 0;
			bool ok = true;
			for (int j = i, k = n - 1; k >= 0 && ok; k--, j--){
				if (j < 0)	j = n - 1;
				if (j > i)	count++;
				if (S[j] != T[k])
					ok = false;
			}
			if (ok)
				ans = min(ans, count);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}
/*

B. Little Pony and Sort by Shift
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day, Twilight Sparkle is interested in how to sort a sequence of integers a1, a2, ..., an in non-decreasing order. Being a young unicorn, the only operation she can perform is a unit shift. That is, she can move the last element of the sequence to its beginning:

a1, a2, ..., an → an, a1, a2, ..., an - 1.
Help Twilight Sparkle to calculate: what is the minimum number of operations that she needs to sort the sequence?

Input
The first line contains an integer n (2 ≤ n ≤ 105). The second line contains n integer numbers a1, a2, ..., an (1 ≤ ai ≤ 105).

Output
If it's impossible to sort the sequence output -1. Otherwise output the minimum number of operations Twilight Sparkle needs to sort it.

Sample test(s)
input
2
2 1
output
1
input
3
1 3 2
output
-1
input
2
1 2
output
0

*/