/* 13918922	840502	2352	Accepted	1000K	407MS	G++	1045B	2015-02-28 17:40:42 */
#include<bits\stdc++.h>
#define N 15005
#define M 35000
using namespace std;
int n;
struct Point{
	int x, y;
};
Point P[N];
int ans[N], BIT[M];
bool cmp(Point A, Point B){
	return A.y < B.y || (A.y == B.y && A.x < B.x);
}
int query(int x){
	int res = 0;
	for (int i = x; i > 0; i -= (i&-i))
		res += BIT[i];
	return res;
}
void update(int x, int value){
	for (int i = x; i <= M; i += (i&-i))
		BIT[i] += value;
}
int main(){
	while (scanf("%d", &n) == 1){
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &P[i].x, &P[i].y), P[i].x++;
		sort(P + 1, P + 1 + n, cmp);
		for (int i = 1; i <= n; i++){
			ans[query(P[i].x)]++;
			update(P[i].x, 1);
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
/*

Stars
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 34888		Accepted: 15151
Description

Astronomers often examine star maps where stars are represented by points on a plane and each star has Cartesian coordinates. Let the level of a star be an amount of the stars that are not higher and not to the right of the given star. Astronomers want to know the distribution of the levels of the stars.


For example, look at the map shown on the figure above. Level of the star number 5 is equal to 3 (it's formed by three stars with a numbers 1, 2 and 4). And the levels of the stars numbered by 2 and 4 are 1. At this map there are only one star of the level 0, two stars of the level 1, one star of the level 2, and one star of the level 3.

You are to write a program that will count the amounts of the stars of each level on a given map.
Input

The first line of the input file contains a number of stars N (1<=N<=15000). The following N lines describe coordinates of stars (two integers X and Y per line separated by a space, 0<=X,Y<=32000). There can be only one star at one point of the plane. Stars are listed in ascending order of Y coordinate. Stars with equal Y coordinates are listed in ascending order of X coordinate.
Output

The output should contain N lines, one number per line. The first line contains amount of stars of the level 0, the second does amount of stars of the level 1 and so on, the last line contains amount of stars of the level N-1.
Sample Input

5
1 1
5 1
7 1
3 3
5 5
Sample Output

1
2
1
1
0
Hint

This problem has huge input data,use scanf() instead of cin to read data to avoid time limit exceed.
Source

Ural Collegiate Programming Contest 1999

*/