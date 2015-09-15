/* 14535879	840502	2054	Accepted	284K	94MS	C++	1672B	2015-08-03 19:16:38 */
#include<bits\stdc++.h>
using namespace std;
int c[1005], f[1005];
double cost[1005];
int cnt[1005];
vector<int> G[1005];
bool m[1005];
int ne[1005];
void DFS(int x) {
  for (int i = 0; i < G[x].size(); i++) {
    int y = G[x][i];
    if (f[y] == 0)
      f[y] = x, DFS(y);
  }
}
void addEdge(int x, int y) {
  while (ne[x])  x = ne[x];
  ne[x] = y;
}
int main() {
  int n, root;
  while (scanf("%d%d", &n, &root) == 2) {
    if (n == 0 && root == 0) break;
    memset(f, 0, sizeof(f));
    memset(m, false, sizeof(m));
    memset(ne, 0, sizeof(ne));
    f[root] = -1;
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= n; i++)
      scanf("%d", c + i);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    DFS(root);
    for (int i = 1; i <= n; i++)
      cost[i] = c[i], cnt[i] = 1;
    
    for (int i = 1, k; i < n; i++) {
      double max = 0;
      for (int j = 1; j <= n; j++)
        if (j != root && !m[j] && max < cost[j])
          max = cost[j], k = j;
      int fa = f[k];
      addEdge(fa, k);
      while (m[fa]) fa = f[fa];
      m[k] = true;
      cost[fa] = (cost[fa] * cnt[fa] + cost[k] * cnt[k]) / (cnt[fa] + cnt[k]);
      cnt[fa] += cnt[k];
    }
    int ans = 0;
    for (int i = 1, p = root; i <= n; i++) {
      ans += i * c[p], p = ne[p];
    }
    printf("%d\n", ans);
  }
  return 0;
}
/*

Color a Tree
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 7246		Accepted: 2503
Description

Bob is very interested in the data structure of a tree. A tree is a directed graph in which a special node is singled out, called the "root" of the tree, and there is a unique path from the root to each of the other nodes.

Bob intends to color all the nodes of a tree with a pen. A tree has N nodes, these nodes are numbered 1, 2, ..., N. Suppose coloring a node takes 1 unit of time, and after finishing coloring one node, he is allowed to color another. Additionally, he is allowed to color a node only when its father node has been colored. Obviously, Bob is only allowed to color the root in the first try.

Each node has a "coloring cost factor", Ci. The coloring cost of each node depends both on Ci and the time at which Bob finishes the coloring of this node. At the beginning, the time is set to 0. If the finishing time of coloring node i is Fi, then the coloring cost of node i is Ci * Fi.

For example, a tree with five nodes is shown in Figure-1. The coloring cost factors of each node are 1, 2, 1, 2 and 4. Bob can color the tree in the order 1, 3, 5, 2, 4, with the minimum total coloring cost of 33.

Given a tree and the coloring cost factor of each node, please help Bob to find the minimum possible total coloring cost for coloring all the nodes.
Input

The input consists of several test cases. The first line of each case contains two integers N and R (1 <= N <= 1000, 1 <= R <= N), where N is the number of nodes in the tree and R is the node number of the root node. The second line contains N integers, the i-th of which is Ci (1 <= Ci <= 500), the coloring cost factor of node i. Each of the next N-1 lines contains two space-separated node numbers V1 and V2, which are the endpoints of an edge in the tree, denoting that V1 is the father node of V2. No edge will be listed twice, and all edges will be listed.

A test case of N = 0 and R = 0 indicates the end of input, and should not be processed.
Output

For each test case, output a line containing the minimum total coloring cost required for Bob to color all the nodes.
Sample Input

5 1
1 2 1 2 4
1 2
1 3
2 4
3 5
0 0
Sample Output

33
Source

Beijing 2004

*/