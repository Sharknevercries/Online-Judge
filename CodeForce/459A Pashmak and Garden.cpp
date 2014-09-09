/* 7455365	2014-08-15 19:40:17	Shark	A - Pashmak and Garden	GNU C++	Accepted	15 ms	0 KB */
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
int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4, s;
	while (scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4){
		bool found = false;
		if (x1 > x2 || (x1 == x2 && y1 > y2)){
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x1 == x2){
			s = abs(y1 - y2);
			if (x1 + s <= 1000)
				x3 = x4 = x1 + s, y3 = y1, y4 = y2, found = true;
			else if (x1 - s >= -1000)
				x3 = x4 = x1 - s, y3 = y1, y4 = y2, found = true;
		}
		else if (y1 == y2){
			s = abs(x1 - x2);
			if (y1 + s <= 1000)
				y3 = y4 = y1 + s, x3 = x1, x4 = x2, found = true;
			else if (y1 - s >= -1000)
				y3 = y4 = y1 - s, x3 = x1, x4 = x2, found = true;
		}
		else if (abs(x1 - x2) == abs(y1 - y2))
			x3 = x1, y3 = y2, x4 = x2, y4 = y1, found = true;
		if (found)
			printf("%d %d %d %d\n", x3, y3, x4, y4);
		else
			puts("-1");
	}
	return 0;
}
/*

A. Pashmak and Garden
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pashmak has fallen in love with an attractive girl called Parmida since one year ago...

Today, Pashmak set up a meeting with his partner in a romantic garden. Unfortunately, Pashmak has forgotten where the garden is. But he remembers that the garden looks like a square with sides parallel to the coordinate axes. He also remembers that there is exactly one tree on each vertex of the square. Now, Pashmak knows the position of only two of the trees. Help him to find the position of two remaining ones.

Input
The first line contains four space-separated x1, y1, x2, y2 ( - 100 ≤ x1, y1, x2, y2 ≤ 100) integers, where x1 and y1 are coordinates of the first tree and x2 and y2 are coordinates of the second tree. It's guaranteed that the given points are distinct.

Output
If there is no solution to the problem, print -1. Otherwise print four space-separated integers x3, y3, x4, y4 that correspond to the coordinates of the two other trees. If there are several solutions you can output any of them.

Note that x3, y3, x4, y4 must be in the range ( - 1000 ≤ x3, y3, x4, y4 ≤ 1000).

Sample test(s)
input
0 0 0 1
output
1 0 1 1
input
0 0 1 1
output
0 1 1 0
input
0 0 1 2
output
-1

*/