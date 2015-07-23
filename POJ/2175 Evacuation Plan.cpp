/* 14456276	840502	2175	Accepted	524K	188MS	C++	2822B	2015-07-23 01:04:11 */
#include<bits\stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 505
#define MAXM 50005
using namespace std;
struct Building{
  int x, y, c;
};
struct Edge{
  int u, v, w, next;
  Edge(){}
  Edge(int u, int v, int w, int next) :u(u), v(v), w(w), next(next){}
};
Edge E[MAXM];
int head[MAXN], e;
void addEdge(int u, int v, int w){
  E[e] = Edge(u, v, w, head[u]), head[u] = e++;
}
int moveCost(Building A, Building B){
  return abs(A.x - B.x) + abs(A.y - B.y) + 1;
}
int ans[MAXN][MAXN], sum[MAXN];
int dist[MAXN], pre[MAXN];
bool V[MAXN];
Building B[MAXN], S[MAXN];
int n, m;
int SPFA(int s){
  int count[MAXN] = { 0 };
  memset(dist, INF, sizeof(dist));
  memset(V, false, sizeof(V));
  V[s] = true;
  queue<int> Q;
  Q.push(s);
  dist[s] = 0;
  count[s]++;
  while (!Q.empty()){
    int u = Q.front(); 
    Q.pop();
    V[u] = false;
    for (int i = head[u]; i != -1; i = E[i].next){
      Edge &e = E[i];
      if (dist[u] + e.w < dist[e.v]){
        dist[e.v] = dist[u] + e.w;
        pre[e.v] = u;
        if (!V[e.v]){
          V[e.v] = true;
          Q.push(e.v);
          if (++count[e.v] >= n + m)
            return e.v;
        }
      }
    }
  }
  return -1;
}
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    e = 0;
    memset(head, -1, sizeof(head));
    memset(pre, -1, sizeof(pre));
    for (int i = 1; i <= n; i++)
      scanf("%d%d%d", &B[i].x, &B[i].y, &B[i].c);
    for (int i = 1; i <= m;i++)
      scanf("%d%d%d", &S[i].x, &S[i].y, &S[i].c);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        addEdge(i, j + n, moveCost(B[i], S[j]));
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        scanf("%d", &ans[i][j]);
        if (ans[i][j])
          addEdge(j + n, i, -moveCost(B[i], S[j])), sum[j] += ans[i][j];
      }
    }
    for (int i = 1; i <= m; i++){
      if (sum[i] < S[i].c)
        addEdge(i + n, n + m + 1, 0);
      if (sum[i] > 0)
        addEdge(n + m + 1, i + n, 0);
    }
    int u = SPFA(n + m + 1);
    if (u == -1)
      puts("OPTIMAL");
    else{
      puts("SUBOPTIMAL");
      memset(V, false, sizeof(V));
      int v = u;
      while (!V[v])
        V[v] = true, v = pre[v];
      u = v;
      do{
        if (pre[v] <= n && v > n)
          ans[pre[v]][v - n]++;
        if (v <= n && pre[v] > n)
          ans[v][pre[v] - n]--;
        v = pre[v];
      } while (v != u);
      for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
          if (j - 1)putchar(' ');
          printf("%d", ans[i][j]);
        }
        putchar('\n');
      }
    }
  }
  return 0;
}
/*

Evacuation Plan
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 3810		Accepted: 1011		Special Judge
Description

The City has a number of municipal buildings and a number of fallout shelters that were build specially to hide municipal workers in case of a nuclear war. Each fallout shelter has a limited capacity in terms of a number of people it can accommodate, and there's almost no excess capacity in The City's fallout shelters. Ideally, all workers from a given municipal building shall run to the nearest fallout shelter. However, this will lead to overcrowding of some fallout shelters, while others will be half-empty at the same time.

To address this problem, The City Council has developed a special evacuation plan. Instead of assigning every worker to a fallout shelter individually (which will be a huge amount of information to keep), they allocated fallout shelters to municipal buildings, listing the number of workers from every building that shall use a given fallout shelter, and left the task of individual assignments to the buildings' management. The plan takes into account a number of workers in every building - all of them are assigned to fallout shelters, and a limited capacity of each fallout shelter - every fallout shelter is assigned to no more workers then it can accommodate, though some fallout shelters may be not used completely.

The City Council claims that their evacuation plan is optimal, in the sense that it minimizes the total time to reach fallout shelters for all workers in The City, which is the sum for all workers of the time to go from the worker's municipal building to the fallout shelter assigned to this worker.

The City Mayor, well known for his constant confrontation with The City Council, does not buy their claim and hires you as an independent consultant to verify the evacuation plan. Your task is to either ensure that the evacuation plan is indeed optimal, or to prove otherwise by presenting another evacuation plan with the smaller total time to reach fallout shelters, thus clearly exposing The City Council's incompetence.

During initial requirements gathering phase of your project, you have found that The City is represented by a rectangular grid. The location of municipal buildings and fallout shelters is specified by two integer numbers and the time to go between municipal building at the location (Xi, Yi) and the fallout shelter at the location (Pj, Qj) is Di,j = |Xi - Pj| + |Yi - Qj| + 1 minutes.

Input

The input consists of The City description and the evacuation plan description. The first line of the input file consists of two numbers N and M separated by a space. N (1 ≤ N ≤ 100) is a number of municipal buildings in The City (all municipal buildings are numbered from 1 to N). M (1 ≤ M ≤ 100) is a number of fallout shelters in The City (all fallout shelters are numbered from 1 to M).

The following N lines describe municipal buildings. Each line contains there integer numbers Xi, Yi, and Bi separated by spaces, where Xi, Yi (-1000 ≤ Xi, Yi ≤ 1000) are the coordinates of the building, and Bi (1 ≤ Bi ≤ 1000) is the number of workers in this building.

The description of municipal buildings is followed by M lines that describe fallout shelters. Each line contains three integer numbers Pj, Qj, and Cj separated by spaces, where Pi, Qi (-1000 ≤ Pj, Qj ≤ 1000) are the coordinates of the fallout shelter, and Cj (1 ≤ Cj ≤ 1000) is the capacity of this shelter.

The description of The City Council's evacuation plan follows on the next N lines. Each line represents an evacuation plan for a single building (in the order they are given in The City description). The evacuation plan of ith municipal building consists of M integer numbers Ei,j separated by spaces. Ei,j (0 ≤ Ei,j ≤ 1000) is a number of workers that shall evacuate from the ith municipal building to the jth fallout shelter.

The plan in the input file is guaranteed to be valid. Namely, it calls for an evacuation of the exact number of workers that are actually working in any given municipal building according to The City description and does not exceed the capacity of any given fallout shelter.

Output

If The City Council's plan is optimal, then write to the output the single word OPTIMAL. Otherwise, write the word SUBOPTIMAL on the first line, followed by N lines that describe your plan in the same format as in the input file. Your plan need not be optimal itself, but must be valid and better than The City Council's one.
Sample Input

3 4
-3 3 5
-2 -2 6
2 2 5
-1 1 3
1 1 4
-2 -2 7
0 -1 3
3 1 1 0
0 0 6 0
0 3 0 2
Sample Output

SUBOPTIMAL
3 0 1 1
0 0 6 0
0 4 0 1
Source

Northeastern Europe 2002

*/