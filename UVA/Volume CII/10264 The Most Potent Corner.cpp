/* 13992896	10264	The Most Potent Corner	Accepted	C++	0.033	2014-08-05 07:04:58 */
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
#define MAX_N 1 << 18
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int W[MAX_N];
int S[MAX_N];
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		memset(S, 0, sizeof(S));
		for (int i = 0; i < (1 << n); i++)
			scanf("%d", W + i);
		for (int i = 0; i < (1 << n); i++){
			for (int j = 1; j < (1 << n); j <<= 1){
				if ((i & j) == 0){
					S[i] += W[i | j];
					S[i | j] += W[i];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << n); i++)
			for (int j = 1; j < (1 << n); j <<= 1)
				if ((i & j) == 0)
					ans = max(ans, S[i] + S[i | j]);
		printf("%d\n", ans);
	}
	return 0;
}
/*

Problem B: The Most Potent Corner

Problem

Every corner of the N-dimensional (1< N<15) unit cube has weight (some positive integer less than 256). We will call two corners neighbouring, if they have common edge. Potency of the corner is the sum of weights of all neighbouring corners. Weights of all the corners are given. You are to determine two neighbouring corners that have the maximum sum of potencies and to output this sum.

Input

The input will consist of several input blocks. Each input block begins with the integer N, the dimension of the cube. Then there are weights of the corners, one per line in the natural order: the first line contains the weight of the corner (0,...0,0,0), the second one - the weight of (0,...,0,0,1), then there is the weight of (0,...,0,1,0), then (0,...,0,1,1), then (0,...,1,0,0), the penultimate line contains the weight of the corner (1,...,1,1,0), the last one - (1,...,1,1,1).

The input is terminated by <EOF>.

Output

For each input block the output line should contain one number, the maximum potencies sum.

Sample Input

3
82
73
8
49
120
44
242
58
2
1
1
1
1
Sample Output

619
4

Sergey Karpovich, 2002

*/