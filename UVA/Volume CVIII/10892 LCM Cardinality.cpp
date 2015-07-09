/* 8935481 10892 LCM Cardinality Accepted C++ 0.096 2011-06-10 11:47:10 */
#include<stdio.h>
#include<math.h>
unsigned long long GCD(unsigned long long x,unsigned long long y){
	int r;
	do{
		r=x%y;
		x=y;
		y=r;
	}while(r!=0);
	return x;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		
		if(n==0) break;
		if(n==1) {	printf("1 1\n"); continue; }
		int sq=sqrt((double)n);
		int m[100000],index;
		int count;
		unsigned long long i,j;
		for(i=1,index=0;i<=sq;i++)
			if(n%i==0){
				m[index++]=i;
				if(i!=n/i)
					m[index++]=n/i;
			}
		for(i=count=0;i<index;i++)
			for(j=i;j<index;j++)
				if(m[i]/GCD(m[i],m[j])==n/m[j])
					count++;
		printf("%d %d\n",n,count);
	}
	return 0;
}
/*

A pair of numbers has a unique LCM but a single number can be the LCM of more than one possible pairs. For example 12 is the LCM of (1, 12), (2, 12), (3,4) etc. For a given positive integer N, the number of different integer pairs with LCM is equal to N can be called the LCM cardinality of that number N. In this problem your job is to find out the LCM cardinality of a number.

Input

The input file contains at most 101 lines of inputs. Each line contains an integer N (0<N<=2*109). Input is terminated by a line containing a single zero. This line should not be processed. 

Output 

For each line of input except the last one produce one line of output. This line contains two integers N and C. Here N is the input number and C is its cardinality. These two numbers are separated by a single space.

Sample Input                             

2
12
24
1011012910
 
Output for Sample Input

2 2
12 8
24 11
101101291 5

--------------------------------------------------------------------------------

Problem setter: Shahriar Manzoor

Special Thanks: Derek Kisman

*/