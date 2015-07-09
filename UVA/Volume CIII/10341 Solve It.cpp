/* 14002681	10341	Solve It	Accepted	C++	0.112	2014-08-07 08:50:06 */
/* Template By Shark */
// C++
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-9
const double PI = 2.0 * acos(0.0);
// main
int p, q, r, s, t, u;
double formula(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t*x*x + u;
}
int main(){
	while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6){
		double L = 0, R = 1;
		bool found = false;
		while (R > L){
			double mid = (L + R) / 2;
			if (formula(mid) > EPS)
				L = mid;
			else if (formula(mid) < -EPS)
				R = mid;
			else{
				L = mid, found = true;	break;
			}
		}
		if (found)
			printf("%.4lf\n", L);
		else
			puts("No solution");
	}
	return 0;
}
/*

Problem F
Solve It
Input: standard input
Output: standard output
Time Limit: 1 second
Memory Limit: 32 MB
Solve the equation:
p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0
where 0 <= x <= 1.

Input

Input consists of multiple test cases and terminated by an EOF. Each test case consists of 6 integers in a single line: p, q, r, s, t and u (where 0 <= p,r <= 20 and -20 <= q,s,t <= 0). There will be maximum 2100 lines in the input file.

Output

For each set of input, there should be a line containing the value of x, correct upto 4 decimal places, or the string "No solution", whichever is applicable.

Sample Input

0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1
Sample Output

0.7071
No solution
0.7554
Mustaq Ahmed

*/