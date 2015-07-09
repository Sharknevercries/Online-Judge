/* 15492704	10180	Rope Crisis in Ropeland!	Accepted	C++	0.162	2015-05-16 16:47:35 */
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
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
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
	double distance(Vector p){
		if (sign((p - a) % (b - a)) < 0)	return p.distance(a);
		if (sign((p - b) % (a - b)) < 0)	return p.distance(b);
		return fabs((a - p)*(b - p)) / a.distance(b);
	}
};
// Circle
struct Circle{
	Vector center;
	double r;
	Circle(){}
	Circle(Vector center, double r) :center(center), r(r){}
};
inline double lowOfCosines(double a, double b, double c){
	return acos((a*a + b*b - c*c) / (2 * a*b));
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		Segment seg;
		Circle cir;
		scanf("%lf%lf%lf%lf%lf", &seg.a.x, &seg.a.y, &seg.b.x, &seg.b.y, &cir.r);
		cir.center = Vector(0, 0);
		double d = seg.distance(cir.center);
		if (seg.a == seg.b || sign(d - cir.r) >= 0)
			printf("%.3lf\n", seg.a.distance(seg.b));
		else{
			double ao = cir.center.distance(seg.a);
			double bo = cir.center.distance(seg.b);
			double ab = seg.a.distance(seg.b);
			double ap = sqrt(ao*ao - cir.r*cir.r);
			double bq = sqrt(bo*bo - cir.r*cir.r);
			double opq = lowOfCosines(ao, bo, ab) - lowOfCosines(ao, cir.r, ap) - lowOfCosines(bo, cir.r, bq);
			printf("%.3lf\n", ap + bq + opq*cir.r);
		}
	}
	return 0;
}
/*

This is a story of Ropeland where rope pulling is a very popular game (like cricket in Bangladesh).
Perhaps you know the game rope pulling: two groups of players hold two ends of a rope. When a certain
signal is given they start pulling ropes. The group that can snatch the rope from the other group is
declared winner. Today is a very happy day in Ropeland as they have got rope status (something
like Bangladeshs test status). So the people of Ropeland are on the street and they are willing to be
engaged in rope pulling. But the shops in the city fail to supply enough rope and so now a rope crisis
has begun. The King of the country declares a new rule that two groups will not be allowed to buy
more ropes than what they require.
The problem is that rope-pulling takes place in a large hall room that has a large round pillar in the
middle with certain radius. So if two groups are on the opposite side of the pillar their pulled rope is
never in a straight line. Given the position of the two groups you are to find out the minimum length
of rope required by them to start rope-pulling. You can assume that a point represents the position of
each group.
Fig 1: Situation when two groups have the round
pillar between them. The pulled rope is never a
straight line
Fig 2: Situation when the two
groups dont have the round pillar
between them
Input
The first line of the input file contains an integer N, which tells how many sets of input are there. Next
there are N lines of input.
Each line contains five numbers X1, Y1, X2, Y2 and R (> 0) where (X1, Y1) and (X2, Y2) are the
coordinates of the two groups and R is the radius of the pillar. The coordinate of the center of the
pillar is always the origin. You can also assume that none of the coordinates will be inside the circle.
All input numbers except N are floating point numbers and none of their absolute value is greater than
10000.
Output
For each set of input output a floating-point number in a new line rounded to the third digit after the
decimal point and this number denotes the minimum length of the rope required.
Sample Input
2
1 1 -1 -1 1
1 1 -1 1 1
Sample Output
3.571
2.000

*/