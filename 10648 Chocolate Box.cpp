/* 15878555	10648	Chocolate Box	Accepted	C++	0.013	2015-08-04 17:13:45 */
#include<bits\stdc++.h>
using namespace std;
int n, m;
double F(int x) { return (double)x / m; }
int main() {
  int c = 1;
  while (scanf("%d", &n) == 1) {
    if (n == -1) break;
    scanf("%d", &m);
    double DP[105][105] = { 0 };
    DP[1][1] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == 1 && j == 1)  continue;
        DP[i][j] = DP[i - 1][j] * F(j) + DP[i - 1][j - 1] * F(m - j + 1);
      }
    }
    printf("Case %d: %.7lf\n", c++, 1 - DP[n][m]);
  }
  return 0;
}
/*

Recently one of my friend Tarik became a member of the food committee of an ACM regional competition.
He has been given m distinguishable boxes, he has to put n types of chocolates in the boxes.
The probability that one chocolate is placed in a certain box is 1/m. What is the probability that one
or more boxes are empty?
At first he thought it as an easy task. But soon he found that it was much harder. So, he falls into
a great trouble and asked you to help him in this task.
Input
Each line of the input contains two integers n indicating total number of distinguishable types of
chocolate and m indicating total number of distinguishable boxes (m ? n < 100). A single line
containing ¡¥-1¡¦ denotes the end.
Output
For each of the cases you should calculate the probability corrected to seven decimal places. The output
format is shown below.
Sample Input
50 12
50 12
-1
Sample Output
Case 1: 0.1476651
Case 2: 0.1476651

*/