/* 15511621	1249	Euclid	Accepted	C++	0.019	2015-05-20 15:38:18 */
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
		return sign(x - a.x) == 0 && sign(y - a.y) == 0;
	}
	double length(){
		return sqrt(x*x + y*y);
	}
	Vector unitVector(double a) {
		a /= length();
		return Vector(x, y) * a;
	}
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
	Vector leftRotate(double angle){
		return Vector(x * cos(angle) - y * sin(angle), x * sin(angle) + y*cos(angle));
	}
};
Vector A, B, C, D, E, F, G, H;
int main(){
	while (true){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y, &E.x, &E.y, &F.x, &F.y);
		if (A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0 && C.x == 0 && C.y == 0
			&& D.x == 0 && D.y == 0 && E.x == 0 && E.y == 0 && F.x == 0 && F.y == 0)
			break;
		double area = abs((E - D) * (F - D)) / 2.0;
		Vector ac = C - A, ab = B - A, p;
		p = ac * abs((area / (ab * ac)));
		H = A + p;
		G = B + p;
		printf("%.3lf %.3lf %.3lf %.3lf\n", G.x + EPS, G.y + EPS, H.x + EPS, H.y + EPS);
	}
	return 0;
}
/*

In one of his notebooks, Euclid gave a complex procedure for solving the following problem. With computers, perhaps there is an easier way.

In a 2D plane, consider a line segment AB, another point C which is not collinear with AB, and a triangle DEF. The goal is to find points G and H such that:


H is on the ray AC (it may be closer to A than C or further away, but angle CAB is the same as angle HAB)
ABGH is a parallelogram (AB is parallel to GH, AH is parallel to BG)
The area of parallelogram ABGH is the same as the area of triangle DEF
\epsfbox{p4601.eps}
Input

Input consists of multiple datasets. Each dataset will consist of twelve real numbers, with no more than 3 decimal places each, on a single line. Those numbers will represent the x and y coordinates of points A through F , as follows:


xA yA xB yB xC yC xD yD xE yE xF yF


Points A, B and C are guaranteed to not be collinear. Likewise, D, E and F are also guaranteed to be non-collinear. Every number is guaranteed to be in the range from -1000.0...1000.0 inclusive.

End of the input will be a line with twelve zero values (0.0).

Output

For each input set, print a single line with four floating point numbers. These represent points G and H, like this:


xG yG xH yH


Print all values to a precision of 3 decimal places (rounded, NOT truncated). Print a single space between numbers.

Sample Input

0 0 5 0 0 5 3 2 7 2 0 4
1.3 2.6 12.1 4.5 8.1 13.7 2.2 0.1 9.8 6.6 1.9 6.7
0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0
Sample Output

5.000 0.800 0.000 0.800
13.756 7.204 2.956 5.304

*/