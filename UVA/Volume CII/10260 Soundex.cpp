/* 13782133	10260	Soundex	Accepted	C++	0.012	2014-06-23 10:27:50 */
#include<cstdio>
char convert(char c){
	switch (c)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		return '1';
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		return '2';
	case 'D':
	case 'T':
		return '3';
	case 'L':
		return '4';
	case 'M':
	case 'N':
		return '5';
	case 'R':
		return '6';
	default:
		return NULL;
	}
}
int main(){
	char S[1000];
	while (scanf("%s", S) == 1){
		char pre = -1;
		for (int i = 0; S[i] != '\0'; i++){
			char c = convert(S[i]);
			if (pre == c)
				continue;
			if (c != NULL)
				printf("%c", c);
			pre = c;
		}
		putchar('\n');
	}
	return 0;
}
/*

Problem D: Soundex

Soundex coding groups together words that appear to sound alike based on their spelling. For example, "can" and "khawn", "con" and "gone" would be equivalent under Soundex coding.
Soundex coding involves translating each word into a series of digits in which each digit represents a letter:

1 represents B, F, P, or V
2 represents C, G, J, K, Q, S, X,  or Z
3 represents D or T
4 represents L
5 represents M or N
6 represents R
The letters A, E, I, O, U, H, W, and Y are not represented in Soundex coding, and repeated letters with the same code digit are represented by a single instance of that digit. Words with the same Soundex coding are considered equivalent.
Each line of input contains a single word, all upper case, less than 20 letters long. For each line of input, produce a line of output giving the Soundex code.

Sample Input

KHAWN
PFISTER
BOBBY
Output for Sample Input

25
1236
11

*/