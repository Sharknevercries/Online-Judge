/* 14025922	10986	Sending email	Accepted	C++11	0.195	2014-08-12 08:04:27 */
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
#define MAX_N 20000
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
typedef pair<int, int> point;
struct edge{
	int v, w;
	edge(int a, int b){
		v = a, w = b;
	}
};
bool cmp(point a, point b){
	return a.second > b.second;
}
vector<edge> E[MAX_N];
int W[MAX_N];
bool V[MAX_N];
int n, m, s, t;
int Dijkstra(){
	memset(V, false, sizeof(V));
	for (int i = 0; i < n; i++)
		W[i] = INF;
	priority_queue<point, vector<point>, function<bool(point, point)> > Q(cmp);
	Q.push(make_pair(s, 0));
	W[s] = 0;
	while (!Q.empty()){
		point it = Q.top();	Q.pop();
		int cur = it.first, w = it.second;
		if (cur == t)	return W[t];
		if (V[cur])	continue;
		V[cur] = true;
		for (int i = 0; i < E[cur].size(); i++){
			edge &e = E[cur][i];
			if (!V[e.v] && W[cur] + e.w < W[e.v]){
				W[e.v] = W[cur] + e.w;
				Q.push(make_pair(e.v, W[e.v]));
			}
		}
	}
	return NONE;
}
int main(){
	int q, c = 1;
	scanf("%d", &q);
	while (q--){
		scanf("%d%d%d%d", &n, &m, &s, &t);
		for (int i = 0; i < n; i++)
			E[i].clear();
		for (int i = 0; i < m; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			E[a].push_back(edge(b, w));
			E[b].push_back(edge(a, w));
		}
		int res = Dijkstra();
		if (res == NONE)
			printf("Case #%d: unreachable\n", c++);
		else
			printf("Case #%d: %d\n", c++, res);
	}
	return 0;
}
/*

Problem E
Sending email
Time Limit: 3 seconds
"A new internet watchdog is creating a stir in
Springfield. Mr. X, if that is his real name, has
come up with a sensational scoop."
Kent Brockman

There are n SMTP servers connected by network cables. Each of the m cables connects two computers and has a certain latency measured in milliseconds required to send an email message. What is the shortest time required to send a message from server S to server T along a sequence of cables? Assume that there is no delay incurred at any of the servers.

Input
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a line containing n (2<=n<20000), m (0<=m<50000), S (0<=S<n) and T (0<=T<n). S!=T. The next m lines will each contain 3 integers: 2 different servers (in the range [0, n-1]) that are connected by a bidirectional cable and the latency, w, along this cable (0<=w<=10000).

Output
For each test case, output the line "Case #x:" followed by the number of milliseconds required to send a message from S to T. Print "unreachable" if there is no route from S to T.

Sample Input	Sample Output
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1
Case #1: 100
Case #2: 150
Case #3: unreachable
Problemsetter: Igor Naverniouk

*/