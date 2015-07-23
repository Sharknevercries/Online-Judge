/* 14453815	840502	2135	Accepted	956K	16MS	C++	2244B	2015-07-22 18:47:33 */
#include<bits\stdc++.h>
#define MAXN 2005
#define MAXM 40005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge{ 
  int u, v, cap, cost, next; 
  Edge(){}
  Edge(int u, int v, int cap, int cost, int next) :u(u), v(v), cap(cap), cost(cost), next(next){}
};
Edge E[MAXM];
int head[MAXN], e;
void addEdge(int u, int v, int cap, int cost){
  E[e++] = Edge(u, v, cap, cost, head[u]), head[u] = e - 1;
  E[e++] = Edge(v, u, 0, -cost, head[v]), head[v] = e - 1;
}
int dist[MAXN];
int pre_vtx[MAXN];
int pre_edge[MAXN];
queue <int> Q;
long long min_cost_max_flow(int s, int t, int &min_cost){
  min_cost = 0;
  long long max_flow = 0;
  while (true){
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    bool inqueue[MAXN] = { false };
    inqueue[s] = true;
    Q.push(s);
    while (!Q.empty()){
      int u = Q.front();
      for (int i = head[u]; i != -1; i = E[i].next){
        Edge &e = E[i];
        if (e.cap && dist[u] + e.cost<dist[e.v]){
          dist[e.v] = dist[u] + e.cost;
          pre_vtx[e.v] = u;
          pre_edge[e.v] = i;
          if (!inqueue[e.v]){
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
    for (int v = t; v != s; v = pre_vtx[v]){
      Edge &e = E[pre_edge[v]];
      e.cap -= tmp_flow;
      E[pre_edge[v] ^ 1].cap += tmp_flow;
    }
    max_flow += tmp_flow;
    min_cost += tmp_flow*dist[t];
  }
  return max_flow;
}
int main(){
  int n, m;
  while (scanf("%d%d", &n, &m) == 2){
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++){
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addEdge(a, b, 1, w);
      addEdge(b, a, 1, w);
    }
    addEdge(0, 1, 2, 0);
    addEdge(n, n + 1, 2, 0);
    int cost;
    min_cost_max_flow(0, n + 1, cost);
    printf("%d\n", cost);
  }
}
/*

Farm Tour
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 13209		Accepted: 4989
Description

When FJ's friends visit him on the farm, he likes to show them around. His farm comprises N (1 <= N <= 1000) fields numbered 1..N, the first of which contains his house and the Nth of which contains the big barn. A total M (1 <= M <= 10000) paths that connect the fields in various ways. Each path connects two different fields and has a nonzero length smaller than 35,000.

To show off his farm in the best way, he walks a tour that starts at his house, potentially travels through some fields, and ends at the barn. Later, he returns (potentially through some fields) back to his house again.

He wants his tour to be as short as possible, however he doesn't want to walk on any given path more than once. Calculate the shortest tour possible. FJ is sure that some tour exists for any given farm.
Input

* Line 1: Two space-separated integers: N and M.

* Lines 2..M+1: Three space-separated integers that define a path: The starting field, the end field, and the path's length.
Output

A single line containing the length of the shortest tour.
Sample Input

4 5
1 2 1
2 3 1
3 4 1
1 3 2
2 4 2
Sample Output

6
Source

USACO 2003 February Green

*/