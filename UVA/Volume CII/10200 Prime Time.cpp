/* 8845995 10200 Prime Time Accepted C++ 0.048 2011-05-15 04:09:26 */
#include<stdio.h>
#define eps 1e-9
int main(){
	int a,b;
	int i,j,gap;
	bool table[10001]={false};
	for(i=0;i<=10000;i++){
			int may_be_prime=i*i+i+41;
			if((may_be_prime&1)==0)		continue;
			if(may_be_prime%3==0)	continue;
			for(j=5,gap=4;j*j<=may_be_prime;j+=gap){
				gap=6-gap;
				if(may_be_prime%j==0)
					break;		
			}
			if(j*j>may_be_prime)
				table[i]=true;
		}
	while(scanf("%d%d",&a,&b)==2){
		int count;
		for(i=a,count=0;i<=b;i++)
			if(table[i])
				count++;
		printf("%.2lf\n",(count*100.0)/(b-a+1)+eps); // 不知道為何要加eps 不過這樣就AC了
	}
	return 0;
}
/*

The Problem
 
Euler is a well-known matematician, and, among many other things, he discovered that the formula n^2 + n + 41 produces a prime for 0 <= n < 40. For n = 40, the formula produces 1681, which is 41 * 41. Even though this formula doesn't always produce a prime, it still produces a lot of primes. It's known that for n <= 10000000, there are 47,5% of primes produced by the formula!
 
So, you'll write a program that will output how many primes does the formula output for a certain interval.
 
The Input
 
Each line of input will be given two positive integer a and b such that 0 <= a <= b <= 10000. You must read until the end of the file.
 
The Output
 
For each pair a,b read, you must output the percentage of prime numbers produced by the formula in this interval (a <= n <= b) rounded to two decimal digits (with round half up rule).
 
Sample Input
 
0 39
0 40
39 40
1423 2222
  
Sample Output 

100.00
97.56
50.00
44.13

--------------------------------------------------------------------------------
 © 2001 Universidade do Brasil (UFRJ). Internal Contest 2001. 

 */
