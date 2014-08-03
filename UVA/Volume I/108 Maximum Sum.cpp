/* 9354316 108 Maximum Sum Accepted C++ 0.084 2011-10-10 08:16:11 */
#include<stdio.h>
#define MAX(s,t) ( (s) >= (t) ? (s) : (t) )
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int m[100][100]={0};
		int temp[100][100];
		int sum[100][100]={0};
		int i,j,x,y;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&m[i][j]);

		for(i=0;i<n;i++){ // 算出由第i列之m[i][0]~m[i][j]之和
			temp[i][0]=m[i][0];
			for(j=1;j<n;j++)
				temp[i][j]=temp[i][j-1]+m[i][j];
		}

		for(j=0;j<n;j++){ // 算出自m[0][j]和m[i][j]所圍出之矩形和
			int t=sum[0][j]=temp[0][j];
			for(i=1;i<n;i++)
				t+=temp[i][j],sum[i][j]=t;	
		}

		int max=-2e9;
		for(i=0;i<n;i++) // 窮舉每塊矩形
			for(j=0;j<n;j++)
				for(y=i;y<n;y++)
					for(x=j;x<n;x++)
						if(i-1>=0&&j-1>=0) 
							max=MAX(max,sum[y][x]-sum[i-1][x]-sum[y][j-1]+sum[i-1][j-1]);
						else if(i-1>=0)
							max=MAX(max,sum[y][x]-sum[i-1][x]);
						else if(j-1>=0)
							max=MAX(max,sum[y][x]-sum[y][j-1]);
						else
							max=MAX(max,sum[y][x]);
		printf("%d\n",max);
	}
	return 0;
}
/*

Background
 
A problem that is simple to solve in one dimension is often much more difficult to solve in more than one dimension. Consider satisfying a boolean expression in conjunctive normal form in which each conjunct consists of exactly 3 disjuncts. This problem (3-SAT) is NP-complete. The problem 2-SAT is solved quite efficiently, however. In contrast, some problems belong to the same complexity class regardless of the dimensionality of the problem.
 
The Problem
 
Given a 2-dimensional array of positive and negative integers, find the sub-rectangle with the largest sum. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. A sub-rectangle is any contiguous sub-array of size or greater located within the whole array. As an example, the maximal sub-rectangle of the array:
 
is in the lower-left-hand corner: 

and has the sum of 15. 

Input and Output
 
The input consists of an array of integers. The input begins with a single positive integer N on a line by itself indicating the size of the square two dimensional array. This is followed by integers separated by white-space (newlines and spaces). These integers make up the array in row-major order (i.e., all numbers on the first row, left-to-right, then all numbers on the second row, left-to-right, etc.). N may be as large as 100. The numbers in the array will be in the range [-127, 127].
 
The output is the sum of the maximal sub-rectangle. 

Sample Input
 
4
0 -2 -7  0 9  2 -6  2
-4  1 -4  1 -1
8  0 -2 

Sample Output
 
15 

*/