/* 14180847	840502	1066	Accepted	168K	32MS	C++	2833B	2015-05-10 16:17:30 */
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
	// not test yet
	int intersect(Segment s, Vector &v){
		double c1 = (b - a)*(s.a - a);
		double c2 = (b - a)*(s.b - a);
		double c3 = (s.b - s.a) * (a - s.a);
		double c4 = (s.b - s.a) * (b - s.a);
		v.x = (c2 * s.a.x - c1 * s.b.x) / (c2 - c1);
		v.y = (c2 * s.a.y - c1 * s.b.y) / (c2 - c1);
		// not on the same line
		if (c1 * c2 < 0 && c3 * c4 < 0)	return 1;
		// on the same line, maybe coincide
		if (c1 == 0 && intersect(s.a))	return 2;
		if (c2 == 0 && intersect(s.b))	return 2;
		if (c3 == 0 && s.intersect(a))	return 2;
		if (c4 == 0 && s.intersect(b))	return 2;
		return 0;
	}
};
Segment Seg[50];
Vector treasure;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf", &Seg[i].a.x, &Seg[i].a.y, &Seg[i].b.x, &Seg[i].b.y);
		scanf("%lf%lf", &treasure.x, &treasure.y);
		int A = 1e9;
		for (int i = 0; i < n; i++){
			int cnt1 = 0, cnt2 = 0;
			Segment a = Segment(treasure, Seg[i].a);
			Segment b = Segment(treasure, Seg[i].b);
			Vector v;
			for (int j = 0; j < n; j++){
				if (a.intersect(Seg[j], v) != 0)	
					cnt1++;
				if (b.intersect(Seg[j], v) != 0)	
					cnt2++;
			}
			A = min(A, cnt1);
			A = min(A, cnt2);
		}
		if (n == 0)	A = 1;
		printf("Number of doors = %d\n", A);
	}
	return 0;
}
/*

Treasure Hunt
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 5734		Accepted: 2387
Description

Archeologists from the Antiquities and Curios Museum (ACM) have flown to Egypt to examine the great pyramid of Key-Ops. Using state-of-the-art technology they are able to determine that the lower floor of the pyramid is constructed from a series of straightline walls, which intersect to form numerous enclosed chambers. Currently, no doors exist to allow access to any chamber. This state-of-the-art technology has also pinpointed the location of the treasure room. What these dedicated (and greedy) archeologists want to do is blast doors through the walls to get to the treasure room. However, to minimize the damage to the artwork in the intervening chambers (and stay under their government grant for dynamite) they want to blast through the minimum number of doors. For structural integrity purposes, doors should only be blasted at the midpoint of the wall of the room being entered. You are to write a program which determines this minimum number of doors.
An example is shown below:

Input

The input will consist of one case. The first line will be an integer n (0 <= n <= 30) specifying number of interior walls, followed by n lines containing integer endpoints of each wall x1 y1 x2 y2 . The 4 enclosing walls of the pyramid have fixed endpoints at (0,0); (0,100); (100,100) and (100,0) and are not included in the list of walls. The interior walls always span from one exterior wall to another exterior wall and are arranged such that no more than two walls intersect at any point. You may assume that no two given walls coincide. After the listing of the interior walls there will be one final line containing the floating point coordinates of the treasure in the treasure room (guaranteed not to lie on a wall).
Output

Print a single line listing the minimum number of doors which need to be created, in the format shown below.
Sample Input

7
20 0 37 100
40 0 76 100
85 0 0 75
100 90 0 90
0 71 100 61
0 14 100 38
100 47 47 100
54.5 55.4
Sample Output

Number of doors = 2
Source

East Central North America 1999

*/