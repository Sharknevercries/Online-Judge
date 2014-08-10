/* 7124542	 2014-07-17 18:02:55	Shark	 448A - Rewards	 GNU C++	Accepted	 15 ms	 0 KB */
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
	int a, b, c, d, e, f, n;
	while (scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &n) == 7){
		int res1 = ceil((double)(a + b + c) / 5.0);
		int res2 = ceil((double)(d + e + f) / 10.0);
		if (res1 + res2 <= n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

A. Rewards
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bizon the Champion is called the Champion for a reason.

Bizon the Champion has recently got a present — a new glass cupboard with n shelves and he decided to put all his presents there. All the presents can be divided into two types: medals and cups. Bizon the Champion has a1 first prize cups, a2 second prize cups and a3 third prize cups. Besides, he has b1 first prize medals, b2 second prize medals and b3 third prize medals.

Naturally, the rewards in the cupboard must look good, that's why Bizon the Champion decided to follow the rules:

any shelf cannot contain both cups and medals at the same time;
no shelf can contain more than five cups;
no shelf can have more than ten medals.
Help Bizon the Champion find out if we can put all the rewards so that all the conditions are fulfilled.

Input
The first line contains integers a1, a2 and a3 (0 ≤ a1, a2, a3 ≤ 100). The second line contains integers b1, b2 and b3 (0 ≤ b1, b2, b3 ≤ 100). The third line contains integer n (1 ≤ n ≤ 100).

The numbers in the lines are separated by single spaces.

Output
Print "YES" (without the quotes) if all the rewards can be put on the shelves in the described manner. Otherwise, print "NO" (without the quotes).

Sample test(s)
input
1 1 1
1 1 1
4
output
YES
input
1 1 3
2 3 4
2
output
YES
input
1 0 0
1 0 0
1
output
NO

*/