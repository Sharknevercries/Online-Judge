/* 8885582 10620 A Flea on a Chessboard Accepted C++ 0.656 2011-05-25 15:38:58 */
#include<stdio.h>
int main(){
	unsigned long long s,x,y,dx,dy;
	while(scanf("%llu%llu%llu%llu%llu",&s,&x,&y,&dx,&dy)==5){
		if(s==0&&x==0&&y==0&&dx==0&&dy==0)
			break;
		unsigned long long jump;		// 自己的方法一直TLE 該死的測資
		for(jump=0;(x%(2*s)/s==y%(2*s)/s||x%s==0||y%s==0)&&jump<2000000;x+=dx,y+=dy,jump++); // 超級暴力
		if(jump>=2000000)
			puts("The flea cannot escape from black squares.");
		else			
			printf("After %llu jumps the flea lands at (%llu, %llu).\n",jump,x,y);
	}	
	return 0;
}
/*

 An infinite chessboard is obtained by extending a finite chessboard to the right and up infinitely. Each square of the chessboard is either black or white with the side of S milimiters, 0 < S < 1000. The leftmost bottom square of the chessboard is black. A flea is positioned on the chessboard at the point (x, y) (given in milimeters) and makes jumps by jumping dx milimeters to the right and dy milimiters up, 0 < dx, dy, that is, a flea at position (x, y) after one jump lands at position (x+dx, y+dy).
 Given the starting position of the flea on the board your task is to find out after how many jumps the flea will reach a white square. If the flea lands on a boundary between two squares then it does not count as landing on the white square. Note that it is possible that the flea never reaches a white square.
 
Input and output

 Each test case consists of one line of input containing five non-negative numbers separated by white space and giving S, x, y, dx, and dy. An input line containing five zeroes follows the last test case. For test case print one line of output in the format shown in the sample.
 
Sample input
 
10 2 3 3 2
100 49 73 214 38
25 0 0 5 25
407 1270 1323 1 1
18 72 6 18 6
407 1270 1170 100 114
0 0 0 0 0

 Output for sample input

After 3 jumps the flea lands at (11, 9).
After 1 jumps the flea lands at (263, 111).
The flea cannot escape from black squares.
After 306 jumps the flea lands at (1576, 1629).
The flea cannot escape from black squares.
After 0 jumps the flea lands at (1270, 1170).

--------------------------------------------------------------------------------
 P. Rudnicki 
 
 */