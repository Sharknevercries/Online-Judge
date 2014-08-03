/* 1219426	 Feb 23, 2012 5:38:16 PM	Shark	 81A - Plug-in	 GNU C++	Accepted	 30 ms	 1800 KB */
#include<stdio.h>
int main(){
	char str[250000];
	int len;
	while(scanf("%s",str)==1){
		char stack[250000];
		int ptr=0;
		for(int i=0;str[i]!='\0';i++)
			if(ptr-1>=0&&stack[ptr-1]==str[i])
				ptr--;
			else
				stack[ptr++]=str[i];
		stack[ptr]='\0';
		printf("%s\n",stack);
	}
	return 0;
}
/*

Polycarp thinks about the meaning of life very often. He does this constantly, even when typing in the editor. Every time he starts brooding he can no longer fully concentrate and repeatedly presses the keys that need to be pressed only once. For example, instead of the phrase "how are you" he can type "hhoow aaaare yyoouu".

Polycarp decided to automate the process of correcting such errors. He decided to write a plug-in to the text editor that will remove pairs of identical consecutive letters (if there are any in the text). Of course, this is not exactly what Polycarp needs, but he's got to start from something!

Help Polycarp and write the main plug-in module. Your program should remove from a string all pairs of identical letters, which are consecutive. If after the removal there appear new pairs, the program should remove them as well. Technically, its work should be equivalent to the following: while the string contains a pair of consecutive identical letters, the pair should be deleted. Note that deleting of the consecutive identical letters can be done in any order, as any order leads to the same result.

Input

The input data consists of a single line to be processed. The length of the line is from 1 to 2¡P105 characters inclusive. The string contains only lowercase Latin letters.

Output

Print the given string after it is processed. It is guaranteed that the result will contain at least one character.

input

hhoowaaaareyyoouu
reallazy
abacabaabacabaa

output

wre
rezy
a

*/