/* 14148584	840502	3384	Accepted	180K	0MS	C++	3547B	2015-04-30 19:55:15 */
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
int n;
double r;
Vector P[1005];
int ptr[2];
Vector plane[2][1005], t1, t2;
void translation(Vector &p1, Vector &p2, double d, Vector &q1, Vector &q2){
	q1 = p1 + (p2 - p1).leftRotate(PI / 2) * d / p1.distance(p2);
	q2 = q1 + p2 - p1;
}
int half_plane_cross(Vector *a, int n, Vector *b, Vector &p1, Vector &p2){
	int m = 0;
	for (int i = 0, j; i < n; i++){
		if (sign((p1 - a[i]) * (p2 - a[i])) >= 0)
			b[m++] = a[i];
		else{
			j = i - 1;
			if (j < 0)	j = n - 1;
			if (sign((p1 - a[j])*(p2 - a[j])) > 0)
				Line(p1, p2).intersect(Line(a[j], a[i]), b[m++]);
			j = i + 1;
			if (j == n)	j = 0;
			if (sign((p1 - a[j]) * (p2 - a[j])) > 0)
				Line(p1, p2).intersect(Line(a[j], a[i]), b[m++]);
		}
	}
	return m;
}
int main(){
	while (scanf("%d%lf", &n, &r) == 2){
		int o1, o2;
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		P[n] = P[0];
		ptr[0] = 4, o1 = 0;
		plane[0][0] = Vector(-1e3, -1e3);
		plane[0][1] = Vector(1e3, -1e3);
		plane[0][2] = Vector(1e3, 1e3);
		plane[0][3] = Vector(-1e3, 1e3);
		for (int i = 0; i < n; i++){
			o2 = o1 ^ 1;
			translation(P[i + 1], P[i], r, t1, t2);
			ptr[o2] = half_plane_cross(plane[o1], ptr[o1], plane[o2], t1, t2);
			o1 = o2;
		}
		double ans = -1;
		for (int i = 0; i < ptr[o1]; i++){
			for (int j = i; j < ptr[o1]; j++){
				double d = plane[o1][i].distance(plane[o1][j]);
				if (sign(d - ans) > 0)
					ans = d, t1 = plane[o1][i], t2 = plane[o1][j];
			}
		}
		printf("%.4lf %.4lf %.4lf %.4lf\n", t1.x, t1.y, t2.x, t2.y);
	}
	return 0;
}
/*

Feng Shui
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 4626		Accepted: 1419		Special Judge
Description

Feng shui is the ancient Chinese practice of placement and arrangement of space to achieve harmony with the environment. George has recently got interested in it, and now wants to apply it to his home and bring harmony to it.

There is a practice which says that bare floor is bad for living area since spiritual energy drains through it, so George purchased two similar round-shaped carpets (feng shui says that straight lines and sharp corners must be avoided). Unfortunately, he is unable to cover the floor entirely since the room has shape of a convex polygon. But he still wants to minimize the uncovered area by selecting the best placing for his carpets, and asks you to help.

You need to place two carpets in the room so that the total area covered by both carpets is maximal possible. The carpets may overlap, but they may not be cut or folded (including cutting or folding along the floor border) — feng shui tells to avoid straight lines.

Input

The first line of the input file contains two integer numbers n and r — the number of corners in George’s room (3 ≤ n ≤ 100) and the radius of the carpets (1 ≤ r ≤ 1000, both carpets have the same radius). The following n lines contain two integers xi and yi each — coordinates of the i-th corner (−1000 ≤ xi, yi ≤ 1000). Coordinates of all corners are different, and adjacent walls of the room are not collinear. The corners are listed in clockwise order.

Output

Write four numbers x1, y1, x2, y2 to the output file, where (x1, y1) and (x2, y2) denote the spots where carpet centers should be placed. Coordinates must be precise up to 4 digits after the decimal point.

If there are multiple optimal placements available, return any of them. The input data guarantees that at least one solution exists.

Sample Input

#1	5 2
-2 0
-5 3
0 8
7 3
5 0
#2	4 3
0 0
0 8
10 8
10 0
Sample Output

#1	-2 3 3 2.5
#2	3 5 7 3
Hint


Source

Northeastern Europe 2006, Northern Subregion

*/