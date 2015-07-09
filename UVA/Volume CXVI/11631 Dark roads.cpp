/* 14020623	11631	Dark roads	Accepted	C++	0.375	2014-08-11 07:26:34 */
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
#define MAX_N 200005
#define MAX_M 1000
#define INF 2e9
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
edge E[MAX_N];
int G[MAX_N];
int find(int x){
	return x == G[x] ? x : G[x] = find(G[x]);
}
bool cmp(edge A, edge B){
	return A.w < B.w;
}
int main(){
	int m, n;
	while (scanf("%d%d", &m, &n) == 2 && n && m){
		lli ans = 0, total = 0;
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].w);
		sort(E, E + n, cmp);
		for (int i = 0; i < m; i++)
			G[i] = i;
		for (int i = 0; i < n; i++){
			int x = find(E[i].a);
			int y = find(E[i].b);
			if (x != y)
				G[x] = y, ans += E[i].w;
			total += E[i].w;
		}
		printf("%lld\n", total - ans);
	}
	return 0;
}
/*

2009/2010 ACM International Collegiate Programming Contest
University of Ulm Local Contest
Problem D: Dark roads

Economic times these days are tough, even in Byteland. To reduce the operating costs, the government of Byteland has decided to optimize the road lighting. Till now every road was illuminated all night long, which costs 1 Bytelandian Dollar per meter and day. To save money, they decided to no longer illuminate every road, but to switch off the road lighting of some streets. To make sure that the inhabitants of Byteland still feel safe, they want to optimize the lighting in such a way, that after darkening some streets at night, there will still be at least one illuminated path from every junction in Byteland to every other junction.

What is the maximum daily amount of money the government of Byteland can save, without making their inhabitants feel unsafe?

Input Specification

The input file contains several test cases. Each test case starts with two numbers m and n, the number of junctions in Byteland and the number of roads in Byteland, respectively. Input is terminated by m=n=0. Otherwise, 1 ≤ m ≤ 200000 and m-1 ≤ n ≤ 200000. Then follow n integer triples x, y, z specifying that there will be a bidirectional road between x and y with length z meters (0 ≤ x, y < m and x ≠ y). The graph specified by each test case is connected. The total length of all roads in each test case is less than 231.

Output Specification

For each test case print one line containing the maximum daily amount the government can save.

Sample Input

7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0
Sample Output

51

*/