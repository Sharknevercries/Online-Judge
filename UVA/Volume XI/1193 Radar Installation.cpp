/* 14234400	1193	Radar Installation	Accepted	C++	0.019	2014-09-20 07:12:20 */
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
	double x;
	int id, type;
};
bool cmp(segment A, segment B){
	return A.x < B.x || (A.x == B.x && A.type < B.type);
}
segment P[2 * MAX_N];
bool used[MAX_N];
int main(){
	int n, r, c = 1;
	while (scanf("%d%d", &n, &r) == 2 && n && r){
		bool fail = false;
		for (int i = 0; i < n; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			double tmp = r*r - y*y;
			if (tmp >= 0){
				P[2 * i] = { x - sqrt((double)r*r - y*y), i, 0 };
				P[2 * i + 1] = { x + sqrt((double)r*r - y*y), i, 1 };
			}
			else
				fail = true;
		}
		if (fail){
			printf("Case %d: -1\n", c++);
			continue;
		}
		sort(P, P + 2 * n, cmp);
		memset(used, false, sizeof(used));
		int ans = 0;
		stack<int> S;
		for (int i = 0; i < 2 * n; i++){
			if (used[P[i].id])continue;
			if (P[i].type == 0)
				S.push(P[i].id);
			else{
				ans++;
				while (!S.empty()){
					used[S.top()] = true;
					S.pop();
				}
			}
		}
		printf("Case %d: %d\n", c++, ans);
	}
	return 0;
}
/*

Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d .

We use Cartesian coordinate system, defining the coasting is the x -axis. The sea side is above x -axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x -y coordinates.

\epsfbox{p2519.eps}
Input

The input consists of several test cases. The first line of each case contains two integers n (1$ \le$n$ \le$1000) and d , where n is the number of islands in the sea and d is the distance of coverage of the radar installation. This is followed by n lines each containing two integers representing the coordinate of the position of each island. Then a blank line follows to separate the cases.

The input is terminated by a line containing pair of zeros.

Output

For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. `-1' installation means no solution for that case.

Sample Input

3 2
1 2
-3 1
2 1

1 2
0 2

0 0
Sample Output

Case 1: 2
Case 2: 1

*/