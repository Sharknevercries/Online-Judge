/* 7271704	2014-07-28 00:34:58	Shark	452B - 4-point polyline	GNU C++	Accepted	15 ms	0 KB */
/*

Template By Shark

*/
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
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
struct point {
	int x, y;
	point(int _x, int _y){ x = _x, y = _y; }
	point(){}
};
double maxL;
vector<point> P;
vector<point> ans;
vector<point> tmp;
double dist(point A, point B){
	return sqrt((double)((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y)));
}
void DFS(int count){
	if (count == 4){
		double L = 0;
		for (int i = 1; i < 4; i++)
			L += dist(tmp[i - 1], tmp[i]);
		if (L > maxL){
			maxL = L;
			ans.clear();
			for (int i = 0; i < 4; i++)
				ans.push_back(tmp[i]);
		}
		return;
	}
	for (int i = 0, j; i < P.size(); i++){
		for (j = 0; j < tmp.size(); j++)
			if (tmp[j].x == P[i].x && tmp[j].y == P[i].y)
				break;
		if (j >= tmp.size()){
			tmp.push_back(P[i]);
			DFS(count + 1);
			tmp.erase(tmp.end() - 1);
		}
	}
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		maxL = -1;
		P.clear();
		P.push_back(point(0, 0));
		P.push_back(point(n, m));
		P.push_back(point(0, m));
		P.push_back(point(n, 0));
		if (n > 0)	P.push_back(point(n - 1, m));
		if (m > 0)	P.push_back(point(n, m - 1));
		if (n >= 1)	P.push_back(point(1, 0));
		if (m >= 1)	P.push_back(point(0, 1));
		DFS(0);
		for (int i = 0; i < 4; i++)
			printf("%d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
}
/*

B. 4-point polyline
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a rectangular grid of lattice points from (0, 0) to (n, m) inclusive. You have to choose exactly 4 different points to build a polyline possibly with self-intersections and self-touching. This polyline should be as long as possible.

A polyline defined by points p1, p2, p3, p4 consists of the line segments p1 p2, p2 p3, p3 p4, and its length is the sum of the lengths of the individual line segments.

Input
The only line of the input contains two integers n and m (0 ≤ n, m ≤ 1000). It is guaranteed that grid contains at least 4 different points.

Output
Print 4 lines with two integers per line separated by space — coordinates of points p1, p2, p3, p4 in order which represent the longest possible polyline.

Judge program compares your answer and jury's answer with 10 - 6 precision.

Sample test(s)
input
1 1
output
1 1
0 0
1 0
0 1
input
0 10
output
0 1
0 10
0 0
0 9

*/