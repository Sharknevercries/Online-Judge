/* 14542214	840502	2342	Accepted	728K	204MS	C++	1021B	2015-08-04 16:40:18 */
#include<bits\stdc++.h>
using namespace std;
int n, root;
int w[10005];
int DP[10005][2];
vector<int> G[10005];
bool V[10005];
void DFS(int x) {
  V[x] = true;
  DP[x][0] = 0;
  DP[x][1] = w[x];
  for (int i = 0; i < G[x].size(); i++) {
    int y = G[x][i];
    if (!V[y]) {
      DFS(y);
      DP[x][0] += max(DP[y][0], DP[y][1]);
      DP[x][1] += DP[y][0];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", w + i);
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    if (a == 0 && b == 0)  break;
    G[a].push_back(b);
    G[b].push_back(a);
    V[a] = true;
  }
  for (int i = 1; i <= n; i++)
    if (!V[i])
      root = i;
  memset(V, false, sizeof(V));
  DFS(root);
  printf("%d\n", max(DP[root][0], DP[root][1]));
  return 0;
}
/*

Anniversary party
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 5171		Accepted: 2932
Description

There is going to be a party to celebrate the 80-th Anniversary of the Ural State University. The University has a hierarchical structure of employees. It means that the supervisor relation forms a tree rooted at the rector V. E. Tretyakov. In order to make the party funny for every one, the rector does not want both an employee and his or her immediate supervisor to be present. The personnel office has evaluated conviviality of each employee, so everyone has some number (rating) attached to him or her. Your task is to make a list of guests with the maximal possible sum of guests' conviviality ratings.
Input

Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go N ¡V 1 lines that describe a supervisor relation tree. Each line of the tree specification has the form:
L K
It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line
0 0
Output

Output should contain the maximal sum of guests' ratings.
Sample Input

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output

5
Source

Ural State University Internal Contest October'2000 Students Session

*/