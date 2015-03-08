/* 9528950	2015-01-23 21:30:57	Shark	507B - Amr and Pins	GNU C++	Accepted	46 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int main(){
	long long int r, x, y, xx, yy;
	double dist;
	scanf("%lld%lld%lld%lld%lld", &r, &x, &y, &xx, &yy);
	dist = sqrt((double)((x - xx)*(x - xx) + (y - yy)*(y - yy)));
	printf("%lld\n", (long long int)ceil(dist / (2 * r)));
	return 0;
}
/*

B. Amr and Pins
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Amr loves Geometry. One day he came up with a very interesting problem.

Amr has a circle of radius r and center in point (x, y). He wants the circle center to be in new position (x', y').

In one step Amr can put a pin to the border of the circle in a certain point, then rotate the circle around that pin by any angle and finally remove the pin.

Help Amr to achieve his goal in minimum number of steps.

Input
Input consists of 5 space-separated integers r, x, y, x' y' (1 ≤ r ≤ 105,  - 105 ≤ x, y, x', y' ≤ 105), circle radius, coordinates of original center of the circle and coordinates of destination center of the circle respectively.

Output
Output a single integer — minimum number of steps required to move the center of the circle to the destination point.

Sample test(s)
input
2 0 0 0 4
output
1
input
1 1 1 4 4
output
3
input
4 5 6 5 6
output
0
Note
In the first sample test the optimal way is to put a pin at point (0, 2) and rotate the circle by 180 degrees counter-clockwise (or clockwise, no matter).

*/