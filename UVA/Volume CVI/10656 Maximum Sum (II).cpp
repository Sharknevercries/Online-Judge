/* 14007948	10656	Maximum Sum (II)	Accepted	C++	0.036	2014-08-08 08:15:10 */
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
#define MAX_N 1001
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n;
	bool first = true;
	while (scanf("%d", &n) == 1 && n){
		if (!first)
			putchar('\n');
		int  A[MAX_N];
		vector<int> ans;
		for (int i = 1; i <= n; i++)
			scanf("%d", A + i);
		for (int i = 1; i <= n; i++)
			if (A[i] > 0)
				ans.push_back(A[i]);
		if (ans.size() == 0)
			ans.push_back(0);
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++)
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}
/*

Problem F
Maximum Sum II
Input: standard input
Output: standard output
Time Limit: 1 second

In a given a sequence of non-negative integers you will have to find such a sub-sequence in it whose summation is maximum.

Input
The input file contains several input sets. The description of each set is given below:

Each set starts with an integer N (N<1000) that indicates how many numbers are in that set. Each of the next N lines contains a single non-negative integer. All these numbers are less than 10000.

Input is terminated by a set where N=0. This set should not be processed.

Output
For each set of input produce one line of output. This line contains one or more integers which is are taken from the input sequence and whose summation is maximum. If there is more than one such sub-sequence print the one that has minimum length. If there is more than one sub-sequence of minimum length, output the one that occurs first in the given sequence of numbers. A valid sub-sequence must have a single number in it. Two consecutive numbers in the output are separated by a single space.

Sample Input                               Output for Sample Input
2
3
4
0
3 4

Problem setter: Shahriar Manzoor, Member of Elite Problemsetters' Panel
Special Thanks: Monirul Hasan, Member of Elite Problemsetters' Panel

*/