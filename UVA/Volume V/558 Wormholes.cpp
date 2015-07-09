/* 14026412	558	Wormholes	Accepted	C++11	0.073	2014-08-12 09:39:01 */
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
#include<tuple>
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
#define MAX_N 1005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct edge{
	int v, w;
	edge(int a, int b){
		v = a, w = b;
	}
};
vector<edge> E[MAX_N];
int W[MAX_N];
int n, m;
bool Bellman(int source){
	for (int i = 0; i < n; i++)
		W[i] = INF;
	W[source] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < E[j].size(); k++)
				if (W[j] + E[j][k].w < W[E[j][k].v])
					W[E[j][k].v] = W[j] + E[j][k].w;
	for (int j = 0; j < n; j++)
			for (int k = 0; k < E[j].size(); k++)
			if (W[j] + E[j][k].w < W[E[j][k].v])
				return true;
	return false;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++)
			E[i].clear();
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			E[a].push_back(edge(b, w));
		}
		if (Bellman(0))
			puts("possible");
		else
			puts("not possible");
	}
	return 0;
}
/*

Wormholes
In the year 2163, wormholes were discovered. A wormhole is a subspace tunnel through space and time connecting two star systems. Wormholes have a few peculiar properties:

Wormholes are one-way only.
The time it takes to travel through a wormhole is negligible.
A wormhole has two end points, each situated in a star system.
A star system may have more than one wormhole end point within its boundaries.
For some unknown reason, starting from our solar system, it is always possible to end up in any star system by following a sequence of wormholes (maybe Earth is the centre of the universe).
Between any pair of star systems, there is at most one wormhole in either direction.
There are no wormholes with both end points in the same star system.
All wormholes have a constant time difference between their end points. For example, a specific wormhole may cause the person travelling through it to end up 15 years in the future. Another wormhole may cause the person to end up 42 years in the past.

A brilliant physicist, living on earth, wants to use wormholes to study the Big Bang. Since warp drive has not been invented yet, it is not possible for her to travel from one star system to another one directly. This can be done using wormholes, of course.

The scientist wants to reach a cycle of wormholes somewhere in the universe that causes her to end up in the past. By travelling along this cycle a lot of times, the scientist is able to go back as far in time as necessary to reach the beginning of the universe and see the Big Bang with her own eyes. Write a program to find out whether such a cycle exists.

Input

The input file starts with a line containing the number of cases c to be analysed. Each case starts with a line with two numbers n and m . These indicate the number of star systems (  $1 \le n \le 1000$) and the number of wormholes (  $0 \le m \le 2000$) . The star systems are numbered from 0 (our solar system) through n-1 . For each wormhole a line containing three integer numbers x, y and t is given. These numbers indicate that this wormhole allows someone to travel from the star system numbered x to the star system numbered y, thereby ending up t (  $-1000 \le t \le 1000$) years in the future.
Output

The output consists of c lines, one line for each case, containing the word possible if it is indeed possible to go back in time indefinitely, or not possible if this is not possible with the given set of star systems and wormholes.
Sample Input

2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
Sample Output

possible
not possible

Miguel A. Revilla
1998-03-10

*/