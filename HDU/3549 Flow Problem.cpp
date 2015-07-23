/* 14108378	2015-07-22 14:30:59	Accepted	3549	1357MS	1664K	1721 B	C++	Shark */
#include<bits\stdc++.h>
#define MAXN 105
#define MAXM 2005
using namespace std;
struct Edge{ int u, v, cap, next; };
Edge E[MAXM];
int path[MAXN], head[MAXN], e;
void addEdge(int u, int v, int cap){
  E[e++] = Edge{ u, v, cap, head[u] }, head[u] = e - 1;
  E[e++] = Edge{ v, u, 0, head[v] }, head[v] = e - 1;
}
int maxFlow(int s, int t){
  int max_flow = 0;
  while (true)    {
    bool visit[MAXN];
    memset(visit, false, sizeof(visit));
    visit[s] = true;
    queue<int>Q;
    Q.push(s);
    int tmp_flow = INT_MAX;
    while (!Q.empty()){
      int u = Q.front();
      Q.pop();
      for (int v = head[u]; v != -1; v = E[v].next){
        int k = E[v].v;
        if (!visit[k] && E[v].cap){
          visit[k] = true;
          path[k] = v;
          Q.push(k);
          if (tmp_flow > E[v].cap)
            tmp_flow = E[v].cap;
        }
      }
    }
    if (!visit[t])
      break;
    for (int u = t; u != s; u = E[path[u]].u){
      E[path[u]].cap -= tmp_flow;
      E[path[u] ^ 1].cap += tmp_flow;
    }
    max_flow += tmp_flow;
  }
  return max_flow;
}
int main(){
  int t, c = 1;
  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);
    e = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++){
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      addEdge(a, b, w);
    }
    printf("Case %d: %d\n", c++, maxFlow(1, n));
  }
  return 0;
}
/*

Flow Problem

Time Limit: 5000/5000 MS (Java/Others)    Memory Limit: 65535/32768 K (Java/Others)
Total Submission(s): 10055    Accepted Submission(s): 4730

Problem Description
Network flow is a well-known difficult problem for ACMers. Given a graph, your task is to find out the maximum flow for the weighted directed graph.

Input
The first line of input contains an integer T, denoting the number of test cases.
For each test case, the first line contains two integers N and M, denoting the number of vertexes and edges in the graph. (2 <= N <= 15, 0 <= M <= 1000)
Next M lines, each line contains three integers X, Y and C, there is an edge from X to Y and the capacity of it is C. (1 <= X, Y <= N, 1 <= C <= 1000)

Output
For each test cases, you should output the maximum flow from source 1 to sink N.

Sample Input
2
3 2
1 2 1
2 3 1
3 3
1 2 1
2 3 1
1 3 1

Sample Output
Case 1: 1
Case 2: 2

Author
HyperHexagon

Source
HyperHexagon's Summer Gift (Original tasks)

Recommend
zhengfeng   |   We have carefully selected several similar problems for you:  3572 3416 3081 3491 1533 

*/