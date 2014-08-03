/* 9047321 11494 Queen Accepted C++ 0.008 2011-07-14 06:15:37 */
#include<stdio.h>
#define ABS(x) ( (x)>=0?(x):-(x) )
int main(){
	int x1,x2,y1,y2;
	while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4){
		if(x1==0&&y1==0&&x2==0&&y2==0)
			break;
		int delta_x,delta_y;
		delta_x=ABS(x1-x2);
		delta_y=ABS(y1-y2);
		if(delta_x==0&&delta_y==0)
			puts("0");
		else if(delta_x==delta_y||delta_x==0||delta_y==0)
			puts("1");
		else
			puts("2");
	}
	return 0;
}
/*

 The game of Chess has several pieces with curious movements. One of them is the Queen, which can move any number of squares in any direction: in the same line, in the same column or in any of the diagonals, as illustrated by the figure below (black dots represent positions the queen may reach in one move):
 
The great Chess Master Kary Gasparov invented a new type of chess problem: given the position of a queen in an empty standard chess board (that is, an 8 x 8 board) how many moves are needed so that she reaches another given square in the board?
 
Kary found the solution for some of those problems, but is having a difficult time to solve some others, and therefore he has asked that you write a program to solve this type of problem.
 
The Input

 The input contains several test cases. The only line of each test case contains four integers X1, Y1, X2 and Y2 (1 ≤ X1, Y1, X2, Y2 ≤ 8). The queen starts in the square with coordinates (X1, Y1), and must finish at the square with coordinates (X2, Y2). In the chessboard, columns are numbered from 1 to 8, from left ro right; lines are also numbered from 1 to 8, from top to bottom. The coordinates of a square in line X and column Y are (X, Y).
 
The end of input is indicated by a line containing four zeros, separated by spaces.
 
The Output

 For each test case in the input your program must print a single line, containing an integer, indicating the smallest number of moves needed for the queen to reach the new position.
 
Sample Input 
4 4 6 2
3 5 3 5
5 5 4 3
0 0 0 0

Sample Output
1
0
2

*/