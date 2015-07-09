/* 14032845	10268	498-bis	Accepted	C++11	0.045	2014-08-13 10:59:02 */
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
#include<tuple>
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
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
lli T[MAX_N];
char S[MAX_N];
char *ptr;
int n;
int main(){
	int x;
	while (scanf("%d", &x) == 1){
		(void)getchar();
		gets(S);
		n = 0;
		ptr = strtok(S, " \n");
		while (ptr != NULL){
			T[n++] = atoll(ptr);
			ptr = strtok(NULL, " \n");
		}
		lli ans = 0;
		for (int i = 0; i < n - 1; i++)
			T[i] *= n - i - 1;
		for (int i = 0; i < n - 1; i++)
			ans = ans * x + T[i];
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem F: 498'

Problem

Looking throw the Online Judge's Problem Set Archive I found a very interesting problem number 498, titled ``Polly the Polynomial''. Frankly speaking, I did not solve it, but I derived from it this problem.

Everything in this problem is a derivative of something from 498. In particular, 498 was "... designed to help you remember ... basic algebra skills, make the world a better place, etc., etc.". This problem is designed to help you remember basic derivation algebra skills, increase the speed in which world becomes a better place, etc., etc.

In 498 you had to evaluate the values of polynomial

a0xn+a1xn-1+...+an-1x+an.
In this problem you should evaluate its derivative. Remember that derivative is defined as

a0nxn-1+a1(n-1)xn-2+...+an-1.
All the input and output data will fit into integer, i.e. its absolute value will be less than 231.

Input

Your program should accept an even number of lines of text. Each pair of lines will represent one problem. The first line will contain one integer - a value for x. The second line will contain a list of integers a0, a1, ..., an-1, an, which represent a set of polynomial coefficients.

Input is terminated by <EOF>.

Output

For each pair of lines, your program should evaluate the derivative of polynomial for the given value x and output it in a single line.

Sample Input

7
1 -1
2
1 1 1
Sample Output

1
5

Alexander Denisjuk, 2002

*/