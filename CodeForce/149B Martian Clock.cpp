/* 5208062	 Nov 24, 2013 4:07:02 PM	Shark	 149B - Martian Clock	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
char A[6], B[6];
int change(char c){
	if (c >= '0'&&c <= '9')
		return c - '0';
	if (c >= 'A'&&c <= 'Z')
		return c - 'A' + 10;
}
bool judge(int num){
	int a, b;
	a = b = 0;
	for (int i = 0; A[i] != '\0'; i++)
		a = a*num + change(A[i]);
	for (int i = 0; B[i] != '\0'; i++)
		b = b*num + change(B[i]);
	if (a >= 0 && a <= 23 && b >= 0 && b <= 59)
		return true;
	else
		return false;
}
void split(char S[],char A[],char B[]){
	int i, j;
	for (i = j = 0; S[i] != ':'; i++)
		A[j++] = S[i];
	A[j] = '\0';
	for (i++, j = 0; S[i] != '\0'; i++)
		B[j++] = S[i];
	B[j] = '\0';
}
int main(){
	char tmp[100];
	while (scanf("%s", tmp) == 1){
		split(tmp, A, B);
		int num = 1;
		for (int i = 0; A[i] != '\0'; i++){
			if (num < change(A[i]))
				num = change(A[i]);
		}
		for (int i = 0; B[i] != '\0'; i++){
			if (num < change(B[i]))
				num = change(B[i]);
		}
		if (judge(60))
			puts("-1");
		else{
			bool first = true;
			for (num++; num <= 59; num++){
				if (judge(num)){
					if (!first)
						putchar(' ');
					first = false;
					printf("%d", num);
				}
				else
					break;
			}
			if (first)
				putchar('0');
			putchar('\n');
		}
	}
	return 0;
}
/*

B. Martian Clock
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Having stayed home alone, Petya decided to watch forbidden films on the Net in secret. "What ungentlemanly behavior!" ¡X you can say that, of course, but don't be too harsh on the kid. In his country films about the Martians and other extraterrestrial civilizations are forbidden. It was very unfair to Petya as he adored adventure stories that featured lasers and robots.

Today Petya is watching a shocking blockbuster about the Martians called "R2:D2". What can "R2:D2" possibly mean? It might be the Martian time represented in the Martian numeral system. Petya knows that time on Mars is counted just like on the Earth (that is, there are 24 hours and each hour has 60 minutes). The time is written as "a:b", where the string a stands for the number of hours (from 0 to 23 inclusive), and string b stands for the number of minutes (from 0 to 59 inclusive). The only thing Petya doesn't know is in what numeral system the Martian time is written.

Your task is to print the radixes of all numeral system which can contain the time "a:b".

Input
The first line contains a single string as "a:b" (without the quotes). There a is a non-empty string, consisting of numbers and uppercase Latin letters. String a shows the number of hours. String b is a non-empty string that consists of numbers and uppercase Latin letters. String b shows the number of minutes. The lengths of strings a and b are from 1 to 5 characters, inclusive. Please note that strings a and b can have leading zeroes that do not influence the result in any way (for example, string "008:1" in decimal notation denotes correctly written time).

We consider characters 0, 1, ..., 9 as denoting the corresponding digits of the number's representation in some numeral system, and characters A, B, ..., Z correspond to numbers 10, 11, ..., 35.

Output
Print the radixes of the numeral systems that can represent the time "a:b" in the increasing order. Separate the numbers with spaces or line breaks. If there is no numeral system that can represent time "a:b", print the single integer 0. If there are infinitely many numeral systems that can represent the time "a:b", print the single integer -1.

Note that on Mars any positional numeral systems with positive radix strictly larger than one are possible.

Sample test(s)
input
11:20
output
3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
input
2A:13
output
0
input
000B:00001
output
-1
Note
Let's consider the first sample. String "11:20" can be perceived, for example, as time 4:6, represented in the ternary numeral system or as time 17:32 in hexadecimal system.

Let's consider the second sample test. String "2A:13" can't be perceived as correct time in any notation. For example, let's take the base-11 numeral notation. There the given string represents time 32:14 that isn't a correct time.

Let's consider the third sample. String "000B:00001" can be perceived as a correct time in the infinite number of numeral systems. If you need an example, you can take any numeral system with radix no less than 12.

*/