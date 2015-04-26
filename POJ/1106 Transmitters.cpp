/* 14130384	840502	1106	Accepted	184K	0MS	C++	1400B	2015-04-25 22:50:25 */
#include<bits\stdc++.h>
#define PI acos(-1.0)
#define EPS 1e-12
using namespace std;
struct Point{
	double x, y;
};
Point cir;
double r;
Point P[1005];
pair<double, int> angle[1005];
int n;
double dist(Point p){
	return sqrt(p.x * p.x + p.y*p.y);
}
int main(){
	while (scanf("%lf%lf%lf", &cir.x, &cir.y, &r) == 3){
		if (r < 0)	break;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		for (int i = 0; i < n; i++)
			P[i].x -= cir.x, P[i].y -= cir.y;
		for (int i = 0; i < n; i++)
			angle[i].first = atan2(P[i].y, P[i].x), angle[i].second = i;
		for (int i = 0; i < n; i++)
			if (angle[i].first < 0)
				angle[i].first += 2 * PI;
		sort(angle, angle + n);
		for (int i = 0; i < n; i++)
			angle[i + n] = angle[i], angle[i + n].first += 2 * PI;
		int ans = 0, count = 0;
		for (int i = 0, j = 0; i < 2 * n; i++){
			while (angle[j].first + PI + EPS < angle[i].first)
				if (dist(P[angle[j++].second]) < r + EPS)
					count--;
			if (dist(P[angle[i].second]) < r + EPS)
				count++;
			if (i >= n)
				ans = max(ans, count);
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

Transmitters
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 4728		Accepted: 2523
Description

In a wireless network with multiple transmitters sending on the same frequencies, it is often a requirement that signals don't overlap, or at least that they don't conflict. One way of accomplishing this is to restrict a transmitter's coverage area. This problem uses a shielded transmitter that only broadcasts in a semicircle.

A transmitter T is located somewhere on a 1,000 square meter grid. It broadcasts in a semicircular area of radius r. The transmitter may be rotated any amount, but not moved. Given N points anywhere on the grid, compute the maximum number of points that can be simultaneously reached by the transmitter's signal. Figure 1 shows the same data points with two different transmitter rotations.


All input coordinates are integers (0-1000). The radius is a positive real number greater than 0. Points on the boundary of a semicircle are considered within that semicircle. There are 1-150 unique points to examine per transmitter. No points are at the same location as the transmitter.
Input

Input consists of information for one or more independent transmitter problems. Each problem begins with one line containing the (x,y) coordinates of the transmitter followed by the broadcast radius, r. The next line contains the number of points N on the grid, followed by N sets of (x,y) coordinates, one set per line. The end of the input is signalled by a line with a negative radius; the (x,y) values will be present but indeterminate. Figures 1 and 2 represent the data in the first two example data sets below, though they are on different scales. Figures 1a and 2 show transmitter rotations that result in maximal coverage.
Output

For each transmitter, the output contains a single line with the maximum number of points that can be contained in some semicircle.
Sample Input

25 25 3.5
7
25 28
23 27
27 27
24 23
26 23
24 29
26 29
350 200 2.0
5
350 202
350 199
350 198
348 200
352 200
995 995 10.0
4
1000 1000
999 998
990 992
1000 999
100 100 -2.5
Sample Output

3
4
4
Source

Mid-Central USA 2001

*/