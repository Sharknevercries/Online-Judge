/* 1214264	 Feb 21, 2012 4:51:37 PM	Shark	 122A - Lucky Division	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int M[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};	
	int k=sizeof(M)/sizeof(int);
	int n;
	while(scanf("%d",&n)==1){	
		bool T=false;
		for(int i=0;i<k&&!T;i++)
			if(n%M[i]==0)
				T=true;
		if(T)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.

Input

The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output

In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).

input

47
16
78

output

YES
YES
NO

Note

Note that all lucky numbers are almost lucky as any number is evenly divisible by itself.

In the first sample 47 is a lucky number. In the second sample 16 is divisible by 4.

*/