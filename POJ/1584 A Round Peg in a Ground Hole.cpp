/* 14219685	840502	1584	Accepted	168K	0MS	C++	2906B	2015-05-21 16:20:41 */
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
};
// Segment
struct Segment{
	Vector a, b;
	Segment(){}
	Segment(Vector a, Vector b) :a(a), b(b){}
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
int n;
Circle peg;
Vector polygon[105];
int solve(){
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n - 2; i++){
		if ((polygon[i + 1] - polygon[i]) * (polygon[i + 2] - polygon[i]) < 0)	cnt1++;
		if ((polygon[i + 1] - polygon[i]) * (polygon[i + 2] - polygon[i]) > 0)	cnt2++;
	}
	if (cnt1 != 0 && cnt2 != 0)		return 0;
	cnt1 = cnt2 = 0;
	for (int i = 0; i < n - 1; i++){
		if ((polygon[i + 1] - polygon[i]) * (peg.center - polygon[i]) > 0)	cnt1++;
		if ((polygon[i + 1] - polygon[i]) * (peg.center - polygon[i]) < 0)	cnt2++;
	}
	if (cnt1 == 0 || cnt2 == 0){
		for (int i = 0; i < n - 1; i++)
			if (sign(Segment(polygon[i + 1], polygon[i]).distance(peg.center) - peg.r) < 0)
				return 1;
		return 2;
	}
	else
		return 1;
}
int main(){
	while (scanf("%d", &n) == 1 && n >= 3){
		scanf("%lf%lf%lf", &peg.r, &peg.center.x, &peg.center.y);
		for (int i = 0; i < n;i++)
			scanf("%lf%lf", &polygon[i].x, &polygon[i].y);
		polygon[n++] = polygon[0];
		int res = solve();
		switch (res){
		case 0:	puts("HOLE IS ILL-FORMED");	break;
		case 1:	puts("PEG WILL NOT FIT");	break;
		case 2: puts("PEG WILL FIT");		break;
		}
	}
	return 0;
}
/*

A Round Peg in a Ground Hole
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 5505		Accepted: 1755
Description

The DIY Furniture company specializes in assemble-it-yourself furniture kits. Typically, the pieces of wood are attached to one another using a wooden peg that fits into pre-cut holes in each piece to be attached. The pegs have a circular cross-section and so are intended to fit inside a round hole.
A recent factory run of computer desks were flawed when an automatic grinding machine was mis-programmed. The result is an irregularly shaped hole in one piece that, instead of the expected circular shape, is actually an irregular polygon. You need to figure out whether the desks need to be scrapped or if they can be salvaged by filling a part of the hole with a mixture of wood shavings and glue.
There are two concerns. First, if the hole contains any protrusions (i.e., if there exist any two interior points in the hole that, if connected by a line segment, that segment would cross one or more edges of the hole), then the filled-in-hole would not be structurally sound enough to support the peg under normal stress as the furniture is used. Second, assuming the hole is appropriately shaped, it must be big enough to allow insertion of the peg. Since the hole in this piece of wood must match up with a corresponding hole in other pieces, the precise location where the peg must fit is known.
Write a program to accept descriptions of pegs and polygonal holes and determine if the hole is ill-formed and, if not, whether the peg will fit at the desired location. Each hole is described as a polygon with vertices (x1, y1), (x2, y2), . . . , (xn, yn). The edges of the polygon are (xi, yi) to (xi+1, yi+1) for i = 1 . . . n − 1 and (xn, yn) to (x1, y1).
Input

Input consists of a series of piece descriptions. Each piece description consists of the following data:
Line 1 < nVertices > < pegRadius > < pegX > < pegY >
number of vertices in polygon, n (integer)
radius of peg (real)
X and Y position of peg (real)
n Lines < vertexX > < vertexY >
On a line for each vertex, listed in order, the X and Y position of vertex The end of input is indicated by a number of polygon vertices less than 3.
Output

For each piece description, print a single line containing the string:
HOLE IS ILL-FORMED if the hole contains protrusions
PEG WILL FIT if the hole contains no protrusions and the peg fits in the hole at the indicated position
PEG WILL NOT FIT if the hole contains no protrusions but the peg will not fit in the hole at the indicated position
Sample Input

5 1.5 1.5 2.0
1.0 1.0
2.0 2.0
1.75 2.0
1.0 3.0
0.0 2.0
5 1.5 1.5 2.0
1.0 1.0
2.0 2.0
1.75 2.5
1.0 3.0
0.0 2.0
1
Sample Output

HOLE IS ILL-FORMED
PEG WILL NOT FIT
Source

Mid-Atlantic 2003

*/