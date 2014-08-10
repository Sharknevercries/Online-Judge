/* 7248030	2014-07-26 11:58:07	Shark	450A - Jzzhu and Children	GNU C++	Accepted	15 ms	0 KB */
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
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		int S[MAX_N], s = 0, ans = -1;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		for (int i = n - 1; i >= 0; i--)
			if (s < ceil((double)S[i] / m))
				s = ceil((double)S[i] / m), ans = i;
		printf("%d\n", ans + 1);
	}
	return 0;
}
/*

A. Jzzhu and Children
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n children in Jzzhu's school. Jzzhu is going to give some candies to them. Let's number all the children from 1 to n. The i-th child wants to get at least ai candies.

Jzzhu asks children to line up. Initially, the i-th child stands at the i-th place of the line. Then Jzzhu start distribution of the candies. He follows the algorithm:

Give m candies to the first child of the line.
If this child still haven't got enough candies, then the child goes to the end of the line, else the child go home.
Repeat the first two steps while the line is not empty.
Consider all the children in the order they go home. Jzzhu wants to know, which child will be the last in this order?

Input
The first line contains two integers n, m (1 ≤ n ≤ 100; 1 ≤ m ≤ 100). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 100).

Output
Output a single integer, representing the number of the last child.

Sample test(s)
input
5 2
1 3 1 4 2
output
4
input
6 4
1 1 2 2 3 3
output
6
Note
Let's consider the first sample.

Firstly child 1 gets 2 candies and go home. Then child 2 gets 2 candies and go to the end of the line. Currently the line looks like [3, 4, 5, 2] (indices of the children in order of the line). Then child 3 gets 2 candies and go home, and then child 4 gets 2 candies and goes to the end of the line. Currently the line looks like [5, 2, 4]. Then child 5 gets 2 candies and goes home. Then child 2 gets two candies and goes home, and finally child 4 gets 2 candies and goes home.

Child 4 is the last one who goes home.

*/