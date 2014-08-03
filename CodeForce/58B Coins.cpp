/* 4677011	 Oct 5, 2013 7:33:13 AM	Shark	 58B - Coins	 GNU C++	Accepted	30 ms	400 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[100000];
		int ptr=0,i,j;
		for(i=n;i>=1;i--){
			for(j=0;j<ptr;j++)
				if( M[j]%i!=0 )
					break;
			if( j>=ptr )
				M[ptr++]=i;
		}
		for(i=0;i<ptr;i++)
			if( i==0 )
				printf("%d",M[i]);
			else
				printf(" %d",M[i]);
		putchar('\n');
	}
	return 0;
}
/*

B. Coins
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
In Berland a money reform is being prepared. New coins are being introduced. After long economic calculations was decided that the most expensive coin should possess the denomination of exactly n Berland dollars. Also the following restriction has been introduced for comfort: the denomination of each coin should be divisible by the denomination of any cheaper coin. It is known that among all the possible variants the variant with the largest number of new coins will be chosen. Find this variant. Print in the order of decreasing of the coins' denominations.

Input
The first and only line contains an integer n (1 ≤ n ≤ 106) which represents the denomination of the most expensive coin.

Output
Print the denominations of all the coins in the order of decreasing. The number of coins must be the largest possible (with the given denomination n of the most expensive coin). Also, the denomination of every coin must be divisible by the denomination of any cheaper coin. Naturally, the denominations of all the coins should be different. If there are several solutins to that problem, print any of them.

Sample test(s)
input
10
output
10 5 1
input
4
output
4 2 1
input
3
output
3 1

*/