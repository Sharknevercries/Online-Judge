/* 4853795	 Oct 23, 2013 6:57:29 PM	Shark	 70A - Cookies	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
#define MOD 1000003
long long int power(int n){
	if( n==0 )
		return 1;
	else if( (n&1)==0 ){
		long long int tmp=power(n>>1)%MOD;
		return (tmp*tmp)%MOD;
	}
	else
		return (3*power(n-1))%MOD;
}
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		if( n==0 )
			puts("1");
		else
			printf("%lld\n",power(n-1));
	}
	return 0;
}
/*

A. Cookies
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fangy collects cookies. Once he decided to take a box and put cookies into it in some way. If we take a square k × k in size, divided into blocks 1 × 1 in size and paint there the main diagonal together with cells, which lie above it, then the painted area will be equal to the area occupied by one cookie k in size. Fangy also has a box with a square base 2n × 2n, divided into blocks 1 × 1 in size. In a box the cookies should not overlap, and they should not be turned over or rotated. See cookies of sizes 2 and 4 respectively on the figure:


To stack the cookies the little walrus uses the following algorithm. He takes out of the repository the largest cookie which can fit in some place in the box and puts it there. Everything could be perfect but alas, in the repository the little walrus has infinitely many cookies of size 2 and larger, and there are no cookies of size 1, therefore, empty cells will remain in the box. Fangy wants to know how many empty cells will be left in the end.

Input
The first line contains a single integer n (0 ≤ n ≤ 1000).

Output
Print the single number, equal to the number of empty cells in the box. The answer should be printed modulo 106 + 3.

Sample test(s)
input
3
output
9
Note
If the box possesses the base of 23 × 23 (as in the example), then the cookies will be put there in the following manner:

*/