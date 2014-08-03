/* 13811910	10168	Summation of Four Primes	Accepted	C++	0.349	2014-06-30 08:42:31 */
/*

GoldBach's conjecture
Every integer >= 4 can be expressed as the sum of two primes.

*/
#include<cstdio>
#include<math.h>
#include<string.h>
#define N 10000000
bool P[10000001];
void makePrime(){
	memset(P, false, sizeof(P));
	int limit = sqrt((double)N);
	for (int i = 2; i <= limit; i++){
		if (!P[i]){
			for (int k = (N - 1) / i, j = i*k; k >= i; k--, j -= i)
				P[j] = true;
		}
	}
}
void Goldbach(int n){
	for (int i = 2;; i++){
		if (!P[i] && !P[n - i]){
			printf("%d %d", i, n - i);
			return;
		}
	}
}
int main(){
	makePrime();
	int n;
	while (scanf("%d", &n) == 1){
		if (n < 8)
			puts("Impossible.");
		else{
			if (n % 2 == 0)
				printf("%d %d ", 2, 2), n -= 4;
			else
				printf("%d %d ", 2, 3), n -= 5;
			Goldbach(n);
			putchar('\n');
		}
	}
	return 0;
}
/*

Problem A
Summation of Four Primes
Input: standard input
Output: standard output
Time Limit: 4 seconds

Euler proved in one of his classic theorems that prime numbers are infinite in number. But can every number be expressed as a summation of four positive primes? I donft know the answer. May be you can help!!! I want your solution to be very efficient as I have a 386 machine at home. But the time limit specified above is for a Pentium III 800 machine. The definition of prime number for this problem is gA prime number is a positive number which has exactly two distinct integer factorsh. As for example 37 is prime as it has exactly two distinct integer factors 37 and 1.

Input
The input contains one integer number N (N<=10000000) in every line. This is the number you will have to express as a summation of four primes. Input is terminated by end of file.

Output
For each line of input there is one line of output, which contains four prime numbers according to the given condition. If the number cannot be expressed as a summation of four prime numbers print the line gImpossible.h in a single line. There can be multiple solutions. Any good solution will be accepted.

Sample Input:
24
36
46

Sample Output:
3 11 3 7
3 7 13 13
11 11 17 7
Shahriar Manzoor

gYou can fool some people all the time, all the people some of the
time but you cannot fool all the people all the time.h

*/