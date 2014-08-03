/* 4803135	 Oct 16, 2013 10:50:55 AM	Shark	 248B - Chilly Willy	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		if( n==1||n==2 )
			puts("-1");
		else if( n==3 ) // special
			puts("210");
		else if( n==4 ) // special
			puts("1050");
		else{
			int digit=n-4;
			int M=50;
			putchar('1');
			for(int i=1;i<=digit;i++){
				putchar('0');
				M*=10;
				while( M>=210 )
					M-=210;
			}
			printf("%03d\n",M);
		}
	}
	return 0;
}
/*

B. Chilly Willy
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Chilly Willy loves playing with numbers. He only knows prime numbers that are digits yet. These numbers are 2, 3, 5 and 7. But Willy grew rather bored of such numbers, so he came up with a few games that were connected with them.

Chilly Willy wants to find the minimum number of length n, such that it is simultaneously divisible by all numbers Willy already knows (2, 3, 5 and 7). Help him with that.

A number's length is the number of digits in its decimal representation without leading zeros.

Input
A single input line contains a single integer n (1 ≤ n ≤ 105).

Output
Print a single integer — the answer to the problem without leading zeroes, or "-1" (without the quotes), if the number that meet the problem condition does not exist.

Sample test(s)
input
1
output
-1
input
5
output
10080

*/