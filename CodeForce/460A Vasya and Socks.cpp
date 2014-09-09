/* 7518279	2014-08-20 19:35:37	Shark	460A - Vasya and Socks	GNU C++	Accepted	15 ms	0 KB */
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int main(){
	int n, m, left, i,ans = 0;
	scanf("%d%d", &n, &m);
	left = n, i = 0;
	while (left > 0){
		ans++;
		left--;
		i++;
		if (i >= m)	left++, i = 0;
	}
	printf("%d\n", ans);
	return 0;
}
/*

A. Vasya and Socks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has n pairs of socks. In the morning of each day Vasya has to put on a pair of socks before he goes to school. When he comes home in the evening, Vasya takes off the used socks and throws them away. Every m-th day (at days with numbers m, 2m, 3m, ...) mom buys a pair of socks to Vasya. She does it late in the evening, so that Vasya cannot put on a new pair of socks before the next day. How many consecutive days pass until Vasya runs out of socks?

Input
The single line contains two integers n and m (1 ≤ n ≤ 100; 2 ≤ m ≤ 100), separated by a space.

Output
Print a single integer — the answer to the problem.

Sample test(s)
input
2 2
output
3
input
9 3
output
13
Note
In the first sample Vasya spends the first two days wearing the socks that he had initially. Then on day three he puts on the socks that were bought on day two.

In the second sample Vasya spends the first nine days wearing the socks that he had initially. Then he spends three days wearing the socks that were bought on the third, sixth and ninth days. Than he spends another day wearing the socks that were bought on the twelfth day.

*/