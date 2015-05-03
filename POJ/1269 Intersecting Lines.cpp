/* 14135877	840502	1269	Accepted	148K	0MS	C++	2164B	2015-04-27 16:45:05 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
double isZero(const double &x){
	return fabs(x) <= EPS ? x : 0;
}
int sign(double x){
	return fabs(x) < 1e-9 ? 0 : (x > 0 ? 1 : -1);
}
struct Vector{
	double x, y;
	Vector(){}
	Vector(double x, double y) :x(x), y(y){}
	Vector operator + (const Vector &a) const{
		return Vector(x + a.x, y + a.y);
	}
	Vector operator - (const Vector &a) const{
		return Vector(x - a.x, y - a.y);
	}
	double operator * (const Vector &a) const{
		return x * a.y - y * a.x;
	}
	double operator % (const Vector &a) const{
		return x * a.x + y * a.y;
	}
	bool operator == (const Vector &a) const{
		return isZero(x - a.x) == 0 && isZero(y - a.y);
	}
	Vector unitVector(double a) const{
		a /= sqrt(x*x + y*y);
		return Vector(x * a, y * a);
	}
	double distance(const Vector &a) const{
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
	double length(){
		return sqrt(x*x + y*y);
	}
};
struct Line{
	Vector a, b;
	Line(){}
	Line(Vector a, Vector b) :a(a), b(b){}
	int cross(Line &s, Vector &v){
		double a1 = (b - a) * (s.a - a), a2 = (b - a) * (s.b - a);
		if (sign(a1) == 0 && sign(a2) == 0)	return 2; // coincide
		if (sign(a1 - a2) == 0)	return 0; // parallel
		v.x = (a2 * s.a.x - a1 * s.b.x) / (a2 - a1);
		v.y = (a2 * s.a.y - a1 * s.b.y) / (a2 - a1);
		return 1;
	}
};
int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	puts("INTERSECTING LINES OUTPUT");
	while (t--){
		Vector p[2][2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				scanf("%lf%lf", &p[i][j].x, &p[i][j].y);
		Line a = Line(p[0][0], p[0][1]);
		Line b = Line(p[1][0], p[1][1]);
		Vector q;
		int m = a.cross(b, q);
		if (m == 0)
			puts("NONE");
		else if (m == 2)
			puts("LINE");
		else
			printf("POINT %.2lf %.2lf\n", q.x, q.y);
	}
	puts("END OF OUTPUT");
	return 0;
}
/*

Intersecting Lines
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 11880		Accepted: 5330
Description

We all know that a pair of distinct points on a plane defines a line and that a pair of lines on a plane will intersect in one of three ways: 1) no intersection because they are parallel, 2) intersect in a line because they are on top of one another (i.e. they are the same line), 3) intersect in a point. In this problem you will use your algebraic knowledge to create a program that determines how and where two lines intersect.
Your program will repeatedly read in four points that define two lines in the x-y plane and determine how and where the lines intersect. All numbers required by this problem will be reasonable, say between -1000 and 1000.
Input

The first line contains an integer N between 1 and 10 describing how many pairs of lines are represented. The next N lines will each contain eight integers. These integers represent the coordinates of four points on the plane in the order x1y1x2y2x3y3x4y4. Thus each of these input lines represents two lines on the plane: the line through (x1,y1) and (x2,y2) and the line through (x3,y3) and (x4,y4). The point (x1,y1) is always distinct from (x2,y2). Likewise with (x3,y3) and (x4,y4).
Output

There should be N+2 lines of output. The first line of output should read INTERSECTING LINES OUTPUT. There will then be one line of output for each pair of planar lines represented by a line of input, describing how the lines intersect: none, line, or point. If the intersection is a point then your program should output the x and y coordinates of the point, correct to two decimal places. The final line of output should read "END OF OUTPUT".
Sample Input

5
0 0 4 4 0 4 4 0
5 0 7 6 1 0 2 3
5 0 7 6 3 -6 4 -3
2 0 2 27 1 5 18 5
0 3 4 0 1 2 2 5
Sample Output

INTERSECTING LINES OUTPUT
POINT 2.00 2.00
NONE
LINE
POINT 2.00 5.00
POINT 1.07 2.20
END OF OUTPUT
Source

Mid-Atlantic 1996

*/