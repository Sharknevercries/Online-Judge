/* 14480642	840502	3308	Accepted	236K	16MS	C++	2174B	2015-07-26 15:19:59 */
#include<bits\stdc++.h>
#define MAXN 505
#define MAXM 50005
#define INF 0x3f3f
#define EPS 1e-7
using namespace std;
struct Edge { 
  int u, v, next; 
  double cap;
  Edge() {}
  Edge(int u, int v, double cap, int next) :u(u), v(v), cap(cap), next(next) {}
};
Edge E[MAXM];
int level[MAXN], head[MAXN], e;
void addEdge(int u, int v, double cap) {
  E[e] = Edge(u, v, cap, head[u]), head[u] = e++;
  E[e] = Edge(v, u, 0, head[v]), head[v] = e++;
}
void BFS(int s) {
  memset(level, -1, sizeof(level));
  queue <int> Q;
  level[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = head[u]; i != -1; i = E[i].next) {
      Edge &e = E[i];
      if (e.cap > 0 && level[e.v] < 0) {
        level[e.v] = level[u] + 1;
        Q.push(e.v);
      }
    }
  }
}
double DFS(int u, int t, double flow) {
  if (u == t)	return flow;
  for (int i = head[u]; i != -1; i = E[i].next) {
    Edge &e = E[i];
    if (e.cap > 0 && level[u] < level[e.v]) {
      double d = DFS(e.v, t, min(flow, e.cap));
      if (d > 0) {
        e.cap -= d;
        E[i ^ 1].cap += d;
        return d;
      }
    }
  }
  return 0;
}
double Dinic(int s, int t) {
  double flow = 0;
  while (true) {
    BFS(s);
    if (level[t] < 0)	return flow;
    while (true) {
      double tmp = DFS(s, t, 1e9);
      if (tmp <= 0)	break;
      flow += tmp;
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    e = 0;
    memset(head, -1, sizeof(head));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      double w;
      scanf("%lf", &w);
      addEdge(0, i, log(w));
    }
    for (int i = 1; i <= m; i++) {
      double w;
      scanf("%lf", &w);
      addEdge(n + i, n + m + 1, log(w));
    }
    for (int i = 1; i <= k; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      addEdge(a, n + b, INF);
    }
    printf("%.4lf\n", exp(Dinic(0, n + m + 1)));
  }
  return 0;
}
/*

Paratroopers
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 7817		Accepted: 2358
Description

It is year 2500 A.D. and there is a terrible war between the forces of the Earth and the Mars. Recently, the commanders of the Earth are informed by their spies that the invaders of Mars want to land some paratroopers in the m กั n grid yard of one their main weapon factories in order to destroy it. In addition, the spies informed them the row and column of the places in the yard in which each paratrooper will land. Since the paratroopers are very strong and well-organized, even one of them, if survived, can complete the mission and destroy the whole factory. As a result, the defense force of the Earth must kill all of them simultaneously after their landing.

In order to accomplish this task, the defense force wants to utilize some of their most hi-tech laser guns. They can install a gun on a row (resp. column) and by firing this gun all paratroopers landed in this row (resp. column) will die. The cost of installing a gun in the ith row (resp. column) of the grid yard is ri (resp. ci ) and the total cost of constructing a system firing all guns simultaneously is equal to the product of their costs. Now, your team as a high rank defense group must select the guns that can kill all paratroopers and yield minimum total cost of constructing the firing system.

Input

Input begins with a number T showing the number of test cases and then, T test cases follow. Each test case begins with a line containing three integers 1 ? m ? 50 , 1 ? n ? 50 and 1 ? l ? 500 showing the number of rows and columns of the yard and the number of paratroopers respectively. After that, a line with m positive real numbers greater or equal to 1.0 comes where the ith number is ri and then, a line with n positive real numbers greater or equal to 1.0 comes where the ith number is ci. Finally, l lines come each containing the row and column of a paratrooper.

Output

For each test case, your program must output the minimum total cost of constructing the firing system rounded to four digits after the fraction point.

Sample Input

1
4 4 5
2.0 7.0 5.0 2.0
1.5 2.0 2.0 8.0
1 1
2 2
3 3
4 4
1 4
Sample Output

16.0000
Source

Amirkabir University of Technology Local Contest 2006

*/