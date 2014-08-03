/* 9069575 11296 Counting Solutions to an Integral Equation Accepted C++ 0.008 2011-07-22 08:36:00 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int t=n/2;
		printf("%llu\n",(unsigned long long )(t+1+1)*(t+1)/2);
	}
	return 0;
}
/*

 Given, n, count the number of solutions to the equation x+2y+2z=n, where x,y,z,n are non negative integers.
 
The Input
 
There is at most 1500 inputs. Each input is n (n<1000001) on a single line. 

The Output
 
For each input, output the number of solutions on a single line. 

Sample Input
 
2
3

Sample Output
 
3
3

--------------------------------------------------------------------------------
 Problem setter: Josh Bao 

*/