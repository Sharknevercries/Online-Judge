/* 14188176	840502	1410	Accepted	164K	0MS	C++	2782B	2015-05-12 21:33:40 */
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
	bool intersect(Segment s){
		return intersect(s.a)
			|| intersect(s.b)
			|| s.intersect(this->a)
			|| s.intersect(this->b);
	}
	int intersect(Segment s, Vector &v){
		double c1 = (b - a)*(s.a - a);
		double c2 = (b - a)*(s.b - a);
		double c3 = (s.b - s.a) * (a - s.a);
		double c4 = (s.b - s.a) * (b - s.a);
		v.x = (c2 * s.a.x - c1 * s.b.x) / (c2 - c1);
		v.y = (c2 * s.a.y - c1 * s.b.y) / (c2 - c1);
		// 端點不共線
		if (c1 * c2 < 0 && c3 * c4 < 0)	return 1;
		// 端點共線
		if (c1 == 0 && intersect(s.a))	return 2;
		if (c2 == 0 && intersect(s.b))	return 2;
		if (c3 == 0 && s.intersect(a))	return 2;
		if (c4 == 0 && s.intersect(b))	return 2;
		// 不相交
		return 0;
	}
};
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		double x1, x2, y1, y2;
		Segment seg;
		Vector V[5], v;
		scanf("%lf%lf%lf%lf", &seg.a.x, &seg.a.y, &seg.b.x, &seg.b.y);
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		if (x1 > x2)	swap(x1, x2);
		if (y1 > y2)	swap(y1, y2);
		V[0] = Vector(x1, y2), V[2] = Vector(x2, y1);;
		V[1].x = V[2].x, V[1].y = V[0].y;
		V[3].x = V[0].x, V[3].y = V[2].y;
		V[4] = V[0];
		bool flag = false;
		for (int i = 0; i < 4; i++)
			flag |= seg.intersect(Segment(V[i], V[i + 1]), v) != 0;
		flag |= seg.a.x >= V[0].x && seg.a.x <= V[2].x && seg.a.y >= V[2].y && seg.a.y <= V[0].y;
		flag |= seg.b.x >= V[0].x && seg.b.x <= V[2].x && seg.b.y >= V[2].y && seg.b.y <= V[0].y;
		puts(flag ? "T" : "F");
	}
	return 0;
}
/*

Intersection
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 12345		Accepted: 3203
Description

You are to write a program that has to decide whether a given line segment intersects a given rectangle.

An example:
line: start point: (4,9)
end point: (11,2)
rectangle: left-top: (1,5)
right-bottom: (7,1)

Figure 1: Line segment does not intersect rectangle

The line is said to intersect the rectangle if the line and the rectangle have at least one point in common. The rectangle consists of four straight lines and the area in between. Although all input values are integer numbers, valid intersection points do not have to lay on the integer grid.
Input

The input consists of n test cases. The first line of the input file contains the number n. Each following line contains one test case of the format:
xstart ystart xend yend xleft ytop xright ybottom

where (xstart, ystart) is the start and (xend, yend) the end point of the line and (xleft, ytop) the top left and (xright, ybottom) the bottom right corner of the rectangle. The eight numbers are separated by a blank. The terms top left and bottom right do not imply any ordering of coordinates.
Output

For each test case in the input file, the output file should contain a line consisting either of the letter "T" if the line segment intersects the rectangle or the letter "F" if the line segment does not intersect the rectangle.
Sample Input

1
4 9 11 2 1 5 7 1
Sample Output

F
Source

Southwestern European Regional Contest 1995

*/