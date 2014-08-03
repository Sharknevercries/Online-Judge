/* 9074814 674 Coin Change Accepted C++ 0.036 2011-07-24 07:02:14 */
#include<stdio.h>
int main(){
	int size[]={1,5,10,25,50};
	int DP[8000]={0};
	int i,j;
	int n=sizeof(size)/sizeof(int);
	DP[0]=1;
	for(i=0;i<n;i++)
		for(j=size[i];j<8000;j++)
			DP[j]+=DP[j-size[i]];
	int t;
	while(scanf("%d",&t)==1)
		printf("%d\n",DP[t]);	
	return 0;
}
/*

Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent. We want to make changes with these coins for a given amount of money.
 
For example, if we have 11 cents, then we can make changes with one 10-cent coin and one 1-cent coin, two 5-cent coins and one 1-cent coin, one 5-cent coin and six 1-cent coins, or eleven 1-cent coins. So there are four ways of making changes for 11 cents with the above coins. Note that we count that there is one way of making change for zero cent.
 
Write a program to find the total number of different ways of making changes for any amount of money in cents. Your program should be able to handle up to 7489 cents.
 
Input

The input file contains any number of lines, each one consisting of a number for the amount of money in cents.
 
Output  

For each input line, output a line containing the number of different ways of making changes with the above 5 types of coins.
 
Sample Input  

11
26

Sample Output 

4
13

--------------------------------------------------------------------------------

Miguel Revilla 
2000-08-14 

*/