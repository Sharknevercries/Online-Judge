/* 14458997	840502	2455	Accepted	6412K	1000MS	C++	2359B	2015-07-23 13:25:15 */
#include<bits\stdc++.h>
#define MAXN 205
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
int main(){
  int n, m, t;
  while (scanf("%d%d%d", &n, &m, &t) == 3){
    int maxValue = 0;
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++){
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addEdge(a, b, 1, w);
      addEdge(b, a, 1, w);
      maxValue = max(w, maxValue);
    }
    for (int i = 0; i < e; i++)
      E2[i] = E[i];
    int L = 1, R = maxValue;
    while (L <= R){
      int mid = (L + R) / 2;
      for (int i = 0; i < e; i++)
        E[i] = E2[i];
      if (SAP(1, n, mid) >= t)
        R = mid - 1;
      else
        L = mid + 1;
    }
    printf("%d\n", L);
  }
  return 0;
}
/*

Secret Milking Machine
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 10568		Accepted: 3094
Description

Farmer John is constructing a new milking machine and wishes to keep it secret as long as possible. He has hidden in it deep within his farm and needs to be able to get to the machine without being detected. He must make a total of T (1 <= T <= 200) trips to the machine during its construction. He has a secret tunnel that he uses only for the return trips.

The farm comprises N (2 <= N <= 200) landmarks (numbered 1..N) connected by P (1 <= P <= 40,000) bidirectional trails (numbered 1..P) and with a positive length that does not exceed 1,000,000. Multiple trails might join a pair of landmarks.

To minimize his chances of detection, FJ knows he cannot use any trail on the farm more than once and that he should try to use the shortest trails.

Help FJ get from the barn (landmark 1) to the secret milking machine (landmark N) a total of T times. Find the minimum possible length of the longest single trail that he will have to use, subject to the constraint that he use no trail more than once. (Note well: The goal is to minimize the length of the longest trail, not the sum of the trail lengths.)

It is guaranteed that FJ can make all T trips without reusing a trail.
Input

* Line 1: Three space-separated integers: N, P, and T

* Lines 2..P+1: Line i+1 contains three space-separated integers, A_i, B_i, and L_i, indicating that a trail connects landmark A_i to landmark B_i with length L_i.
Output

* Line 1: A single integer that is the minimum possible length of the longest segment of Farmer John's route.
Sample Input

7 9 2
1 2 2
2 3 5
3 7 5
1 4 1
4 3 1
4 5 7
5 7 1
1 6 3
6 7 3
Sample Output

5
Hint

Farmer John can travel trails 1 - 2 - 3 - 7 and 1 - 6 - 7. None of the trails travelled exceeds 5 units in length. It is impossible for Farmer John to travel from 1 to 7 twice without using at least one trail of length 5.

Huge input data,scanf is recommended.
Source

USACO 2005 February Gold

*/