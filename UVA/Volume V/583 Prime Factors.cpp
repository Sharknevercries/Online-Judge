/* 9047857 583 Prime Factors Accepted C++ 0.216 2011-07-14 11:10:20 */
#include<stdio.h>
#include<math.h>
#define INT_MAX 2147483647
static int prime[5000];
int index;
void initial(){
	int limit=sqrt((double)INT_MAX)+1;
	int i,j,gap;
	prime[0]=2;
	prime[1]=3;
	index=2;
	for(i=5,gap=2;i<=limit;i+=gap,gap=6-gap){
		for(j=0;j<index&&i%prime[j]!=0;j++);
		if(j>=index)
			prime[index++]=i;
	}
}
int main(){
	initial();
	int n;
	while(scanf("%d",&n)==1&&n!=0){			
		int i,j;
		bool first=true;
		if(n==1){
			printf("%d = 1\n",n);
			continue;
		}
		else if(n==-1){
			printf("%d = -1\n",n);
			continue;
		}
		if(n<0){			
			printf("%d = -1",n);
			n*=-1;			
			first=false;
		}		
		for(i=0;n>1&&prime[i]<=sqrt((double)n)+1&&i<index;i++)
			while(n%prime[i]==0){
				if(first){
					printf("%d = %d",n,prime[i]);
					first=false;
				}
				else
					printf(" x %d",prime[i]);
				n/=prime[i];
			}
		if(n>1)
			if(first)
				printf("%d = %d",n,n);			
			else
				printf(" x %d",n);		
		putchar('\n');
	}
	return 0;
}
/*

 Webster defines prime as: 

prime (prim) n.[ME, fr. MF, fem. of prin first, L primus; akin to L prior] 1 :first in time: original 2 a : having no factor except itself and one 3 is a   number b : having no common factor except one 12 and 25 are relatively   3 a : first in rank, authority or significance : principal b : having the highest quality or value   television time [from Webster's New Collegiate Dictionary]
 
The most relevant definition for this problem is 2a: An integer g>1 is said to be prime if and only if its only positive divisors are itself and one (otherwise it is said to be composite). For example, the number 21 is composite; the number 23 is prime. Note that the decompositon of a positive number g into its prime factors, i.e.,
 
is unique if we assert that fi > 1 for all i and for i<j. 

One interesting class of prime numbers are the so-called Mersenne primes which are of the form 2p- 1. Euler proved that 231 - 1 is prime in 1772 -- all without the aid of a computer.
 
Input 

The input will consist of a sequence of numbers. Each line of input will contain one number g in the range -231 < g <231, but different of -1 and 1. The end of input will be indicated by an input line having a value of zero.
 
Output  

For each line of input, your program should print a line of output consisting of the input number and its prime factors. For an input number , where each fi is a prime number greater than unity (with for i<j), the format of the output line should be
 
When g < 0, if , the format of the output line should be 

Sample Input  
-190
-191
-192
-193
-194
195
196
197
198
199
200
0

 Sample Output  
-190 = -1 x 2 x 5 x 19
-191 = -1 x 191
-192 = -1 x 2 x 2 x 2 x 2 x 2 x 2 x 3
-193 = -1 x 193
-194 = -1 x 2 x 97
195 = 3 x 5 x 13
196 = 2 x 2 x 7 x 7
197 = 197
198 = 2 x 3 x 3 x 11
199 = 199
200 = 2 x 2 x 2 x 5 x 5

--------------------------------------------------------------------------------

Miguel Revilla 
2000-05-19 

*/