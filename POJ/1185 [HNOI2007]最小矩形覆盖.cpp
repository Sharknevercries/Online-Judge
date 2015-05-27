/* 985991	840502	1185	Accepted	2840 kb	176 ms	C++/Edit	3748 B	2015-05-23 00:21:10 */
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
bool cmp(Vector A, Vector B){
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}
int n, m;
Vector P[50005];
Vector CH[50005];
Vector ta[4];
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
	m--;
}
void rectangleCover(){
	ans = 1e15;
	int a = 1, b = 1, p = 1;
	double L, R, D, H;
	for (int i = 0; i < m; i++){
		// ±ÛÂà¥d´ß
		D = CH[i].distance(CH[i + 1]);
		while (sign((CH[i + 1] - CH[i]) * (CH[p + 1] - CH[i]) - (CH[i + 1] - CH[i]) * (CH[p] - CH[i])) >= 0)	p = (p + 1) % m;
		while (sign((CH[i + 1] - CH[i]) % (CH[b + 1] - CH[i]) - (CH[i + 1] - CH[i]) % (CH[b] - CH[i])) >= 0)	b = (b + 1) % m;
		if (i == 0)	a = b;	// first, set a
		while (sign((CH[i + 1] - CH[i]) % (CH[a + 1] - CH[i]) - (CH[i + 1] - CH[i]) % (CH[a] - CH[i])) <= 0)	a = (a + 1) % m;
		L = (CH[i + 1] - CH[i]) % (CH[a] - CH[i]) / D;
		R = (CH[i + 1] - CH[i]) % (CH[b] - CH[i]) / D;
		H = (CH[i + 1] - CH[i]) * (CH[p] - CH[i]) / D;
		if (H < 0)	H *= -1;
		if (ans > (R - L) * H){
			ans = (R - L)*H;
			ta[0] = CH[i] + (CH[i + 1] - CH[i]) * (R / D);
			ta[1] = ta[0] + (CH[b] - ta[0]) * (H / ta[0].distance(CH[b]));
			ta[2] = ta[1] - (ta[0] - CH[i]) * ((R - L) / CH[i].distance(ta[0]));
			ta[3] = ta[2] - (ta[1] - ta[0]);
		}
	}
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		getConvexHull();
		rectangleCover();
		int pi = 0;
		for (int i = 1; i < 4; i++)
			if (ta[i].y < ta[pi].y || (ta[i].y == ta[pi].y && ta[i].x < ta[pi].x))
				pi = i;
		printf("%.4lf\n", ans);
		for (int i = 0; i < 4; i++)
			printf("%.5lf %.5lf\n", ta[(pi + i) % 4].x, ta[(pi + i) % 4].y);
	}
	return 0;
}
/*

Plz go to website to see full problem description.

*/