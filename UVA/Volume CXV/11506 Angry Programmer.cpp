/* 14027395	11506	Angry Programmer	Accepted	C++11	0.038	2014-08-12 12:46:00 */
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
#define MAX_N 200
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
	int v, capacity, rev;
};
vector<edge> E[MAX_N];
void addEdge(int u, int v, int capacity){
	E[u].push_back(edge{ v, capacity, E[v].size() });
	E[v].push_back(edge{ u, 0, E[u].size() - 1 });
}
int level[MAX_N];
int iter[MAX_N];
int n, m;
void BFS(int source){
	memset(level, NONE, sizeof(level));
	queue<int> Q;
	level[source] = 0;
	Q.push(source);
	while (!Q.empty()){
		int u = Q.front();	Q.pop();
		for (int i = 0; i < E[u].size(); i++){
			edge &e = E[u][i];
			if (e.capacity > 0 && level[e.v] == NONE)
				level[e.v] = level[u] + 1, Q.push(e.v);
		}
	}
}
int DFS(int u, int t, int flow){
	if (u == t)	return flow;
	for (int &i = iter[u]; i < E[u].size(); i++){
		edge &e = E[u][i];
		if (e.capacity > 0 && level[u] < level[e.v]){
			int d = DFS(e.v, t, min(flow, e.capacity));
			if (d > 0){
				e.capacity -= d;
				E[e.v][e.rev].capacity += d;
				return d;
			}
		}
	}
	return 0;
}
int maxFlow(int s, int t){
	int flow = 0;
	while (true){
		BFS(s);
		if (level[t] == NONE)
			return flow;
		memset(iter, 0, sizeof(iter));
		while (true){
			int tmp = DFS(s, t, INF);
			if (tmp <= 0)	break;
			flow += tmp;
		}
	}
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= 2 * n; i++)
			E[i].clear();
		for (int i = 2; i < n; i++){
			int s, w;
			scanf("%d%d", &s, &w);
			addEdge(s, s + n - 1, w);
			addEdge(s + n - 1, s, w);
		}
		for (int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if ((u == 1 && v == n) || (u == n && v == 1))
				addEdge(u, v, w), addEdge(v, u, w);
			else if (u == 1)
				addEdge(u, v, w), addEdge(v + n - 1, u, w);
			else if (v == n)
				addEdge(u + n - 1, v, w), addEdge(v, u, w);
			else
				addEdge(v + n - 1, u, w), addEdge(u + n - 1, v, w);
		}
		printf("%d\n", maxFlow(1, n));
	}
	return 0;
}
/*

Angry Programmer
You, a programmer of an important software house, have been fired because you didn't solve an important problem that was assigned to you. You are very furious and want to take revenge on your boss, breaking the communication between his computer and the central server.

The computer of your boss and the central server are in the same network, which is composed of many machines (computers) and wires linking pairs of those machines. There is at most one wire between any pair of machines and there can be pairs of machines without a wire between them.

To accomplish your objective, you can destroy machines and wires, but you can't destroy neither the computer of your boss nor the central server, because those machines are monitored by security cameras. You have estimated the cost of blowing up each machine and the cost of cutting each wire in the network.

You want to determine the minimum cost of interrupting the communication between your boss' computer and the central server. Two computers A and B can communicate if there is a sequence of undestroyed machines x1,..., xn such that x1 = A , xn = B and xi is linked with xi+1 with an uncut wire (for each 1 $ \leq$ i $ \leq$ n - 1 ).

Input

The input consists of several test cases. Each test case is represented as follows:

A line with two integers M and W ( 2 $ \leq$ M $ \leq$ 50 , 0 $ \leq$ W $ \leq$ 1000 ), representing (respectively) the number of machines and the number of wires in the network.
M - 2 lines, one per machine (different from the boss' machine and the central server), containing the following information separated by spaces:
An integer i ( 2 $ \leq$ i $ \leq$ M - 1 ) with the identifier of the machine. Assume that the boss' machine has id 1 and that the central server has id M .
An integer c ( 0 $ \leq$ c $ \leq$ 100000 ) specifying the cost of destroying the machine.
W lines, one per wire, containing the following information separated by spaces:
Two integers j and k ( 1 $ \leq$ j < k $ \leq$ M ) specifying the identifiers of the machines linked by the wire. Remember that the wire is bidirectional.
An integer d ( 0 $ \leq$ d $ \leq$ 100000 ) specifying the cost of cutting the wire.

The end of the input is specified by a line with the string ``0 0''.

Suppose that the machines have distinct identifiers.

Output

For each test case, print a line with the minimum cost of interrupting the communication between the computer of your boss and the central server.

Sample Input

4 4
3 5
2 2
1 2 3
1 3 3
2 4 1
3 4 3
4 4
3 2
2 2
1 2 3
1 3 3
2 4 1
3 4 3
0 0
Sample Output

4
3

Colombia'2008

*/