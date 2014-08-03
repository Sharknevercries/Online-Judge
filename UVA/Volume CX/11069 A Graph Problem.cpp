/* 9116442 11069 A Graph Problem Accepted C++ 0.012 2011-08-05 09:12:00 */
#include<stdio.h>
int main(){
	int DP[77];
	DP[0]=DP[1]=1;
	DP[2]=2;
	for(int i=3;i<=76;i++)
		DP[i]=DP[i-2]+DP[i-3];
	int n;
	while(scanf("%d",&n)==1){
		printf("%d\n",DP[n]);
	}
	return 0;
}
/*

Given an undirected graph of the following form with n nodes, 1 ≤ n ≤ 76: 

Your task is to calculate the number of subsets of nodes of the graph with the following properties:
 • no nodes in the subset should be connected 
• it shouldn't be possible to add further nodes to the subset without violating the first condition 
For a graph with 5 nodes the number of subsets which fulfill the above conditions is 4. The subsets are {1,3,5},{2,4},{2,5},{1,4}.
 
Input
 
The input will consist of a sequence of numbers n,1 ≤ n ≤ 76. Each number will be on a separate line. The input will be terminated by EOF.
 
Output
 
Output the number of subsets as described above on a single line. The number of all subsets will be less than 2^31.
 
Sample input

1
2
3
4
5
30

 Sample output

1
2
2
3
4
4410
 
--------------------------------------------------------------------------------
FAU Local Summer Contest 2005 
Author: Der General 

*/