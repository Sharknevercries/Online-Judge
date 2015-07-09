/* 13987957	11991	Easy Problem from Rujia Liu?	Accepted	C++	0.152	2014-08-04 07:46:29 */
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
#define MAX_N 100000
#define MAX_M 1000000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int A[MAX_N + 1];
vector<int> S[MAX_M + 1];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; i++)
			S[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", A + i);
		for (int i = 1; i <= n; i++)
			S[A[i]].push_back(i);
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if (S[b].size() < a)
				printf("%d\n", 0);
			else
				printf("%d\n", S[b][a - 1]);
		}
	}
	return 0;
}
/*

Problem E

Easy Problem from Rujia Liu?

Though Rujia Liu usually sets hard problems for contests (for example, regional contests like Xi'an 2006, Beijing 2007 and Wuhan 2009, or UVa OJ contests like Rujia Liu's Presents 1 and 2), he occasionally sets easy problem (for example, 'the Coco-Cola Store' in UVa OJ), to encourage more people to solve his problems :D

Given an array, your task is to find the k-th occurrence (from left to right) of an integer v. To make the problem more difficult (and interesting!), you'll have to answer m such queries.

Input

There are several test cases. The first line of each test case contains two integers n, m(1<=n,m<=100,000), the number of elements in the array, and the number of queries. The next line contains n positive integers not larger than 1,000,000. Each of the following m lines contains two integer k and v (1<=k<=n, 1<=v<=1,000,000). The input is terminated by end-of-file (EOF). The size of input file does not exceed 5MB.

Output

For each query, print the 1-based location of the occurrence. If there is no such element, output 0 instead.

Sample Input

8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2
Output for the Sample Input

2
0
7
0
Rujia Liu's Present 3: A Data Structure Contest Celebrating the 100th Anniversary of Tsinghua University
Special Thanks: Yiming Li
Note: Please make sure to test your program with the gift I/O files before submitting!

*/