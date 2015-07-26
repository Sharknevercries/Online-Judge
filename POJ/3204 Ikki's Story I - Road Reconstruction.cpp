/* 14480232	840502	3204	Accepted	408K	63MS	C++	2400B	2015-07-26 14:27:03 */
#include<bits\stdc++.h>
#define MAXN 505
#define MAXM 100005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge {
  int u, v, next, cap;
  Edge() {}
  Edge(int u, int v, int cap, int next) :u(u), v(v), cap(cap), next(next) {}
};
Edge E[MAXM];
int head[MAXN], e;
void addEdge(int u, int v, int cap) {
  E[e++] = Edge(u, v, cap, head[u]), head[u] = e - 1;
  E[e++] = Edge(v, u, 0, head[v]), head[v] = e - 1;
}
int diss[MAXN], gapp[MAXN];
int DFS(int u, int s, int t, int n, int aug) {
  if (u == t) return aug;
  int remain = aug;
  int mindis = n;
  for (int i = head[u]; i != -1; i = E[i].next) {
    Edge &e = E[i];
    if (E[i].cap > 0) {
      if (diss[e.v] + 1 == diss[u]) {
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
  if (remain == aug) {
    if (!(--gapp[diss[u]])) diss[s] = n;
    diss[u] = mindis + 1;
    gapp[diss[u]]++;
  }
  return aug - remain;
}
int SAP(int s, int t, int n) {
  int res = 0;
  memset(diss, 0, sizeof(diss));
  memset(gapp, 0, sizeof(gapp));
  gapp[s] = n;
  while (diss[s] < n)
    res += DFS(s, s, t, n, INF);
  return res;
}
bool V[MAXN][2];
void DFS2(int u, int type) {
  V[u][type] = true;
  for (int i = head[u]; i != -1; i = E[i].next) {
    Edge &e = E[i];
    if (V[e.v][type])  continue;
    if (i % 2 == (type ^ 1)) continue;
    if (E[i^type].cap == 0)  continue;
    DFS2(e.v, type);
  }
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    e = 0;
    memset(head, -1, sizeof(head));
    memset(V, false, sizeof(V));
    for (int i = 1; i <= m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addEdge(a, b, w);
    }
    SAP(0, n - 1, n);
    DFS2(0, 0);
    DFS2(n - 1, 1);
    int ans = 0;
    for (int i = 0; i < e; i += 2) {
      Edge &e = E[i];
      if (e.cap == 0 && V[e.u][0] && V[e.v][1])
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
/*

Ikki's Story I - Road Reconstruction
Time Limit: 2000MS		Memory Limit: 131072K
Total Submissions: 7224		Accepted: 2088
Description

Ikki is the king of a small country ¡V Phoenix, Phoenix is so small that there is only one city that is responsible for the production of daily goods, and uses the road network to transport the goods to the capital. Ikki finds that the biggest problem in the country is that transportation speed is too slow.

Since Ikki was an ACM/ICPC contestant before, he realized that this, indeed, is a maximum flow problem. He coded a maximum flow program and found the answer. Not satisfied with the current status of the transportation speed, he wants to increase the transportation ability of the nation. The method is relatively simple, Ikki will reconstruct some roads in this transportation network, to make those roads afford higher capacity in transportation. But unfortunately, the country of Phoenix is not so rich in GDP that there is only enough money to rebuild one road. Ikki wants to find such roads that if reconstructed, the total capacity of transportation will increase.

He thought this problem for a loooong time but cannot get it. So he gave this problem to frkstyc, who put it in this POJ Monthly contest for you to solve. Can you solve it for Ikki?

Input

The input contains exactly one test case.

The first line of the test case contains two integers N, M (N ? 500, M ? 5,000) which represents the number of cities and roads in the country, Phoenix, respectively.

M lines follow, each line contains three integers a, b, c, which means that there is a road from city a to city b with a transportation capacity of c (0 ? a, b < n, c ? 100). All the roads are directed.

Cities are numbered from 0 to n ? 1, the city which can product goods is numbered 0, and the capital is numbered n ? 1.

Output

You should output one line consisting of only one integer K, denoting that there are K roads, reconstructing each of which will increase the network transportation capacity.
Sample Input

2 1
0 1 1
Sample Output

1
Source

POJ Monthly--2007.03.04, Ikki

*/