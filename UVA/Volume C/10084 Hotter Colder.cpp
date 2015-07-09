/* 15519197	10084	Hotter Colder	Accepted	C++	0.016	2015-05-22 08:06:38 */
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
	Vector a, b;
	Line(){}
	Line(Vector a, Vector b) :a(a), b(b){}
	Line(double a, double b, double c){
		if (sign(a) == 0)
			this->a = Vector(b < 0 ? -1 : 1, -c / b), this->b = Vector(b < 0 ? 1 : -1, -c / b);
		else if (sign(b) == 0)
			this->a = Vector(-c / a, a < 0 ? 1 : -1), this->b = Vector(-c / a, a < 0 ? -1 : 1);
		else if (b < 0)
			this->a = Vector(0, -c / b), this->b = Vector(1, -(a + c) / b);
		else
			this->a = Vector(1, -(a + c) / b), this->b = Vector(0, -c / b);
	}
	bool parallel(Line s){
		return sign((b - a) * (s.b - s.a)) == 0;
	}
	int intersect(Line s, Vector &v){
		double a1 = (b - a) * (s.a - a), a2 = (b - a) * (s.b - a);
		if (sign(a1) == 0 && sign(a2) == 0)	return 2; // coincide
		if (sign(a1 - a2) == 0)	return 0; // parallel
		v.x = (a2 * s.a.x - a1 * s.b.x) / (a2 - a1);
		v.y = (a2 * s.a.y - a1 * s.b.y) / (a2 - a1);
		return 1;
	}
	double angle(){
		return atan2(b.y - a.y, b.x - a.x);
	}
};
Line HP[205], b[205];
Vector P[205];
bool cmp(Line a, Line b){
	if (sign(a.angle() - b.angle()) == 0)
		return (a.a - a.b) * (b.a - a.b) > 0;
	return a.angle() < b.angle();
}
Vector intersection(Line a, Line b){
	Vector v;
	a.intersect(b, v);
	return v;
}
int half_plane_cross(Line *a, int n, Vector *p){
	sort(a, a + n, cmp);
	int L = 0, R = 1, m = 1;
	for (int i = 1; i < n; i++)
		if (sign(a[i].angle() - a[i - 1].angle()) > 0)
			a[m++] = a[i];
	n = m, m = 0;
	b[0] = a[0], b[1] = a[1];
	for (int i = 2; i < n; i++){
		if (b[R].parallel(b[R - 1]) || b[L].parallel(b[L + 1]))	break;
		while (L < R && (a[i].a - a[i].b) * (intersection(b[R], b[R - 1]) - a[i].b) > 0)	--R;
		while (L < R && (a[i].a - a[i].b) * (intersection(b[L], b[L + 1]) - a[i].b) > 0)	++L;
		b[++R] = a[i];
	}
	while (L < R && (b[L].a - b[L].b) * (intersection(b[R], b[R - 1]) - b[L].b) > 0)	--R;
	while (L < R && (b[R].a - b[R].b) * (intersection(b[L], b[L + 1]) - b[R].b) > 0)	++L;
	b[++R] = b[L];
	for (int i = L; i < R; i++)
		p[m++] = intersection(b[i], b[i + 1]);
	return m;
}
int main(){
	int n = 0;
	bool flag = false;
	char str[100];
	double x1, x2, y1, y2;
	HP[n++] = Line(Vector(0, 0), Vector(10, 0));
	HP[n++] = Line(Vector(10, 0), Vector(10, 10));
	HP[n++] = Line(Vector(10, 10), Vector(0, 10));
	HP[n++] = Line(Vector(0, 10), Vector(0, 0));
	x1 = y1 = 0;
	while (~scanf("%lf%lf%s", &x2, &y2, str)){
		double a = x1 - x2;
		double b = y1 - y2;
		double c = -(a * (x1 + x2) + b * (y1 + y2)) / 2;
		if (str[0] == 'C')
			HP[n++] = Line(-a, -b, -c);
		else if (str[0] == 'H')
			HP[n++] = Line(a, b, c);
		else
			flag = true;
		x1 = x2, y1 = y2;
		double ans = 0;
		if (!flag){
			int m = half_plane_cross(HP, n, P);
			if (m > 2){
				P[m] = P[0];
				for (int i = 0; i < m; i++)
					ans += P[i] * P[i + 1];
			}
		}
		printf("%.2lf\n", fabs(ans) / 2);
	}
	return 0;
}
/*

The children・s game Hotter Colder is played as follows. Player A leaves the room while player B hides
an object somewhere in the room. Player A re-enters at position (0,0) and then visits various other
positions about the room. When player A visits a new position, player B announces ：Hotter； if this
position is closer to the object than the previous position; player B announces ：Colder； if it is farther
and ：Same； if it is the same distance.
Input
Input consists of up to 50 lines, each containing an x, y coordinate pair followed by ．Hotter・, ．Colder・,
or ．Same・. Each pair represents a position within the room, which may be assumed to be a square with
opposite corners at (0,0) and (10,10).
Output
For each line of input print a line giving the total area of the region in which the object may have been
placed, to 2 decimal places. If there is no such region, output ．0.00・.
Sample Input
10.0 10.0 Colder
10.0 0.0 Hotter
0.0 0.0 Colder
10.0 10.0 Hotter
Sample Output
50.00
37.50
12.50
0.00

*/