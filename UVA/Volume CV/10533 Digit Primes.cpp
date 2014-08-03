/* 9130566 10533 Digit Primes Accepted C++ 0.468 2011-08-09 13:22:21 */
#include<stdio.h>
#include<math.h>
#define UNKNOW 0
int result[1000001]={UNKNOW};
int index;
int check(int n){	
	if(n==1)
		return false;
	if(n==2||n==3||n==5)
		return true;
	if((n&1)==0||n%3==0)
		return false;
	int limit=sqrt((double)n);
	int i,gap;
	for(i=5,gap=2;i<=limit;i+=gap,gap=6-gap)
		if(n%i==0)
			return false;
	return true;
}
void make_result(){
	index=0;
	int i,j;
	for(i=1;i<=1000000;i++)
		if(check(i)){
			int temp;
			for(j=0,temp=i;temp>0;j+=(temp%10),temp/=10);
			if(check(j))
				result[index++]=i;
		}
	result[index]=result[index-1]+10000;
	index++;
}
int search(int n,int left,int right){
	int mid;
	while(right-1>left){
		mid=(left+right)/2;
		if(result[mid]>n)
			right=mid;
		else if(result[mid]==n)
			return mid;
		else
			left=mid;
	}
	return left;
}
int main(){
	make_result();
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		int L,R;		
		int a,b;
		scanf("%d%d",&a,&b);	

		L=search(a,0,index-1);
		if(result[L]!=a&&result[L]<a)
			L++;
		R=search(b,0,index-1);;
		printf("%d\n",R-L+1);
	}
	return 0;
}
/*

A prime number is a positive number, which is divisible by exactly two different integers. A digit prime is a prime number whose sum of digits is also prime. For example the prime number 41 is a digit prime because 4+1=5 and 5 is a prime number. 17 is not a digit prime because 1+7 = 8, and 8 is not a prime number. In this problem your job is to find out the number of digit primes within a certain range less than 1000000.

Input

First line of the input file contains a single integer N (0<N<=500000) that indicates the total number of inputs. Each of the next N lines contains two integers t1 and t2 (0<t1<=t2<1000000).
 
Output

For each line of input except the first line produce one line of output containing a single integer that indicates the number of digit primes between t1 and t2 (inclusive).

Sample Input 

3
10 20
10 100
100 10000
 
1
10
576

--------------------------------------------------------------------------------

Problemsetter: Shahriar Manzoor, Member of Elite Problemsetters' Panel

Note: You should at least use scanf() and printf() to take input and produce output for this problem. cin and cout is too slow for this problem to get it within time limit.

*/