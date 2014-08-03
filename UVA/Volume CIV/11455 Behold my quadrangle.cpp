/* 9075214 11455 Behold my quadrangle Accepted C++ 0.008 2011-07-24 08:47:43 */
#include<stdio.h>
#define SWAP(x,y) {int temp=x; x=y; y=temp; }
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		unsigned long long m[4];
		scanf("%llu%llu%llu%llu",&m[0],&m[1],&m[2],&m[3]);
		for(int j=0;j<4;j++)
			for(int k=j+1;k<4;k++)
				if(m[j]<m[k])
					SWAP(m[j],m[k]);
		if(m[0]==m[1]&&m[0]==m[2]&&m[0]==m[3])
			puts("square");
		else if(m[0]==m[1]&&m[2]==m[3])
			puts("rectangle");
		else if(m[0]<m[1]+m[2]+m[3])
			puts("quadrangle");
		else
			puts("banana");
	}
	return 0;
}
/*

Any square is a rectangle, any rectangle is a quadrangle, and any quadrangle is composed of four sides. But not all rectangles are squares, not all quadrangles are rectangles, and not all sets of four sides are quadrangles.

The Problem

We have the length of four sides. You have to determine if they can form a square. If not, determine if they can form a rectangle. If not, determine if they can form a quadrangle.

The Input

The first line of the input contains an integer indicating the number of test cases.

For each test case, there is a line with four positive integer numbers, between 0 and 230.

The Output

For each test case, the output should consist of a line with the text "square", "rectangle", "quadrangle" or "banana", if the sides of the corresponding case can form a square, a rectangle, a quadrangle or none, respectively.

Sample Input

4
10 8 7 6
9 1 9 1
29 29 29 29
5 12 30 7

 Sample Output

quadrangle
rectangle
square
banana

*/