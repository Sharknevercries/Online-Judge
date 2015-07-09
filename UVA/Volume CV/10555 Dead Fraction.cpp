/* 15189974	10555	Dead Fraction	Accepted	C++	0.025	2015-03-21 07:02:10 */
#include<bits\stdc++.h>
using namespace std;
unsigned long long GCD(unsigned long long a, unsigned long long b){
	unsigned long long r;
	do{
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
unsigned long long mask[15] = { 1 };
int main(){
	for (int i = 1; i < 15; i++)
		mask[i] = mask[i - 1] * 10;
	string str;
	while (cin >> str){
		if (str == "0")	break;
		unsigned long long ans1, ans2 = 1e18;
		unsigned long long num = 0, L = 0;
		for (int i = 2; str[i] != '.'; i++)
			num = num * 10 + str[i] - '0', L++;
		for (int i = 0; i < L; i++){
			unsigned long long a, b, c, d, gcd, p, q;
			c = num % mask[L - i];
			a = num / mask[L - i];
			b = mask[i];
			d = mask[L - i];
			if (d - 1 != 0){
				p = a * (d - 1) + c;
				q = b*(d - 1);
			}
			else
				p = a, q = b;
			gcd = GCD(p, q);
			p /= gcd, q /= gcd;
			if (q < ans2)
				ans2 = q, ans1 = p;
		}
		printf("%llu/%llu\n", ans1, ans2);
	}
	return 0;
}
/*

Problem B: Dead Fraction

Mike is frantically scrambling to finish his thesis at the last minute. He needs to assemble all his research notes into vaguely coherent form in the next 3 days. Unfortunately, he notices that he had been extremely sloppy in his calculations. Whenever he needed to perform arithmetic, he just plugged it into a calculator and scribbled down as much of the answer as he felt was relevant. Whenever a repeating fraction was displayed, Mike simply reccorded the first few digits followed by "...". For instance, instead of "1/3" he might have written down "0.3333...". Unfortunately, his results require exact fractions! He doesn't have time to redo every calculation, so he needs you to write a program (and FAST!) to automatically deduce the original fractions.
To make this tenable, he assumes that the original fraction is always the simplest one that produces the given sequence of digits; by simplest, he means the the one with smallest denominator. Also, he assumes that he did not neglect to write down important digits; no digit from the repeating portion of the decimal expansion was left unrecorded (even if this repeating portion was all zeroes).

There are several test cases. For each test case there is one line of input of the form "0.dddd..." where dddd is a string of 1 to 9 digits, not all zero. A line containing 0 follows the last case. For each case, output the original fraction.

Note that an exact decimal fraction has two repeating expansions (e.g. 1/5 = 0.2000... = 0.19999...).

Sample Input

0.2...
0.20...
0.474612399...
0
Output for Sample Input

2/9
1/5
1186531/2500000
D. Kisman

*/