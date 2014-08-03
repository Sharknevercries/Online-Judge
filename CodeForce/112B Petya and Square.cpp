/* 4803243	 Oct 16, 2013 11:06:25 AM	Shark	 112B - Petya and Square	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
int main(){
	int n,x,y;
	while( scanf("%d%d%d",&n,&x,&y)==3 ){
		if( x==n/2&&y==n/2 ) // if the marked cell is located at center of the square,it must not meet the question
			puts("NO");
		else if( x==n/2&&y==n/2+1 )
			puts("NO");
		else if( x==n/2+1&&y==n/2 )
			puts("NO");
		else if( x==n/2+1&&y==n/2+1 )
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
/*

B. Petya and Square
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Petya loves playing with squares. Mum bought him a square 2n × 2n in size. Petya marked a cell inside the square and now he is solving the following task.

The task is to draw a broken line that would go along the grid lines and that would cut the square into two equal parts. The cutting line should not have any common points with the marked cell and the resulting two parts should be equal up to rotation.

Petya wants to determine whether it is possible to cut the square in the required manner given the sizes of the square side and the coordinates of the marked cell. Help him.

Input
The first line contains three space-separated integers 2n, x and y (2 ≤ 2n ≤ 100, 1 ≤ x, y ≤ 2n), representing the length of a square's side and the coordinates of the marked cell. It is guaranteed that 2n is even.

The coordinates of the marked cell are represented by a pair of numbers x y, where x represents the number of the row and y represents the number of the column. The rows and columns are numbered by consecutive integers from 1 to 2n. The rows are numbered from top to bottom and the columns are numbered from the left to the right.

Output
If the square is possible to cut, print "YES", otherwise print "NO" (without the quotes).

Sample test(s)
input
4 1 1
output
YES
input
2 2 2
output
NO
Note
A sample test from the statement and one of the possible ways of cutting the square are shown in the picture:

*/