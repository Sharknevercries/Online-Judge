/* 10014 Simple calculations Accepted C++ 0.008 2011-02-27 11:03:52 */
#include<stdio.h>
int main(){
	int t;
	while(scanf("%d",&t)==1)
		while(t--){
			double a1;
			double a0,an1,tempc;
			int i,n;
			scanf("%d",&n);
			scanf("%lf%lf",&a0,&an1);
			a1=n*a0+an1;
			for(i=n;i>=1;i--){
				scanf("%lf",&tempc);
				a1-=2*i*tempc;
			}
			a1/=(n+1);
			printf("%.2lf\n",a1);
			if(t>0)
				putchar('\n');
		}
	return 0;
}
/*

There is a sequence of n+2 elements a0, a1,¡K, an+1 (n <= 3000; -1000 <=  ai 1000). It is known that ai = (ai¡V1 + ai+1)/2 ¡V ci   for each i=1, 2, ..., n. You are given a0, an+1, c1, ... , cn. Write a program which calculates a1.

The Input

The first line is the number of test cases, followed by a blank line.

For each test case, the first line of an input file contains an integer n. The next two lines consist of numbers a0 and an+1 each having two digits after decimal point, and the next n lines contain numbers ci (also with two digits after decimal point), one number per line. 

Each test case will be separated by a single line.

The Output

For each test case, the output file should contain a1 in the same format as a0 and an+1. 

Print a blank line between the outputs for two consecutive test cases.

Sample Input

1

1
50.50
25.50
10.15

Sample Output

27.85

*/