/* 14144399	10036	Divisibility	Accepted	C++	0.085	2014-09-04 06:23:38 */
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
#define MAX_N 10005
#define MAX_M 105
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, k;
		int S[MAX_N];
		bool DP[2][MAX_M] = { false };
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		DP[0][0] = true;
		for (int i = 0; i < n; i++){
			memset(DP[(i + 1) % 2], false, sizeof(DP[(i + 1) % 2]));
			for (int j = 0; j < k; j++){
				int u = (j + S[i]) % k, v = (j - S[i]) % k;
				if (u < 0) u += k;
				if (v < 0) v += k;
				DP[(i + 1) % 2][u] |= DP[i % 2][j];
				DP[(i + 1) % 2][v] |= DP[i % 2][j];
			}
		}
		if (DP[n % 2][0])
			puts("Divisible");
		else
			puts("Not divisible");
	}
	return 0;
}
/*

Problem C: Divisibility

Consider an arbitrary sequence of integers. One can place + or - operators between integers in the sequence, thus deriving different arithmetical expressions that evaluate to different values. Let us, for example, take the sequence: 17, 5, -21, 15. There are eight possible expressions:
17	+	5	+	-21	+	15	=	16
17	+	5	+	-21	-	15	=	-14
17	+	5	-	-21	+	15	=	58
17	+	5	-	-21	-	15	=	28
17	-	5	+	-21	+	15	=	6
17	-	5	+	-21	-	15	=	-24
17	-	5	-	-21	+	15	=	48
17	-	5	-	-21	-	15	=	18
We call the sequence of integers divisible by K if + or - operators can be placed between integers in the sequence in such way that resulting value is divisible by K. In the above example, the sequence is divisible by 7 (17+5+-21-15=-14) but is not divisible by 5.

You are to write a program that will determine divisibility of sequence of integers.

Input

The first line of the input file contains a integer M indicating the number of cases to be analyzed. Then M couples of lines follow.
For each one of this couples, the first line contains two integers, N and K (1 <= N <= 10000, 2 <= K <= 100) separated by a space. The second line contains a sequence of N integers separated by spaces. Each integer is not greater than 10000 by it's absolute value.
Output

For each case in the input file, write to the output file the word "Divisible" if given sequence of integers is divisible by K or "Not divisible" if it's not.
Sample input

2
4 7
17 5 -21 15
4 5
17 5 -21 15
Sample Output

Divisible
Not divisible

*/