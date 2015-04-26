/* 14123232	840502	3301	Accepted	740K	32MS	G++	1190B	2015-04-24 00:37:18 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
struct Point{
	double x, y;
};
int n;
Point P[1000];
double cal(double angle){
	double res = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			double a = fabs(cos(angle) * (P[i].y - P[j].y) - sin(angle) * (P[i].x - P[j].x));
			double b = fabs(sin(angle) * (P[i].y - P[j].y) + cos(angle) * (P[i].x - P[j].x));
			res = max(res, a);
			res = max(res, b);
		}
	}
	return res * res;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		double L = 0, R = acos(-1.0);
		double res1, res2;
		while (R - L >= EPS){
			double mid1 = (L + R) / 2;
			double mid2 = (mid1 + R) / 2;
			res1 = cal(mid1);
			res2 = cal(mid2);
			if (res1 < res2)
				R = mid2;
			else
				L = mid1;
		}
		printf("%.2f\n", min(res1, res2));
	}
	return 0;
}
/*

Texas Trip
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 4242		Accepted: 1305
Description

After a day trip with his friend Dick, Harry noticed a strange pattern of tiny holes in the door of his SUV. The local American Tire store sells fiberglass patching material only in square sheets. What is the smallest patch that Harry needs to fix his door?

Assume that the holes are points on the integer lattice in the plane. Your job is to find the area of the smallest square that will cover all the holes.

Input

The first line of input contains a single integer T expressed in decimal with no leading zeroes, denoting the number of test cases to follow. The subsequent lines of input describe the test cases.

Each test case begins with a single line, containing a single integer n expressed in decimal with no leading zeroes, the number of points to follow; each of the following n lines contains two integers x and y, both expressed in decimal with no leading zeroes, giving the coordinates of one of your points.

You are guaranteed that T ≤ 30 and that no data set contains more than 30 points. All points in each data set will be no more than 500 units away from (0,0).

Output

Print, on a single line with two decimal places of precision, the area of the smallest square containing all of your points.

Sample Input

2
4
-1 -1
1 -1
1 1
-1 1
4
10 1
10 -1
-10 1
-10 -1
Sample Output

4.00
242.00
Source

Waterloo Local Contest, 2007.7.14

*/