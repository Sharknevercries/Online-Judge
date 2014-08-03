/* 9190538 10921 Find the Telephone Accepted C++ 0.008 2011-08-25 13:16:51 */
#include<stdio.h>
char change(char c){
	switch(c){
	case 'A':
	case 'B':
	case 'C':
		return '2';
	case 'D':
	case 'E':
	case 'F':
		return '3';
	case 'G':
	case 'H':
	case 'I':
		return '4';
	case 'J':
	case 'K':
	case 'L':
		return '5';
	case 'M':
	case 'N':
	case 'O':
		return '6';
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
		return '7';
	case 'T':
	case 'U':
	case 'V':
		return '8';
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		return '9';
	default:
		return c;
	}
}
int main(){
	char str[100];
	while(gets(str)){
		char temp[100];
		int i;
		for(i=0;str[i]!='\0';i++)
			temp[i]=change(str[i]);
		temp[i]='\0';
		printf("%s\n",temp);
	}
	return 0;
}
/*

In some places is common to remember a phone number associating its digits to letters. In this way the expression MY LOVE means 69 5683. Of course there are some problems, because some phone numbers can not form a word or a phrase and the digits 1 and 0 are not associated to any letter.
 
Your task is to read an expression and find the corresponding phone number based on the table below. An expression is composed by the capital letters (A-Z), hyphens (-) and the numbers 1 and 0.
 
Letters Number
ABC 2
DEF 3
GHI 4
JKL 5
MNO 6
PQRS 7
TUV 8
WXYZ 9
Input


 The input consists of a set of expressions. Each expression is in a line by itself and has C characters, where 1 ≤ C ≤ 30. The input is terminated by enf of file (EOF).
 
Output

 For each expression you should print the corresponding phone number. 

Sample Input

1-HOME-SWEET-HOME
MY-MISERABLE-JOB

 Sample Output

1-4663-79338-4663
69-647372253-562

--------------------------------------------------------------------------------
 Problem setter: S�rgio Queiroz de Medeiros 

 */