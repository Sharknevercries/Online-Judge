/* 14478331	840502	1815	Accepted	1884K	204MS	C++	2903B	2015-07-26 02:09:14 */
#include<bits\stdc++.h>
#define MAXN 505
#define MAXM 50005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge {
  int u, v, cap, next;
  Edge() {}
  Edge(int u, int v, int cap, int next) :u(u), v(v), cap(cap), next(next) {}
};
Edge E[MAXM], E2[MAXM];
int head[MAXN], e;
void addEdge(int u, int v, int cap) {
  E[e++] = Edge(u, v, cap, head[u]), head[u] = e - 1;
  E[e++] = Edge(v, u, 0, head[v]), head[v] = e - 1;
}
int diss[MAXN], gapp[MAXN];
int DFS(int u, int s, int t, int n, int aug) {
  if (u == t) return aug;
  int remain = aug, mindis = n;
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
int con[205][205];
int main(){
  int n, s, t;
  while (scanf("%d%d%d", &n, &s, &t) == 3){
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        scanf("%d", &con[i][j]);
    if (con[s][t]){
      puts("NO ANSWER!");
      continue;
    }
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++){
      if (i != s && i != t)
        addEdge(i, i + n, 1);
      for (int j = 1; j <= n; j++){
        if (con[i][j] && i != j){
          if (i == s)
            addEdge(i, j, INF);
          else if (i != t)
            addEdge(i + n, j, INF);
        }
      }
    }
    memcpy(E2, E, sizeof(E));
    int ans = SAP(s, t, 2 * n - 2);
    printf("%d\n", ans);
    bool flag = true;
    for (int i = 1; i <= n; i++){
      if (i != s && i != t){
        for (int j = head[i]; j != -1; j = E[j].next){
          Edge &e = E[j];
          if (e.cap == 0 && e.v == i + n){
            E2[j].cap = E2[j ^ 1].cap = 0;
            memcpy(E, E2, sizeof(E));
            if (SAP(s, t, 2 * n - 2) != ans - 1) {
              E2[j].cap = 1, E2[j ^ 1].cap = 0;
              continue;
            }
            if (!flag)
              putchar(' ');
            flag = false;
            printf("%d", i);
            ans--;
            break;
          }
        }
      }
    }
    putchar('\n');
  }
  return 0;
}
/*

Friendship
Time Limit: 2000MS		Memory Limit: 20000K
Total Submissions: 9756		Accepted: 2708
Description

In modern society, each person has his own friends. Since all the people are very busy, they communicate with each other only by phone. You can assume that people A can keep in touch with people B, only if
1.	A knows B's phone number, or
2.	A knows people C's phone number and C can keep in touch with B.
It's assured that if people A knows people B's number, B will also know A's number.

Sometimes, someone may meet something bad which makes him lose touch with all the others. For example, he may lose his phone number book and change his phone number at the same time.

In this problem, you will know the relations between every two among N people. To make it easy, we number these N people by 1,2,...,N. Given two special people with the number S and T, when some people meet bad things, S may lose touch with T. Your job is to compute the minimal number of people that can make this situation happen. It is supposed that bad thing will never happen on S or T.
Input

The first line of the input contains three integers N (2<=N<=200), S and T ( 1 <= S, T <= N , and S is not equal to T).Each of the following N lines contains N integers. If i knows j's number, then the j-th number in the (i+1)-th line will be 1, otherwise the number will be 0.

You can assume that the number of 1s will not exceed 5000 in the input.
Output

If there is no way to make A lose touch with B, print "NO ANSWER!" in a single line. Otherwise, the first line contains a single number t, which is the minimal number you have got, and if t is not zero, the second line is needed, which contains t integers in ascending order that indicate the number of people who meet bad things. The integers are separated by a single space.

If there is more than one solution, we give every solution a score, and output the solution with the minimal score. We can compute the score of a solution in the following way: assume a solution is A1, A2, ..., At (1 <= A1 < A2 <...< At <=N ), the score will be (A1-1)*N^t+(A2-1)*N^(t-1)+...+(At-1)*N. The input will assure that there won't be two solutions with the minimal score.
Sample Input

3 1 3
1 1 0
1 1 1
0 1 1
Sample Output

1
2
Source

POJ Monthly

*/