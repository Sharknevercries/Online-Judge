/* 5366738	 Dec 7, 2013 8:19:50 AM	Shark	 325A - Square and Rectangles	 GNU C++	Accepted	30 ms	100 KB */
#include<stdio.h>
#include<algorithm>
struct data{
	int x1, x2, y1, y2;
};
bool cmp(struct data A, struct data B){
	return A.x1 < B.x1 || (A.x1 == B.x1&&A.y1 < B.y1);
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int Y[31401] = { 0 };
		int L, R, T, D;
		struct data M[5];
		bool ans = true;
		L = D = 2e9, R = T = 0; // Left, Down, Right, Top
		for (int i = 0; i < n; i++){
			scanf("%d%d%d%d", &M[i].x1, &M[i].y1, &M[i].x2, &M[i].y2);
			if (L > M[i].x1)	L = M[i].x1;
			if (D > M[i].y1)	D = M[i].y1;
			if (R < M[i].x2)	R = M[i].x2;
			if (T < M[i].y2)	T = M[i].y2;
		}
		std::sort(M, M + n, cmp);
		for (int i = D; i <= T - 1; i++)
			Y[i] = L;
		for (int i = 0; i < n; i++){
			for (int j = M[i].y1; j <= M[i].y2 - 1; j++){
				if (Y[j] == M[i].x1)
					Y[j] = M[i].x2;
				else
					ans = false;
			}
		}
		for (int i = D; i <= T - 1; i++){
			if (Y[i] != R)
				ans = false;
		}
		if (R - L != T - D)
			ans = false;
		if (ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

A. Square and Rectangles
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n rectangles. The corners of rectangles have integer coordinates and their edges are parallel to the Ox and Oy axes. The rectangles may touch each other, but they do not overlap (that is, there are no points that belong to the interior of more than one rectangle).

Your task is to determine if the rectangles form a square. In other words, determine if the set of points inside or on the border of at least one rectangle is precisely equal to the set of points inside or on the border of some square.

Input
The first line contains a single integer n (1 ≤ n ≤ 5). Next n lines contain four integers each, describing a single rectangle: x1, y1, x2, y2 (0 ≤ x1 < x2 ≤ 31400, 0 ≤ y1 < y2 ≤ 31400) — x1 and x2 are x-coordinates of the left and right edges of the rectangle, and y1 and y2 are y-coordinates of the bottom and top edges of the rectangle.

No two rectangles overlap (that is, there are no points that belong to the interior of more than one rectangle).

Output
In a single line print "YES", if the given rectangles form a square, or "NO" otherwise.

Sample test(s)
input
5
0 0 2 3
0 3 3 5
2 0 5 2
3 2 5 5
2 2 3 3
output
YES
input
4
0 0 2 3
0 3 3 5
2 0 5 2
3 2 5 5
output
NO

*/