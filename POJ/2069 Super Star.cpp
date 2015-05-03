/* 14069658	840502	2069	Accepted	188K	282MS	C++	1369B	2015-04-10 20:11:54
 */
#include<bits\stdc++.h>
using namespace std;
struct Point{
	double x, y, z;
};
Point P[35];
Point ans;
int n;
inline double calDist(Point a, Point b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	double dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}
int main(){
	srand(time(0));
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &P[i].x, &P[i].y, &P[i].z);
		double dist = 0;
		int mi = -1;
		ans.x = (rand() % 1000 + 1) / 1000.0 * 100;
		ans.y = (rand() % 1000 + 1) / 1000.0 * 100;
		ans.z = (rand() % 1000 + 1) / 1000.0 * 100;
		for (int i = 0; i < n; i++)
			if (dist < calDist(ans, P[i]))
				dist = calDist(ans, P[i]), mi = i;
		double d = 100;
		while (d > 1e-8){
			for (int i = 0; i < 30; i++){
				ans.x += d * (P[mi].x - ans.x) / dist;
				ans.y += d * (P[mi].y - ans.y) / dist;
				ans.z += d * (P[mi].z - ans.z) / dist;
				dist = 0;
				for (int i = 0; i < n; i++)
					if (dist < calDist(ans, P[i]))
						dist = calDist(ans, P[i]), mi = i;
			}
			d *= 0.98;
		}
		printf("%.5lf\n", dist);
	}
	return 0;
}
/*

Super Star
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 3517		Accepted: 921		Special Judge
Description

During a voyage of the starship Hakodate-maru (see Problem 1406), researchers found strange synchronized movements of stars. Having heard these observations, Dr. Extreme proposed a theory of "super stars". Do not take this term as a description of actors or singers. It is a revolutionary theory in astronomy.
According to this theory, starts we are observing are not independent objects, but only small portions of larger objects called super stars. A super star is filled with invisible (or transparent) material, and only a number of points inside or on its surface shine. These points are observed as stars by us.

In order to verify this theory, Dr. Extreme wants to build motion equations of super stars and to compare the solutions of these equations with observed movements of stars. As the first step, he assumes that a super star is sphere-shaped, and has the smallest possible radius such that the sphere contains all given stars in or on it. This assumption makes it possible to estimate the volume of a super star, and thus its mass (the density of the invisible material is known).

You are asked to help Dr. Extreme by writing a program which, given the locations of a number of stars, finds the smallest sphere containing all of them in or on it. In this computation, you should ignore the sizes of stars. In other words, a star should be regarded as a point. You may assume the universe is a Euclidean space.
Input

The input consists of multiple data sets. Each data set is given in the following format.

n
x1 y1 z1
x2 y2 z2
. . .
xn yn zn

The first line of a data set contains an integer n, which is the number of points. It satisfies the condition 4 <= n <= 30.

The location of n points are given by three-dimensional orthogonal coordinates: (xi, yi, zi) (i = 1, ..., n). Three coordinates of a point appear in a line, separated by a space character. Each value is given by a decimal fraction, and is between 0.0 and 100.0 (both ends inclusive). Points are at least 0.01 distant from each other.

The end of the input is indicated by a line containing a zero.
Output

For each data set, the radius of the smallest sphere containing all given points should be printed, each in a separate line. The printed values should have 5 digits after the decimal point. They may not have an error greater than 0.00001.
Sample Input

4
10.00000 10.00000 10.00000
20.00000 10.00000 10.00000
20.00000 20.00000 10.00000
10.00000 20.00000 10.00000
4
10.00000 10.00000 10.00000
10.00000 50.00000 50.00000
50.00000 10.00000 50.00000
50.00000 50.00000 10.00000
0
Sample Output

7.07107
34.64102
Source

Japan 2001

*/