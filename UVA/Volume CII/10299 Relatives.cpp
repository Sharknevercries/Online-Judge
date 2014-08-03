/* 9133983 10299 Relatives Accepted C++ 0.340 2011-08-10 09:43:19 */
#include<stdio.h>
#include<math.h>
#define MAX 100000
int fac(int prime[],int n){
	int i,gap,index;
	index=0;
	if(n%2==0){
		prime[index++]=2;
		while(n%2==0)
			n/=2;
	}
	if(n%3==0){
		prime[index++]=3;
		while(n%3==0)
			n/=3;
	}
	for(i=5,gap=2;i<=sqrt((double)n)&&n>1;i+=gap,gap=6-gap)
		if(n%i==0){
		prime[index++]=i;
		while(n%i==0)
			n/=i;
	}
	if(n>1)
		prime[index++]=n;
	return index;
}
int main(){
	int prime[MAX];
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		int index=fac(prime,n);
		unsigned long long result= (n==1) ? 0 : n ;
		for(int i=0;i<index;i++) // n = a1^k1 * a2^k2 ...
			result=(result/prime[i])*(prime[i]-1); // result = n * (1 - 1/a1) * (1 - 1/a2) ...
		printf("%llu\n",result);
	}
	return 0;
}
/*

 Given n, a positive integer, how many positive integers less than n are relatively prime to n? Two integers a and b are relatively prime if there are no integers x > 1, y > 0, z > 0 such that a = xy and b = xz.
 There are several test cases. For each test case, standard input contains a line with n <= 1,000,000,000. A line containing 0 follows the last case.
 
For each test case there should be single line of output answering the question posed above.
 
Sample Input

7
12
0
 
Output for Sample Input

6
4
 
 */