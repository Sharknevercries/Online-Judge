/* 14125128	840502	2546	Accepted	172K	16MS	C++	935B	2015-04-24 17:08:03 */
#include<bits\stdc++.h>
#define PI acos(-1.0)
using namespace std;
struct Circle{
	double x, y, r;
};
Circle a, b;
int main(){
	while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &a.r, &b.x, &b.y, &b.r) == 6){
		if (a.r < b.r)	swap(a, b);
		double res;
		double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
		if (a.r + b.r <= d)
			res = 0;
		else if (d <= a.r - b.r)
			res = PI * b.r * b.r;
		else{
			double alpha = acos((a.r*a.r + d*d - b.r*b.r) / (2 * a.r*d));
			double beta = acos((b.r*b.r + d*d - a.r*a.r) / (2 * b.r*d));
			res = alpha * a.r * a.r + beta * b.r * b.r - sin(alpha) * d * a.r;
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
/*

Circular Area
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 5288		Accepted: 2104
Description

Your task is to write a program, which, given two circles, calculates the area of their intersection with the accuracy of three digits after decimal point.
Input

In the single line of input file there are space-separated real numbers x1 y1 r1 x2 y2 r2. They represent center coordinates and radii of two circles.
Output

The output file must contain single real number - the area.
Sample Input

20.0 30.0 15.0 40.0 30.0 30.0
Sample Output

608.366
Source

Northeastern Europe 2000, Far-Eastern Subregion

*/