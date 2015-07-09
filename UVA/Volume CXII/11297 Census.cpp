/* 14147226	11297	Census	Accepted	C++	0.196	2014-09-04 17:05:25 */
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
#define MAX_N 505
#define MAX_M 1000
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
int n, m, t;
int S[MAX_N][MAX_N];
int minV[MAX_N * 4][MAX_N * 4], maxV[MAX_N * 4][MAX_N * 4];
int L1, L2, R1, R2, v;
pair<int, int > ans;
void buildY(int rootX, int x, int L, int R, int rootY){
	if(L == R){
		if(x != NONE)
			minV[rootX][rootY] = maxV[rootX][rootY] = S[x][L];
		else{
			minV[rootX][rootY] = min(minV[rootX * 2][rootY], minV[rootX * 2 + 1][rootY]);
			maxV[rootX][rootY] = max(maxV[rootX * 2][rootY], maxV[rootX * 2 + 1][rootY]);
		}
	}
	else{
		int mid = (L + R) / 2;
		buildY(rootX, x, L, mid, rootY * 2);
		buildY(rootX, x, mid + 1, R, rootY * 2 + 1);
		maxV[rootX][rootY] = max(maxV[rootX][rootY * 2], maxV[rootX][rootY * 2 + 1]);
		minV[rootX][rootY] = min(minV[rootX][rootY * 2], minV[rootX][rootY * 2 + 1]);
	}
}
void buildX(int L, int R, int root){
	if(L == R)
		buildY(root, L, 1, m, 1);
	else{
		int mid = (L + R) / 2;
		buildX(L, mid, root * 2);
		buildX(mid + 1, R, root * 2 + 1);
		buildY(root, NONE, 1, m, 1);
	}
}
void updateY(int rootX, int x, int L, int R, int rootY){
	if (L == R){
		if (x != NONE)
			maxV[rootX][rootY] = minV[rootX][rootY] = v;
		else{
			maxV[rootX][rootY] = max(maxV[rootX * 2][rootY], maxV[rootX * 2 + 1][rootY]);
			minV[rootX][rootY] = min(minV[rootX * 2][rootY], minV[rootX * 2 + 1][rootY]);
		}
	}
	else{
		int mid = (L + R) / 2;
		if (mid >= L2)
			updateY(rootX, x, L, mid, rootY * 2);
		else
			updateY(rootX, x, mid + 1, R, rootY * 2 + 1);
		maxV[rootX][rootY] = max(maxV[rootX][rootY * 2], maxV[rootX][rootY * 2 + 1]);
		minV[rootX][rootY] = min(minV[rootX][rootY * 2], minV[rootX][rootY * 2 + 1]);
	}
}
void updateX(int L, int R, int root){
	if (L == R)
		updateY(root, L, 1, m, 1);
	else{
		int mid = (L + R) / 2;
		if (mid >= L1)
			updateX(L, mid, root * 2);
		else
			updateX(mid + 1, R, root * 2 + 1);
		updateY(root, NONE, 1, m, 1);
	}
}
void queryY(int rootX, int L, int R, int rootY){
	if (L >= R1&&R <= R2){
		ans.first = max(ans.first, maxV[rootX][rootY]);
		ans.second = min(ans.second, minV[rootX][rootY]);
	}
	else{
		int mid = (L + R) / 2;
		if (mid >= R1)	queryY(rootX, L, mid, rootY * 2);
		if (mid < R2)	queryY(rootX, mid + 1, R, rootY * 2 + 1);
	}
}
void queryX(int L, int R, int root){
	if (L >= L1&&R <= L2)
		queryY(root, 1, m, 1);
	else{
		int mid = (L + R) / 2;
		if (mid >= L1)	queryX(L, mid, root * 2);
		if (mid < L2)	queryX(mid + 1, R, root * 2 + 1);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &S[i][j]);
	buildX(1, n, 1);
	scanf("%d", &t);
	while (t--){
		char str[5];
		scanf("%s", str);
		if (str[0] == 'q'){
			scanf("%d%d%d%d", &L1, &R1, &L2, &R2);
			ans.first = -INF, ans.second = INF;
			queryX(1, n, 1);
			printf("%d %d\n", ans.first, ans.second);
		}
		else{
			scanf("%d%d%d", &L1, &L2, &v);
			updateX(1, n, 1);
		}
	}
	return 0;
}
/*


C. Census

Time Limit: 8 sec
Description

This year, there have been many problems with population calculations, since in some cities, there are many emigrants, or the population growth is very high. Every year the ACM (for Association for Counting Members) conducts a census in each region. The country is divided into N^2 regions, consisting of an N x N grid of regions. Your task is to find the least, and the greatest population in some set of regions. Since in a single year there is no significant change in the populations, the ACM modifies the population counts by some number of inhabitants.

The Input

In the first line you will find N (0 <= N <= 500), in following the N lines you will be given N numbers, which represent, the initial population of city C [i, j]. In the following line is the number Q (Q <= 40000), followed by Q lines with queries:

There are two possible queries:

- "x1 y1 x2 y2" which represent the coordinates of the upper left and lower right of where you must calculate the maximum and minimum change in population.

- "x y v" indicating a change of the population of city C [x, y] by value v.

The Output

For each query, "x1 y1 x2 y2" print in a single line the greatest and least amount of current population. Separated each output by a space.

Notice: There is only a single test case.

Sample Input	Sample Output
5 5
1 2 3 4 5
0 9 2 1 3
0 2 3 4 1
0 1 2 4 5
8 5 3 1 4
4
q 1 1 2 3
c 2 3 10
q 1 1 5 5
q 1 2 2 2
9 0
10 0
9 2
Problemsetter: Rodrigo Burgos Domínguez

*/