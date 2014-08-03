/* 5367633	 Dec 7, 2013 11:10:40 AM	Shark	 370A - Rook, Bishop and King	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
#define ABS(x) ( (x) >= 0 ? (x) : -(x))
int main(){
	int x1, x2, y1, y2;
	while (scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4){
		int ans[3] = { 0 };
		if (x1 == x2&&y1 == y2)
			ans[0] = ans[1] = ans[2] = 0;
		else{
			if (x1 == x2 || y1 == y2)
				ans[0] = 1;
			else
				ans[0] = 2;
			if ((ABS(x1 - x2) + ABS(y1 - y2)) % 2 == 0){
				if (ABS(x1 - x2) == ABS(y1 - y2))
					ans[1] = 1;
				else
					ans[1] = 2;
			}
			else
				ans[1] = 0;
			if (ABS(x1 - x2) > ABS(y1 - y2))
				ans[2] += ABS(x1 - x2);
			else
				ans[2] += ABS(y1 - y2);
		}
		printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	}
	return 0;
}
/*

A. Rook, Bishop and King
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Petya is learning to play chess. He has already learned how to move a king, a rook and a bishop. Let us remind you the rules of moving chess pieces. A chessboard is 64 square fields organized into an 8 × 8 table. A field is represented by a pair of integers (r, c) — the number of the row and the number of the column (in a classical game the columns are traditionally indexed by letters). Each chess piece takes up exactly one field. To make a move is to move a chess piece, the pieces move by the following rules:

A rook moves any number of fields horizontally or vertically.
A bishop moves any number of fields diagonally.
A king moves one field in any direction — horizontally, vertically or diagonally.
The pieces move like that
Petya is thinking about the following problem: what minimum number of moves is needed for each of these pieces to move from field (r1, c1) to field (r2, c2)? At that, we assume that there are no more pieces besides this one on the board. Help him solve this problem.

Input
The input contains four integers r1, c1, r2, c2 (1 ≤ r1, c1, r2, c2 ≤ 8) — the coordinates of the starting and the final field. The starting field doesn't coincide with the final one.

You can assume that the chessboard rows are numbered from top to bottom 1 through 8, and the columns are numbered from left to right 1 through 8.

Output
Print three space-separated integers: the minimum number of moves the rook, the bishop and the king (in this order) is needed to move from field (r1, c1) to field (r2, c2). If a piece cannot make such a move, print a 0 instead of the corresponding number.

Sample test(s)
input
4 3 1 6
output
2 1 3
input
5 5 5 6
output
1 0 1

*/