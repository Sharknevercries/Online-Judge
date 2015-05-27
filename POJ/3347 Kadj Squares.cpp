/* 14195401	840502	3347	Accepted	144K	0MS	C++	1283B	2015-05-14 20:02:54 */
#include<bits\stdc++.h>
using namespace std;
struct Segment{
	double L, R;
};
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		int s[105];
		Segment seg[105];
		Segment visible[105];
		for (int i = 0; i < n; i++)
			scanf("%d", s + i);
		for (int i = 0; i < n; i++)
			seg[i].L = seg[i].R = visible[i].L = visible[i].R = 0;
		for (int i = 0; i < n; i++){
			for (int j = i - 1; j >= 0; j--)
				seg[i].L = max(seg[i].L, seg[j].R - abs(s[j] - s[i]) / sqrt(2.0));
			seg[i].R = seg[i].L + sqrt(2.0) * s[i];
		}
		for (int i = 0; i < n; i++){
			visible[i].L = seg[i].L;
			for (int j = i - 1; j >= 0;j--)
				visible[i].L = max(visible[i].L, seg[j].R);
			visible[i].R = seg[i].R;
			for (int j = i + 1; j < n; j++)
				visible[i].R = min(visible[i].R, seg[j].L);
		}
		bool first = true;
		for (int i = 0; i < n; i++){
			if (visible[i].R - visible[i].L > 1e-6){
				if (!first)	putchar(' ');
				printf("%d", i + 1);
				first = false;
			}
		}
		putchar('\n');
	}
	return 0;
}
/*

Kadj Squares
Time Limit: 2000MS		Memory Limit: 65536K
Total Submissions: 2656		Accepted: 1036
Description

In this problem, you are given a sequence S1, S2, ..., Sn of squares of different sizes. The sides of the squares are integer numbers. We locate the squares on the positive x-y quarter of the plane, such that their sides make 45 degrees with x and y axes, and one of their vertices are on y=0 line. Let bi be the x coordinates of the bottom vertex of Si. First, put S1 such that its left vertex lies on x=0. Then, put S1, (i > 1) at minimum bi such that

bi > bi-1 and
the interior of Si does not have intersection with the interior of S1...Si-1.

The goal is to find which squares are visible, either entirely or partially, when viewed from above. In the example above, the squares S1, S2, and S4 have this property. More formally, Si is visible from above if it contains a point p, such that no square other than Si intersect the vertical half-line drawn from p upwards.

Input

The input consists of multiple test cases. The first line of each test case is n (1 ≤ n ≤ 50), the number of squares. The second line contains n integers between 1 to 30, where the ith number is the length of the sides of Si. The input is terminated by a line containing a zero number.

Output

For each test case, output a single line containing the index of the visible squares in the input sequence, in ascending order, separated by blank characters.

Sample Input

4
3 5 1 4
3
2 1 2
0
Sample Output

1 2 4
1 3
Source

Tehran 2006

*/