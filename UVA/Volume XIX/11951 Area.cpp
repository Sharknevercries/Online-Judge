/* 12412828	11951	Area	Accepted	C++	0.965	2013-09-28 10:05:12 */
#include<stdio.h>
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int N,M,K;
		int S[101][101];
		int DP[101][101]={0};
		int minCost,maxArea;

		scanf("%d%d%d",&N,&M,&K);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				scanf("%d",&S[i][j]);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				DP[i][j]=DP[i][j-1]+S[i][j];
		
		minCost=maxArea=0;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				for(int k=1;k<=j;k++){
					int cost=0,area=0;
					for(int p=0;i+p<=N;p++){
						cost+=DP[i+p][j]-DP[i+p][k-1],area+=(j-k+1);
						if( cost<=K ){
							if( area>maxArea )
								maxArea=area,minCost=cost;
							else if( area==maxArea&&minCost>cost )
								minCost=cost;
						}
						else
							break;
					}
				}
		printf("Case #%d: %d %d\n",T,maxArea,minCost);
	}
	return 0;
}
/*

A  — Area

Time Limit: 1 sec
Memory Limit: 32 MB
Steve has a dream to move from dormitory where we live now to a private house. He has already earned some money by solving various problems and now wants to make a first move towards his dream. Steve is going to buy a plot for his future house. However, due to high tax rate, he is going to buy only one plot. Certainly Steve wants to maximize its area for the amount of money he owns (and if there are several plots of same area, Steve certainly chooses a cheaper one). Can you help Steve?

The whole district where Steve wants to reside is divided into N * M equal strips. Each strip is sold separately, for its own price Pi;j. According to the country law, plot is defined as a rectangular collection of strips with sides parallel to the district.

INPUT

There is a number of tests T (T ≤ 110) on the first line. After T tests follows. Each test case is defined by three numbers N M K (N; M ≤ 100; K ≤ 109). Next N lines with M numbers each stands for prices of the strips Pi;j (Pi;j ≤ 106).

OUTPUT

For each test print a line formatted as "Case #T: S P", where T stands for test case number (starting from 1), S for maximal plot area that Steve can afford and P for plot’s total cost.

SAMPLE INPUT

1
5 6 15
10 1 10 20 10 10
30 1 1 5 1 1
50 1 1 20 1 1
10 5 5 10 5 1
40 10 90 1 10 10
SAMPLE OUTPUT

Case #1: 6 10
Problem by: Aleksej Viktorchik; Leonid Sislo
Huge Easy Contest #2

*/