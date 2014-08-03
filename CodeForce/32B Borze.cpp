/* 5023208	 Nov 7, 2013 5:56:15 PM	Shark	 32B - Borze	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
int main(){
	char str[1000];
	while( scanf("%s",str)==1 ){
		char code[1000];
		int ptr=0;
		for(int i=0;str[i]!='\0';)
			if( str[i]=='.' )
				code[ptr++]='0',i++;
			else if( str[i]=='-'&&str[i+1]=='.' )
				code[ptr++]='1',i+=2;
			else 
				code[ptr++]='2',i+=2;
		code[ptr++]='\0';
		printf("%s\n",code);
	}
	return 0;
}
/*

B. Borze
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ternary numeric notation is quite popular in Berland. To telegraph the ternary number the Borze alphabet is used. Digit 0 is transmitted as «.», 1 as «-.» and 2 as «--». You are to decode the Borze code, i.e. to find out the ternary number given its representation in Borze alphabet.

Input
The first line contains a number in Borze code. The length of the string is between 1 and 200 characters. It's guaranteed that the given string is a valid Borze code of some ternary number (this number can have leading zeroes).

Output
Output the decoded ternary number. It can have leading zeroes.

Sample test(s)
input
.-.--
output
012
input
--.
output
20
input
-..-.--
output
1012

*/