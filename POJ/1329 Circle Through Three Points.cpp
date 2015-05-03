/* 14137250	840502	1329	Accepted	160K	0MS	C++	4098B	2015-04-27 21:27:24 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
double isZero(const double &x){
	return fabs(x) <= EPS ? x : 0;
}
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
	double operator % (const Vector &a) {
		return x * a.x + y * a.y;
	}
	Vector operator / (double a){
		return Vector(x / a, y / a);
	}
	bool operator == (Vector &a) {
		return isZero(x - a.x) == 0 && isZero(y - a.y);
	}
	Vector unitVector(double a) {
		a /= sqrt(x*x + y*y);
		return Vector(x * a, y * a);
	}
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
	double length(){
		return sqrt(x*x + y*y);
	}
	Vector leftRotate(){
		return Vector(-y, x);
	}
};
// Line
struct Line{
	Vector a, b;
	Line(){}
	Line(Vector a, Vector b) :a(a), b(b){}
	int intersect(Line &s, Vector &v){
		double a1 = (b - a) * (s.a - a), a2 = (b - a) * (s.b - a);
		if (sign(a1) == 0 && sign(a2) == 0)	return 2; // coincide
		if (sign(a1 - a2) == 0)	return 0; // parallel
		v.x = (a2 * s.a.x - a1 * s.b.x) / (a2 - a1);
		v.y = (a2 * s.a.y - a1 * s.b.y) / (a2 - a1);
		return 1;
	}
};
// Segment
struct Segment{
	Vector a, b;
	Segment(){}
	Segment(Vector a, Vector b) :a(a), b(b){}
	bool intersect(Vector &p){
		return p.x >= min(a.x, b.x)
			&& p.x <= max(a.x, b.x)
			&& p.y >= min(a.y, b.y)
			&& p.y <= max(a.y, b.y);
	}
	bool intersect(Segment &s){
		return intersect(s.a)
			|| intersect(s.b)
			|| s.intersect(this->a)
			|| s.intersect(this->b);
	}
	int intersect(Segment &s, Vector &v){
		double c1 = (b - a)*(s.a - a);
		double c2 = (b - a)*(s.b - a);
		double c3 = (s.b - s.a) * (a - s.a);
		double c4 = (s.b - s.a) * (b - s.a);
		v.x = (c2 * s.a.x - c1 * s.b.x) / (c2 - c1);
		v.y = (c2 * s.a.y - c1 * s.b.y) / (c2 - c1);
		// not on the same line
		if (c1 * c2 < 0 && c3 * c4 < 0)	return 1;
		// on the same line, maybe coincide
		if (c1 == 0 && intersect(s.a))	return 2;
		if (c2 == 0 && intersect(s.b))	return 2;
		if (c3 == 0 && s.intersect(a))	return 2;
		if (c4 == 0 && s.intersect(b))	return 2;
		return 0;
	}
	Line perpendicularBisector(){
		Vector tmp = (a + b) / 2;
		Vector alpha = b - a;
		return Line(tmp, tmp + alpha.leftRotate());
	}
};
// Triangle
struct Triangle{
	Vector a, b, c;
	Triangle(){}
	Triangle(Vector a, Vector b, Vector c) :a(a), b(b), c(c){}
};
// Circle
struct Circle{
	Vector center;
	double r;
	Circle(){}
	Circle(Vector center, double r) :center(center), r(r){}
	Circle(Triangle t){
		Line a = Segment(t.a, t.b).perpendicularBisector();
		Line b = Segment(t.a, t.c).perpendicularBisector();
		a.intersect(b, center);
		r = center.distance(t.a);
	}
};
double square(double x){
	return x*x;
}
void print(Circle c){
	printf("(x ");
	putchar(c.center.x >= 0 ? '-' : '+');
	printf(" %.3lf)^2 + ", fabs(c.center.x));
	printf("(y ");
	putchar(c.center.y >= 0 ? '-' : '+');
	printf(" %.3lf)^2 = ", fabs(c.center.y));
	printf("%.3lf^2\n", c.r);
	// ---
	printf("x^2 + y^2 ");
	putchar(c.center.x > 0 ? '-' : '+');
	printf(" %.3lfx ", fabs(2 * c.center.x));
	putchar(c.center.y > 0 ? '-' : '+');
	printf(" %.3lfy ", fabs(2 * c.center.y));
	double t = square(c.center.x) + square(c.center.y) - square(c.r);
	putchar(t >= 0 ? '+' : '-');
	printf(" %.3lf = 0\n\n", fabs(t));
}
int main(){
	Vector a, b, c;
	while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6){
		Triangle tri = Triangle(a, b, c);
		Circle cir = Circle(tri);
		print(cir);
	}
	return 0;
}
/*

Circle Through Three Points
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 3552		Accepted: 1490
Description

Your team is to write a program that, given the Cartesian coordinates of three points on a plane, will find the equation of the circle through them all. The three points will not be on a straight line.
The solution is to be printed as an equation of the form
(x - h)^2 + (y - k)^2 = r^2				(1)

and an equation of the form
x^2 + y^2 + cx + dy - e = 0				(2)

Input

Each line of input to your program will contain the x and y coordinates of three points, in the order Ax, Ay, Bx, By, Cx, Cy. These coordinates will be real numbers separated from each other by one or more spaces.
Output

Your program must print the required equations on two lines using the format given in the sample below. Your computed values for h, k, r, c, d, and e in Equations 1 and 2 above are to be printed with three digits after the decimal point. Plus and minus signs in the equations should be changed as needed to avoid multiple signs before a number. Plus, minus, and equal signs must be separated from the adjacent characters by a single space on each side. No other spaces are to appear in the equations. Print a single blank line after each equation pair.
Sample Input

7.0 -5.0 -1.0 1.0 0.0 -6.0
1.0 7.0 8.0 6.0 7.0 -2.0
Sample Output

(x - 3.000)^2 + (y + 2.000)^2 = 5.000^2
x^2 + y^2 - 6.000x + 4.000y - 12.000 = 0

(x - 3.921)^2 + (y - 2.447)^2 = 5.409^2
x^2 + y^2 - 7.842x - 4.895y - 7.895 = 0
Source

Southern California 1989,UVA 190

*/