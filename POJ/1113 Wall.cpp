/* 14157198	840502	1113	Accepted	212K	16MS	C++	2208B	2015-05-03 19:39:26 */
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
Vector P[1005], CH[1005];
bool cmp(Vector a, Vector b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int main(){
	int n, L;
	while (scanf("%d%d", &n, &L) == 2){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		sort(P, P + n, cmp);
		int m = 0;
		for (int i = 0; i < n; i++){
			while (m >= 2 && (CH[m - 1] - CH[m - 2]) * (P[i] - CH[m - 2]) <= 0)
				m--;
			CH[m++] = P[i];
		}
		for (int i = n - 2, t = m + 1; i >= 0; i--){
			while (m >= t && (CH[m - 1] - CH[m - 2]) * (P[i] - CH[m - 2]) <= 0)
				m--;
			CH[m++] = P[i];
		}
		double res = 0;
		for (int i = 0; i < m - 1; i++)
			res += CH[i].distance(CH[i + 1]);
		printf("%.0lf\n", res + 2 * L * PI);
	}
	return 0;
}
/*

Wall
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 31336		Accepted: 10572
Description

Once upon a time there was a greedy King who ordered his chief Architect to build a wall around the King's castle. The King was so greedy, that he would not listen to his Architect's proposals to build a beautiful brick wall with a perfect shape and nice tall towers. Instead, he ordered to build the wall around the whole castle using the least amount of stone and labor, but demanded that the wall should not come closer to the castle than a certain distance. If the King finds that the Architect has used more resources to build the wall than it was absolutely necessary to satisfy those requirements, then the Architect will loose his head. Moreover, he demanded Architect to introduce at once a plan of the wall listing the exact amount of resources that are needed to build the wall.


Your task is to help poor Architect to save his head, by writing a program that will find the minimum possible length of the wall that he could build around the castle to satisfy King's requirements.

The task is somewhat simplified by the fact, that the King's castle has a polygonal shape and is situated on a flat ground. The Architect has already established a Cartesian coordinate system and has precisely measured the coordinates of all castle's vertices in feet.
Input

The first line of the input file contains two integer numbers N and L separated by a space. N (3 <= N <= 1000) is the number of vertices in the King's castle, and L (1 <= L <= 1000) is the minimal number of feet that King allows for the wall to come close to the castle.

Next N lines describe coordinates of castle's vertices in a clockwise order. Each line contains two integer numbers Xi and Yi separated by a space (-10000 <= Xi, Yi <= 10000) that represent the coordinates of ith vertex. All vertices are different and the sides of the castle do not intersect anywhere except for vertices.
Output

Write to the output file the single number that represents the minimal possible length of the wall in feet that could be built around the castle to satisfy King's requirements. You must present the integer number of feet to the King, because the floating numbers are not invented yet. However, you must round the result in such a way, that it is accurate to 8 inches (1 foot is equal to 12 inches), since the King will not tolerate larger error in the estimates.
Sample Input

9 100
200 400
300 400
300 300
400 300
400 400
500 400
500 200
350 200
200 200
Sample Output

1628
Hint

结果四舍五入就可以了
Source

Northeastern Europe 2001

*/