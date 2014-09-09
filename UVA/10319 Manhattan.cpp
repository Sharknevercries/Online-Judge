/* 14074749	10319	Manhattan	Accepted	C++	0.012	2014-08-21 12:40:46 */
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
vector<int> E[MAX_N];
int V[MAX_N], low[MAX_N], mark;
int stack[MAX_N], top;
bool instack[MAX_N];
int G[MAX_N];
void addEdge(int u, int v){
	E[u ^ 1].push_back(v), E[v ^ 1].push_back(u);
}
void DFS(int x){
	V[x] = low[x] = mark++;
	stack[top++] = x, instack[x] = true;
	for (int i = 0; i < E[x].size(); i++){
		int target = E[x][i];
		if (V[target] == NONE)
			DFS(target);
		if (instack[target])
			low[x] = min(low[x], low[target]);
	}
	if (V[x] == low[x]){
		int j;
		do{
			j = stack[--top];
			instack[j] = false;
			G[j] = G[x];
		} while (j != x);
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < MAX_N; i++)
			G[i] = i, E[i].clear();
		memset(V, NONE, sizeof(V));
		memset(low, NONE, sizeof(low));
		memset(instack, false, sizeof(instack));
		top = mark = 0;
		for (int i = 0; i < k; i++){
			int x1, y1, x2, y2, a, b, c, d;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1--, y1--, x2--, y2--;
			// (a and d) or (b and c)
			a = 2 * x1 + int(y2 < y1);
			b = 2 * y1 + int(x2 < x1) + 2 * n;
			c = 2 * x2 + int(y2 < y1);
			d = 2 * y2 + int(x2 < x1) + 2 * n;
			if (x1 == x2 && y1 == y2)
				continue;
			else if (x1 == x2)
				addEdge(a, a);
			else if (y1 == y2)
				addEdge(b, b);
			else{
				addEdge(a, c);
				addEdge(a, b);
				addEdge(c, d);
				addEdge(b, d);
			}
		}
		for (int i = 0; i < (n + m) * 2; i++)
			if (V[i] == NONE)
				DFS(i);
		bool res = true;
		for (int i = 0; i < n + m; i++)
			if (G[2 * i] == G[2 * i + 1])
				res = false;
		printf("%s\n", res ? "Yes" : "No");
	}
	return 0;
}
/*

Problem H
Manhattan
Input: standard input
Output:  standard output
Time Limit: 1 second
Memory Limit: 32 MB


You are the mayor of a city with severe traffic problems. To deal with the situation, you have decided to make a new plan for the street grid. As it is impossible to make the streets wider, your approach is to make them one-way (only traffic in one direction is allowed on a street), thus creating a more efficient flow of traffic.

The streets in the city form an orthogonal grid - like on Manhattan avenues run in north-south-direction, while streets run in east-west-direction. Your mission is to make all the streets and avenues one-way, i.e. fix the direction in which traffic is allowed, while maintaining a short driving distance between some ordered pairs of locations. More specifically, a route in the city is defined by two street-avenue crossings, the start and goal location. On a one-way street grid, a route has a legal path if it is possible to drive from the start location to the goal location along the path passing streets and avenues in their prescribed direction only. A route does not define a specific path between the two locations - there may be many possible paths for each route. A legal path in a one-way street grid is considered simple if it requires at most one turn, i.e. a maximum of one street and one avenue need to be used for the path.

When traveling by car from one location to another, a simple path will be preferred over a non-simple one, since it is faster. However, as each street in the grid is one-way, there may always be routes for which no simple path exists. On your desk lies a list of important routes which you want to have simple paths after the re-design of the street grid.

Your task is to write a program that determines if it is possible to fix the directions of the one-way streets and avenues in such a way that each route in the list has at least one simple path.


Input
On the first line of the input, there is a single integer n, telling how many city descriptions that follows. Each city description begins with a line containing three integers: the number of streets 0<S<=30 and avenues 0<A<=30 in the street grid, and the number of routes 0<m<=200 that should have at least one simple path. The next m lines define these routes, one on each line. Each route definition consists of four integers, s1, a1, s2, a2, where the start location of the route is at the crossing of street s1 and avenue a1, and the goal location is at the crossing of street s2 and avenue a2. Obviously, 0<s1, s2<=S and 0<a1, a2<=A.

Output
For each city, your program should output 'Yes' on a single line if it is possible to make the streets and avenues one-way, so that each route has at least one simple path. Otherwise the text 'No' should be printed on a line of its own.

Sample Input
3
6 6 2
1 1 6 6
6 6 1 1
7 7 4
1 1 1 6
6 1 6 6
6 6 1 1
4 3 5 1
9 8 6
2 2 4 4
4 5 3 2
3 4 2 2
3 2 4 4
4 5 2 2
2 1 3 4

Sample Output
Yes
No
No
(The Decider Contest, Problem Source: Swedish National Programming Contest, arranged by department of Computer Science at Lund Institute of Technology.)

*/