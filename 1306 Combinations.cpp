/* 14528541	840502	1306	Accepted	236K	0MS	C++	685B	2015-08-02 18:44:25 */
#include<bits\stdc++.h>
using namespace std;
unsigned long long C[105][105] = { 0 };
int main() {
  for (int i = 0; i <= 100; i++)
    C[i][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    if (n == 0 && k == 0)  break;
    printf("%d things taken %d at a time is %llu exactly.\n", n, k, C[n][k]);
  }
  return 0;
}
/*

Combinations
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 8807		Accepted: 4101
Description

Computing the exact number of ways that N things can be taken M at a time can be a great challenge when N and/or M become very large. Challenges are the stuff of contests. Therefore, you are to make just such a computation given the following:
GIVEN: 5 <= N <= 100; 5 <= M <= 100; M <= N
Compute the EXACT value of: C = N! / (N-M)!M!
You may assume that the final value of C will fit in a 32-bit Pascal LongInt or a C long. For the record, the exact value of 100! is:
93,326,215,443,944,152,681,699,238,856,266,700,490,715,968,264,381,621, 468,592,963,895,217,599,993,229,915,608,941,463,976,156,518,286,253, 697,920,827,223,758,251,185,210,916,864,000,000,000,000,000,000,000,000
Input

The input to this program will be one or more lines each containing zero or more leading spaces, a value for N, one or more spaces, and a value for M. The last line of the input file will contain a dummy N, M pair with both values equal to zero. Your program should terminate when this line is read.
Output

The output from this program should be in the form:
N things taken M at a time is C exactly.
Sample Input

100  6
20  5
18  6
0  0
Sample Output

100 things taken 6 at a time is 1192052400 exactly.
20 things taken 5 at a time is 15504 exactly.
18 things taken 6 at a time is 18564 exactly.
Source

UVA Volume III 369

*/