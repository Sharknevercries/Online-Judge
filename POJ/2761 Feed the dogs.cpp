/* 14364525	840502	2761	Accepted	3460K	3235MS	C++	3166B	2015-07-09 14:40:26 */
#include<bits\stdc++.h>
#define LCH(x) (T[x].LC)
#define RCH(x) (T[x].RC)
#define MAXN 100005
#define MAXM 50005
using namespace std;
struct Node{
  int pri, LC, RC;
  int value, count;
  Node() :pri(-1), LC(0), RC(0), value(0), count(0){}
  Node(int _value){
    pri = (rand() << 15) + rand();
    LC = RC = 0;
    value = _value;
    count = 1;
  }
};
struct Query{
  int L, R, k, ans;
};
Node T[MAXN];
Query Q[MAXM];
int nMem, root;
int getNode(int value){
  T[nMem] = Node(value);
  if (nMem >= MAXN) while (1);
  return nMem++;
}
void pull(int root){
  if (!root)  return;
  T[root].count = T[LCH(root)].count + T[RCH(root)].count + 1;
}
void push(int root){

}
int merge(int a, int b){
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
  if (k == T[root].count) return make_pair(root, 0);
  pair<int, int> res;
  if (T[LCH(root)].count >= k){
    res = split(LCH(root), k);
    LCH(root) = res.second;
    res.second = root;
    pull(res.second);
  }
  else{
    res = split(RCH(root), k - T[LCH(root)].count - 1);
    RCH(root) = res.first;
    res.first = root;
    pull(res.first);
  }
  return res;
}
bool sortByInterval(int A, int B){
  return Q[A].L < Q[B].L || (Q[A].L == Q[B].L && Q[A].R < Q[B].R);
}
int getPosition(int root, int value){
  if (!root)  return 0;
  if (T[root].value < value)
    return T[LCH(root)].count + 1 + getPosition(RCH(root), value);
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
  root = merge(LT.first, RT.second);
}
int getKth(int root, int k){
  if (k == T[LCH(root)].count + 1)
    return T[root].value;
  else if (k <= T[LCH(root)].count)
    return getKth(LCH(root), k);
  else
    return getKth(RCH(root), k - T[LCH(root)].count - 1);
}
int n, m;
int W[MAXN];
int idx[MAXM];
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    nMem = 1, root = 0;
    for (int i = 1; i <= n;i++)
      scanf("%d", W + i);
    for (int i = 0; i < m; i++)
      scanf("%d%d%d", &Q[i].L, &Q[i].R, &Q[i].k), idx[i] = i;
    sort(idx, idx + m, sortByInterval);
    for (int i = 0, L = 1, R = 1; i < m; i++){
      int target = idx[i];
      while (Q[target].R >= R)
        insert(root, W[R++]);
      while (Q[target].L > L)
        remove(root, W[L++]);
      Q[target].ans = getKth(root, Q[target].k);
    }
    for (int i = 0; i < m; i++)
      printf("%d\n", Q[i].ans);
  }
  return 0;
}
/*

Feed the dogs
Time Limit: 6000MS		Memory Limit: 65536K
Total Submissions: 16623		Accepted: 5194
Description

Wind loves pretty dogs very much, and she has n pet dogs. So Jiajia has to feed the dogs every day for Wind. Jiajia loves Wind, but not the dogs, so Jiajia use a special way to feed the dogs. At lunchtime, the dogs will stand on one line, numbered from 1 to n, the leftmost one is 1, the second one is 2, and so on. In each feeding, Jiajia choose an inteval[i,j], select the k-th pretty dog to feed. Of course Jiajia has his own way of deciding the pretty value of each dog. It should be noted that Jiajia do not want to feed any position too much, because it may cause some death of dogs. If so, Wind will be angry and the aftereffect will be serious. Hence any feeding inteval will not contain another completely, though the intervals may intersect with each other.

Your task is to help Jiajia calculate which dog ate the food after each feeding.
Input

The first line contains n and m, indicates the number of dogs and the number of feedings.

The second line contains n integers, describe the pretty value of each dog from left to right. You should notice that the dog with lower pretty value is prettier.

Each of following m lines contain three integer i,j,k, it means that Jiajia feed the k-th pretty dog in this feeding.

You can assume that n<100001 and m<50001.
Output

Output file has m lines. The i-th line should contain the pretty value of the dog who got the food in the i-th feeding.
Sample Input

7 2
1 5 2 6 3 7 4
1 5 3
2 7 1
Sample Output

3
2
Source

POJ Monthly--2006.02.26,zgl & twb

*/