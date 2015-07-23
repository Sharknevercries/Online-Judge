/* 14107655	2015-07-22 14:05:15	Accepted	1532	15MS	1628K	1790 B	C++	Shark */
#include<bits\stdc++.h>
#define MAXN 205
#define MAXM 505
using namespace std;
struct Edge{ int u, v, cap, next; };
Edge E[MAXM];
int level[MAXN], head[MAXN], e;
void addEdge(int u, int v, int cap){
  E[e++] = Edge{ u, v, cap, head[u] }, head[u] = e - 1;
  E[e++] = Edge{ v, u, 0, head[v] }, head[v] = e - 1;
}
void BFS(int s){
  memset(level, -1, sizeof(level));
  queue <int> Q;
  level[s] = 0;
  Q.push(s);
  while (!Q.empty()){
    int u = Q.front(); Q.pop();
    for (int i = head[u]; i != -1; i = E[i].next){
      Edge &e = E[i];
      if (e.cap > 0 && level[e.v] < 0){
        level[e.v] = level[u] + 1;
        Q.push(e.v);
      }
    }
  }
}
int DFS(int u, int t, int flow){
  if (u == t)	return flow;
  for (int i = head[u]; i != -1; i = E[i].next){
    Edge &e = E[i];
    if (e.cap > 0 && level[u] < level[e.v]){
      int d = DFS(e.v, t, min(flow, e.cap));
      if (d > 0){
        e.cap -= d;
        E[i ^ 1].cap += d;
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
    if (level[t] < 0)	return flow;
    while (true){
      int tmp = DFS(s, t, 1e9);
      if (tmp <= 0)	break;
      flow += tmp;
    }
  }
}
int n, m;
int main(){
  while (scanf("%d%d", &m, &n) == 2){
    memset(head, -1, sizeof(head));
    e = 0;
    for (int i = 1; i <= m; i++){
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addEdge(a, b, w);
    }
    printf("%d\n", maxFlow(1, n));
  }
}
/*

Drainage Ditches

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 11580    Accepted Submission(s): 5454

Problem Description
Every time it rains on Farmer John's fields, a pond forms over Bessie's favorite clover patch. This means that the clover is covered by water for awhile and takes quite a long time to regrow. Thus, Farmer John has built a set of drainage ditches so that Bessie's clover patch is never covered in water. Instead, the water is drained to a nearby stream. Being an ace engineer, Farmer John has also installed regulators at the beginning of each ditch, so he can control at what rate water flows into that ditch.
Farmer John knows not only how many gallons of water each ditch can transport per minute but also the exact layout of the ditches, which feed out of the pond and into each other and stream in a potentially complex network.
Given all this information, determine the maximum rate at which water can be transported out of the pond and into the stream. For any given ditch, water flows in only one direction, but there might be a way that water can flow in a circle.

Input
The input includes several cases. For each case, the first line contains two space-separated integers, N (0 <= N <= 200) and M (2 <= M <= 200). N is the number of ditches that Farmer John has dug. M is the number of intersections points for those ditches. Intersection 1 is the pond. Intersection point M is the stream. Each of the following N lines contains three integers, Si, Ei, and Ci. Si and Ei (1 <= Si, Ei <= M) designate the intersections between which this ditch flows. Water will flow through this ditch from Si to Ei. Ci (0 <= Ci <= 10,000,000) is the maximum rate at which water will flow through the ditch.

Output
For each case, output a single integer, the maximum rate at which water may emptied from the pond.

Sample Input
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10

Sample Output
50

Source
USACO 93

Recommend
lwg   |   We have carefully selected several similar problems for you:  1533 3338 1569 3572 3416 

*/