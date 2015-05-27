/* 14196702	840502	1039	Accepted	168K	16MS	C++	2457B	2015-05-14 23:48:11 */
#include<bits\stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
int sign(double x){
	return fabs(x) < EPS ? 0 : (x > 0 ? 1 : -1);
}
// Vector
struct Vector{
	double x, y;
	Vector(){}
	Vector(double x, double y) :x(x), y(y){}
	Vector operator + (const Vector &a) {
		return Vector(x + a.x, y + a.y);
	}
	Vector operator - (const Vector &a) {
		return Vector(x - a.x, y - a.y);
	}
	double operator * (const Vector &a) {
		return x * a.y - y * a.x;
	}
	Vector operator * (const double &a){
		return Vector(x*a, y*a);
	}
	double operator % (const Vector &a) {
		return x * a.x + y * a.y;
	}
	Vector operator / (double a){
		return Vector(x / a, y / a);
	}
	bool operator == (Vector &a) {
		return sign(x - a.x) == 0 && sign(y - a.y);
	}
};
// Line
struct Line{
	Vector a, b;
	Line(){}
	Line(Vector a, Vector b) :a(a), b(b){}
	int intersect(Line s, Vector &v){
		double a1 = (b - a) * (s.a - a), a2 = (b - a) * (s.b - a);
		if (sign(a1) == 0 && sign(a2) == 0)	return 2; // coincide
		if (sign(a1 - a2) == 0)	return 0; // parallel
		v.x = (a2 * s.a.x - a1 * s.b.x) / (a2 - a1);
		v.y = (a2 * s.a.y - a1 * s.b.y) / (a2 - a1);
		return 1;
	}
};
double maxX;
Vector a[55], b[55];
int n;
bool judge(Vector p, Vector q, int k){
	int i, flag = 0;
	Vector v;
	for (i = 0; i < n - 1; i++){
		if ((a[i] - q)*(p - q) < 0 || (a[i + 1] - q)*(p - q) < 0){
			Line(p, q).intersect(Line(a[i], a[i + 1]), v);
			break;
		}
		if ((b[i] - q)*(p - q) > 0 || (b[i + 1] - q) * (p - q) > 0){
			Line(p, q).intersect(Line(b[i], b[i + 1]), v);
			break;
		}
	}
	if (i >= n - 1)	return true;
	if (i >= k)	maxX = max(maxX, v.x);
	return false;
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++){
			scanf("%lf%lf", &a[i].x, &a[i].y);
			b[i].x = a[i].x;
			b[i].y = a[i].y - 1;
		}
		bool flag = false;
		maxX = -1e15;
		for (int i = 0; i < n && !flag; i++){
			for (int j = i + 1; j < n && !flag; j++){
				flag |= judge(a[i], b[j], j);
				flag |= judge(b[i], a[j], j);
			}
		}
		if (flag)
			puts("Through all the pipe.");
		else
			printf("%.2lf\n", maxX);
	}
	return 0;
}
/*

Pipe
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 9511		Accepted: 2885
Description

The GX Light Pipeline Company started to prepare bent pipes for the new transgalactic light pipeline. During the design phase of the new pipe shape the company ran into the problem of determining how far the light can reach inside each component of the pipe. Note that the material which the pipe is made from is not transparent and not light reflecting.


Each pipe component consists of many straight pipes connected tightly together. For the programming purposes, the company developed the description of each component as a sequence of points [x1; y1], [x2; y2], . . ., [xn; yn], where x1 < x2 < . . . xn . These are the upper points of the pipe contour. The bottom points of the pipe contour consist of points with y-coordinate decreased by 1. To each upper point [xi; yi] there is a corresponding bottom point [xi; (yi)-1] (see picture above). The company wants to find, for each pipe component, the point with maximal x-coordinate that the light will reach. The light is emitted by a segment source with endpoints [x1; (y1)-1] and [x1; y1] (endpoints are emitting light too). Assume that the light is not bent at the pipe bent points and the bent points do not stop the light beam.
Input

The input file contains several blocks each describing one pipe component. Each block starts with the number of bent points 2 <= n <= 20 on separate line. Each of the next n lines contains a pair of real values xi, yi separated by space. The last block is denoted with n = 0.
Output

The output file contains lines corresponding to blocks in input file. To each block in the input file there is one line in the output file. Each such line contains either a real value, written with precision of two decimal places, or the message Through all the pipe.. The real value is the desired maximal x-coordinate of the point where the light can reach from the source for corresponding pipe component. If this value equals to xn, then the message Through all the pipe. will appear in the output file.
Sample Input

4
0 1
2 2
4 1
6 4
6
0 1
2 -0.6
5 -4.45
7 -5.57
12 -10.8
17 -16.55
0
Sample Output

4.67
Through all the pipe.
Source

Central Europe 1995

*/