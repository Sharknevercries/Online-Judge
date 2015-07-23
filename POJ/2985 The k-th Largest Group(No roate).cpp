/* 14366084	840502	2985	Accepted	7192K	750MS	C++	4281B	2015-07-09 19:05:37 */
#include<bits\stdc++.h>
#define LCH(x) (T[x].LC)
#define RCH(x) (T[x].RC)
#define MAXN 200005
#define MAXM 500005
using namespace std;
struct Node{
  int pri, LC, RC;
  int value, size, count, nodeCount;
  Node() :pri(-1), LC(0), RC(0), value(0), size(0), count(0), nodeCount(0){}
  Node(int _value){
    pri = (rand() << 15) + rand();
    LC = RC = 0;
    value = _value, nodeCount = count = size = 1;
  }
};
queue<int> GC;
Node T[MAXN];
int G[MAXN], S[MAXN];
int nMem, root;
int n, m;
int getNode(int value){
  int newNode;
  if (!GC.empty())
    newNode = GC.front(), GC.pop();
  else if (nMem < MAXN)
    newNode = nMem++;
  else
    while (1);
  T[newNode] = Node(value);
  return newNode;
}
void pull(int root){
  if (!root) return;
  T[root].size = T[LCH(root)].size + T[RCH(root)].size + T[root].count;
  T[root].nodeCount = T[LCH(root)].nodeCount + T[RCH(root)].nodeCount + 1;
}
void push(int root){

}
int merge(int a,int b){
  push(a), push(b);
  if (!a) return b;
  if (!b) return a;
  int res = 0;
  if (T[a].pri > T[b].pri)
    RCH(a) = merge(RCH(a), b), res = a;
  else
    LCH(b) = merge(a, LCH(b)), res = b;
  pull(res);
  return res;
}
pair<int, int> split(int root, int k){
  push(root);
  if (k == 0) return make_pair(0, root);
  if (k == T[root].nodeCount) return make_pair(root, 0);
  pair<int, int> res;
  if (T[LCH(root)].nodeCount >= k){
    res = split(LCH(root), k);
    LCH(root) = res.second;
    res.second = root;
    pull(res.second);
  }
  else{
    res = split(RCH(root), k - T[LCH(root)].nodeCount - 1);
    RCH(root) = res.first;
    res.first = root;
    pull(res.first);
  }
  return res;
}
int getPosition(int root, int value){
  if (!root)  return 0;
  if (T[root].value < value)
    return T[LCH(root)].nodeCount + 1 + getPosition(RCH(root), value);
  else
    return getPosition(LCH(root), value);
}
void insert(int &root, int value){
  pair<int, int> LT = split(root, getPosition(root, value));
  root = merge(merge(LT.first, getNode(value)), LT.second);
}
void remove(int &root, int value){
  pair<int, int> LT = split(root, getPosition(root, value));
  pair<int, int> RT = split(LT.second, 1);
  GC.push(RT.first);
  root = merge(LT.first, RT.second);
}
int lazyRemove(int root, int value){
  int res = 0;
  if (T[root].value == value)
    res = --T[root].count;
  else if (T[root].value < value)
    res = lazyRemove(RCH(root), value);
  else
    res = lazyRemove(LCH(root), value);
  pull(root);
  return res;
}
bool lazyInsert(int root, int value){
  if (!root)  return false;
  bool res;
  if (T[root].value == value)
    T[root].count++, res = true;
  else if (T[root].value < value)
    res = lazyInsert(RCH(root), value);
  else
    res = lazyInsert(LCH(root), value);
  pull(root);
  return res;
}
int getKth(int root, int k){
  if (!root)  return 0;
  if (k <= T[LCH(root)].size)
    return getKth(LCH(root), k);
  else if (k <= T[LCH(root)].size + T[root].count)
    return T[root].value;
  else
    return getKth(RCH(root), k - T[LCH(root)].size - T[root].count);
}
int find(int x){
  return x == G[x] ? x : G[x] = find(G[x]);
}
void joint(int a, int b){
  a = find(a), b = find(b);
  if (a == b) return;
  if (!lazyRemove(root, S[a]))
    remove(root, S[a]);
  if (!lazyRemove(root, S[b]))
    remove(root, S[b]);
  G[b] = a, S[a] += S[b], S[b] = 0;
  if(!lazyInsert(root, S[a]))
    insert(root, S[a]);
}
void init(){
  nMem = 1, root = 0;
  while (!GC.empty()) GC.pop();
  for (int i = 1; i <= n; i++)
    G[i] = i, S[i] = 1;
  for (int i = 1; i <= n; i++)
    if (!lazyInsert(root, 1))
      insert(root, 1);
}
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    init();
    for (int i = 0; i < m; i++){
      int command, a, b;
      scanf("%d", &command);
      if (command == 0){
        scanf("%d%d", &a, &b);
        joint(a, b);
      }
      else if (command == 1){
        scanf("%d", &a);
        printf("%d\n", getKth(root, T[root].size - a + 1));
      }
    }
  }
  return 0;
}
/*

The k-th Largest Group
Time Limit: 2000MS		Memory Limit: 131072K
Total Submissions: 7813		Accepted: 2514
Description

Newman likes playing with cats. He possesses lots of cats in his home. Because the number of cats is really huge, Newman wants to group some of the cats. To do that, he first offers a number to each of the cat (1, 2, 3, …, n). Then he occasionally combines the group cat i is in and the group cat j is in, thus creating a new group. On top of that, Newman wants to know the size of the k-th biggest group at any time. So, being a friend of Newman, can you help him?

Input

1st line: Two numbers N and M (1 ≤ N, M ≤ 200,000), namely the number of cats and the number of operations.

2nd to (m + 1)-th line: In each line, there is number C specifying the kind of operation Newman wants to do. If C = 0, then there are two numbers i and j (1 ≤ i, j ≤ n) following indicating Newman wants to combine the group containing the two cats (in case these two cats are in the same group, just do nothing); If C = 1, then there is only one number k (1 ≤ k ≤ the current number of groups) following indicating Newman wants to know the size of the k-th largest group.

Output

For every operation “1” in the input, output one number per line, specifying the size of the kth largest group.

Sample Input

10 10
0 1 2
1 4
0 3 4
1 2
0 5 6
1 1
0 7 8
1 1
0 9 10
1 1
Sample Output

1
2
2
2
2
Hint

When there are three numbers 2 and 2 and 1, the 2nd largest number is 2 and the 3rd largest number is 1.

Source

POJ Monthly--2006.08.27, zcgzcgzcg

*/