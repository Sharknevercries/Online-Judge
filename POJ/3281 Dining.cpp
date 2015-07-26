/* 14465995	840502	3281	Accepted	300K	16MS	C++	2228B	2015-07-24 13:58:38 */
#include<bits\stdc++.h>
#define MAXN 10005
#define MAXM 100005
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
int main(){
  int N, F, D;
  while (scanf("%d%d%d", &N, &F, &D) == 3){
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= N; i++){
      int f, d, w;
      scanf("%d%d", &f, &d);
      for (int j = 1; j <= f; j++){
        scanf("%d", &w);
        addEdge(w, F + i, 1);
      }
      addEdge(F + i, F + N + i, 1);
      for (int j = 1; j <= d; j++){
        scanf("%d", &w);
        addEdge(F + N + i, F + N + N + w, 1);
      }
    }
    for (int i = 1; i <= F; i++)
      addEdge(0, i, 1);
    for (int i = 1; i <= D; i++)
      addEdge(F + N + N + i, F + N + N + D + 1, 1);
    printf("%d\n", SAP(0, F + N + N + D + 1));
  }
  return 0;
}
/*

Dining
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 10900		Accepted: 5004
Description

Cows are such finicky eaters. Each cow has a preference for certain foods and drinks, and she will consume no others.

Farmer John has cooked fabulous meals for his cows, but he forgot to check his menu against their preferences. Although he might not be able to stuff everybody, he wants to give a complete meal of both food and drink to as many cows as possible.

Farmer John has cooked F (1 ≤ F ≤ 100) types of foods and prepared D (1 ≤ D ≤ 100) types of drinks. Each of his N (1 ≤ N ≤ 100) cows has decided whether she is willing to eat a particular food or drink a particular drink. Farmer John must assign a food type and a drink type to each cow to maximize the number of cows who get both.

Each dish or drink can only be consumed by one cow (i.e., once food type 2 is assigned to a cow, no other cow can be assigned food type 2).

Input

Line 1: Three space-separated integers: N, F, and D
Lines 2..N+1: Each line i starts with a two integers Fi and Di, the number of dishes that cow i likes and the number of drinks that cow i likes. The next Fi integers denote the dishes that cow i will eat, and the Di integers following that denote the drinks that cow i will drink.
Output

Line 1: A single integer that is the maximum number of cows that can be fed both food and drink that conform to their wishes
Sample Input

4 3 3
2 2 1 2 3 1
2 2 2 3 1 2
2 2 1 3 1 2
2 1 1 3 3
Sample Output

3
Hint

One way to satisfy three cows is:
Cow 1: no meal
Cow 2: Food #2, Drink #2
Cow 3: Food #1, Drink #1
Cow 4: Food #3, Drink #3
The pigeon-hole principle tells us we can do no better since there are only three kinds of food or drink. Other test data sets are more challenging, of course.
Source

USACO 2007 Open Gold

*/