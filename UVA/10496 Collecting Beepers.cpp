/* 13881067	10496	Collecting Beepers	Accepted	C++	0.022	2014-07-14 09:08:03 */
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
#define MAX_N 13
#define MAX_M 1000
#define INF 1e9
#define NONE -1
const double PI = 2.0 * acos(0.0);
struct point{
	int x, y;
};
point P[MAX_N];
int W[MAX_N][MAX_N];
int DP[1 << MAX_N][MAX_N];
int n, m;
int dist(point A, point B){
	return abs(A.x - B.x) + abs(A.y - B.y);
}
int query(int s, int last){
	if (s == 0)	return DP[s][last];
	if (DP[s][last] != INF)	return DP[s][last];
	for (int i = 0; i <= n; i++){
		if (s & (1 << i)){
			int p = s ^ (1 << i);
			DP[s][last] = min(DP[s][last], query(p, i) + W[i][last]);
		}
	}
	return DP[s][last];
}
int main(){
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		scanf("%d%d", &n, &m);
		scanf("%d%d", &P[0].x, &P[0].y);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &P[i].x, &P[i].y);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				W[i][j] = dist(P[i], P[j]);
		for (int i = 0; i <= (1 << (n + 1)) - 1; i++)
			for (int j = 0; j <= n; j++)
				DP[i][j] = INF;
		DP[0][0] = 0;

		printf("The shortest path has length %d\n", query((1 << (n + 1)) - 1, 0));
	}
	return 0;
}
/*

Problem E
Collecting Beepers
Input: standard input
Output: standard output
Time Limit: 2 seconds

Karel is a robot who lives in a rectangular coordinate system where each place is designated by a set of integer coordinates (x and y). Your job is to design a program that will help Karel pick up a number of beepers that are placed in her world. To do so you must direct Karel to the position where each beeper is located. Your job is to write a computer program that finds the length of the shortest path that will get Karel from her starting position, to each of the beepers, and return back again to the starting position.

Karel can only move along the x and y axis, never diagonally. Moving from one position (i, j) to an adjacent position (i, j + 11), (i, j-1 ), (i-1, j), or (i+1, j), j) has a cost of one.

You can assume that Karel¡¦s world is never larger than 20 x _ 20 squares and that there will never be more than 10 beepers to pick up. Each coordinate will be given as a pair (x, y) ) where each value will be in the range 1 through the size of that particular direction of the coordinate system.

Input
First there will be a line containing the number of scenarios you are asked to help Karel in. For each scenario there will first be a line containing the size of the world. This will be given as two integers (x-size and y-size). Next there will be one line containing two numbers giving the starting position of Karel. On the next line there will be one number giving the number of beepers. For each beeper there will be a line containing two numbers giving the coordinates of each beeper.
Output

The output will be one line per scenario, giving the minimum distance that Karel has to move to get from her starting position to each of the beepers and back again to the starting position.
Sample Input

1
10 10
1 1
4
2 3
5 5
9 4
6 5
Sample Output

The shortest path has length 24
A Swedish Problem

*/