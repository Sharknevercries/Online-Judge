/* 14180631	840502	1375	Accepted	200K	47MS	C++	3987B	2015-05-10 15:35:00 */
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
// Circle
struct Circle{
	Vector center;
	double r;
	Circle(){}
	Circle(Vector center, double r) :center(center), r(r){}
};
struct Segment{
	double L, R;
	Segment(){}
	Segment(double L, double R) :L(L), R(R){}
};
Vector light;
Circle cir[505];
Segment seg[505];
Line axisX;
bool cmp(Segment A, Segment B){
	return A.L < B.L;
}
void print(Segment res){
	if (res.L > 0)
		printf("%.2lf", res.L + EPS);
	else
		printf("%.2lf", res.L - EPS);
	if (res.R > 0)
		printf(" %.2lf\n", res.R + EPS);
	else
		printf(" %.2lf\n", res.R - EPS);
}
int main(){
	int n;
	axisX = Line(Vector(0, 0), Vector(1, 0));
	while (scanf("%d", &n) == 1 && n){
		scanf("%lf%lf", &light.x, &light.y);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &cir[i].center.x, &cir[i].center.y, &cir[i].r);
		for (int i = 0; i < n; i++){
			if (cir[i].r == 0)	continue;
			double d = light.distance(cir[i].center);
			double theta = asin(cir[i].r / d);
			Line a = Line(light, (cir[i].center - light).leftRotate(-theta) + light);
			Line b = Line(light, (cir[i].center - light).leftRotate(theta) + light);
			Vector u, v;
			a.intersect(axisX, u);
			b.intersect(axisX, v);
			seg[i] = Segment(u.x, v.x);
		}
		sort(seg, seg + n, cmp);
		Segment ans = seg[0];
		for (int i = 1; i < n; i++){
			if (cir[i].r == 0)	continue;
			if (sign(seg[i].L - ans.R) > 0){
				print(ans);
				ans = seg[i];
			}
			else
				ans.R = max(ans.R, seg[i].R);
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}
/*

Intervals
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 4101		Accepted: 1206
Description

In the ceiling in the basement of a newly open developers building a light source has been installed. Unfortunately, the material used to cover the floor is very sensitive to light. It turned out that its expected life time is decreasing dramatically. To avoid this, authorities have decided to protect light sensitive areas from strong light by covering them. The solution was not very easy because, as it is common, in the basement there are different pipelines under the ceiling and the authorities want to install the covers just on those parts of the floor that are not shielded from the light by pipes. To cope with the situation, the first decision was to simplify the real situation and, instead of solving the problem in 3D space, to construct a 2D model first.
Within this model, the x-axis has been aligned with the level of the floor. The light is considered to be a point light source with integer co-ordinates [bx,by]. The pipes are represented by circles. The center of the circle i has the integer co-ordinates [cxi,cyi] and an integer radius ri. As pipes are made from solid material, circles cannot overlap. Pipes cannot reflect the light and the light cannot go through the pipes. You have to write a program which will determine the non-overlapping intervals on the x-axis where there is, due to the pipes, no light from the light source.

Input

The input consists of blocks of lines, each of which except the last describes one situation in the basement. The first line of each block contains a positive integer number N < 500 expressing the number of pipes. The second line of the block contains two integers bx and by separated by one space. Each of the next N lines of the block contains integers cxi, cyi and ri, where cyi + ri < by. Integers in individual lines are separated by one space. The last block consists of one line containing n = 0.
Output

The output consists of blocks of lines, corresponding to the blocks in the input(except the last one). One empty line must be put after each block in the output. Each of the individual lines of the blocks in the output will contain two real numbers, the endpoints of the interval where there is no light from the given point light source. The reals are exact to two decimal places and separated by one space. The intervals are sorted according to increasing x-coordinate.
Sample Input

6
300 450
70 50 30
120 20 20
270 40 10
250 85 20
220 30 30
380 100 100
1
300 300
300 150 90
1
300 300
390 150 90
0
Sample Output

0.72 78.86
88.50 133.94
181.04 549.93

75.00 525.00

300.00 862.50
Source

Central Europe 1996

*/