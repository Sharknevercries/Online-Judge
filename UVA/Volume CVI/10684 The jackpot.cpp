/*8893098 10684 The jackpot Accepted C++ 0.084 2011-05-27 14:56:39 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		if(n==0)
			break;		
		int i,max;
		int m[10000];
		int DP[10000]={0};
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);
		max=0;
		if(m[0]>0){
			DP[0]=m[0];
			max=DP[0];
		}
		else
			DP[0]=0;
		for(i=1;i<n;i++){
			DP[i]=DP[i-1]+m[i];
			if(DP[i]<0)
				DP[i]=0;
			if(max<DP[i])
				max=DP[i];
		}
		if(max>0)
			printf("The maximum winning streak is %d.\n",max);
		else
			puts("Losing streak.");
	}
	return 0;
}
/*

Background 

As Manuel wants to get rich fast and without too much work, he decided to make a career in gambling. Initially, he plans to study the gains and losses of players, so that, he can identify patterns of consecutive wins and elaborate a win-win strategy. But Manuel, as smart as he thinks he is, does not know how to program computers. So he hired you to write programs that will assist him in elaborating his strategy.
 
The Problem 

Your first task is to write a program that identifies the maximum possible gain out of a sequence of bets. A bet is an amount of money and is either winning (and this is recorded as a positive value), or losing (and this is recorded as a negative value).
 
Input 

The input set consists of a positive number N ≤ 10000 , that gives the length of the sequence, followed by N integers. Each bet is an integer greater than 0 and less than 1000. 

The input is terminated with N = 0. 

Output 

For each given input set, the output will echo a line with the corresponding solution. If the sequence shows no possibility to win money, then the output is the message "Losing streak."
 
Sample input 

5
12 -4 -10 4 9
3
-2 -1 -20 

Sample output 

The maximum winning streak is 13.
Losing streak. 

--------------------------------------------------------------------------------

David Deharbe 2004-06-19 

*/