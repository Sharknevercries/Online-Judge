/* 1701499	4253	Archery	Accepted	C++	0.109	2015-05-22 10:32:08 */
/* WA on UVA, but AC on UVALive*/
#include<bits\stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-6;
int sign(double x){
	return fabs(x) < EPS ? 0 : (x > 0 ? 1 : -1);
}
// Segment
struct Segment{
	double y, x1, x2;
};
bool cmp(Segment A, Segment B){
	return A.y < B.y;
}
Segment seg[5025];
int n;
double w;
int judge(double x){
	double L = 0, R = 1e9;
	for (int i = 0; i < n; i++){
		double newR = atan2(seg[i].y, seg[i].x1 - x);
		double newL = atan2(seg[i].y, seg[i].x2 - x);
		if (L - newR > EPS)	return	1;
		if (newL - R > EPS)	return -1;
		L = max(L, newL);
		R = min(R, newR);
	}
	return 0;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%lf%d", &w, &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &seg[i].y, &seg[i].x1, &seg[i].x2);
		sort(seg, seg + n, cmp);
		double L = 0, R = w;
		bool flag = false;
		while (R - L > EPS){
			double mid = (L + R) / 2;
			int res = judge(mid);
			if (res == 0){
				flag = true;
				break;
			}
			else if (res == 1)
				R = mid;
			else
				L = mid;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
/*

Korea's reputation in archery is well known because the Korean archery teams have been sweeping almost all gold, silver, and bronze medals in the Olympic Games.

An archery game ICPC supported by NEXON (one of Korea's leading publishers of online contents) will be held in Korea. As a ceremonial event of the game, a famous master of archery will shoot an arrow to hit through all target boards made of paper. Because an arrow flies along a straight line, it depends on his position of the archer line whether or not he hits all targets.

The figure below shows an example of the complete view of a game field from the sky. Every target is represented by a line segment parallel to the archer line. Imagine the coordinate system of which the origin is the leftmost point of the archer line and the archer line is located on the positive x -axis.

\epsfbox{p4253.eps}
In the above figure, the master can hit all targets in position B. However, he never hits all targets in position A because any ray from A intersects at most 3 targets.

Given the width of the archer line and the target locations, write a program for determining if there exists a position at which the master can hit all targets. You may assume that the y -coordinates of all targets are different. Note that if an arrow passes through an end point of a target, it is considered to hit that target.

Input

Your program is to read from standard input. The input consists of T test cases. The number of test cases T (1$ \le$T$ \le$30) is given in the first line of the input. Each test case starts with a line containing an integer W (2$ \le$W$ \le$10, 000, 000) , the width of an archer line. The next line contains an integer N (2$ \le$N$ \le$5, 000) , the number of target boards. The i -th line of the following N lines contains three integers Di , Li , Ri (1$ \le$Di$ \le$W, 0$ \le$Li < Ri$ \le$W) , where 1$ \le$i$ \le$N , Di represents the y -coordinate of the i -th target, and Li and Ri represent the x -coordinates of the leftmost point and the rightmost point of the target, respectively. Note that Di $ \neq$ Dj if i $ \neq$ j .

Output

Your program is to write to standard output. Print exactly one line for each test case. Print ``YES" if there exists a position on the archer line at which a master of archery can hit all targets, otherwise, ``NO".

The following shows sample input and output for three test cases.

Sample Input

3
15
4
10 2 7
7 5 12
2 7 12
4 9 13
6
3
2 1 3
4 0 2
5 4 6
10
4
8 2 5
4 2 5
6 5 8
2 5 8
Sample Output

YES
NO
YES

*/