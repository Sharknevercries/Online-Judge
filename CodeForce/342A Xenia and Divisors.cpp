/* 4655285	 Oct 4, 2013 1:06:19 PM	Shark	 342A - Xenia and Divisors	 GNU C++	Accepted	62 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[8]={0};
		int A[3]={0}; // (1,2,4),(1,2,6),(1,3,6)
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			M[tmp]++;
		}
		if( M[7]>0||M[5]>0 )
			printf("%d\n",-1);
		else{
			if( M[1]>=M[4]&&M[2]>=M[4]&&M[4]>=0 )
				A[0]+=M[4],M[1]-=M[4],M[2]-=M[4],M[4]=0;
			if( M[1]>=M[2]&&M[6]>=M[2]&&M[2]>=0 )
				A[1]+=M[2],M[1]-=M[2],M[6]-=M[2],M[2]=0; 
			if( M[1]>=M[3]&&M[6]>=M[3]&&M[3]>=0 )
				A[2]+=M[3],M[1]-=M[3],M[6]-=M[3],M[3]=0;
			if( M[1]+M[2]+M[3]+M[4]+M[6]==0 ){
				for(int i=0;i<A[0];i++)
					puts("1 2 4");
				for(int i=0;i<A[1];i++)
					puts("1 2 6");
				for(int i=0;i<A[2];i++)
					puts("1 3 6");
			}
			else
				printf("%d\n",-1);
		}
	}
	return 0;
}
/*

A. Xenia and Divisors
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Xenia the mathematician has a sequence consisting of n (n is divisible by 3) positive integers, each of them is at most 7. She wants to split the sequence into groups of three so that for each group of three a, b, c the following conditions held:

a < b < c;
a divides b, b divides c.
Naturally, Xenia wants each element of the sequence to belong to exactly one group of three. Thus, if the required partition exists, then it has  groups of three.

Help Xenia, find the required partition or else say that it doesn't exist.

Input
The first line contains integer n (3 ≤ n ≤ 99999) — the number of elements in the sequence. The next line contains n positive integers, each of them is at most 7.

It is guaranteed that n is divisible by 3.

Output
If the required partition exists, print  groups of three. Print each group as values of the elements it contains. You should print values in increasing order. Separate the groups and integers in groups by whitespaces. If there are multiple solutions, you can print any of them.

If there is no solution, print -1.

Sample test(s)
input
6
1 1 1 2 2 2
output
-1
input
6
2 2 1 1 4 6
output
1 2 4
1 2 6

*/