/* 7142988	2014-07-18 05:25:32	Shark	D - Multiplication Table	GNU C++	Accepted	156 ms	8 KB */
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
lli solve(lli x, lli n, lli m){
	lli cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += min(m, x / i);
	return cnt;
}
int main(){
	lli n, m, k;
	while (scanf("%lld%lld%lld", &n, &m, &k) == 3){
		lli L = 1, R = n*m;
		while (R > L){
			lli mid = (L + R) / 2;
			if (solve(mid, n, m) < k)
				L = mid + 1;
			else
				R = mid;
		}
		printf("%lld\n", L);
	}
	return 0;
}
/*

D. Multiplication Table
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bizon the Champion isn't just charming, he also is very smart.

While some of us were learning the multiplication table, Bizon the Champion had fun in his own manner. Bizon the Champion painted an n × m multiplication table, where the element on the intersection of the i-th row and j-th column equals i·j (the rows and columns of the table are numbered starting from 1). Then he was asked: what number in the table is the k-th largest number? Bizon the Champion always answered correctly and immediately. Can you repeat his success?

Consider the given multiplication table. If you write out all n·m numbers from the table in the non-decreasing order, then the k-th number you write out is called the k-th largest number.

Input
The single line contains integers n, m and k (1 ≤ n, m ≤ 5·105; 1 ≤ k ≤ n·m).

Output
Print the k-th largest number in a n × m multiplication table.

Sample test(s)
input
2 2 2
output
2
input
2 3 4
output
3
input
1 10 5
output
5
Note
A 2 × 3 multiplication table looks like this:

1 2 3
2 4 6

*/