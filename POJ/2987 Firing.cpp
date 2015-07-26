/* 14478329	840502	2987	Accepted	2520K	500MS	C++	2571B	2015-07-26 02:00:03 */
#include<bits\stdc++.h>
#define MAXN 5005
#define MAXM 100005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
struct Edge {
  int u, v, next;
  long long cap;
  Edge() {}
  Edge(int u, int v, long long cap, int next) :u(u), v(v), cap(cap), next(next) {}
};
Edge E[MAXM];
int level[MAXN], head[MAXN], e;
void addEdge(int u, int v, long long cap) {
  E[e++] = Edge(u, v, cap, head[u]), head[u] = e - 1;
  E[e++] = Edge(v, u, 0, head[v]), head[v] = e - 1;
}
int diss[MAXN], gapp[MAXN];
long long DFS(int u, int s, int t, int n, long long aug) {
  if (u == t) return aug;
  long long remain = aug;
  int mindis = n;
  for (int i = head[u]; i != -1; i = E[i].next) {
    Edge &e = E[i];
    if (E[i].cap > 0) {
      if (diss[e.v] + 1 == diss[u]) {
        long long d = min(remain, e.cap);
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
long long SAP(int s, int t, int n) {
  long long res = 0;
  memset(diss, 0, sizeof(diss));
  memset(gapp, 0, sizeof(gapp));
  gapp[s] = n;
  while (diss[s] < n)
    res += DFS(s, s, t, n, INF);
  return res;
}
int BFS(int s) {
  queue<int> Q;
  bool V[MAXN] = { false };
  Q.push(s);
  V[s] = true;
  int count = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    count++;
    for (int i = head[u]; i != -1; i = E[i].next) {
      Edge &e = E[i];
      if (e.cap > 0 && !V[e.v]) {
        V[e.v] = true;
        Q.push(e.v);
      }
    }
  }
  return count - 1;
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    long long b[MAXN], sum = 0;
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
      scanf("%lld", b + i);
    for (int i = 1; i <= n; i++)
      if (b[i] > 0)
        addEdge(0, i, b[i]), sum += b[i];
      else
        addEdge(i, n + 1, -b[i]);
    for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      addEdge(a, b, INF);
    }
    long long ans = SAP(0, n + 1, n + 2);
    printf("%d %lld\n", BFS(0), sum - ans);
  }
  return 0;
}
/*

Firing
Time Limit: 5000MS		Memory Limit: 131072K
Total Submissions: 8935		Accepted: 2684
Description

You¡¦ve finally got mad at ¡§the world¡¦s most stupid¡¨ employees of yours and decided to do some firings. You¡¦re now simply too mad to give response to questions like ¡§Don¡¦t you think it is an even more stupid decision to have signed them?¡¨, yet calm enough to consider the potential profit and loss from firing a good portion of them. While getting rid of an employee will save your wage and bonus expenditure on him, termination of a contract before expiration costs you funds for compensation. If you fire an employee, you also fire all his underlings and the underlings of his underlings and those underlings¡¦ underlings¡¦ underlings¡K An employee may serve in several departments and his (direct or indirect) underlings in one department may be his boss in another department. Is your firing plan ready now?

Input

The input starts with two integers n (0 < n ? 5000) and m (0 ? m ? 60000) on the same line. Next follows n + m lines. The first n lines of these give the net profit/loss from firing the i-th employee individually bi (|bi| ? 107, 1 ? i ? n). The remaining m lines each contain two integers i and j (1 ? i, j ? n) meaning the i-th employee has the j-th employee as his direct underling.

Output

Output two integers separated by a single space: the minimum number of employees to fire to achieve the maximum profit, and the maximum profit.

Sample Input

5 5
8
-9
-20
12
-10
1 2
2 5
1 4
3 4
4 5
Sample Output

2 2
Hint

As of the situation described by the sample input, firing employees 4 and 5 will produce a net profit of 2, which is maximum.
Source

POJ Monthly--2006.08.27, frkstyc

*/