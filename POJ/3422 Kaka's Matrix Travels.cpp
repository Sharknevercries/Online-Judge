/* 14482011	840502	3422	Accepted	1064K	79MS	C++	2563B	2015-07-26 18:16:25 */
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
    bool inqueue[MAXN] = { false };
    dist[s] = 0;
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
int w[55][55];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        scanf("%d", &w[i][j]);
    addEdge(0, 1, k, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int v = (i - 1)*n + j;
        addEdge(v, v + n*n, 1, -w[i][j]);
        addEdge(v, v + n*n, INF, 0);
        if (j + 1 <= n) addEdge(v + n*n, (i - 1)*n + j + 1, k, 0);
        if (i + 1 <= n) addEdge(v + n*n, i*n + j, k, 0);
      }
    }
    addEdge(2*n*n, 2 * n*n + 1, INF, 0);
    int cost;
    min_cost_max_flow(0, 2 * n*n + 1, cost);
    printf("%d\n", -cost);
  }
  return 0;
}
/*

Kaka's Matrix Travels
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8629		Accepted: 3460
Description

On an N กั N chessboard with a non-negative number in each grid, Kaka starts his matrix travels with SUM = 0. For each travel, Kaka moves one rook from the left-upper grid to the right-bottom one, taking care that the rook moves only to the right or down. Kaka adds the number to SUM in each grid the rook visited, and replaces it with zero. It is not difficult to know the maximum SUM Kaka can obtain for his first travel. Now Kaka is wondering what is the maximum SUM he can obtain after his Kth travel. Note the SUM is accumulative during the K travels.

Input

The first line contains two integers N and K (1 ? N ? 50, 0 ? K ? 10) described above. The following N lines represents the matrix. You can assume the numbers in the matrix are no more than 1000.

Output

The maximum SUM Kaka can obtain after his Kth travel.

Sample Input

3 2
1 2 3
0 2 1
1 4 2
Sample Output

15
Source

POJ Monthly--2007.10.06, Huang, Jinsong

*/