/* 9354982 10827 Maximum sum on a torus Accepted C++ 1.180 2011-10-10 12:08:44 */
#include<stdio.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
int main(){
	int t;
	scanf("%d",&t);
	for(int s=1;s<=t;s++){
		int m[200][200];
		int sum1[200][200]; // Line
		int sum2[200][200];	// Rec	
		int i,j,k,x,y,n,nn;
		scanf("%d",&n);
		nn=n*2-2;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&m[i][j]);

		for(i=0;i<n;i++)
			for(j=n;j<nn;j++)
				m[i][j]=m[i][j-n];
		for(i=n;i<nn;i++)
			for(j=0;j<nn;j++)
				if(j-n>=0)
					m[i][j]=m[i-n][j-n];
				else
					m[i][j]=m[i-n][j];		

		for(i=0;i<nn;i++){
			sum1[i][0]=m[i][0];
			for(j=1;j<nn;j++)
				sum1[i][j]=sum1[i][j-1]+m[i][j];
		}
		for(j=0;j<nn;j++)
			for(i=k=0;i<nn;i++)
				k+=sum1[i][j],sum2[i][j]=k;

		int max=-2e9;
		for(i=0;i<n;i++) // 這個算法還滿多重複的計算
			for(j=0;j<n;j++)
				for(y=i;y-i<n&&y<nn;y++)
					for(x=j;x-j<n&&x<nn;x++)
						if(i-1>=0&&j-1>=0)
							max=MAX(max,sum2[y][x]-sum2[y][j-1]-sum2[i-1][x]+sum2[i-1][j-1]);
						else if(i-1>=0)
							max=MAX(max,sum2[y][x]-sum2[i-1][x]);
						else if(j-1>=0)
							max=MAX(max,sum2[y][x]-sum2[y][j-1]);
						else
							max=MAX(max,sum2[y][x]);
						
		printf("%d\n",max);
	}
	return 0;
}
/*

A grid that wraps both horizontally and vertically is called a torus. Given a torus where each cell contains an integer, determine the sub-rectangle with the largest sum. The sum of a sub-rectangle is the sum of all the elements in that rectangle. The grid below shows a torus where the maximum sub-rectangle has been shaded.

1 -1 0 0 -4
2 3 -2 -3 2
4 1 -1 5 0
3 -2 1 -3 2
-3 2 4 1 -4 

Input

The first line in the input contains the number of test cases (at most 18). Each case starts with an integer N (1≤N≤75) specifying the size of the torus (always square). Then follows N lines describing the torus, each line containing N integers between -100 and 100, inclusive.

Output 

For each test case, output a line containing a single integer: the maximum sum of a sub-rectangle within the torus.
 
Sample Input                                  

2
5
1 -1 0 0 -4
2 3 -2 -3 2
4 1 -1 5 0
3 -2 1 -3 2
-3 2 4 1 -4
3
1 2 3
4 5 6
7 8 9

Output for Sample Input

15
45
 
--------------------------------------------------------------------------------

Problem setter: Jimmy Mårdell 

Special Thanks: Derek Kisman, Md. Kamruzzaman

*/