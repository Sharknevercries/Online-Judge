/* 9348313 10520 Determine it Accepted C++ 0.048 2011-10-08 16:50:27 */
#include<stdio.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		unsigned long long DP[30][30]={0};
		DP[n][1]=k;

		int i,j,k;
		for(i=n;i>=1;i--)
			for(j=1;j<=n;j++)
				if(i==n&&j==1)
					continue;
				else if(i>=j){
					unsigned long long max;
					for(k=i+1,max=0;k<=n;k++)
						max = MAX(max,DP[k][1]+DP[k][j]);
					DP[i][j]+=max;
					for(k=1,max=0;k<j;k++)
						max = MAX(max,DP[i][k]+DP[n][k]);
					DP[i][j]+=max;
				}
				else{
					unsigned long long max;
					for(k=i,max=0;k<j;k++)
						max = MAX(max,DP[i][k]+DP[k+1][j]);
					DP[i][j]+=max;
				}
		printf("%llu\n",DP[1][n]);
	}
	return 0;
}
/*

ai,j is defined as: 

You are to calculate the value of a1,n on the basis of the values of n and an,1.

The Input
 
The input consists of several test cases. Each Test case consists of two integers n ( 0 < n < 20 ) and an,1 ( 0 < an,1 < 500 ).
 
The Output
 
For each test case your correct program should print the value of a1,n in a separate line.
 
Sample Input
 
5 10
4 1
6 13
 
Sample Output
 
1140
42
3770

Hasan Shihab Uddin ( BUET PESSIMISTIC ) 

*/