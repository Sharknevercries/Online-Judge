/* 7339444	2014-08-03 20:31:05	Shark	453A - Little Pony and Expected Maximum	GNU C++	Accepted	31 ms	0 KB */
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n, m;
	while (scanf("%d%d", &m, &n) == 2){
		double ans = 0;
		for (int i = 1; i <= m; i++)
			ans += i *(pow((double)i / m, n) - pow((double)(i - 1) / m, n));
		printf("%.12lf\n", ans);
	}
	return 0;
}
/*

A. Little Pony and Expected Maximum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Twilight Sparkle was playing Ludo with her friends Rainbow Dash, Apple Jack and Flutter Shy. But she kept losing. Having returned to the castle, Twilight Sparkle became interested in the dice that were used in the game.

The dice has m faces: the first face of the dice contains a dot, the second one contains two dots, and so on, the m-th face contains m dots. Twilight Sparkle is sure that when the dice is tossed, each face appears with probability . Also she knows that each toss is independent from others. Help her to calculate the expected maximum number of dots she could get after tossing the dice n times.

Input
A single line contains two integers m and n (1 ≤ m, n ≤ 105).

Output
Output a single real number corresponding to the expected maximum. The answer will be considered correct if its relative or absolute error doesn't exceed 10  - 4.

Sample test(s)
input
6 1
output
3.500000000000
input
6 3
output
4.958333333333
input
2 2
output
1.750000000000
Note
Consider the third test example. If you've made two tosses:

You can get 1 in the first toss, and 2 in the second. Maximum equals to 2.
You can get 1 in the first toss, and 1 in the second. Maximum equals to 1.
You can get 2 in the first toss, and 1 in the second. Maximum equals to 2.
You can get 2 in the first toss, and 2 in the second. Maximum equals to 2.
The probability of each outcome is 0.25, that is expectation equals to:

You can read about expectation using the following link: http://en.wikipedia.org/wiki/Expected_value

*/