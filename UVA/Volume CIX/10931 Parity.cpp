/* 8923532 10931 Parity Accepted C++ 0.012 2011-06-06 08:58:55 */
#include<stdio.h>
int main(){
	unsigned long long i;
	while(scanf("%llu",&i)==1){
		if(i==0) break;
		char str[100];
		int index;
		int count;
		unsigned long long j;
		for(j=1;j<=i;j<<=1);	
		j>>=1;
		for(index=count=0;j>0;j>>=1){
			if(i>=j){
				str[index++]='1';
				count++;
				i-=j;
			}
			else
				str[index++]='0';
		}
		str[index]='\0';		
		printf("The parity of %s is %d (mod 2).\n",str,count);
	} 
	return 0;
}
/*

We define the parity of an integer n as the sum of the bits in binary representation computed modulo two. As an example, the number 21 = 101012 has three 1s in its binary representation so it has parity 3 (mod 2), or 1.
 
In this problem you have to calculate the parity of an integer 1 ≤ I ≤ 2147483647.
 
Input

 Each line of the input has an integer I and the end of the input is indicated by a line where I = 0 that should not be processed.
 
Output

 For each integer I in the inputt you should print a line The parity of B is P (mod 2)., where B is the binary representation of I.
 
Sample Input

1
2
10
21
0

 Sample Output

The parity of 1 is 1 (mod 2).
The parity of 10 is 1 (mod 2).
The parity of 1010 is 2 (mod 2).
The parity of 10101 is 3 (mod 2).

--------------------------------------------------------------------------------
 Problem setter: S�rgio Queiroz de Medeiros 
 
 */