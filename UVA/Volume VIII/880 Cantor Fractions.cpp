/* 880 Cantor Fractions Accepted C++ 0.064 2011-03-01 09:49:55 */
#include<stdio.h>
#include<math.h>
int main(){
	unsigned long long n;
	while(scanf("%llu",&n)==1){
		unsigned long long k,r;
		k=(unsigned long long)(sqrt((double)2*n)+0.5); // 0 < k*(k+1)^0.5-(k^2)^0.5 < 0.5
		r=k*(k+1)/2-n;
		printf("%llu/%llu\n",1+r,k-r);
	}
	return 0;
}
/*

   In the late XIXth century the German mathematician George Cantor argued that the set of positive fractions Q+ is equipotent to the set of positive integers N, meaning that they are both infinite, but of the same class. To justify this, he exhibited a mapping from N to Q+ that is onto. This mapping is just traversal of the N x N plane that covers all the pairs: 
   
   The first fractions in the Cantor mapping are: 

Problem

   Write a program that finds the i-th Cantor fraction following the mapping outlined above. 

Input

   The inputs consists of several lines with a positive integer number i each one. 

Output

   The output consists of a line per input case, that contains the i-th fraction, with numerator and denominator separed by a slash (/). The fraction should not be in the most simple form. 

Sample Input

6

Sample Output

1/3

*/