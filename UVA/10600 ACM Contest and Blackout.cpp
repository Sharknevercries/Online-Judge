/* 14021075	10600	ACM Contest and Blackout	Accepted	C++	0.016	2014-08-11 09:01:17 */
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
#define MAX_N 200
#define MAX_M 10000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct edge{
	int a, b, w;
};
edge E[MAX_N * MAX_N + 5];
int G[MAX_N];
int ansOne, ansTwo;
vector<int> mst;
int n, m;
bool cmp(edge A, edge B){
	return A.w < B.w;
}
int find(int x){
	return x == G[x] ? x : G[x] = find(G[x]);
}
void MST(int ban){
	int sum = 0, count = 0;
	for (int i = 1; i <= n; i++)
		G[i] = i;
	for (int i = 0; i < m; i++){
		if (i == ban)	continue;
		int x = find(E[i].a);
		int y = find(E[i].b);
		if (x != y){
			G[x] = y, sum += E[i].w;
			if (ban == NONE)
				mst.push_back(i);
			count++;
		}
	}
	if (count != n - 1)	return;
	if (ban == NONE)
		ansOne = sum;
	else
		ansTwo = min(ansTwo, sum);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].w);
		sort(E, E + m, cmp);
		ansOne = 0, ansTwo = INF;
		mst.clear();
		MST(NONE);
		for (int i = 0; i < mst.size(); i++)
			MST(mst[i]);
		printf("%d %d\n", ansOne, ansTwo);
	}
	return 0;
}
/*

Problem A
ACM CONTEST AND BLACKOUT

In order to prepare the “The First National ACM School Contest”(in 20??) the major of the city decided to provide all the schools with a reliable source of power. (The major is really afraid of blackoutsJ). So, in order to do that, power station “Future” and one school (doesn’t matter which one) must be connected; in addition, some schools must be connected as well.

You may assume that a school has a reliable source of power if it’s connected directly to “Future”, or to any other school that has a reliable source of power. You are given the cost of connection between some schools. The major has decided to pick out two the cheapest connection plans – the cost of the connection is equal to the sum of the connections between the schools. Your task is to help the major – find the cost of the two cheapest connection plans.

Input
The Input starts with the number of test cases, T (1£T£15) on a line. Then T test cases follow. The first line of every test case contains two numbers, which are separated by a space, N (3£N£100) the number of schools in the city, and M the number of possible connections among them. Next M lines contain three numbers Ai, Bi, Ci , where Ci  is the cost of the connection (1£Ci£300) between schools Ai  and Bi. The schools are numbered with integers in the range 1 to N.

Output
For every test case print only one line of output. This line should contain two numbers separated by a single space - the cost of two the cheapest connection plans. Let S1 be the cheapest cost and S2 the next cheapest cost. It’s important, that S1=S2 if and only if there are two cheapest plans, otherwise S1£S2. You can assume that it is always possible to find the costs S1 and S2..

Sample Input
Sample Output
2
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66
9 14
1 2 4
1 8 8
2 8 11
3 2 8
8 9 7
8 7 1
7 9 6
9 3 2
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
5 6 10
110 121
37 37

Problem source: Ukrainian National Olympiad in Informatics 2001
Problem author: Shamil Yagiyayev
Problem submitter: Dmytro Chernysh
Problem solution: Shamil Yagiyayev, Dmytro Chernysh, K M Hasan

*/