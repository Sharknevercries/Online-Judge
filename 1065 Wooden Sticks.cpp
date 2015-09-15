/* 14535445	840502	1065	Accepted	192K	32MS	C++	1029B	2015-08-03 17:59:29 */
#include<bits\stdc++.h>
using namespace std;
struct Wood {
  int l, w;
};
Wood wood[5005];
bool used[5005];
bool cmp(Wood A, Wood B) {
  return A.l < B.l || (A.l == B.l && A.w < B.w);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &wood[i].l, &wood[i].w);
    sort(wood, wood + n, cmp);
    memset(used, false, sizeof(used));
    int ans = 0;
    while (true) {
      int i;
      for (i = 0; i < n; i++)
        if (!used[i])
          break;
      if (i >= n)  break;
      ans++;
      used[i] = true;
      for (int j = 0; j < n; j++)
        if (!used[j] && wood[j].l >= wood[i].l && wood[j].w >= wood[i].w)
          used[i = j] = true;
    }
    printf("%d\n", ans);
  }
  return 0;
}
/*

Wooden Sticks
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 19535		Accepted: 8241
Description

There is a pile of n wooden sticks. The length and weight of each stick are known in advance. The sticks are to be processed by a woodworking machine in one by one fashion. It needs some time, called setup time, for the machine to prepare processing a stick. The setup times are associated with cleaning operations and changing tools and shapes in the machine. The setup times of the woodworking machine are given as follows:
(a) The setup time for the first wooden stick is 1 minute.
(b) Right after processing a stick of length l and weight w , the machine will need no setup time for a stick of length l' and weight w' if l <= l' and w <= w'. Otherwise, it will need 1 minute for setup.
You are to find the minimum setup time to process a given pile of n wooden sticks. For example, if you have five sticks whose pairs of length and weight are ( 9 , 4 ) , ( 2 , 5 ) , ( 1 , 2 ) , ( 5 , 3 ) , and ( 4 , 1 ) , then the minimum setup time should be 2 minutes since there is a sequence of pairs ( 4 , 1 ) , ( 5 , 3 ) , ( 9 , 4 ) , ( 1 , 2 ) , ( 2 , 5 ) .
Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of two lines: The first line has an integer n , 1 <= n <= 5000 , that represents the number of wooden sticks in the test case, and the second line contains 2n positive integers l1 , w1 , l2 , w2 ,..., ln , wn , each of magnitude at most 10000 , where li and wi are the length and weight of the i th wooden stick, respectively. The 2n integers are delimited by one or more spaces.
Output

The output should contain the minimum setup time in minutes, one per line.
Sample Input

3
5
4 9 5 2 2 1 3 5 1 4
3
2 2 1 1 2 2
3
1 3 2 2 3 1
Sample Output

2
1
3
Source

Taejon 2001

*/