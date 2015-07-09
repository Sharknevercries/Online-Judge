/* 15519275	10167	Birthday Cake	Accepted	C++	0.012	2015-05-22 08:27:31 */
#include<bits\stdc++.h>
#define PI acos(-1.0)
using namespace std;
struct Point{
	double x, y;
};
int n;
Point P[105];
int main(){
	srand(time(0));
	while (scanf("%d", &n) == 1 && n) {
		n <<= 1;
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		int A, B;
		while (true){
			A = -500 + rand() % 1001;
			B = -500 + rand() % 1001;
			int cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < n; i++)
				if (A*P[i].x + B*P[i].y > 0)
					cnt1++;
				else if (A*P[i].x + B*P[i].y < 0)
					cnt2++;
			if (cnt1 == n / 2 && cnt2 == n / 2)
				break;
		}
		printf("%d %d\n", A, B);
	}
	return 0;
}
/*

Lucy and Lily are twins. Today is their birthday.
Mother buys a birthday cake for them. Now we put
the cake onto a Descartes coordinate. Its center is at
(0, 0), and the cake’s length of radius is 100.
There are 2N (N is a integer, 1 ≤ N ≤ 50) cherries
on the cake. Mother wants to cut the cake into two
halves with a knife (of course a beeline). The twins
would like to be treated fairly, that means, the shape
of the two halves must be the same (that means the
beeline must go through the center of the cake) , and
each half must have N cherrie(s). Can you help her?
Note: the coordinate of a cherry (x, y) are two integers.
You must give the line as form two integers A,
B (stands for Ax + By = 0) each number mustn’t in
[−500, 500]. Cherries are not allowed lying on the beeline.
For each dataset there is at least one solution.
Input
The input file contains several scenarios. Each of them consists of 2 parts:
The first part consists of a line with a number N, the second part consists of 2N lines, each line
has two number, meaning (x, y). There is only one space between two border numbers. The input file
is ended with N = 0.
Output
For each scenario, print a line containing two numbers A and B. There should be a space between
them. If there are many solutions, you can only print one of them.
Sample Input
2
-20 20
-30 20
-10 -50
10 -5
0
Sample Output
0 1

*/