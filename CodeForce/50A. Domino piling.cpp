/* 1204253	 Feb 19, 2012 6:43:50 PM	Shark	 50A - Domino piling	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)==2){
		if((a&1)==0||(b&1)==0)
			if((a&1)==0)
				printf("%d\n",a/2*b);
			else
				printf("%d\n",b/2*a);
		else
			printf("%d\n",(a-1)/2*b+b/2);
	}
	return 0;
}
/*

You are given a rectangular board of M × N squares. Also you are given an unlimited number of standard domino pieces of 2 × 1 squares. You are allowed to rotate the pieces. You are asked to place as many dominoes as possible on the board so as to meet the following conditions:

1. Each domino completely covers two squares.

2. No two dominoes overlap.

3. Each domino lies entirely inside the board. It is allowed to touch the edges of the board.

Find the maximum number of dominoes, which can be placed under these restrictions.

Input

In a single line you are given two integers M and N — board sizes in squares (1 ≤ M ≤ N ≤ 16).

Output

Output one number — the maximal number of dominoes, which can be placed.

input

2 4
3 3

output

4
4

*/