/* 9130898 11226 Reaching the fix-point. Accepted C++ 0.112 2011-08-09 14:48:14 */
#include<stdio.h>
#include<math.h>
#define YES 0
#define SWAP(x,y) { int tmp=x; x=y; y=tmp; }
#define UNKNOW 0
int result_sopf[500001]={UNKNOW};
int result_isopf[500001]={UNKNOW};
int is_prime(int n){
	int i,gap;
	if(n==2||n==3||n==5)
		return YES;
	if((n&1)==0)
		return 2;
	if(n%3==0)
		return 3;
	for(i=5,gap=2;i<=sqrt((double)n);i+=gap,gap=6-gap)
		if(n%i==0)
			return i;
	return YES;
}
int sopf(int n){	
	int sum;	
	int index=is_prime(n);
	if(index==YES)
		sum=n;
	else	
		sum=result_sopf[index]+result_sopf[n/index];	
	return sum;
}
int isopf(int n){
	int temp;
	temp= result_sopf[n];
	temp = (temp==n) ? 0 : isopf(temp) ;
	return 1+temp;
}
int main(){
	int i;
	for(i=1;i<=500000;i++){
		result_sopf[i]=sopf(i);	
		result_isopf[i]=isopf(i);	
	}
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		int i,a,b,max;		
		scanf("%d%d",&a,&b);
		if(a>b)
			SWAP(a,b);

		for(max=-1,i=a;i<=b;i++)
			if(result_isopf[i]>max)
				max=result_isopf[i];

		printf("Case #%d:\n",t);
		printf("%d\n",max);
	}
	return 0;
}
/*

A prime number p is a natural number greater than 1 that has only two natural divisors: 1 and p itself. Any natural number n, such that n > 1, has a unique decomposition into prime factors, for instance 4 = 2 × 2, 5 = 5, 6 = 2 × 3. 

Let sopf(n) denote the sum of the prime factors of a natural number n. For instance, sopf(4) = 2 + 2 = 4, sopf(5) = 5, and sopf(6) = 2 + 3 = 5. 

If we take the result of this sum, we may compute again the sum of its prime factors, and repeat this ad nauseam. However, at some point, we always reach a fix-point, that is a number f such that f = sopf(f). For instance, starting from 8, sopf(8) = 2 + 2 + 2 = 6, then sopf(6) = 2 + 3 = 5, and sopf(5) = 5: applying repetitively sopf from 8 generates the sequence 8, 6, 5, 5, 5,... So, from the initial value 8, it takes 3 applications of sopf to discover that we have reached a fix-point.

Let lsopf(n) denote the number of applications of sopf from n that is required to discover that the fix-point has been reached. For instance, lsopf(8) = 3 and lsopf(4) = 1.

Your task is, given two natural numbers n and m (with n > 1 and m > 1), find the largest value the function lsopf takes in the interval between n and m.
 
Input

The first line of input gives the number of cases, T (with 1 ≤ T ≤ 150). T test cases follow. Each test case is on a single line, containing two natural numbers n and m, such that 1 < n, m ≤ 500000. 

Output

 For each test case first print a line "Case #C:" (where C is the number of the current test case). Then print another line with the maximum of the function lsopf in the interval bounded by n and m.
 
Sample input

2
2 10
11 20

Sample output

Case #1:
3
Case #2:
4

--------------------------------------------------------------------------------
 
Problem setter: David Deharbe.
 Universidade Federal do Rio Grande do Norte Qualifying Contest IV, June 9th, 2007.

*/