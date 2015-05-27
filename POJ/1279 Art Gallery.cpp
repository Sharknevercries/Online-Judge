/* 14148908	840502	1279	Accepted	284K	16MS	C++	3832B	2015-04-30 21:06:22 */
#include<bits\stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
double isZero(const double &x){
	return fabs(x) <= EPS ? x : 0;
}
int sign(double x){
	return fabs(x) < EPS ? 0 : (x > 0 ? 1 : -1);
}
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
	Vector leftRotate(double angle){
		return Vector(x * cos(angle) - y * sin(angle), x * sin(angle) + y*cos(angle));
	}
};
struct Line{
	double A, B, C;
	Vector a, b;
	Line(){}
	Line(Vector a, Vector b) :a(a), b(b){
		A = -(a.y - b.y);
		B = -(b.x - a.x);
		C = -(a.x * b.y - b.x * a.y);
	}
	double F(Vector p){
		return A * p.x + B * p.y + C;
	}
	double rang(){
		return atan2(B, A);
	}
	double dist(){
		return C / sqrt(A*A + B*B);
	}
	int intersect(Line s, Vector &v){
		double a1 = (b - a) * (s.a - a), a2 = (b - a) * (s.b - a);
		if (sign(a1) == 0 && sign(a2) == 0)	return 2; // coincide
		if (sign(a1 - a2) == 0)	return 0; // parallel
		v.x = (a2 * s.a.x - a1 * s.b.x) / (a2 - a1);
		v.y = (a2 * s.a.y - a1 * s.b.y) / (a2 - a1);
		return 1;
	}
};
Vector P[2005], c[2005], d[2005];
Line L[2005], b[2005];
bool cmp(Line a, Line b){
	if (sign(a.rang() - b.rang()) != 0)
		return a.rang() < b.rang();
	else
		return a.dist() < b.dist();
}
int half_plane_cross(Line *a, int n, Vector *p){
	sort(a + 1, a + 1 + n, cmp);
	int newN = 1;
	for (int i = 2; i <= n; i++){
		if (sign(a[i].rang() - a[i - 1].rang()) != 0)	a[++newN] = a[i];
		if (sign(a[newN].A) == 0 && sign(a[newN].B) == 0)
			if (sign(a[newN].C) == 1)
				newN--;
			else
				return -1;
	}
	n = newN;
	int L = 0, R = 1;
	b[0] = a[1], b[1] = a[2], b[1].intersect(b[0], c[1]);
	for (int i = 3; i <= n; i++){
		while (L < R && sign(a[i].F(c[R])) < 0)	R--;
		while (L < R && sign(a[i].F(c[L + 1])) < 0) L++;
		b[++R] = a[i];
		b[R].intersect(b[R - 1], c[R]);
	}
	while (L < R && sign(b[L].F(c[R])) < 0)	R--;
	while (L < R && sign(b[R].F(c[L + 1])) < 0) L++;
	if (L + 1 >= R)	return -1;
	b[L].intersect(b[R], p[0]);
	for (int i = L; i < R; i++)
		p[i - L + 1] = c[i + 1];
	p[R - L + 1] = p[0];
	return R - L + 1;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		P[n + 1] = P[1];
		for (int i = 1; i <= n; i++)
			L[i] = Line(P[i], P[i + 1]);
		int m = half_plane_cross(L, n, d);
		if (m == -1)
			puts("0.00");
		else{
			double ans = 0;
			for (int i = 0; i < m; i++)
				ans += d[i] * d[i + 1];
			printf("%.2lf\n", ans / 2);
		}

	}
	return 0;
}
/*

Art Gallery
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 5796		Accepted: 2449
Description

The art galleries of the new and very futuristic building of the Center for Balkan Cooperation have the form of polygons (not necessarily convex). When a big exhibition is organized, watching over all of the pictures is a big security concern. Your task is that for a given gallery to write a program which finds the surface of the area of the floor, from which each point on the walls of the gallery is visible. On the figure 1. a map of a gallery is given in some co-ordinate system. The area wanted is shaded on the figure 2.

Input

The number of tasks T that your program have to solve will be on the first row of the input file. Input data for each task start with an integer N, 5 <= N <= 1500. Each of the next N rows of the input will contain the co-ordinates of a vertex of the polygon ? two integers that fit in 16-bit integer type, separated by a single space. Following the row with the co-ordinates of the last vertex for the task comes the line with the number of vertices for the next test and so on.
Output

For each test you must write on one line the required surface - a number with exactly two digits after the decimal point (the number should be rounded to the second digit after the decimal point).
Sample Input

1
7
0 0
4 4
4 7
9 7
13 -1
8 -6
4 -4
Sample Output

80.00
Source

Southeastern Europe 2002

*/