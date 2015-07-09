/* 14012739	11094	Continents	Accepted	C++	0.016	2014-08-09 09:39:50 */
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
#define MAX_N 25
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct point{
	int x, y;
	point();
	point(int a, int b){ y = a, x = b; }
};
int n, m;
int x, y;
char T[MAX_N][MAX_N];
bool V[MAX_N][MAX_N];
char symbol;
int floodfill(point source){
	queue<point> Q;
	Q.push(source);
	V[source.y][source.x] = true;
	int count = 1;
	bool reside = false;
	while (!Q.empty()){
		point cur = Q.front();
		if (cur.y == y && cur.x == x)
			reside = true;
		Q.pop();
		for (int i = 0; i < 4; i++){
			point next = cur;
			next.x += mx[i], next.y += my[i];
			if (next.x < 0) next.x = m - 1;
			if (next.x >= m) next.x = 0;
			if (next.y < 0 || next.y >= n || T[next.y][next.x] != symbol)
				continue;
			if (!V[next.y][next.x])
				Q.push(next), V[next.y][next.x] = true, count++;
		}
	}
	if (reside)
		return 0;
	return count;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		memset(V, false, sizeof(V));
		for (int i = 0; i < n; i++)
			scanf("%s", T + i);
		scanf("%d%d", &y, &x);
		symbol = T[y][x];
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!V[i][j] && symbol == T[i][j])
					ans = max(ans, floodfill(point(i, j)));
		printf("%d\n", ans);
	}
	return 0;
}
/*

Problem A
Continents
Time Limit: 1 Second
Mijid the Great is the king of Dodars territory. He likes to travel between the cities in his territory and actually, you can never see him in the same city as where he was the day before. Therefore, he captured all territories of his continent! In spite of this fact, he has seen all cities of his territory so far and wants to capture another continent in order to have some choices to travel into new cities. Now, having the world map, he needs your help to find the biggest continent except the one in which he resides.

Maps are given as M x N tables, filled with at most two different letters denoting land and water regions. A continent is a set of connected land regions which is completely surrounded by water regions or the end of map. Two regions are assumed to be connected if they have an edge in common. The coordinates of top left region is (0,0) and bottom right region (M-1,N-1). Region with coordinates (x,N-1) should be assumed to  have a common edge with region (x,0) for every x between 0 and M-1 (inclusive).

Input
There will be several test cases. Each test case contains two integers M<=20 and N<=20 in the first line denoting the number of rows and columns in the map respectively. Next, there will be M lines of exactly N characters representing the map. Finally in the last line there would be two integers 0<=X<M and 0<=Y<N , the coordinates of the region in which Mijid the Great currently stays. There will one blank line after each test case.

Output
For each test case, output a line containing an integer that is the number of regions in the biggest continent that Mijid the Great can capture.

Sample Input                               Output for Sample Input
5 5
wwwww
wwllw
wwwww
wllww
wwwww
1 3

2
Problem setter: Hossein Azizpour
1st Amirkabir UT Annual Programming Contest  Qualification Round

*/