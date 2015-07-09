/* 13850580	10101	Bangla Numbers	Accepted	C++	0.022	2014-07-08 10:40:55 */
#include<cstdio>
#define kuti 10000000
#define lakh 100000
#define hajar 1000
#define shata 100
void solve(unsigned long long money){
	if (money >= kuti){
		if (money >= kuti * 100){
			solve(money / (kuti * 100) * 100);
			money %= kuti * 100;
			if (money / kuti == 0)
				printf(" kuti");
			else
				printf(" %llu kuti", money / kuti);
		}
		else if (money / kuti != 0)
			printf(" %llu kuti", money / kuti);
		money %= kuti;
	}
	if (money >= lakh){
		if (money / lakh != 0)
			printf(" %llu lakh", money / lakh);
		money %= lakh;
	}
	if (money >= hajar){
		if (money / hajar != 0)
			printf(" %llu hajar", money / hajar);
		money %= hajar;
	}
	if (money >= shata){
		if (money / shata != 0)
			printf(" %llu shata", money / shata);
		money %= shata;
	}
	if (money != 0)
		printf(" %llu", money);
}
int main(){
	int c = 1;
	unsigned long long money;
	while (scanf("%llu", &money) == 1){
		printf("%4d.", c++);
		if (money != 0)
			solve(money);
		else
			printf(" 0");
		putchar('\n');
	}
	return 0;
}
/*

Problem F
Bangla Numbers
Input: standard input
Output: standard output

Bangla numbers normally use 'kuti' (10000000), 'lakh' (100000), 'hajar' (1000), 'shata' (100) while expanding and converting to text. You are going to write a program to convert a given number to text with them.

Input
The input file may contain several test cases. Each case will contain a non-negative number <= 999999999999999.

Output
For each case of input, you have to output a line starting with the case number with four digits adjustment followed by the converted text.

Sample Input
23764
45897458973958

Sample Output
1. 23 hajar 7 shata 64
2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58

Tanbir Ahmed

*/