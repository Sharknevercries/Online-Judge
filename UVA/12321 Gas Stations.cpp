/* 14234077	12321	Gas Stations	Accepted	C++	0.073	2014-09-20 05:41:26 */
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
#define MAX_M 1000
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
struct segment{
	int L, R;
};
bool cmp(segment A, segment B){
	return A.L < B.L || (A.L == B.L && A.R < B.R);
}
segment seg[MAX_N];
bool used[MAX_N];
int main(){
	int L, G;
	while (scanf("%d%d", &L, &G) == 2 && L && G){
		for (int i = 0; i < G; i++){
			int x, r;
			scanf("%d%d", &x, &r);
			seg[i] = segment{ x - r, x + r };
		}
		memset(used, false, sizeof(used));
		sort(seg, seg + G, cmp);
		int pos = 0, ptr = 0;
		while (pos < L && ptr < G){
			int maxR = NONE, p = NONE;
			for (; ptr < G && seg[ptr].L <= pos; ptr++)
				if (seg[ptr].R >= pos)
					if (maxR < seg[ptr].R)
						maxR = seg[ptr].R, p = ptr;
			if (maxR == NONE)	break;
			used[p] = true, pos = maxR;
		}
		if (pos < L)
			puts("-1");
		else{
			int cnt = 0;
			for (int i = 0; i < G; i++)
				if (!used[i])
					cnt++;
			printf("%d\n", cnt);
		}
	}
	return 0;
}
/*


Gas Stations
G gas stations are authorized to operate over a road of length L. Each gas station is able to sell fuel over a specific area of influence, defined as the closed interval  $ \left[\vphantom{x - r,x + r}\right.$x - r, x + r$ \left.\vphantom{x - r,x + r}\right]$, where x is the station's location on the road ( 0 $ \leq$ x $ \leq$ L) and r is its radius of coverage ( 0 < r $ \leq$ L). The points covered by a gas station are those within its radius of coverage.

It is clear that the areas of influence may interfere, causing disputes among the corresponding gas stations. It seems to be better to close some stations, trying to minimize such interferences without reducing the service availability along the road.


The owners have agreed to close some gas stations in order to avoid as many disputes as possible. You have been hired to write a program to determine the maximum number of gas stations that may be closed, so that every point on the road is in the area of influence of some remaining station. By the way, if some point on the road is not covered by any gas station, you must acknowledge the situation and inform about it.

Input

The input consists of several test cases. The first line of each test case contains two integer numbers L and G (separated by a blank), representing the length of the road and the number of gas stations, respectively ( 1 $ \leq$ L $ \leq$ 108, 1 $ \leq$ G $ \leq$ 104). Each one of the next G lines contains two integer numbers xi and ri (separated by a blank) where xi is the location and ri is the radius of coverage of the i-th gas station ( 0 $ \leq$ xi $ \leq$ L, 0 < ri $ \leq$ L). The last test case is followed by a line containing two zeros.

Output

For each test case, print a line with the maximum number of gas stations that can be eliminated, so that every point on the road belongs to the area of influence of some not closed station. If some point on the road is not covered by any of the initial G gas stations, print `-1' as the answer for such a case.

Sample Input

40 3
5 5
20 10
40 10
40 5
5 5
11 8
20 10
30 3
40 10
40 5
0 10
10 10
20 10
30 10
40 10
40 3
10 10
18 10
25 10
40 3
10 10
18 10
25 15
0 0
Sample Output

0
2
3
-1
1

*/