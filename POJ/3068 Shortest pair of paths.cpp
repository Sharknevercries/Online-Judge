/* 14481180	840502	3068	Accepted	196K	0MS	C++	2328B	2015-07-26 16:16:00 */
#include<bits\stdc++.h>
#define MAXN 1005
#define MAXM 100005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge { 
  int u, v, cap, cost, next; 
  Edge() {}
  Edge(int u, int v, int cap, int cost, int next) :u(u), v(v), cap(cap), cost(cost), next(next) {}
};
Edge E[MAXM];
int head[MAXN], e;
void addEdge(int u, int v, int cap, int cost) {
  E[e] = Edge(u, v, cap, cost, head[u]), head[u] = e++;
  E[e] = Edge(v, u, 0, -cost, head[v]), head[v] = e++;
}
int dist[MAXN];
int pre_vtx[MAXN];
int pre_edge[MAXN];
long long min_cost_max_flow(int s, int t, int &min_cost) {
  queue <int> Q;
  min_cost = 0;
  int max_flow = 0;
  while (true) {
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    bool inqueue[MAXN] = { false };
    inqueue[s] = true;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      for (int i = head[u]; i != -1; i = E[i].next) {
        Edge &e = E[i];
        if (e.cap && dist[u] + e.cost < dist[e.v]) {
          dist[e.v] = dist[u] + e.cost;
          pre_vtx[e.v] = u;
          pre_edge[e.v] = i;
          if (!inqueue[e.v]) {
            Q.push(e.v);
            inqueue[e.v] = true;
          }
        }
      }
      Q.pop();
      inqueue[u] = false;
    }
    if (dist[t] == INF)
      break;
    int tmp_flow = INF;
    for (int v = t; v != s; v = pre_vtx[v])
      tmp_flow = min(tmp_flow, E[pre_edge[v]].cap);
    for (int v = t; v != s; v = pre_vtx[v]) {
      Edge &e = E[pre_edge[v]];
      e.cap -= tmp_flow;
      E[pre_edge[v] ^ 1].cap += tmp_flow;
    }
    max_flow += tmp_flow;
    min_cost += tmp_flow*dist[t];
  }
  return max_flow;
}
int main() {
  int n, m, c = 1;
  while (scanf("%d%d", &n, &m) == 2) {
    if (n == 0 && m == 0)  break;
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addEdge(a, b, 1, w);
    }
    addEdge(n, 0, 2, 0);
    int cost;
    printf("Instance #%d: ", c++);
    if (min_cost_max_flow(n, n - 1, cost) == 2)
      printf("%d\n", cost);
    else
      puts("Not possible");
  }
  return 0;
}
/*

"Shortest" pair of paths
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 1080		Accepted: 432
Description

A chemical company has an unusual shortest path problem.

There are N depots (vertices) where chemicals can be stored. There are M individual shipping methods (edges) connecting pairs of depots. Each individual shipping method has a cost. In the usual problem, the company would need to find a way to route a single shipment from the first depot (0) to the last (N - 1). That's easy. The problem they have seems harder. They have to ship two chemicals from the first depot (0) to the last (N - 1). The chemicals are dangerous and cannot safely be placed together. The regulations say the company cannot use the same shipping method for both chemicals. Further, the company cannot place the two chemicals in same depot (for any length of time) without special storage handling --- available only at the first and last depots. To begin, they need to know if it's possible to ship both chemicals under these constraints. Next, they need to find the least cost of shipping both chemicals from first depot to the last depot. In brief, they need two completely separate paths (from the first depot to the last) where the overall cost of both is minimal.

Your program must simply determine the minimum cost or, if it's not possible, conclusively state that the shipment cannot be made.
Input

The input will consist of multiple cases. The first line of each input will contain N and M where N is the number of depots and M is the number of individual shipping methods. You may assume that N is less than 64 and that M is less than 10000. The next M lines will contain three values, i, j, and v. Each line corresponds a single, unique shipping method. The values i and j are the indices of two depots, and v is the cost of getting from i to j. Note that these shipping methods are directed. If something can be shipped from i to j with cost 10, that says nothing about shipping from j to i. Also, there may be more than one way to ship between any pair of depots, and that may be important here.
A line containing two zeroes signals the end of data and should not be processed.
Output

follow the output format of sample output.
Sample Input

2 1
0 1 20
2 3
0 1 20
0 1 20
1 0 10
4 6
0 1 22
1 3 11
0 2 14
2 3 26
0 3 43
0 3 58
0 0
Sample Output

Instance #1: Not possible
Instance #2: 40
Instance #3: 73
Source

Southeastern Europe 2006

*/