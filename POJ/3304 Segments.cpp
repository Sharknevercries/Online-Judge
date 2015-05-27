/* 14157919	840502	3304	Accepted	188K	47MS	C++	2749B	2015-05-03 23:29:25 */
#include<bits\stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-8;
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
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
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
};
int n;
Vector P[205];
Segment S[105];
bool solve(){
	for (int i = 0; i < 2 * n; i++){
		for (int j = i + 1; j < 2 * n; j++){
			if (P[i].distance(P[j]) < EPS)	continue;
			Vector v;
			Line L = Line(P[i], P[j]);
			bool flag = true;
			for (int k = 0; k < n && flag; k++){
				int res = L.intersect(Line(P[2 * k], P[2 * k + 1]), v);
				if (res == 2)	continue;
				if (res == 0)	flag = false;
				if (res == 1)
					flag &= S[k].intersect(v);
			}
			if (flag)
				return true;
		}
	}
	return false;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf", &P[i * 2].x, &P[i * 2].y, &P[2 * i + 1].x, &P[2 * i + 1].y);
		for (int i = 0; i < n; i++)
			S[i] = Segment(P[2 * i], P[2 * i + 1]);
		puts(solve() ? "Yes!" : "No!");
	}
	return 0;
}
/*

Segments
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 10328		Accepted: 3197
Description

Given n segments in the two dimensional space, write a program, which determines if there exists a line such that after projecting these segments on it, all projected segments have at least one point in common.

Input

Input begins with a number T showing the number of test cases and then, T test cases follow. Each test case begins with a line containing a positive integer n ≤ 100 showing the number of segments. After that, n lines containing four real numbers x1 y1 x2 y2 follow, in which (x1, y1) and (x2, y2) are the coordinates of the two endpoints for one of the segments.

Output

For each test case, your program must output "Yes!", if a line with desired property exists and must output "No!" otherwise. You must assume that two floating point numbers a and b are equal if |a - b| < 10-8.

Sample Input

3
2
1.0 2.0 3.0 4.0
4.0 5.0 6.0 7.0
3
0.0 0.0 0.0 1.0
0.0 1.0 0.0 2.0
1.0 1.0 2.0 1.0
3
0.0 0.0 0.0 1.0
0.0 2.0 0.0 3.0
1.0 1.0 2.0 1.0
Sample Output

Yes!
Yes!
No!
Source

Amirkabir University of Technology Local Contest 2006

*/