/* 14371609	840502	1442	Accepted	2212K	235MS	C++	2452B	2015-07-10 19:54:50 */
#include<bits\stdc++.h>
#define MAXN 100005
#define LCH(x) (T[x].LC)
#define RCH(x) (T[x].RC)
using namespace std;
struct Node{
  int pri, LC, RC;
  int value, size;
  Node() :pri(-1), LC(0), RC(0), value(0), size(0){}
  Node(int _value){
    pri = (rand() << 15) + rand();
    value = _value;
    size = 1, LC = RC = 0;
  }
};
Node T[MAXN];
int nMem, root;
int n, m, W[MAXN];
int getNode(int value){
  T[nMem] = Node(value);
  if (nMem >= MAXN) while (1);
  return nMem++;
}
void pull(int root){
  if (!root)  return;
  T[root].size = T[LCH(root)].size + T[RCH(root)].size + 1;
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
  if (k == T[root].size) return make_pair(root, 0);
  pair<int, int> res;
  if (T[LCH(root)].size >= k){
    res = split(LCH(root), k);
    LCH(root) = res.second;
    res.second = root;
    pull(res.second);
  }
  else{
    res = split(RCH(root), k - T[LCH(root)].size - 1);
    RCH(root) = res.first;
    res.first = root;
    pull(res.first);
  }
  return res;
}
int getPosition(int root, int value){
  if (!root)  return 0;
  if (T[root].value < value)
    return T[LCH(root)].size + 1 + getPosition(RCH(root), value);
  else
    return getPosition(LCH(root), value);
}
void insert(int &root, int value){
  pair<int, int> LT = split(root, getPosition(root, value));
  root = merge(merge(LT.first, getNode(value)), LT.second);
}
int getKth(int root, int k){
  if (k == T[LCH(root)].size + 1)
    return T[root].value;
  else if (k <= T[LCH(root)].size)
    return getKth(LCH(root), k);
  else
    return getKth(RCH(root), k - T[LCH(root)].size - 1);
}
int main(){
  while (scanf("%d%d", &n, &m) == 2){
    nMem = 1, root = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", W + i);
    for (int k = 1, L = 1, R; k <= m; k++){
      scanf("%d", &R);
      while (L <= R)
        insert(root, W[L++]);
      printf("%d\n", getKth(root, k));
    }
  }
  return 0;
}
/*

Black Box
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 8525		Accepted: 3501
Description

Our Black Box represents a primitive database. It can save an integer array and has a special i variable. At the initial moment Black Box is empty and i equals 0. This Black Box processes a sequence of commands (transactions). There are two types of transactions:

ADD (x): put element x into Black Box;
GET: increase i by 1 and give an i-minimum out of all integers containing in the Black Box. Keep in mind that i-minimum is a number located at i-th place after Black Box elements sorting by non- descending.

Let us examine a possible sequence of 11 transactions:

Example 1

N Transaction i Black Box contents after transaction Answer

(elements are arranged by non-descending)

1 ADD(3)      0 3

2 GET         1 3                                    3

3 ADD(1)      1 1, 3

4 GET         2 1, 3                                 3

5 ADD(-4)     2 -4, 1, 3

6 ADD(2)      2 -4, 1, 2, 3

7 ADD(8)      2 -4, 1, 2, 3, 8

8 ADD(-1000)  2 -1000, -4, 1, 2, 3, 8

9 GET         3 -1000, -4, 1, 2, 3, 8                1

10 GET        4 -1000, -4, 1, 2, 3, 8                2

11 ADD(2)     4 -1000, -4, 1, 2, 2, 3, 8

It is required to work out an efficient algorithm which treats a given sequence of transactions. The maximum number of ADD and GET transactions: 30000 of each type.


Let us describe the sequence of transactions by two integer arrays:


1. A(1), A(2), ..., A(M): a sequence of elements which are being included into Black Box. A values are integers not exceeding 2 000 000 000 by their absolute value, M <= 30000. For the Example we have A=(3, 1, -4, 2, 8, -1000, 2).

2. u(1), u(2), ..., u(N): a sequence setting a number of elements which are being included into Black Box at the moment of first, second, ... and N-transaction GET. For the Example we have u=(1, 2, 6, 6).

The Black Box algorithm supposes that natural number sequence u(1), u(2), ..., u(N) is sorted in non-descending order, N <= M and for each p (1 <= p <= N) an inequality p <= u(p) <= M is valid. It follows from the fact that for the p-element of our u sequence we perform a GET transaction giving p-minimum number from our A(1), A(2), ..., A(u(p)) sequence.


Input

Input contains (in given order): M, N, A(1), A(2), ..., A(M), u(1), u(2), ..., u(N). All numbers are divided by spaces and (or) carriage return characters.
Output

Write to the output Black Box answers sequence for a given sequence of transactions, one number each line.
Sample Input

7 4
3 1 -4 2 8 -1000 2
1 2 6 6
Sample Output

3
3
1
2
Source

Northeastern Europe 1996

*/