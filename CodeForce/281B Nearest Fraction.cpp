/* 5366837	 Dec 7, 2013 8:54:29 AM	Shark	 281B - Nearest Fraction	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<math.h>
#define ABS(x) ( (x) >= 0 ? (x) : -(x) )
int GCD(int a, int b){
	int r;
	do{
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
int main(){
	int x, y, n;
	while (scanf("%d%d%d", &x, &y, &n) == 3){
		if (n >= y){ // vicious test
			int gcd = GCD(x, y);
			printf("%d/%d\n", x / gcd, y / gcd);
		}
		else{
			int ansa = 0, ansb = 1;
			for (int b = 1; b <= n; b++){
				int a = floor((double)b*x / y);
				if ((long long)ABS(ansb*x - ansa*y)*b > (long long)ABS(b*x - a*y)*ansb)
					ansa = a, ansb = b;
				a++;
				if ((long long)ABS(ansb*x - ansa*y)*b > (long long)ABS(b*x - a*y)*ansb)
					ansa = a, ansb = b;
			}
			printf("%d/%d\n", ansa, ansb);
		}
	}
	return 0;
}
/*

B. Nearest Fraction
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given three positive integers x, y, n. Your task is to find the nearest fraction to fraction  whose denominator is no more than n.

Formally, you should find such pair of integers a, b (1 ≤ b ≤ n; 0 ≤ a) that the value  is as minimal as possible.

If there are multiple "nearest" fractions, choose the one with the minimum denominator. If there are multiple "nearest" fractions with the minimum denominator, choose the one with the minimum numerator.

Input
A single line contains three integers x, y, n (1 ≤ x, y, n ≤ 105).

Output
Print the required fraction in the format "a/b" (without quotes).

Sample test(s)
input
3 7 6
output
2/5
input
7 2 4
output
7/2

*/