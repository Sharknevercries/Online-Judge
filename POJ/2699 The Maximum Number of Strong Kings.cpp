/* 14469129	840502	2699	Accepted	376K	16MS	C++	2688B	2015-07-24 19:09:59 */
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
int n, score[105];
int s, t;
char str[100005];
void input(){
  memset(score, 0, sizeof(score));
  n = 0;
  char c;
  int tmp = 0;
  bool flag = false;
  while ((c = getchar()) != '\n'){
    if (c == ' '){
      if (flag)
        score[++n] = tmp, tmp = 0;
      flag = false;
    }
    else
      tmp = tmp * 10 + c - '0', flag = true;
  }
  if (flag)
    score[++n] = tmp;
}
int main(){
  freopen("input.txt", "r", stdin);
  int c;
  scanf("%d", &c);
  getchar();
  while (c--){
    input();
    s = 0, t = n + n*(n - 1) / 2 + 1;
    int ans = 0;
    for (int k = 0; k <= n; k++){
      e = 0;
      memset(head, -1, sizeof(head));
      for (int i = 1; i <= n; i++)
        addEdge(s, i, score[i]);
      int competition = 1;
      for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
          addEdge(n + competition, t, 1);
          addEdge(i, n + competition, 1);
          if (!(i > n - k && score[j] > score[i]))
            addEdge(j, n + competition, 1);
          competition++;
        }
      }
      if (SAP(s, t) == n * (n - 1) / 2)
        ans = k;
      else
        break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
/*

The Maximum Number of Strong Kings
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 1818		Accepted: 852
Description

A tournament can be represented by a complete graph in which each vertex denotes a player and a directed edge is from vertex x to vertex y if player x beats player y. For a player x in a tournament T, the score of x is the number of players beaten by x. The score sequence of T, denoted by S(T) = (s1, s2, . . . , sn), is a non-decreasing list of the scores of all the players in T. It can be proved that S(T) = (s1, s2, . . . , sn) is a score sequence of T if and only if
for k = 1, 2, . . . , n and equality holds when k = n. A player x in a tournament is a strong king if and only if x beats all of the players whose scores are greater than the score of x. For a score sequence S, we say that a tournament T realizes S if S(T) = S. In particular, T is a heavy tournament realizing S if T has the maximum number of strong kings among all tournaments realizing S. For example, see T2 in Figure 1. Player a is a strong king since the score of player a is the largest score in the tournament. Player b is also a strong king since player b beats player a who is the only player having a score larger than player b. However, players c, d and e are not strong kings since they do not beat all of the players having larger scores.
The purpose of this problem is to find the maximum number of strong kings in a heavy tournament after a score sequence is given. For example,Figure 1 depicts two possible tournaments on five players with the same score sequence (1, 2, 2, 2, 3). We can see that there are at most two strong kings in any tournament with the score sequence (1, 2, 2, 2, 3) since the player with score 3 can be beaten by only one other player. We can also see that T2 contains two strong kings a and b. Thus, T2 is one of heavy tournaments. However, T1 is not a heavy tournament since there is only one strong king in T1. Therefore, the answer of this example is 2.


Input

The first line of the input file contains an integer m, m <= 10, which represents the number of test cases. The following m lines contain m score sequences in which each line contains a score sequence. Note that each score sequence contains at most ten scores.
Output

The maximum number of strong kings for each test case line by line.
Sample Input

5
1 2 2 2 3
1 1 3 4 4 4 4
3 3 4 4 4 4 5 6 6 6
0 3 4 4 4 5 5 5 6
0 3 3 3 3 3
Sample Output

2
4
5
3
5
Source

Taiwan 2004

*/