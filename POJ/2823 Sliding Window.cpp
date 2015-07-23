/* 14381106	840502	2823	Accepted	22912K	6579MS	C++	1138B	2015-07-12 21:10:37 */
#include<bits\stdc++.h>
using namespace std;
typedef pair<int, int> PRII;
int n, m;
int a[1000005];
priority_queue<PRII, vector<PRII>, greater<PRII> > PQ1;
priority_queue<PRII, vector<PRII>, less<PRII> > PQ2;
int main(){
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= m - 1; i++)
    PQ1.push(PRII(a[i], i));
  for (int i = m; i <= n; i++){
    while (!PQ1.empty() && i - PQ1.top().second >= m) PQ1.pop();
    PQ1.push(PRII(a[i], i));
    printf("%d", PQ1.top().first);
    if (i < n)  putchar(' ');
  }
  putchar('\n');
  for (int i = 1; i <= m - 1; i++)
    PQ2.push(PRII(a[i], i));
  for (int i = m; i <= n; i++){
    while (!PQ2.empty() && i - PQ2.top().second >= m) PQ2.pop();
    PQ2.push(PRII(a[i], i));
    printf("%d", PQ2.top().first);
    if (i < n)  putchar(' ');
  }
  putchar('\n');
  return 0;
}
/*

Sliding Window
Time Limit: 12000MS		Memory Limit: 65536K
Total Submissions: 44162		Accepted: 13016
Case Time Limit: 5000MS
Description

An array of size n ≤ 106 is given to you. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves rightwards by one position. Following is an example:
The array is [1 3 -1 -3 5 3 6 7], and k is 3.
Window position	Minimum value	Maximum value
[1  3  -1] -3  5  3  6  7 	-1	3
1 [3  -1  -3] 5  3  6  7 	-3	3
1  3 [-1  -3  5] 3  6  7 	-3	5
1  3  -1 [-3  5  3] 6  7 	-3	5
1  3  -1  -3 [5  3  6] 7 	3	6
1  3  -1  -3  5 [3  6  7]	3	7
Your task is to determine the maximum and minimum values in the sliding window at each position.

Input

The input consists of two lines. The first line contains two integers n and k which are the lengths of the array and the sliding window. There are n integers in the second line.
Output

There are two lines in the output. The first line gives the minimum values in the window at each position, from left to right, respectively. The second line gives the maximum values.
Sample Input

8 3
1 3 -1 -3 5 3 6 7
Sample Output

-1 -3 -3 -3 3 3
3 3 5 5 6 7
Source

POJ Monthly--2006.04.28, Ikki

*/