/* 1240755	 Feb 28, 2012 11:51:29 AM	Shark	 133B - Unary	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str[1000];
	while(scanf("%s",str)==1){
		int sum=0;
		for(int i=0;str[i]!='\0';i++){
			if(str[i]=='>')
				sum= (sum<<4)+8;
			else if(str[i]=='<')
				sum= (sum<<4)+9;
			else if(str[i]=='+')
				sum= (sum<<4)+10;
			else if(str[i]=='-')
				sum= (sum<<4)+11;
			else if(str[i]=='.')
				sum= (sum<<4)+12;
			else if(str[i]==',')
				sum= (sum<<4)+13;
			else if(str[i]=='[')
				sum= (sum<<4)+14;
			else if(str[i]==']')
				sum= (sum<<4)+15;
			sum%=1000003;
		}
		printf("%d\n",sum);
	}
	return 0;
}
/*

Unary is a minimalistic Brainfuck dialect in which programs are written using only one token.

Brainfuck programs use 8 commands: "+", "-", "[", "]", "<", ">", "." and "," (their meaning is not important for the purposes of this problem). Unary programs are created from Brainfuck programs using the following algorithm. First, replace each command with a corresponding binary code, using the following conversion table:

">"  →  1000,
"<"  →  1001,
"+"  →  1010,
"-"  →  1011,
"."  →  1100,
","  →  1101,
"["  →  1110,
"]"  →  1111.
Next, concatenate the resulting binary codes into one binary number in the same order as in the program. Finally, write this number using unary numeral system — this is the Unary program equivalent to the original Brainfuck one.

You are given a Brainfuck program. Your task is to calculate the size of the equivalent Unary program, and print it modulo 1000003 (106 + 3).

Input

The input will consist of a single line p which gives a Brainfuck program. String p will contain between 1 and 100 characters, inclusive. Each character of p will be "+", "-", "[", "]", "<", ">", "." or ",".

Output

Output the size of the equivalent Unary program modulo 1000003 (106 + 3).

input

,.
++++[>,.<-]

output

220
61425

Note

To write a number n in unary numeral system, one simply has to write 1 n times. For example, 5 written in unary system will be 11111.

In the first example replacing Brainfuck commands with binary code will give us 1101 1100. After we concatenate the codes, we'll get 11011100 in binary system, or 220 in decimal. That's exactly the number of tokens in the equivalent Unary program.

*/