/* 14025640	929	Number Maze	Accepted	C++11	2.315	2014-08-12 07:12:01 */
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
#define MAX_N 1000
#define MAX_M 1000
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
typedef tuple<int, int, int> point;
int W[MAX_N][MAX_N];
int S[MAX_N][MAX_N];
bool V[MAX_N][MAX_N];
int n, m;
bool cmp(point a, point b){
	return get<2>(a) > get<2>(b);
}
int Dijkstra(pair<int, int> source){
	memset(V, false, sizeof(V));
	priority_queue <point, vector<point>, function<bool(point, point)> > Q(cmp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			W[i][j] = INF;
	W[source.second][source.first] = S[source.second][source.first];
	Q.push(make_tuple(source.first, source.second, W[source.second][source.first]));
	while (!Q.empty()){
		point it = Q.top();	Q.pop();
		int curX = get<0>(it), curY = get<1>(it);
		if (curX == m - 1 && curY == n - 1)	return W[curY][curX];
		if (V[curY][curX])	continue;
		V[curY][curX] = true;
		for (int i = 0; i < 4; i++){
			int nextX = curX + mx[i], nextY = curY + my[i];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || V[nextY][nextX])
				continue;
			if (W[curY][curX] + S[nextY][nextX] < W[nextY][nextX]){
				W[nextY][nextX] = W[curY][curX] + S[nextY][nextX];
				Q.push(make_tuple(nextX, nextY, W[nextY][nextX]));
			}
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &S[i][j]);
		printf("%d\n", Dijkstra(make_pair(0, 0)));
	}
	return 0;
}
/*

http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=870

*/