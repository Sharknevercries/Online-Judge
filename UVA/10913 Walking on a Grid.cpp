/* 14032271	10913	Walking on a Grid	Accepted	C++11	2.539	2014-08-13 08:56:35 */
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
#include<tuple>
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
#define MAX_N 80
#define MAX_M 10
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
typedef tuple<int, int, int, int> P;
int n, m;
lli ans;
int T[MAX_N][MAX_N];
int W[MAX_N][MAX_N][MAX_M][4];
bool V[MAX_N][MAX_N];
bool cmp(P A, P B){
	return get<3>(A) > get<3>(B);
}
void DFS(pair<int, int> s, int neg, lli sum){
	if (neg > m)	return;
	if (s.first == n - 1 && s.second == n - 1){
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i < 4; i++){
		int nextX = s.first + mx[i], nextY = s.second + my[i];
		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || V[nextY][nextX])
			continue;
		V[nextY][nextX] = true;
		if (T[nextY][nextX] >= 0 && T[nextY][nextX] + sum > W[nextY][nextX][neg][i]){
			W[nextY][nextX][neg][i] = T[nextY][nextX] + sum;
			DFS(make_pair(nextX, nextY), neg, sum + T[nextY][nextX]);
		}
		else if (T[nextY][nextX] < 0 && T[nextY][nextX] + sum > W[nextY][nextX][neg + 1][i]){
			W[nextY][nextX][neg + 1][i] = T[nextY][nextX] + sum;
			DFS(make_pair(nextX, nextY), neg + 1, sum + T[nextY][nextX]);
		}
		V[nextY][nextX] = false;
	}
}
int main(){
	int c = 1;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)	break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &T[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k <= m; k++)
					for (int dir = 0; dir < 4; dir++)
						W[i][j][k][dir] = -INF;
		memset(V, false, sizeof(V));
		V[0][0] = true;
		ans = -INF;
		if (T[0][0] >= 0)
			DFS(make_pair(0, 0), 0, T[0][0]);
		else
			DFS(make_pair(0, 0), 1, T[0][0]);
		if (ans == -INF)
			printf("Case %d: impossible\n", c++);
		else
			printf("Case %d: %lld\n", c++, ans);
	}
	return 0;
}
/*

4th IIUC Inter-University Programming Contest, 2005

I

Walking on a Grid

Input: standard input
Output: standard output

Problemsetter: Sohel Hafiz

You will be given a square grid of size N × N. The top-left square has a coordinate of (1, 1) and that of bottom-right is (N, N). Your job is to walk from (1, 1) to (N, N). Very easy, right? That’s why you have to follow some rules when walking.

You can only move left, right or down.
(i, j-1) is left of (i, j), (i, j+1) is right of (i, j) and (i+1, j) is down of (i, j).
You can never move outside the grid.
You can not step on a cell more than once.
Every cell has an integer associated with it.
You have to make sure the sum of integers of the path is maximized.
You can step on at most k negative integers from source to destination.
Input

Each case will start with two integers N and k. N ≤ 75 and k ≤ 5. Each of the next N lines will contain N integers each given in row major order. That is, the first integer of the first row is (1, 1) and the last integer of last row is (N, N). Input terminates with two zeros on a line.

Output

For every case output the case number. If it’s not possible to reach the destination meeting the above rules then output “impossible”, else print the maximum sum of integers of the path.

Sample Input

Output for Sample Input

4 1
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1
4 0
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1
0 0

Case 1: 11
Case 2: impossible

*/