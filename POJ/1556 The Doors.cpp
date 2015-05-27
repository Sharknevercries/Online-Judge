/* 14222016	840502	1556	Accepted	376K	16MS	C++	4442B	2015-05-22 01:15:19 */
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
	double distance(Vector a) {
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
};
double w[305][305];
double DP[305];
bool V[305];
Vector P[35][5];
Segment seg[35][3];
int n, m;
bool noIntersect(int px1, int px2, Segment s){
	for (int i = 0; i < n; i++){
		if (px1 == i || px2 == i)	continue;
		for (int j = 0; j < 3; j++){
			Vector v;
			if (s.intersect(seg[i][j], v) != 0)
				return false;
		}
	}
	return true;
}
double Dijkstra(int source, int target){
	memset(V, false, sizeof(V));
	for (int i = 0; i <= m; i++)
		DP[i] = 1e9;
	DP[0] = 0;
	while (true){
		double minD = 1e9;
		int pi = -1;
		for (int i = 0; i <= m; i++)
			if (!V[i] && sign(minD - DP[i]) > 0)
				minD = DP[i], pi = i;
		if (pi == -1)	break;
		if (pi == target)	return DP[target];
		V[pi] = true;
		for (int i = 0; i <= m; i++)
			DP[i] = min(DP[i], DP[pi] + w[pi][i]);
	}
	return DP[target];
}
int main(){
	while (scanf("%d", &n) == 1 && n != -1){
		m = 4 * n + 1;
		for (int i = 0; i < n; i++){
			double x, y;
			scanf("%lf", &x);
			for (int j = 1; j <= 4; j++){
				scanf("%lf", &y);
				P[i][j] = Vector(x, y);
			}
		}
		for (int i = 0; i < n; i++){
			double x = P[i][1].x;
			seg[i][0] = Segment(Vector(x, 0), Vector(x, P[i][1].y));
			seg[i][1] = Segment(Vector(x, P[i][2].y), Vector(x, P[i][3].y));
			seg[i][2] = Segment(Vector(x, P[i][4].y), Vector(x, 10));
		}
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= m; j++)
				w[i][j] = 1e9;
		if (noIntersect(-1, -1, Segment(Vector(0, 5), Vector(10, 5))))
			w[0][4 * n + 1] = w[4 * n + 1][0] = Vector(0, 5).distance(Vector(10, 5));
		for (int i = 0; i < n; i++){
			for (int j = 1; j <= 4; j++){
				if (noIntersect(i, -1, Segment(Vector(0, 5), P[i][j])))
					w[0][i * 4 + j] = w[i * 4 + j][0] = Vector(0, 5).distance(P[i][j]);
				if (noIntersect(i, -1, Segment(Vector(10, 5), P[i][j])))
					w[4 * n + 1][i * 4 + j] = w[i * 4 + j][4 * n + 1] = Vector(10, 5).distance(P[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int p = 1; p <= 4; p++)
					for (int q = 1; q <= 4; q++)
						if (noIntersect(i, j, Segment(P[i][p], P[j][q])))
							w[i * 4 + p][j * 4 + q] = w[j * 4 + q][i * 4 + p] = P[i][p].distance(P[j][q]);
		double minDist = Dijkstra(0, m);
		printf("%.2lf\n", minDist + EPS);
	}
	return 0;
}
/*

The Doors
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 6822		Accepted: 2698
Description

You are to find the length of the shortest path through a chamber containing obstructing walls. The chamber will always have sides at x = 0, x = 10, y = 0, and y = 10. The initial and final points of the path are always (0, 5) and (10, 5). There will also be from 0 to 18 vertical walls inside the chamber, each with two doorways. The figure below illustrates such a chamber and also shows the path of minimal length.

Input

The input data for the illustrated chamber would appear as follows.

2
4 2 7 8 9
7 3 4.5 6 7

The first line contains the number of interior walls. Then there is a line for each such wall, containing five real numbers. The first number is the x coordinate of the wall (0 < x < 10), and the remaining four are the y coordinates of the ends of the doorways in that wall. The x coordinates of the walls are in increasing order, and within each line the y coordinates are in increasing order. The input file will contain at least one such set of data. The end of the data comes when the number of walls is -1.
Output

The output should contain one line of output for each chamber. The line should contain the minimal path length rounded to two decimal places past the decimal point, and always showing the two decimal places past the decimal point. The line should contain no blanks.
Sample Input

1
5 4 6 7 8
2
4 2 7 8 9
7 3 4.5 6 7
-1
Sample Output

10.00
10.06
Source

Mid-Central USA 1996

*/