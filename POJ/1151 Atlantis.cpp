/* 14145931	840502	1151	Accepted	184K	0MS	C++	2063B	2015-04-30 01:12:49 */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	int L, R, cover;
	double len;
};
struct Segment{
	double y, x1, x2;
	int v;
	Segment(){}
	Segment(double y, double x1, double x2, int v) :y(y), x1(x1), x2(x2), v(v){}
};
Node T[5005];
Segment S[5005];
double H[205];
int Sptr, Hptr;
bool cmp(Segment A, Segment B){
	return A.y < B.y;
}
void build(int pos, int L, int R){
	T[pos].L = L, T[pos].R = R;
	T[pos].cover = T[pos].len = 0;
	if (L + 1 >= R)	return;
	int mid = (L + R) / 2;
	build(pos * 2, L, mid);
	build(pos * 2 + 1, mid, R);
}
void pushUp(int pos){
	if (T[pos].cover)
		T[pos].len = H[T[pos].R] - H[T[pos].L];
	else if (T[pos].L + 1 >= T[pos].R)
		T[pos].len = 0;
	else
		T[pos].len = T[pos * 2].len + T[pos * 2 + 1].len;
}
void update(int pos, int L, int R, int v){
	if (T[pos].L >= R || T[pos].R <= L)	return;
	if (L <= T[pos].L && T[pos].R <= R)
		T[pos].cover += v;
	else{
		update(pos * 2, L, R, v);
		update(pos * 2 + 1, L, R, v);
	}
	pushUp(pos);
}
int main(){
	int n, c = 1;
	while (scanf("%d", &n) == 1 && n){
		Sptr = Hptr = 0;
		for (int i = 0; i < n; i++){
			double x1, x2, y1, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			S[Sptr++] = Segment(y1, x1, x2, 1);
			S[Sptr++] = Segment(y2, x1, x2, -1);
			H[Hptr++] = x1, H[Hptr++] = x2;
		}
		sort(S, S + Sptr, cmp);
		sort(H, H + Hptr);
		Hptr = unique(H, H + Hptr) - H;
		build(1, 0, Hptr - 1);
		printf("Test case #%d\n", c++);
		double ans = 0;
		for (int i = 0; i < Sptr; i++){
			int L = lower_bound(H, H + Hptr, S[i].x1) - H;
			int R = lower_bound(H, H + Hptr, S[i].x2) - H;
			update(1, L, R, S[i].v);
			if (i + 1 < Sptr)
				ans += T[1].len * (S[i + 1].y - S[i].y);
		}
		printf("Total explored area: %.2lf\n\n", ans);

	}
	return 0;
}
/*

Atlantis
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 18581		Accepted: 7055
Description

There are several ancient Greek texts that contain descriptions of the fabled island Atlantis. Some of these texts even include maps of parts of the island. But unfortunately, these maps describe different regions of Atlantis. Your friend Bill has to know the total area for which maps exist. You (unwisely) volunteered to write a program that calculates this quantity.
Input

The input consists of several test cases. Each test case starts with a line containing a single integer n (1 <= n <= 100) of available maps. The n following lines describe one map each. Each of these lines contains four numbers x1;y1;x2;y2 (0 <= x1 < x2 <= 100000;0 <= y1 < y2 <= 100000), not necessarily integers. The values (x1; y1) and (x2;y2) are the coordinates of the top-left resp. bottom-right corner of the mapped area.
The input file is terminated by a line containing a single 0. Don't process it.
Output

For each test case, your program should output one section. The first line of each section must be "Test case #k", where k is the number of the test case (starting with 1). The second one must be "Total explored area: a", where a is the total explored area (i.e. the area of the union of all rectangles in this test case), printed exact to two digits to the right of the decimal point.
Output a blank line after each test case.
Sample Input

2
10 10 20 20
15 15 25 25.5
0
Sample Output

Test case #1
Total explored area: 180.00
Source

Mid-Central European Regional Contest 2000

*/