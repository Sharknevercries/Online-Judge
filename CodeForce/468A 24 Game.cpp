/* 7876028	2014-09-20 18:02:09	Shark	C - 24 Game	GNU C++	Accepted	46 ms	8 KB */
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
#define MAX_N 1000
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
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		if (n < 4)
			puts("NO");
		else{
			puts("YES");
			int k = n % 4;
			if (k == 0){
				puts("1 * 2 = 2");
				puts("2 * 3 = 6");
				puts("6 * 4 = 24");
			}
			else if (k == 1){
				puts("5 * 4 = 20");
				puts("3 + 2 = 5");
				puts("5 - 1 = 4");
				puts("20 + 4 = 24");
			}
			else if (k == 2){
				puts("2 * 3 = 6");
				puts("6 * 4 = 24");
				puts("6 - 5 = 1");
				puts("1 - 1 = 0");
				puts("24 - 0 = 24");
			}
			else{
				puts("5 * 4 = 20");
				puts("20 * 1 = 20");
				puts("3 + 2 = 5");
				puts("7 - 6 = 1");
				puts("5 - 1 = 4");
				puts("20 + 4 = 24");
			}
			for (int i = 8 + k; i <= n; i += 4){
				printf("%d - %d = %d\n", i - 2, i - 3, 1);
				printf("%d - %d = %d\n", i, i - 1, 1);
				printf("%d - %d = %d\n", 1, 1, 0);
				printf("%d - %d = %d\n", 24, 0, 24);
			}
		}
	}
	return 0;
}
/*

A. 24 Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little X used to play a card game called "24 Game", but recently he has found it too easy. So he invented a new game.

Initially you have a sequence of n integers: 1, 2, ..., n. In a single step, you can pick two of them, let's denote them a and b, erase them from the sequence, and append to the sequence either a + b, or a - b, or a × b.

After n - 1 steps there is only one number left. Can you make this number equal to 24?

Input
The first line contains a single integer n (1 ≤ n ≤ 105).

Output
If it's possible, print "YES" in the first line. Otherwise, print "NO" (without the quotes).

If there is a way to obtain 24 as the result number, in the following n - 1 lines print the required operations an operation per line. Each operation should be in form: "a op b = c". Where a and b are the numbers you've picked at this operation; op is either "+", or "-", or "*"; c is the result of corresponding operation. Note, that the absolute value of c mustn't be greater than 1018. The result of the last operation must be equal to 24. Separate operator sign and equality sign from numbers with spaces.

If there are multiple valid answers, you may print any of them.

Sample test(s)
input
1
output
NO
input
8
output
YES
8 * 7 = 56
6 * 5 = 30
3 - 4 = -1
1 - 2 = -1
30 - -1 = 31
56 - 31 = 25
25 + -1 = 24

*/