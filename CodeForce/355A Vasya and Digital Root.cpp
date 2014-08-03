/* 4771030	 Oct 13, 2013 8:01:47 PM	Shark	 355A - Vasya and Digital Root	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
int main(){
	int k,d;
	while( scanf("%d%d",&k,&d)==2 ){
		if( d==0 )
			if( k==1 )
				puts("0");
			else
				puts("No solution");
		else{
			char ans[1001];
			for(int i=1;i<k;i++)
				ans[i]='0';
			ans[k]='\0';
			if( k==1 )
				ans[0]='0'+d;
			else{
				ans[0]='1';
				ans[k-1]='0'+d-1;
			}
			printf("%s\n",ans);
		}
	}
	return 0;
}
/*

A. Vasya and Digital Root
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has recently found out what a digital root of a number is and he decided to share his knowledge with you.

Let's assume that S(n) is the sum of digits of number n, for example, S(4098) = 4 + 0 + 9 + 8 = 21. Then the digital root of number n equals to:

dr(n) = S(n), if S(n) < 10;
dr(n) = dr( S(n) ), if S(n) ≥ 10.
For example, dr(4098)  =  dr(21)  =  3.

Vasya is afraid of large numbers, so the numbers he works with are at most 101000. For all such numbers, he has proved that dr(n)  =  S( S( S( S(n) ) ) ) (n ≤ 101000).

Now Vasya wants to quickly find numbers with the given digital root. The problem is, he hasn't learned how to do that and he asked you to help him. You task is, given numbers k and d, find the number consisting of exactly k digits (the leading zeroes are not allowed), with digital root equal to d, or else state that such number does not exist.

Input
The first line contains two integers k and d (1 ≤ k ≤ 1000; 0 ≤ d ≤ 9).

Output
In a single line print either any number that meets the requirements (without the leading zeroes) or "No solution" (without the quotes), if the corresponding number does not exist.

The chosen number must consist of exactly k digits. We assume that number 0 doesn't contain any leading zeroes.

Sample test(s)
input
4 4
output
5881
input
5 1
output
36172
input
1 0
output
0
Note
For the first test sample dr(5881)  =  dr(22)  =  4.

For the second test sample dr(36172)  =  dr(19)  =  dr(10)  =  1.

*/