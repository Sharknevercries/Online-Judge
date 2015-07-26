/* 14466549	840502	1637	Accepted	356K	16MS	C++	2348B	2015-07-24 14:46:25 */
#include<bits\stdc++.h>
#define MAXN 20005
#define MAXM 20005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge{
  int u, v, cap, next;
  Edge(){}
  Edge(int u, int v, int cap, int next) :u(u), v(v), cap(cap), next(next){}
};
Edge E[MAXM];
int level[MAXN], head[MAXN], e;
void addEdge(int u, int v, int cap){
  E[e++] = Edge(u, v, cap, head[u]), head[u] = e - 1;
  E[e++] = Edge(v, u, 0, head[v]), head[v] = e - 1;
}
int diss[MAXN], gapp[MAXN];
int DFS(int u, int s, int t, int n, int aug){
  if (u == t) return aug;
  int remain = aug, mindis = n;
  for (int i = head[u]; i != -1; i = E[i].next){
    Edge &e = E[i];
    if (E[i].cap > 0){
      if (diss[e.v] + 1 == diss[u]){
        int d = min(remain, e.cap);
        d = DFS(e.v, s, t, n, d);
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
int SAP(int s, int t){
  int res = 0;
  int n = t + 1;
  memset(diss, 0, sizeof(diss));
  memset(gapp, 0, sizeof(gapp));
  gapp[0] = n;
  while (diss[s] < n)
    res += DFS(s, s, t, n, INF);
  return res;
}
int in[MAXN], out[MAXN];
int main(){
  int n, m, t;
  scanf("%d", &t);
  while (t--){
    bool flag = true;
    int sum = 0;
    e = 0;
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      in[b]++, out[a]++;
      if (w == 0)
        addEdge(a, b, 1);
    }
    for (int i = 1; i <= n; i++){
      int delta = out[i] - in[i];
      flag &= abs(delta) % 2 == 0;
      if (delta > 0)
        sum += delta / 2, addEdge(0, i, delta / 2);
      if (delta < 0)
        addEdge(i, n + 1, -delta / 2);
    }
    if (!flag || sum != SAP(0, n + 1))
      puts("impossible");
    else
      puts("possible");
  }
  return 0;
}
/*

Sightseeing tour
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 8229		Accepted: 3465
Description

The city executive board in Lund wants to construct a sightseeing tour by bus in Lund, so that tourists can see every corner of the beautiful city. They want to construct the tour so that every street in the city is visited exactly once. The bus should also start and end at the same junction. As in any city, the streets are either one-way or two-way, traffic rules that must be obeyed by the tour bus. Help the executive board and determine if it's possible to construct a sightseeing tour under these constraints.
Input

On the first line of the input is a single positive integer n, telling the number of test scenarios to follow. Each scenario begins with a line containing two positive integers m and s, 1 <= m <= 200,1 <= s <= 1000 being the number of junctions and streets, respectively. The following s lines contain the streets. Each street is described with three integers, xi, yi, and di, 1 <= xi,yi <= m, 0 <= di <= 1, where xi and yi are the junctions connected by a street. If di=1, then the street is a one-way street (going from xi to yi), otherwise it's a two-way street. You may assume that there exists a junction from where all other junctions can be reached.
Output

For each scenario, output one line containing the text "possible" or "impossible", whether or not it's possible to construct a sightseeing tour.
Sample Input

4
5 8
2 1 0
1 3 0
4 1 1
1 5 0
5 4 1
3 4 0
4 2 1
2 2 0
4 4
1 2 1
2 3 0
3 4 0
1 4 1
3 3
1 2 0
2 3 0
3 2 0
3 4
1 2 0
2 3 1
1 2 0
3 2 0
Sample Output

possible
impossible
impossible
possible
Source

Northwestern Europe 2003

*/