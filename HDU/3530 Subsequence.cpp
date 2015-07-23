/* 14023265	2015-07-15 19:53:31	Accepted	3530	280MS	2776K	1204 B	C++	Shark */
#include<bits\stdc++.h>
#define MAXN 100005
using namespace std;
int n, m, k;
int a[100005];
deque<int> Qmax, Qmin;
int main(){
  while (scanf("%d%d%d", &n, &m, &k) == 3){
    for (int i = 1; i <= n; i++)
      scanf("%d", a + i);
    int ans = 0;
    Qmax.clear(), Qmin.clear();
    for (int i = 1, j = 0; i <= n; i++){
      while (!Qmax.empty() && a[Qmax.back()] <= a[i]) Qmax.pop_back();
      Qmax.push_back(i);
      while (!Qmin.empty() && a[Qmin.back()] >= a[i]) Qmin.pop_back();
      Qmin.push_back(i);
      while (!Qmax.empty() && !Qmin.empty() && a[Qmax.front()] - a[Qmin.front()] > k){
        if (Qmax.front() < Qmin.front())
          j = Qmax.front(), Qmax.pop_front();
        else
          j = Qmin.front(), Qmin.pop_front();
      }
      if (!Qmax.empty() && !Qmin.empty() && a[Qmax.front()] - a[Qmin.front()] >= m)
        ans = max(ans, i - j);
    }
    printf("%d\n", ans);
  }
  return 0;
}
/*

Subsequence

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 4980    Accepted Submission(s): 1649

Problem Description
There is a sequence of integers. Your task is to find the longest subsequence that satisfies the following condition: the difference between the maximum element and the minimum element of the subsequence is no smaller than m and no larger than k.

Input
There are multiple test cases.
For each test case, the first line has three integers, n, m and k. n is the length of the sequence and is in the range [1, 100000]. m and k are in the range [0, 1000000]. The second line has n integers, which are all in the range [0, 1000000].
Proceed to the end of file.

Output
For each test case, print the length of the subsequence on a single line.

Sample Input
5 0 0
1 1 1 1 1
5 0 3
1 2 3 4 5

Sample Output
5
4

Source
2010 ACM-ICPC Multi-University Training Contest¡]10¡^¡X¡XHost by HEU

Recommend
zhengfeng   |   We have carefully selected several similar problems for you:  3535 3529 3528 3527 3415 

*/