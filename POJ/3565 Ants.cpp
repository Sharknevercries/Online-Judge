/* 14220428	840502	3565	Accepted	444K	204MS	C++	2262B	2015-05-21 19:23:01 */
#include<bits\stdc++.h>
#define M 310
#define inf 0x3f3f3f3f
const double EPS = 1e-6;
int n, nx, ny;
int link[M];
double lx[M], ly[M], slack[M], w[M][M];
int visx[M], visy[M];
int sign(double x){
	return fabs(x) < EPS ? 0 : (x > 0 ? 1 : -1);
}
int DFS(int x)
{
	visx[x] = 1;
	for (int y = 1; y <= ny; y++)
	{
		if (visy[y])
			continue;
		double t = lx[x] + ly[y] - w[x][y];
		if (sign(t) == 0)
		{
			visy[y] = 1;
			if (link[y] == -1 || DFS(link[y]))
			{
				link[y] = x;
				return 1;
			}
		}
		else if (sign(slack[y] - t) > 0)
			slack[y] = t;
	}
	return 0;
}
int KM()
{
	int i, j;
	memset(link, -1, sizeof(link));
	memset(ly, 0, sizeof(ly));
	for (i = 1; i <= nx; i++)
		for (j = 1, lx[i] = -inf; j <= ny; j++)
			if (sign(w[i][j] - lx[i]) > 0)
				lx[i] = w[i][j];

	for (int x = 1; x <= nx; x++)
	{
		for (i = 1; i <= ny; i++)
			slack[i] = inf;
		while (1)
		{
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (DFS(x))     
				break;  
			double d = inf;
			for (i = 1; i <= ny; i++)
				if (!visy[i] && sign(d - slack[i]) > 0)
					d = slack[i];
			for (i = 1; i <= nx; i++)
				if (visx[i])
					lx[i] -= d;
			for (i = 1; i <= ny; i++)
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
		}
	}
	double res = 0;
	for (i = 1; i <= ny; i++)
		if (link[i] > -1)
			res += w[link[i]][i];
	return res;
}
double ax[105], ay[105];
double tx[105], ty[105];
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		nx = ny = n;
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", ax + i, ay + i);
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", tx + i, ty + i);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				w[i][j] = -sqrt((ax[i] - tx[j]) * (ax[i] - tx[j]) + (ay[i] - ty[j]) * (ay[i] - ty[j]));
		KM();
		int idx[105];
		for (int i = 1; i <= n; i++)
			idx[link[i]] = i;
		for (int i = 1; i <= n; i++)
			printf("%d\n", idx[i]);
	}
	return 0;
}
/*

Ants
Time Limit: 5000MS		Memory Limit: 65536K
Total Submissions: 4632		Accepted: 1450		Special Judge
Description

Young naturalist Bill studies ants in school. His ants feed on plant-louses that live on apple trees. Each ant colony needs its own apple tree to feed itself.

Bill has a map with coordinates of n ant colonies and n apple trees. He knows that ants travel from their colony to their feeding places and back using chemically tagged routes. The routes cannot intersect each other or ants will get confused and get to the wrong colony or tree, thus spurring a war between colonies.

Bill would like to connect each ant colony to a single apple tree so that all n routes are non-intersecting straight lines. In this problem such connection is always possible. Your task is to write a program that finds such connection.


On this picture ant colonies are denoted by empty circles and apple trees are denoted by filled circles. One possible connection is denoted by lines.

Input

The first line of the input file contains a single integer number n (1 ≤ n ≤ 100) — the number of ant colonies and apple trees. It is followed by n lines describing n ant colonies, followed by n lines describing n apple trees. Each ant colony and apple tree is described by a pair of integer coordinates x and y (−10 000 ≤ x, y ≤ 10 000) on a Cartesian plane. All ant colonies and apple trees occupy distinct points on a plane. No three points are on the same line.

Output

Write to the output file n lines with one integer number on each line. The number written on i-th line denotes the number (from 1 to n) of the apple tree that is connected to the i-th ant colony.

Sample Input

5
-42 58
44 86
7 28
99 34
-13 -59
-47 -44
86 74
68 -75
-68 60
99 -60
Sample Output

4
2
1
5
3
Source

Northeastern Europe 2007

*/