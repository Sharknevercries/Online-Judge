/* 12416659	10616	Divisible Group Sums	Accepted	C++	0.025	2013-09-29 03:04:39 */
#include<stdio.h>
#define MAXN 200
#define MAXM 10
#define MAXD 20
int Solve(int S[],int N,int D,int M){
	int DP[MAXN+1][MAXM+1][MAXD+1]={0}; // DP(i,j,k): 至 i 時,已選 j 個,其和模D為 k,之數量
	DP[0][0][0]=1;
	for(int i=1;i<=N;i++)
		for(int j=0;j<=i&&j<=M;j++)
			for(int k=0;k<D;k++){
				DP[i][j][k]=DP[i-1][j][k];
				
				if( j-1>=0 ){
					int tmp=(D+k-S[i]%D)%D;
					DP[i][j][k]+=DP[i-1][j-1][tmp];
				}
			}
	return DP[N][M][0];
}
int main(){
	int N,M,Q,D;
	int T=1;
	while( scanf("%d%d",&N,&Q)==2 ){
		if( N==0&&Q==0 )
			break;

		int S[201];
		for(int i=1;i<=N;i++)
			scanf("%d",&S[i]);

		printf("SET %d:\n",T);
		for(int i=1;i<=Q;i++){
			scanf("%d%d",&D,&M);
			printf("QUERY %d: %d\n",i,Solve(S,N,D,M));
		}
		T++;
	}
	return 0;
}
/*

Problem H
Divisible Group Sums
Input: Standard Input
Output: Standard Output
Time Limit: 1 Second
 
Given a list of N numbers you will be allowed to choose any M of them. So you can choose in NCM ways. You will have to determine how many of these chosen groups have a sum, which is divisible by D.
 
Input
The input file contains maximum ten sets of inputs. The description of each set is given below.
 
The first line of each set contains two integers N (0<N<=200) and Q (0<Q<=10). Here N indicates how many numbers are there and Q is the total no of query. Each of the next N lines contains one 32 bit signed integer. Our queries will have to be answered based on these N numbers. Next Q lines contain Q queries. Each query contains two integers D (0<D<=20) and M (0<M<=10) whose meanings are explained in the first paragraph.
 
Input is terminated by a case whose N=0 and Q=0. This case should not be processed.
 
Output
For each set of input, print the set number. Then for each query in the set print the query number followed by the number of desired groups. See sample output to know the exact output format.
 
Sample Input                             Output for Sample Input
10 2
1
2
3
4
5
6
7
8
9
10
5 1
5 2
5 1
2
3
4
5
6
6 2
0 0
SET 1:
QUERY 1: 2
QUERY 2: 9
SET 2:
QUERY 1: 1
Problemsetter: Shahriar Manzoor, Member of Elite Problemsetters' Panel

*/