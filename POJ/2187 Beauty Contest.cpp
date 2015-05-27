/* 14157351	840502	2187	Accepted	984K	266MS	C++	2318B	2015-05-03 20:31:19 */
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
	double distance(Vector &a) {
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}
};
bool cmp(Vector a, Vector b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int n;
Vector P[50005], CHL[50005], CHU[50005];
int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		sort(P, P + n, cmp);
		int L = 0, U = 0;
		for (int i = 0; i < n; i++){
			while (L >= 2 && (CHL[L - 1] - CHL[L - 2]) * (P[i] - CHL[L - 2]) <= 0)	L--;
			while (U >= 2 && (CHU[U - 1] - CHU[U - 2]) * (P[i] - CHU[U - 2]) >= 0)	U--;
			CHL[L++] = P[i], CHU[U++] = P[i];
		}
		if (U - 2 >= 0)	CHL[L] = CHU[U - 2];
		double ans = 0;
		for (int i = 0, j = U - 1; i < L && j > 0;){
			ans = max(ans, CHL[i].distance(CHU[j]));
			if ((CHL[i + 1] - CHL[i]) * (CHU[j - 1] - CHU[j]) < 0)
				i++;
			else
				j--;
		}
		printf("%.0lf\n", ans * ans);
	}
	return 0;
}
/*

Beauty Contest
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 29845		Accepted: 9244
Description

Bessie, Farmer John's prize cow, has just won first place in a bovine beauty contest, earning the title 'Miss Cow World'. As a result, Bessie will make a tour of N (2 <= N <= 50,000) farms around the world in order to spread goodwill between farmers and their cows. For simplicity, the world will be represented as a two-dimensional plane, where each farm is located at a pair of integer coordinates (x,y), each having a value in the range -10,000 ... 10,000. No two farms share the same pair of coordinates.

Even though Bessie travels directly in a straight line between pairs of farms, the distance between some farms can be quite large, so she wants to bring a suitcase full of hay with her so she has enough food to eat on each leg of her journey. Since Bessie refills her suitcase at every farm she visits, she wants to determine the maximum possible distance she might need to travel so she knows the size of suitcase she must bring.Help Bessie by computing the maximum distance among all pairs of farms.

Input

* Line 1: A single integer, N

* Lines 2..N+1: Two space-separated integers x and y specifying coordinate of each farm
Output

* Line 1: A single integer that is the squared distance between the pair of farms that are farthest apart from each other.
Sample Input

4
0 0
0 1
1 1
1 0
Sample Output

2
Hint

Farm 1 (0, 0) and farm 3 (1, 1) have the longest distance (square root of 2)
Source

USACO 2003 Fall

*/