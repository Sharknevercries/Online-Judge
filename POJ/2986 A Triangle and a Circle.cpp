/* 14126892	840502	2986	Accepted	168K	1407MS	C++	2933B	2015-04-24 22:58:43 */
#include<bits\stdc++.h>
#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;
struct Point{
	double x, y;
	Point(){}
	Point(double x, double y) :x(x), y(y){}
	Point operator +(const Point &a) const{
		return Point(x + a.x, y + a.y);
	}
	Point operator -(const Point &a) const{
		return Point(x - a.x, y - a.y);
	}
	Point operator *(const double &m) const{
		return Point(x * m, y * m);
	}
	Point operator /(const double &m) const{
		return Point(x / m, y / m);
	}
	double cross(const Point &a, const Point &b){
		return (a.x - x)*(b.y - y) - (a.y - y)*(b.x - x);
	}
	double length() const{
		return sqrt(x*x + y*y);
	}
	double distance(const Point &a) const{
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
};
Point P[50], circle;
double circleR;
double isZero(double x){
	return fabs(x) < EPS ? 0 : x;
}
double segment_cross_circle(Point p, Point q, double r, Point pp[]){
	double a = p.distance(q) * p.distance(q);
	Point tmp = q - p;
	double b = (tmp.x*p.x + tmp.y*p.y) * 2;
	double c = p.length() * p.length() - r*r;
	double D = b*b - 4 * a*c;
	D = isZero(D);
	if (D < 0)	return 0;
	D = sqrt(D);
	double x1 = (-b + D) / 2 / a;
	double x2 = (-b - D) / 2 / a;
	if (x1 > x2)	swap(x1, x2);
	int ptr = 0;
	if (isZero(x1) > 0 && isZero(x1 - 1) < 0)
		pp[ptr++] = Point(p.x + (q.x - p.x) * x1, p.y + (q.y - p.y) * x1);
	if (isZero(x2 - x1) != 0 && isZero(x2) > 0 && isZero(x2 - 1) < 0)
		pp[ptr++] = Point(p.x + (q.x - p.x) * x2, p.y + (q.y - p.y) * x2);
	return ptr;
}
double getArea(Point p[], int ptr, double r){
	double res = 0;
	for (int i = 1; i < ptr; i++){
		Point a = p[i - 1], b = p[i];
		if (isZero(a.distance(circle) - r) > 0 || isZero(b.distance(circle) - r) > 0){
			double angle = atan2(b.y, b.x) - atan2(a.y, a.x);
			while (isZero(angle - PI) > 0) angle -= PI * 2;
			while (isZero(angle + PI) < 0) angle += PI * 2;
			res += angle * r * r;
		}
		else
			res += circle.cross(a, b);
	}
	return res;
}
double triangle_cross_circle(Point a, Point b, double radius){
	Point q[2], pp[5];
	int ptr = 0, cnt;
	pp[ptr++] = a;
	cnt = segment_cross_circle(a, b, radius, q);
	for (int i = 0; i < cnt; i++)	pp[ptr++] = q[i];
	pp[ptr++] = b;
	return getArea(pp, ptr, radius);
}
int main(){
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &P[0].x, &P[0].y, &P[1].x, &P[1].y, &P[2].x, &P[2].y, &circle.x, &circle.y, &circleR) == 9){
		double ans = 0;
		for (int i = 0; i < 3; i++)
			P[i] = P[i] - circle;
		circle = circle - circle;
		for (int i = 0; i < 3; i++)
			ans += triangle_cross_circle(P[i], P[(i + 1) % 3], circleR);
		printf("%.2lf\n", fabs(ans)*0.5);
	}
	return 0;
}
/*

A Triangle and a Circle
Time Limit: 5000MS		Memory Limit: 131072K
Total Submissions: 2981		Accepted: 673		Special Judge
Description

Given one triangle and one circle in the plane. Your task is to calculate the common area of these two figures.

Input

The input will contain several test cases. Each line of input describes a test case. Each test case consists of nine floating point numbers, x1, y1, x2, y2, x3, y3, x4, y4 and r, where (x1, y1), (x2, y2) and (x3, y3) are the three vertices of the triangle and (x4, y4) is the center of the circle and r is the radius. We guarantee the triangle and the circle are not degenerate.

Output

For each test case you should output one real number, which is the common area of the triangle and the circle, on a separate line. The result should be rounded to two decimal places.

Sample Input

0 20 10 0 -10 0 0 0 10
Sample Output

144.35
Source

POJ Monthly--2006.08.27, Rainer

*/