/* 8846418 10235 Simply Emirp Accepted C++ 0.028 2011-05-15 07:05:03 */
#include<stdio.h>
#include<math.h>
int main(){
	long long int n;
	while(scanf("%lld",&n)==1){
		long long int i,gap,limit;
		bool is_prime=true;
		if(n!=2&&n!=3){
			if((n&1)==0) is_prime=false;
			if(n%3==0) is_prime=false;
			limit=(int)ceil(sqrt((double)n));
			for(i=5,gap=4;i<=limit;i+=gap){
				gap=6-gap;
				if(n%i==0)
					break;
			}
			if(i<=limit)
				is_prime=false;			
		}
		if(n==1)
			is_prime=false;
		if(is_prime){
			long long int emirp=0;
			for(i=n;i>0;emirp*=10){
				emirp+=i%10;
				i/=10;
			}
			emirp/=10;
			if(emirp==n) is_prime=false;
			if(emirp!=2&&emirp!=3){
				if((emirp&1)==0) is_prime=false;
				if(emirp%3==0) is_prime=false;
				limit=(int)ceil(sqrt((double)emirp));
				for(i=5,gap=4;i<=limit;i+=gap){
					gap=6-gap;
					if(emirp%i==0)
						break;
				}
				if(i<=limit)
					is_prime=false;
				
			}
			if(is_prime)
				printf("%lld is emirp.\n",n);
			else
				printf("%lld is prime.\n",n);
		}
		else
			printf("%lld is not prime.\n",n);

	}
	return 0;
}
/*

An integer greater than 1 is called a prime number if its only positive divisors (factors) are 1 and itself. Prime numbers have been studied over the years by a lot of mathematicians. Applications of prime numbers arise in Cryptography and Coding Theory among others.

Have you tried reversing a prime ? For most primes, you get a composite (43 becomes 34). An Emirp (Prime spelt backwards) is a Prime that gives you a different Prime when its digits are reversed. For example, 17 is Emirp because 17 as well as 71 are Prime. In this problem, you have to decide whether a number N is Non-prime or Prime or Emirp. Assume that 1< N< 1000000.

Interestingly, Emirps are not new to NTU students. We have been boarding 199 and 179 buses for quite a long time!

Input

 Input consists of several lines specifying values for N.

Output

For each N given in the input, output should contain one of the following:

    1. "N is not prime.", if N is not a Prime number.
    2. "N is prime.", if N is Prime and N is not Emirp.
    3. "N is emirp.", if N is Emirp.
	 
Sample Input

17
18
19
179
199 

Sample Output

 17 is emirp.
18 is not prime.
19 is prime.
179 is emirp.
199 is emirp.
 
Arun Kishore

*/