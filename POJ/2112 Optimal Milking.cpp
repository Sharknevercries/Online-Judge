/* 14459183	840502	2112	Accepted	916K	141MS	C++	2882B	2015 - 07 - 23 13:56 : 37 */
#include<bits\stdc++.h>
#define MAXN 305
#define MAXM 200005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge{
  int u, v, cap, length, next;
  Edge(){}
  Edge(int u, int v, int cap, int length, int next) :u(u), v(v), cap(cap), length(length), next(next){}
};
Edge E[MAXM], E2[MAXM];
int level[MAXN], head[MAXN], e;
void addEdge(int u, int v, int cap, int length){
  E[e++] = Edge(u, v, cap, length, head[u]), head[u] = e - 1;
  E[e++] = Edge(v, u, 0, length, head[v]), head[v] = e - 1;
}
int diss[MAXN], gapp[MAXN];
int DFS(int u, int s, int t, int n, int aug, int threshold){
  if (u == t) return aug;
  int remain = aug, mindis = n;
  for (int i = head[u]; i != -1; i = E[i].next){
    Edge &e = E[i];
    if (E[i].cap > 0 && E[i].length <= threshold){
      if (diss[e.v] + 1 == diss[u]){
        int d = min(remain, e.cap);
        d = DFS(e.v, s, t, n, d, threshold);
        e.cap -= d;
        E[i ^ 1].cap += d;
        remain -= d;
        if (diss[s] >= n) return aug - remain;
        if (remain == 0) break;
      }
      if (diss[e.v] < mindis)
        mindis = diss[e.v];
    }
  }
  if (remain == aug){
    if (!(--gapp[diss[u]])) diss[s] = n;
    diss[u] = mindis + 1;
    gapp[diss[u]]++;
  }
  return aug - remain;
}
int SAP(int s, int t, int threshold){
  int res = 0;
  int n = t + 1;
  memset(diss, 0, sizeof(diss));
  memset(gapp, 0, sizeof(gapp));
  gapp[0] = n;
  while (diss[s] < n)
    res += DFS(s, s, t, n, INF, threshold);
  return res;
}
int dist[MAXN][MAXN];
int main(){
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3){
    int maxValue = 0;
    e = 0;
    memset(head, -1, sizeof(head)); 
    for (int i = 1; i <= n + m; i++){
      for (int j = 1; j <= n + m; j++){
        scanf("%d", &dist[i][j]);
        if (i != j && dist[i][j] == 0)
          dist[i][j] = INF;
      }
    }
    for (int t = 1; t <= n + m; t++)
      for (int i = 1; i <= n + m; i++)
        for (int j = 1; j <= n + m; j++)
          dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
    for (int i = 1; i <= n + m; i++){
      for (int j = 1; j <= n + m; j++){
        if (i <= n && j > n)
          addEdge(i, j, k, dist[i][j]);
        maxValue = max(maxValue, dist[i][j]);
      }
      if (i <= n)
        addEdge(0, i, k, 0);
      else
        addEdge(i, n + m + 1, 1, 0);
    }
    for (int i = 0; i < e; i++)
      E2[i] = E[i];
    int L = 0, R = maxValue;
    while (L <= R){
      int mid = (L + R) / 2;
      for (int i = 0; i < e; i++)
        E[i] = E2[i];
      if (SAP(0, n + m + 1, mid) == m)
        R = mid - 1;
      else
        L = mid + 1;
    }
    printf("%d\n", L);
  }
  return 0;
}
/*

Optimal Milking
Time Limit: 2000MS		Memory Limit: 30000K
Total Submissions: 13867		Accepted: 5006
Case Time Limit: 1000MS
Description

FJ has moved his K (1 <= K <= 30) milking machines out into the cow pastures among the C (1 <= C <= 200) cows. A set of paths of various lengths runs among the cows and the milking machines. The milking machine locations are named by ID numbers 1..K; the cow locations are named by ID numbers K+1..K+C.

Each milking point can "process" at most M (1 <= M <= 15) cows each day.

Write a program to find an assignment for each cow to some milking machine so that the distance the furthest-walking cow travels is minimized (and, of course, the milking machines are not overutilized). At least one legal assignment is possible for all input data sets. Cows can traverse several paths on the way to their milking machine.
Input

* Line 1: A single line with three space-separated integers: K, C, and M.

* Lines 2.. ...: Each of these K+C lines of K+C space-separated integers describes the distances between pairs of various entities. The input forms a symmetric matrix. Line 2 tells the distances from milking machine 1 to each of the other entities; line 3 tells the distances from machine 2 to each of the other entities, and so on. Distances of entities directly connected by a path are positive integers no larger than 200. Entities not directly connected by a path have a distance of 0. The distance from an entity to itself (i.e., all numbers on the diagonal) is also given as 0. To keep the input lines of reasonable length, when K+C > 15, a row is broken into successive lines of 15 numbers and a potentially shorter line to finish up a row. Each new row begins on its own line.
Output

A single line with a single integer that is the minimum possible total distance for the furthest walking cow.
Sample Input

2 3 2
0 3 2 1 1
3 0 3 2 0
2 3 0 1 0
1 2 1 0 2
1 0 0 2 0
Sample Output

2
Source

USACO 2003 U S Open

*/