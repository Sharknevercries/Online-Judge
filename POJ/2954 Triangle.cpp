/* 14219949	840502	2954	Accepted	168K	0MS	C++	1734B	2015-05-21 16:54:30 */
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
		return sign(x - a.x) == 0 && sign(y - a.y) == 0;
	}
};
double gcd(double a, double b){
	int aa = a + EPS, bb = b + EPS, r;
	do{
		r = aa % bb;
		aa = bb;
		bb = r;
	} while (r != 0);
	return aa;
}
double pointOnBound(Vector p){
	if (sign(p.x) == 0)	return abs(p.y);
	if (sign(p.y) == 0)	return abs(p.x);
	return gcd(abs(p.x), abs(p.y));
}
int main(){
	Vector a, b, c;
	while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6){
		if (a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0 && c.x == 0 && c.y == 0)	break;
		double area = abs((b - a) * (c - a)) / 2.0;
		printf("%d\n", (int)(area - (pointOnBound(a - b) + pointOnBound(b - c) + pointOnBound(c - a)) / 2 + 1));
	}
	return 0;
}
/*

Triangle
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 5377		Accepted: 2330
Description

A lattice point is an ordered pair (x, y) where x and y are both integers. Given the coordinates of the vertices of a triangle (which happen to be lattice points), you are to count the number of lattice points which lie completely inside of the triangle (points on the edges or vertices of the triangle do not count).

Input

The input test file will contain multiple test cases. Each input test case consists of six integers x1, y1, x2, y2, x3, and y3, where (x1, y1), (x2, y2), and (x3, y3) are the coordinates of vertices of the triangle. All triangles in the input will be non-degenerate (will have positive area), and −15000 ≤ x1, y1, x2, y2, x3, y3 ≤ 15000. The end-of-file is marked by a test case with x1 =  y1 = x2 = y2 = x3 = y3 = 0 and should not be processed.

Output

For each input case, the program should print the number of internal lattice points on a single line.

Sample Input

0 0 1 0 0 1
0 0 5 0 0 5
0 0 0 0 0 0
Sample Output

0
6
Source

Stanford Local 2004

*/