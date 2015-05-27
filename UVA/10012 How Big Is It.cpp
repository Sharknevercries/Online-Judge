/* 15512096	10012	How Big Is It?	Accepted	C++	0.139	2015-05-20 17:24:35
 */
#include<bits\stdc++.h>
using namespace std;
struct Vector{
	double x, y;
	Vector(){}
	Vector(double x, double y) :x(x), y(y){}
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
};
Vector p[10];
double r[10];
int idx[10];
int n;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		double ans = 1e9;
		for (int i = 0; i < n; i++)
			scanf("%lf", r + i), idx[i] = i;
		do{
			double rr[10], l = 0;
			for (int i = 0; i < n; i++)
				rr[i] = r[idx[i]];
			p[0] = Vector(rr[0], rr[0]);
			l = max(p[0].x + rr[0], l);
			for (int i = 1; i < n; i++){
				p[i] = Vector(rr[i], rr[i]);
				for (int j = i - 1; j >= 0; j--)
					p[i].x = max(p[i].x, p[j].x + 2 * sqrt(rr[i] * rr[j]));
				l = max(p[i].x + rr[i], l);
				if (l > ans)	break;
			}
			ans = min(ans, l);
		} while (next_permutation(idx, idx + n));
		printf("%.3lf\n", ans);
	}
	return 0;
}
/*

Ian’s going to California, and he has to pack his things, including his collection of circles. Given a set
of circles, your program must find the smallest rectangular box in which they fit.
All circles must touch the bottom of the box. The figure below shows an acceptable packing for a
set of circles (although this may not be the optimal packing for these particular circles). Note that in
an ideal packing, each circle should touch at least one other circle (but you probably figured that out).
Input
The first line of input contains a single positive decimal integer n, n ≤ 50. This indicates the number
of lines which follow. The subsequent n lines each contain a series of numbers separated by spaces.
The first number on each of these lines is a positive integer m, m ≤ 8, which indicates how many other
numbers appear on that line. The next m numbers on the line are the radii of the circles which must
be packed in a single box. These numbers need not be integers.
Output
For each data line of input, excluding the first line of input containing n, your program must output
the size of the smallest rectangle which can pack the circles. Each case should be output on a separate
line by itself, with three places after the decimal point. Do not output leading zeroes unless the number
is less than 1, e.g. 0.543.
Sample Input
3
3 2.0 1.0 2.0
4 2.0 2.0 2.0 2.0
3 2.0 1.0 4.0
Sample Output
9.657
16.000
12.657

*/