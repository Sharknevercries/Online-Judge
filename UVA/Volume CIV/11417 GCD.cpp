/* 9075044 11417 GCD Accepted C++ 0.012 2011-07-24 07:50:22 */
#include<stdio.h>
int GCD(int a,int b){
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main(){
	int result[501];
	int i,N,t;
	result[1]=0;
	for(N=2;N<=500;N++){
		result[N]=result[N-1];
		for(i=1;i<N;i++)
			result[N]+=GCD(i,N);
	}
	while(scanf("%d",&t)==1&&t!=0){				
		printf("%d\n",result[t]);
	}
	return 0;
}
/*

Given the value of N, you will have to find the value of G. The definition of G is given below:

Here GCD(i,j) means the greatest common divisor of integer i and integer j.

For those who have trouble understanding summation notation, the meaning of G is given in the following code:

G=0;

for(i=1;i<N;i++)

for(j=i+1;j<=N;j++)

{

    G+=GCD(i,j);

}

Here GCD() is a function that finds the greatest common divisor of the two input numbers

Input

The input file contains at most 100 lines of inputs. Each line contains an integer N (1<N<501). The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.  This zero should not be processed.
 
Output 

For each line of input produce one line of output. This line contains the value of G for corresponding N. 

Sample Input                              

10
100
500

Output for Sample Input

0
67
13015
442011
 
--------------------------------------------------------------------------------

Problemsetter: Shahriar Manzoor

Special Thanks: Syed Monowar Hossain
 
*/