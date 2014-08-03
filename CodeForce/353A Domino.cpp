/* 4743705	 Oct 11, 2013 2:09:13 PM	Shark	 353A - Domino	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int S1[100];
		int S2[100];
		for(int i=0;i<n;i++)
			scanf("%d%d",&S1[i],&S2[i]);

		int sum1=0,sum2=0;
		for(int i=0;i<n;i++)
			sum1+=S1[i],sum2+=S2[i];
		if( ((sum1&1)==0&&(sum2&1)==0)||((sum1&1)==1&&(sum2&1)==1) )
			if( (sum1&1)==0&&(sum2&1)==0 )
				puts("0");
			else{
				bool found=false;
				for(int i=0;i<n;i++)
					if( ((S1[i]&1)==0&&(S2[i]&1)==1)||((S1[i]&1)==1&&(S2[i]&1)==0) )
						found=true;
				if( found )
					puts("1");
				else
					puts("-1");
			}
		else
			puts("-1");
	}
	return 0;
}
/*

A. Domino
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Valera has got n domino pieces in a row. Each piece consists of two halves — the upper one and the lower one. Each of the halves contains a number from 1 to 6. Valera loves even integers very much, so he wants the sum of the numbers on the upper halves and the sum of the numbers on the lower halves to be even.

To do that, Valera can rotate the dominoes by 180 degrees. After the rotation the upper and the lower halves swap places. This action takes one second. Help Valera find out the minimum time he must spend rotating dominoes to make his wish come true.

Input
The first line contains integer n (1 ≤ n ≤ 100), denoting the number of dominoes Valera has. Next n lines contain two space-separated integers xi, yi (1 ≤ xi, yi ≤ 6). Number xi is initially written on the upper half of the i-th domino, yi is initially written on the lower half.

Output
Print a single number — the minimum required number of seconds. If Valera can't do the task in any time, print  - 1.

Sample test(s)
input
2
4 2
6 4
output
0
input
1
2 3
output
-1
input
3
1 4
2 3
4 4
output
1
Note
In the first test case the sum of the numbers on the upper halves equals 10 and the sum of the numbers on the lower halves equals 6. Both numbers are even, so Valera doesn't required to do anything.

In the second sample Valera has only one piece of domino. It is written 3 on the one of its halves, therefore one of the sums will always be odd.

In the third case Valera can rotate the first piece, and after that the sum on the upper halves will be equal to 10, and the sum on the lower halves will be equal to 8.

*/