/* 7074460	 2014-07-13 17:03:22	Shark	 447A - DZY Loves Hash	 GNU C++	Accepted	 15 ms	 0 KB */
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
const double PI = 2.0 * acos(0.0);
int main(){
	int n, p;
	while (scanf("%d%d", &p, &n) == 2){
		bool S[301] = { false };
		int ans = -1;
		for (int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			if (!S[x%p])
				S[x%p] = true;
			else if (ans == -1)
				ans = i + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

A. DZY Loves Hash
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
DZY has a hash table with p buckets, numbered from 0 to p - 1. He wants to insert n numbers, in the order they are given, into the hash table. For the i-th number xi, DZY will put it into the bucket numbered h(xi), where h(x) is the hash function. In this problem we will assume, that h(x) = x mod p. Operation a mod b denotes taking a remainder after division a by b.

However, each bucket can contain no more than one element. If DZY wants to insert an number into a bucket which is already filled, we say a "conflict" happens. Suppose the first conflict happens right after the i-th insertion, you should output i. If no conflict happens, just output -1.

Input
The first line contains two integers, p and n (2 ≤ p, n ≤ 300). Then n lines follow. The i-th of them contains an integer xi (0 ≤ xi ≤ 109).

Output
Output a single integer — the answer to the problem.

Sample test(s)
input
10 5
0
21
53
41
53
output
4
input
5 5
0
1
2
3
4
output
-1

*/