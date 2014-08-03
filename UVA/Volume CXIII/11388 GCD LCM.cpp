/* 9075125 11388 GCD LCM Accepted C++ 0.012 2011-07-24 08:19:00 */
#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int j,GCD,LCM;			
		scanf("%d%d",&GCD,&LCM);
		if(LCM%GCD==0) // input = output if b is divisible by a
			printf("%d %d",GCD,LCM);
		else
			printf("-1");
		putchar('\n');
	}		
	return 0;
}
/*

The GCD of two positive integers is the largest integer that divides both the integers without any remainder. The LCM of two positive integers is the smallest positive integer that is divisible by both the integers. A positive integer can be the GCD of many pairs of numbers. Similarly, it can be the LCM of many pairs of numbers. In this problem, you will be given two positive integers. You have to output a pair of numbers whose GCD is the first number and LCM is the second number.

Input
 
The first line of input will consist of a positive integer T. T denotes the number of cases. Each of the next T lines will contain two positive integer, G and L.

Output
 
For each case of input, there will be one line of output. It will contain two positive integers a and b, a ≤ b, which has a GCD of G and LCM of L. In case there is more than one pair satisfying the condition, output the pair for which a is minimized. In case there is no such pair, output -1.

Constraints
 
-           T ≤ 100

-           Both G and L will be less than 231.

Sample Input
 
2
1 2
3 4 

Output for Sample Input

1 2
-1
 
Problem setter: Shamim Hafiz
  
*/