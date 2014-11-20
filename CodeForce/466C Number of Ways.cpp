/* 7763529	2014-09-12 20:23:47	Shark	C - Number of Ways	GNU C++	Accepted	124 ms	5900 KB */
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
#define MAX_N 500005
#define MAX_M 1000
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
int S[MAX_N];
lli T[MAX_N];
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		memset(T, 0, sizeof(T));
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);
		for (int i = 1; i <= n; i++)
			T[i] = T[i - 1] + S[i];
		if (n >= 3 && T[n] % 3 == 0){
			lli DP[2] = { 0 };
			lli avg = T[n] / 3;
			for (int i = 1; i <= n; i++){
				if (T[i] == avg * 2)	DP[1] += DP[0];
				if (T[i] == avg)	DP[0]++;
			}
			if (avg == 0)
				DP[1] -= DP[0] - 1;
			printf("%lld\n", DP[1]);
		}
		else
			puts("0");
	}
	return 0;
}
/*

C. Number of Ways
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You've got array a[1], a[2], ..., a[n], consisting of n integers. Count the number of ways to split all the elements of the array into three contiguous parts so that the sum of elements in each part is the same.

More formally, you need to find the number of such pairs of indices i, j (2 ≤ i ≤ j ≤ n - 1), that .

Input
The first line contains integer n (1 ≤ n ≤ 5·105), showing how many numbers are in the array. The second line contains n integers a[1], a[2], ..., a[n] (|a[i]| ≤  109) — the elements of array a.

Output
Print a single integer — the number of ways to split the array into three parts with the same sum.

Sample test(s)
input
5
1 2 3 0 3
output
2
input
4
0 1 -1 0
output
1
input
2
4 1
output
0

*/