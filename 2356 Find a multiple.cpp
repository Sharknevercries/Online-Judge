/* 14528843	840502	2356	Accepted	268K	0MS	C++	835B	2015-08-02 20:01:33 */
#include<bits\stdc++.h>
using namespace std;
int sum[10005] = { 0 };
int mod[10005] = { 0 };
int w[10005];
void print(int L, int R) {
  printf("%d\n", R - L + 1);
  for (int i = L; i <= R; i++)
    printf("%d\n", w[i]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", w + i);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + w[i];
    if (sum[i] % n == 0) {
      print(1, i);
      break;
    }
    else if (mod[sum[i] % n] > 0) {
      print(mod[sum[i] % n] + 1, i);
      break;
    }
    else
      mod[sum[i] % n] = i;
  }
  return 0;
}
/*

Find a multiple
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 6741		Accepted: 2956		Special Judge
Description

The input contains N natural (i.e. positive integer) numbers ( N <= 10000 ). Each of that numbers is not greater than 15000. This numbers are not necessarily different (so it may happen that two or more of them will be equal). Your task is to choose a few of given numbers ( 1 <= few <= N ) so that the sum of chosen numbers is multiple for N (i.e. N * k = (sum of chosen numbers) for some natural number k).
Input

The first line of the input contains the single number N. Each of next N lines contains one number from the given set.
Output

In case your program decides that the target set of numbers can not be found it should print to the output the single number 0. Otherwise it should print the number of the chosen numbers in the first line followed by the chosen numbers themselves (on a separate line each) in arbitrary order.

If there are more than one set of numbers with required properties you should print to the output only one (preferably your favorite) of them.
Sample Input

5
1
2
3
4
1
Sample Output

2
2
3
Source

Ural Collegiate Programming Contest 1999

*/