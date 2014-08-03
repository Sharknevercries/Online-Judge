/* 13843929	10179	Irreducable Basic Fractions	Accepted	C++	0.075	2014-07-07 07:04:56 */
#include<cstdio>
#include<math.h>
unsigned long long GCD(unsigned long long a, unsigned long long b){
	unsigned long long r;
	do{
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		unsigned long long ans = n;
		int s = n;
		for (int i = 2; i <= sqrt((double)s); i++){
			if (s % i == 0){
				ans /= i;
				ans *= (i - 1);
				while (s % i == 0)
					s /= i;
			}
		}
		if (n != 1 && s != 1){
			ans /= s;
			ans *= (s - 1);
		}
		if (n == 1)
			printf("%llu\n", ans);
		else
			printf("%llu\n", ans);
	}
	return 0;
}
/*

Problem L
Irreducible Basic Fractions
Input: standard input
Output: standard output
Time Limit: 4 seconds
A fraction m / n is basic if 0 <= m < n and it is irreducible if gcd(m, n) = 1. Given a positive integer n, in this problem you are required to find out the number of irreducible basic fractions with denominator n .

For example, the set of all basic fractions with denominator 12, before reduction to lowest terms, is

Reduction yields

Hence there are only the following 4 irreducible basic fractions with denominator 12

Input

Each line of the input contains a positive integer n (< 1000000000) and the input terminates with a value 0 for n (do not process this terminating value).

Output

For each n in the input print a line containing the number of irreducible basic fractions with denominator n

Sample Input

12
123456
7654321
0
Sample Output

4
41088
7251444
Rezaul Alam Chowdhury

¡§I shot an arrow into the air,
It fell to earth, I knew not where;
For, so swiftly it flew, the sight
Could not follow it in its flight.

I breathed a song into the air,
It fell to earth, I knew not where;
For who has sight so keen and strong,
That it can follow the flight of song?

Long, Long afterward, in an oak
I found the arrow, still unbroke;
And the song from beginning to end,
I found again in the heart of a friend.¡¨

*/