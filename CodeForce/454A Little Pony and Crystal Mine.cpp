/* 7339038	2014-08-03 19:09:54	Shark	454A - Little Pony and Crystal Mine	GNU C++	Accepted	15 ms	0 KB */
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
	int n;
	while (scanf("%d", &n) == 1){
		for (int row = 0; row < n; row++){
			int count = abs(n / 2 - row);
			for (int j = 0; j < n; j++){
				if (abs(n / 2 - j) <= n / 2 - count)
					putchar('D');
				else
					putchar('*');
			}
			putchar('\n');
		}
	}
	return 0;
}
/*

A. Little Pony and Crystal Mine
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Twilight Sparkle once got a crystal from the Crystal Mine. A crystal of size n (n is odd; n > 1) is an n × n matrix with a diamond inscribed into it.

You are given an odd integer n. You need to draw a crystal of size n. The diamond cells of the matrix should be represented by character "D". All other cells of the matrix should be represented by character "*". Look at the examples to understand what you need to draw.

Input
The only line contains an integer n (3 ≤ n ≤ 101; n is odd).

Output
Output a crystal of size n.

Sample test(s)
input
3
output
*D*
DDD
*D*
input
5
output
**D**
*DDD*
DDDDD
*DDD*
**D**
input
7
output
***D***
**DDD**
*DDDDD*
DDDDDDD
*DDDDD*
**DDD**
***D***

*/