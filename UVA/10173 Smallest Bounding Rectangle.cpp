/* 15521094	10173	Smallest Bounding Rectangle	Accepted	C++	0.035	2015-05-22 15:15:58 */
#include<bits\stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-6;
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
// Line
struct Line{
	Vector a, b;
	Line(){}
	Line(Vector a, Vector b) :a(a), b(b){}
	double distance(Vector p){
		return fabs((a - p)*(b - p)) / a.distance(b);
	}
};
bool cmp(Vector A, Vector B){
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}
int n, m;
Vector P[1005];
Vector CH[1005];
double ans;
void getConvexHull(){
	m = 0;
	sort(P, P + n, cmp);
	for (int i = 0; i < n; i++){
		while (m >= 2 && (CH[m - 1] - CH[m - 2]) * (P[i] - CH[m - 2]) <= 0)
			m--;
		CH[m++] = P[i];
	}
	for (int i = n - 2, j = m + 1; i >= 0; i--){
		while (m >= j && (CH[m - 1] - CH[m - 2]) * (P[i] - CH[m - 2]) <= 0)
			m--;
		CH[m++] = P[i];
	}
}
void rectangleCover(){
	ans = 1e15;
	for (int i = 0; i < m - 1; i++){
		double L = 1e15, R = -1e15, d = 0;
		for (int j = 0; j < m - 1; j++){
			d = max(d, Line(CH[i], CH[i + 1]).distance(CH[j]));
			double pos = (CH[i + 1] - CH[i]) % (CH[j] - CH[i]) / (CH[i + 1] - CH[i]).length();
			L = min(L, pos);
			R = max(R, pos);
		}
		ans = min(ans, (R - L) * d);
	}
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		if (n < 3){
			puts("0.0000");
			continue;
		}
		getConvexHull();
		rectangleCover();
		printf("%.4lf\n", ans);
	}
	return 0;
}
/*

Given the Cartesian coordinates of n (> 0) 2-dimensional points, write a program that computes the
area of their smallest bounding rectangle (smallest rectangle containing all the given points).
Input
The input file may contain multiple test cases. Each test case begins with a line containing a positive
integer n (< 1001) indicating the number of points in this test case. Then follows n lines each containing
two real numbers giving respectively the x- and y-coordinates of a point. The input terminates with a
test case containing a value 0 for n which must not be processed.
Output
For each test case in the input print a line containing the area of the smallest bounding rectangle
rounded to the 4th digit after the decimal point.
Sample Input
3
-3.000 5.000
7.000 9.000
17.000 5.000
4
10.000 10.000
10.000 20.000
20.000 20.000
20.000 10.000
0
Sample Output
80.0000
100.0000

*/