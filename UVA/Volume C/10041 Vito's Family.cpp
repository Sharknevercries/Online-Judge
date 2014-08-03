/* 12417328	10041	Vito's Family	Accepted	C++	0.095	2013-09-29 07:44:49 */
#include<stdio.h>
#define SWAP(x,y) { int temp=x;	x=y;	y=temp;	}
#define ABS(x) ( (x) >= 0 ? (x) : -(x) )
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int n;
		int S[501];
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
			scanf("%d",&S[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if( S[i]>S[j] )
					SWAP(S[i],S[j]);
		int M=(n+1)/2;
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=ABS(S[M]-S[i]);
		printf("%d\n",sum);
	}
	return 0;
}
/*


  Problem C: Vito's family 
Background 

The world-known gangster Vito Deadstone is moving to New York. He has a very big family there, all of them living in Lamafia Avenue. Since he will visit all his relatives very often, he is trying to find a house close to them.
Problem 

Vito wants to minimize the total distance to all of them and has blackmailed you to write a program that solves his problem.
Input 

The input consists of several test cases. The first line contains the number of test cases.
For each test case you will be given the integer number of relatives r ( 0 < r < 500) and the street numbers (also integers)  $s_1, s_2, \ldots, s_i, \ldots, s_r$ where they live ( 0 < si < 30000 ). Note that several relatives could live in the same street number.

Output 

For each test case your program must write the minimal sum of distances from the optimal Vito's house to each one of his relatives. The distance between two street numbers si and sj is dij= |si-sj|.
Sample Input 

2
2 2 4 
3 2 4 6
Sample Output 

2
4


Miguel Revilla 
2000-11-19

*/