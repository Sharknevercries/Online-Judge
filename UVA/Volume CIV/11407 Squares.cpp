/* 14222487	11407	Squares	Accepted	C++	0.022	2014-09-18 06:49:04 */
// C++
#include<iostream>
#include<stack>
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 10000
#define MAX_M 10000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
int DP[MAX_N + 5];
int main(){
	for (int i = 0; i <= MAX_N; i++)
		DP[i] = i;
	for (int i = 1; i <= MAX_N; i++)
		for (int j = 1; j <= sqrt((double)i); j++)
			DP[i] = min(DP[i], DP[i - j * j] + 1);
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		printf("%d\n", DP[n]);
	}
	return 0;
}
/*


Squares
For any positive integer N , N = a1$\scriptstyle \wedge$2 + a2$\scriptstyle \wedge$2 +...+ an$\scriptstyle \wedge$2 that is, any positive integer can be represented as sum of squares of other numbers.

Your task is to print the smallest `n ' such that N = a1$\scriptstyle \wedge$2 + a2$\scriptstyle \wedge$2 +...+ an$\scriptstyle \wedge$2 .

Input

The first line of the input will contain an integer `t ' which indicates the number of test cases to follow.

Each test case will contain a single integer `N ' (1$ \le$N$ \le$10000) on a line by itself.

Output

Print an integer which represents the smallest `n ' such that

N = a1$\scriptstyle \wedge$2 + a2$\scriptstyle \wedge$2 +...+ an$\scriptstyle \wedge$2 .


Explanation for sample test cases:


5 - > number of test cases

1 = 1$\scriptstyle \wedge$2 (1 term)

2 = 1$\scriptstyle \wedge$2 + 1$\scriptstyle \wedge$2 (2 terms)

3 = 1$\scriptstyle \wedge$2 + 1$\scriptstyle \wedge$2 + 1$\scriptstyle \wedge$2 (3 terms)

1 = 2$\scriptstyle \wedge$2 (1 term)

2 = 5$\scriptstyle \wedge$2 + 5$\scriptstyle \wedge$2 (2 terms)

Sample Input

5
1
2
3
4
50
Sample Output

1
2
3
1
2

*/