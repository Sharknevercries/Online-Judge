/* */
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
#define MAX_N 1005
#define MAX_M 1000
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
struct box{
	int w, load;
};
box B[MAX_N];
int main(){
	int n;
	while (scanf("%d" , &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%d%d", &B[i].w, &B[i].load);
		for (int i = 0, j = n - 1; i < j; i++, j--)
			swap(B[i], B[j]);
		int DP[MAX_N];
		for (int i = 0; i <= n; i++)
			DP[i] = INF;
		DP[0] = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j >= 1; j--)
				if (DP[j - 1] <= B[i].load)
					DP[j] = min(DP[j], DP[j - 1] + B[i].w);
		int ans = n;
		for (; DP[ans] == INF; ans--);
		printf("%d\n", ans);
	}
	return 0;
}
/*


Problem E: Boxes

The Problem

We have some boxes numbered 1 to N. The dimensions of all boxes are identical. Now we have to stack up some of the boxes, subject to the following constraints:

One cannot put more than one boxes directly upon a box;
Boxes with lower serial numbers are not to be put upon one with a higher number;
The weight and maximum load for each box are given. The total weight of all boxes upon a box should not exceed its maximum load.
Please write a program that finds the maximum number of boxes that can be stacked up according to the above constraints.

The Input

The first line of each set of input is an integer N (1 ≤ N ≤ 1000). This is followed by N lines, each with two integers, both ≤ 3000, representing the weight and maximum load of each box respectively.

Input ends with a case where N = 0.

The Output

Each line of your output should give the number of boxes that can be stacked up.

Sample Input

5
19 15
7 13
5 7
6 8
1 2
0
Sample Output

4

*/