/* 3941395	2015-04-24 16:44:40	Accepted	3203	C++	0	272	840502 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
double H, h, D;
double cal(double x){
	return H + D - (D*(H - h) / x + x);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%lf%lf%lf", &H, &h, &D);
		double L = D - D*h / H, R = D;
		while (L + EPS <= R){
			double mid1 = (L + R) / 2;
			double mid2 = (mid1 + R) / 2;
			double res1 = cal(mid1);
			double res2 = cal(mid2);
			if (res1 < res2)
				L = mid1;
			else
				R = mid2;
		}
		printf("%.3lf\n", max(cal(L), D*h / H));
	}
	return 0;
}
/*

Compared to wildleopard's wealthiness, his brother mildleopard is rather poor. His house is narrow and he has only one light bulb in his house. Every night, he is wandering in his incommodious house, thinking of how to earn more money. One day, he found that the length of his shadow was changing from time to time while walking between the light bulb and the wall of his house. A sudden thought ran through his mind and he wanted to know the maximum length of his shadow.


Input

The first line of the input contains an integer T (T <= 100), indicating the number of cases.

Each test case contains three real numbers H, h and D in one line. H is the height of the light bulb while h is the height of mildleopard. D is distance between the light bulb and the wall. All numbers are in range from 10-2 to 103, both inclusive, and H - h >= 10-2.

Output

For each test case, output the maximum length of mildleopard's shadow in one line, accurate up to three decimal places..

Sample Input

3
2 1 0.5
2 0.5 3
4 3 4
Sample Output

1.000
0.750
4.000
Author: GUAN, Yao
Source: The 6th Zhejiang Provincial Collegiate Programming Contest

*/