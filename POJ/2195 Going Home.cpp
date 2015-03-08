/* 13884346	840502	2195	Accepted	1212K	0MS	G++	2182B	2015-02-12 17:11:43 */
#include<bits\stdc++.h>
#define N 5005
#define INF 1e9
using namespace std;
struct Object{
	int x, y;
	Object(){}
	Object(int x, int y) :x(x), y(y){}
};
vector<Object> house, boy;
int n, m;
int w[N][N];
int lx[N], ly[N], match[N], slack[N];
bool vx[N], vy[N];
bool DFS(int u){
	vx[u] = true;
	for (int v = 0; v < m; v++){
		if (vy[v])continue;
		int t = lx[u] + ly[v] - w[u][v];
		if (t == 0){
			vy[v] = true;
			if (match[v] == -1 || DFS(match[v])){
				match[v] = u;
				return true;
			}
		}
		else
			slack[v] = min(slack[v], t);
	}
	return false;
}
int KM(){
	memset(match, -1, sizeof(match));
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			lx[i] = max(lx[i], w[i][j]);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			slack[j] = INF;
		while (true){
			memset(vx, false, sizeof(vx));
			memset(vy, false, sizeof(vy));
			if (DFS(i))break;
			int d = INF;
			for (int j = 0; j < m; j++)
				if (!vy[j])
					d = min(d, slack[j]);
			for (int j = 0; j < n; j++)
				if (vx[j])
					lx[j] -= d;
			for (int j = 0; j < m; j++)
				if (vy[j])
					ly[j] += d;
				else
					slack[j] -= d;
		}
	}
	int res = 0;
	for (int i = 0; i < m; i++)
		if (match[i] != -1)
			res += w[match[i]][i];
	return res;
}
int main(){
	int a, b;
	char S[105][105];
	while (scanf("%d%d", &a, &b) == 2 && a && b){
		for (int i = 0; i < a; i++)
			scanf("%s", S + i);
		house.clear();
		boy.clear();
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if (S[i][j] == 'H')
					house.push_back(Object(i, j));
				else if (S[i][j] == 'm')
					boy.push_back(Object(i, j));
		n = m = boy.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				w[i][j] = -(abs(house[i].x - boy[j].x) + abs(house[i].y - boy[j].y));
		printf("%d\n", -KM());
	}
	return 0;
}
/*

Description

On a grid map there are n little men and n houses. In each unit time, every little man can move one unit step, either horizontally, or vertically, to an adjacent point. For each little man, you need to pay a $1 travel fee for every step he moves, until he enters a house. The task is complicated with the restriction that each house can accommodate only one little man.

Your task is to compute the minimum amount of money you need to pay in order to send these n little men into those n different houses. The input is a map of the scenario, a '.' means an empty space, an 'H' represents a house on that point, and am 'm' indicates there is a little man on that point.


You can think of each point on the grid map as a quite large square, so it can hold n little men at the same time; also, it is okay if a little man steps on a grid with a house without entering that house.
Input

There are one or more test cases in the input. Each case starts with a line giving two integers N and M, where N is the number of rows of the map, and M is the number of columns. The rest of the input will be N lines describing the map. You may assume both N and M are between 2 and 100, inclusive. There will be the same number of 'H's and 'm's on the map; and there will be at most 100 houses. Input will terminate with 0 0 for N and M.
Output

For each test case, output one line with the single integer, which is the minimum amount, in dollars, you need to pay.
Sample Input

2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
Sample Output

2
10
28
Source

Pacific Northwest 2004

*/