/* 14380453	840502	3017	Accepted	6624K	672MS	C++	1924B	2015-07-12 19:10:03 */
#include<bits\stdc++.h>
using namespace std;
struct Node{
  int L, R;
  long long int value;
};
int n;
Node T[400100];
long long m;
long long a[100005];
long long sum[100005]; 
long long DP[100005];
int Q[100005];
void build(int root, int L, int R){
  T[root].L = L, T[root].R = R;
  if (L == R)
    T[root].value = 1e15;
  else{
    int mid = (L + R) / 2;
    build(root * 2, L, mid);
    build(root * 2 + 1, mid + 1, R);
    T[root].value = min(T[root * 2].value, T[root * 2 + 1].value);
  }
}
void update(int root, int target, long long _value){ // degenerate to [t, t]
  if (T[root].L == target && T[root].R == target)
    T[root].value = _value;
  else{
    int mid = (T[root].L + T[root].R) / 2;
    if (target <= mid)
      update(root * 2, target, _value);
    else
      update(root * 2 + 1, target, _value);
    T[root].value = min(T[root * 2].value, T[root * 2 + 1].value);
  }
}
int main(){
  while (scanf("%d%lld", &n, &m) == 2){
    memset(sum, 0, sizeof(sum));
    bool flag = false;
    for (int i = 1; i <= n; i++){
      scanf("%lld", a + i);
      flag |= a[i] > m;
    }
    if (flag){
      puts("-1");
      continue;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i];
    int tail = 0, head = 1, L = 0;
    for (int i = 1; i <= n; i++){
      while (sum[i] - sum[L] > m) L++;
      while (head <= tail && Q[head] <= L) update(1, head++, 1e18);
      while (head <= tail && a[i] >= a[Q[tail]]) update(1, tail--, 1e18);
      Q[++tail] = i;
      if (head < tail)
        update(1, tail - 1, DP[Q[tail - 1]] + a[i]);
      DP[i] = min(DP[L] + a[Q[head]], T[1].value);
    }
    printf("%lld\n", DP[n]);
  }
  return 0;
}
/*

Cut the Sequence
Time Limit: 2000MS		Memory Limit: 131072K
Total Submissions: 9487		Accepted: 2806
Description

Given an integer sequence { an } of length N, you are to cut the sequence into several parts every one of which is a consecutive subsequence of the original sequence. Every part must satisfy that the sum of the integers in the part is not greater than a given integer M. You are to find a cutting that minimizes the sum of the maximum integer of each part.

Input

The first line of input contains two integer N (0 < N ≤ 100 000), M. The following line contains N integers describes the integer sequence. Every integer in the sequence is between 0 and 1 000 000 inclusively.

Output

Output one integer which is the minimum sum of the maximum integer of each part. If no such cuttings exist, output −1.

Sample Input

8 17
2 2 2 8 1 8 2 1
Sample Output

12
Hint

Use 64-bit integer type to hold M.

Source

POJ Monthly--2006.09.29, zhucheng

*/