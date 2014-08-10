/* 13970843	10025	The ? 1 ? 2 ? ... ? n = k problem	Accepted	C++	0.009	2014-07-31 11:05:54 */
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
	int t;
	scanf("%d", &t);
	while (t--){
		lli n;
		scanf("%lld", &n);
		if (n < 0)
			n *= -1;
		if (n == 0)
			printf("%lld\n", 3);
		else{
			lli ans = ceil(((double)sqrt((double)1 + 8 * n) - 1) / 2);
			for (lli i = ans; i <= ans + 2; i++){
				if (((i*(i + 1)) / 2 - n) % 2 == 0){
					printf("%lld\n", i);
					break;
				}
			}
		}
		if (t)	putchar('\n');
	}
	return 0;
}
/*

The ? 1 ? 2 ? ... ? n = k problem

The problem

Given the following formula, one can set operators '+' or '-' instead of each '?', in order to obtain a given k
? 1 ? 2 ? ... ? n = k

For example: to obtain k = 12 , the expression to be used will be:
- 1 + 2 + 3 + 4 + 5 + 6 - 7 = 12
with n = 7

The Input

The first line is the number of test cases, followed by a blank line.

Each test case of the input contains integer k (0<=|k|<=1000000000).

Each test case will be separated by a single line.

The Output

For each test case, your program should print the minimal possible n (1<=n) to obtain k with the above formula.

Print a blank line between the outputs for two consecutive test cases.

Sample Input

2

12

-3646397
Sample Output

7

2701
Alex Gevak
September 15, 2000 (Revised 4-10-00, Antonio Sanchez)

*/