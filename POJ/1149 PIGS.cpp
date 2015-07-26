/* 14460709	840502	1149	Accepted	488K	0MS	C++	2214B	2015-07-23 16:21:34 */
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
int C[MAXN], last[MAXN];
int main(){
  int n, m;
  while (scanf("%d%d", &n, &m) == 2){
    int maxValue = 0;
    e = 0;
    memset(head, -1, sizeof(head));
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= n; i++)
      scanf("%d", &C[i]);
    for (int i = 1; i <= m; i++){
      int b, k;
      scanf("%d", &k);
      for (int j = 0; j < k; j++){
        int id;
        scanf("%d", &id);
        if (last[id] == 0)
          addEdge(0, i, C[id]);
        else
          addEdge(last[id], i, INF);
        last[id] = i;
      }
      scanf("%d", &b);
      addEdge(i, m + 1, b);
    }

    printf("%d\n", SAP(0, m + 1));
  }
  return 0;
}
/*

PIGS
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 18019		Accepted: 8199
Description

Mirko works on a pig farm that consists of M locked pig-houses and Mirko can't unlock any pighouse because he doesn't have the keys. Customers come to the farm one after another. Each of them has keys to some pig-houses and wants to buy a certain number of pigs.
All data concerning customers planning to visit the farm on that particular day are available to Mirko early in the morning so that he can make a sales-plan in order to maximize the number of pigs sold.
More precisely, the procedure is as following: the customer arrives, opens all pig-houses to which he has the key, Mirko sells a certain number of pigs from all the unlocked pig-houses to him, and, if Mirko wants, he can redistribute the remaining pigs across the unlocked pig-houses.
An unlimited number of pigs can be placed in every pig-house.
Write a program that will find the maximum number of pigs that he can sell on that day.
Input

The first line of input contains two integers M and N, 1 <= M <= 1000, 1 <= N <= 100, number of pighouses and number of customers. Pig houses are numbered from 1 to M and customers are numbered from 1 to N.
The next line contains M integeres, for each pig-house initial number of pigs. The number of pigs in each pig-house is greater or equal to 0 and less or equal to 1000.
The next N lines contains records about the customers in the following form ( record about the i-th customer is written in the (i+2)-th line):
A K1 K2 ... KA B It means that this customer has key to the pig-houses marked with the numbers K1, K2, ..., KA (sorted nondecreasingly ) and that he wants to buy B pigs. Numbers A and B can be equal to 0.
Output

The first and only line of the output should contain the number of sold pigs.
Sample Input

3 3
3 1 10
2 1 2 2
2 1 3 3
1 2 6
Sample Output

7
Source

Croatia OI 2002 Final Exam - First day

*/

