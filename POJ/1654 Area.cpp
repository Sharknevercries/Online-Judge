/* 14134247	840502	1654	Accepted	928K	110MS	C++	1929B	2015-04-27 00:40:38 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
double isZero(const double &a){
	return fabs(a) <= EPS ? a : 0;
}
struct Vector{
	double x, y;
	Vector(){}
	Vector(double x, double y) :x(x), y(y){}
	Vector operator + (const Vector &a) const{
		return Vector(x + a.x, y + a.y);
	}
	Vector operator - (const Vector &a) const{
		return Vector(x - a.x, y + a.y);
	}
	double operator * (const Vector &a) const{
		return x * a.y - y * a.x;
	}
	double operator % (const Vector &a) const{
		return x * a.x + y * a.y;
	}
	bool operator == (const Vector &a) const{
		return isZero(x - a.x) == 0 && isZero(y - a.y);
	}
	Vector unitVector(double a) const{
		a /= sqrt(x*x + y*y);
		return Vector(x * a, y * a);
	}
	double distance(const Vector &a) const{
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
	double length(){
		return sqrt(x*x + y*y);
	}
};
char s[1000005];
int n;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%s", s);
		long long ans = 0;
		Vector p1, p2;
		p1 = Vector(0, 0);
		for (int i = 0; s[i] != '\0'; i++){
			if (s[i] == '1')	p2 = p1 + Vector(-1, -1);
			if (s[i] == '2')	p2 = p1 + Vector(0, -1);
			if (s[i] == '3')	p2 = p1 + Vector(1, -1);
			if (s[i] == '4')	p2 = p1 + Vector(-1, 0);
			if (s[i] == '5')	p2 = Vector(0, 0);
			if (s[i] == '6')	p2 = p1 + Vector(1, 0);
			if (s[i] == '7')	p2 = p1 + Vector(-1, 1);
			if (s[i] == '8')	p2 = p1 + Vector(0, 1);
			if (s[i] == '9')	p2 = p1 + Vector(1, 1);
			ans += p1 * p2;
			p1 = p2;
		}
		if (ans < 0)	ans = -ans;
		printf("%lld", ans / 2);
		if (ans % 2 == 1)
			printf(".5");
		putchar('\n');
	}
	return 0;
}
/*

Area
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 16250		Accepted: 4512
Description

You are going to compute the area of a special kind of polygon. One vertex of the polygon is the origin of the orthogonal coordinate system. From this vertex, you may go step by step to the following vertexes of the polygon until back to the initial vertex. For each step you may go North, West, South or East with step length of 1 unit, or go Northwest, Northeast, Southwest or Southeast with step length of square root of 2.

For example, this is a legal polygon to be computed and its area is 2.5:

Input

The first line of input is an integer t (1 <= t <= 20), the number of the test polygons. Each of the following lines contains a string composed of digits 1-9 describing how the polygon is formed by walking from the origin. Here 8, 2, 6 and 4 represent North, South, East and West, while 9, 7, 3 and 1 denote Northeast, Northwest, Southeast and Southwest respectively. Number 5 only appears at the end of the sequence indicating the stop of walking. You may assume that the input polygon is valid which means that the endpoint is always the start point and the sides of the polygon are not cross to each other.Each line may contain up to 1000000 digits.
Output

For each polygon, print its area on a single line.
Sample Input

4
5
825
6725
6244865
Sample Output

0
0
0.5
2
Source

POJ Monthly--2004.05.15 Liu Rujia@POJ

*/