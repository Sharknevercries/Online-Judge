/* 9355634 10755 Garbage Heap Accepted C++ 0.520 2011-10-10 14:43:29 */
#include<stdio.h>
#include<string.h>
#define MAX(q,w) ( (q) >= (w) ? (q) : (w) ) 
#define INF -2147483648LL;
int main(){
	int t;
	scanf("%d",&t);
	for(int s=1;s<=t;s++){
		if(s!=1)
			putchar('\n');
		long long int m[20][20][20];
		long long int DP[20][20][20];
		int A,B,C;
		int i,j,k,x,y,z;
		scanf("%d%d%d",&A,&B,&C);

		for(i=0;i<A;i++)
			for(j=0;j<B;j++)
				for(k=0;k<C;k++)
					scanf("%lld",&m[i][j][k]);
		
		for(i=0;i<A;i++)
			for(j=0;j<B;j++)
				for(k=0;k<C;k++)
					if(i-1>=0&&j-1>=0&&k-1>=0)
						DP[i][j][k]=DP[i][j][k-1]+DP[i][j-1][k]+DP[i-1][j][k]-DP[i-1][j-1][k]-DP[i][j-1][k-1]-DP[i-1][j][k-1]+DP[i-1][j-1][k-1]+m[i][j][k];
					else if(i-1>=0&&j-1>=0)
						DP[i][j][k]=DP[i][j-1][k]+DP[i-1][j][k]-DP[i-1][j-1][k]+m[i][j][k];
					else if(i-1>=0&&k-1>=0)
						DP[i][j][k]=DP[i][j][k-1]+DP[i-1][j][k]-DP[i-1][j][k-1]+m[i][j][k];
					else if(j-1>=0&&k-1>=0)
						DP[i][j][k]=DP[i][j][k-1]+DP[i][j-1][k]-DP[i][j-1][k-1]+m[i][j][k];
					else if(i-1>=0)
						DP[i][j][k]=DP[i-1][j][k]+m[i][j][k];
					else if(j-1>=0)
						DP[i][j][k]=DP[i][j-1][k]+m[i][j][k];
					else if(k-1>=0)
						DP[i][j][k]=DP[i][j][k-1]+m[i][j][k];
					else
						DP[i][j][k]=m[i][j][k];

		long long int max=INF; // 之前都設為0,之前類似題目也是,但都AC. 之後我設為 -2e9 ,但依舊WA , 換成INF後,AC了.
		for(i=0;i<A;i++)
			for(j=0;j<B;j++)
				for(k=0;k<C;k++)
					for(z=i;z<A;z++)
						for(y=j;y<B;y++)
							for(x=k;x<C;x++){ // DP[i][j][k] - DP[z][y][x]
								long long int result;
								if(i-1>=0&&j-1>=0&&k-1>=0)
									result=DP[z][y][x]-DP[z][y][k-1]-DP[z][j-1][x]-DP[i-1][y][x]+DP[i-1][j-1][x]+DP[i-1][y][k-1]+DP[z][j-1][k-1]-DP[i-1][j-1][k-1];
								else if(i-1>=0&&j-1>=0)
									result=DP[z][y][x]-DP[z][j-1][x]-DP[i-1][y][x]+DP[i-1][j-1][x];
								else if(i-1>=0&&k-1>=0)
									result=DP[z][y][x]-DP[z][y][k-1]-DP[i-1][y][x]+DP[i-1][y][k-1];
								else if(j-1>=0&&k-1>=0)
									result=DP[z][y][x]-DP[z][y][k-1]-DP[z][j-1][x]+DP[z][j-1][k-1];
								else if(i-1>=0)
									result=DP[z][y][x]-DP[i-1][y][x];
								else if(j-1>=0)
									result=DP[z][y][x]-DP[z][j-1][x];
								else if(k-1>=0)
									result=DP[z][y][x]-DP[z][y][k-1];
								else
									result=DP[z][y][x];
								max=MAX(max,result);
								//printf("DP[%d][%d][%d] - DP[%d][%d][%d] = %d\n",i,j,k,z,y,x,max);
							}
		printf("%lld\n",max);
	}
	return 0;
}
/*

 Farmer John has a heap of garbage formed in a rectangular parallelepiped. 

It consists of garbage pieces each of which has a value. The value of a piece may be 0, if the piece is neither profitable nor harmful, and may be negative which means that the piece is not just unprofitable, but even harmful (for environment).
 
The farmer thinks that he has too much harmful garbage, so he wants to decrease the heap size, leaving a rectangular nonempty parallelepiped of smaller size cut of the original heap to maximize the sum of the values of the garbage pieces in it. You have to find the optimal parallelepiped value. (Actually, if any smaller parallelepiped has value less than the original one, the farmer will leave the original parallelepiped).
 
Input

 The first line of the input contains the number of the test cases, which is at most 15. The descriptions of the test cases follow. The first line of a test case description contains three integers A, B, and C (1 ≤ A, B, C ≤ 20). The next lines contain numbers, which are the values of garbage pieces. Each number does not exceed by absolute value. If we introduce coordinates in the parallelepiped such that the cell in one corner is (1,1,1) and the cell in the opposite corner is (A,B,C), then the values are listed in the order
 
The test cases are separated by blank lines. 

Output

 For each test case in the input, output a single integer denoting the maximal value of the new garbage heap. Print a blank line between test cases.
 
Input

1
2 2 2
-1 2 0 -3 -2 -1 1 5

Output

6
 
*/