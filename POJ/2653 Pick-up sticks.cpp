/* 14135615	840502	2653	Accepted	3280K	469MS	C++	2189B	2015-04-27 15:43:15 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
double isZero(const double &x){
	return fabs(x) <= EPS ? x : 0;
}
double sign(double x){
	return fabs(x) < 1e-9 ? 0 : (x > 0 ? +1 : -1);
}
struct Vector{
	double x, y;
	Vector(){}
	Vector(double x, double y) :x(x), y(y){}
	Vector operator + (const Vector &a) const{
		return Vector(x + a.x, y + a.y);
	}
	Vector operator - (const Vector &a) const{
		return Vector(x - a.x, y - a.y);
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
double mul(Vector &a, Vector &b, Vector &c){
	return (b - a) * (c - a);
}
int cross_over(Vector &p1, Vector &p2, Vector &p3, Vector &p4){
	double a1 = mul(p1, p2, p3), a2 = mul(p1, p2, p4);
	if (sign(a1) == 0 && sign(a2) == 0)	return 2; // coincide
	if (sign(a1) == sign(a2))	return 0; // fail
	return 1; // cross
}
Vector a[100005], b[100005];
int n;
int main(){
	//freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
		int ans[1005], ptr = 0;
		for (int i = 0; i < n - 1; i++){
			bool flag = false;
			for (int j = i + 1; j < n && !flag; j++)
				if (cross_over(a[i], b[i], a[j], b[j]) == 1 && cross_over(a[j], b[j], a[i], b[i]) == 1)
					flag = true;
			if (!flag)
				ans[ptr++] = i + 1;
		}
		printf("Top sticks: ");
		for (int i = 0; i < ptr;i++)
			printf("%d, ", ans[i]);
		printf("%d.\n", n);
	}
	return 0;
}
/*

Pick-up sticks
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 10404		Accepted: 3851
Description

Stan has n sticks of various length. He throws them one at a time on the floor in a random way. After finishing throwing, Stan tries to find the top sticks, that is these sticks such that there is no stick on top of them. Stan has noticed that the last thrown stick is always on top but he wants to know all the sticks that are on top. Stan sticks are very, very thin such that their thickness can be neglected.
Input

Input consists of a number of cases. The data for each case start with 1 <= n <= 100000, the number of sticks for this case. The following n lines contain four numbers each, these numbers are the planar coordinates of the endpoints of one stick. The sticks are listed in the order in which Stan has thrown them. You may assume that there are no more than 1000 top sticks. The input is ended by the case with n=0. This case should not be processed.
Output

For each input case, print one line of output listing the top sticks in the format given in the sample. The top sticks should be listed in order in which they were thrown.

The picture to the right below illustrates the first case from input.
Sample Input

5
1 1 4 2
2 3 3 1
1 -2.0 8 4
1 4 8 2
3 3 6 -2.0
3
0 0 1 1
1 0 2 1
2 0 3 1
0
Sample Output

Top sticks: 2, 4, 5.
Top sticks: 1, 2, 3.
Hint

Huge input,scanf is recommended.
Source

Waterloo local 2005.09.17

*/