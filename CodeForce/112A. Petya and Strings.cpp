/* 1204270	 Feb 19, 2012 6:54:20 PM	Shark	 112A - Petya and Strings	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int compare(char str1[],char str2[]){
	for(int i=0;str1[i]!='\0';i++)
		if(str1[i]>str2[i])
			return 1;
		else if(str1[i]<str2[i])
			return -1;
	return 0;
}
int main(){
	char str1[1000],str2[1000];
	while(scanf("%s%s",str1,str2)==2){
		for(int i=0;str1[i]!='\0';i++){
			if(str1[i]>='A'&&str1[i]<='Z')
				str1[i]+=32;		
			if(str2[i]>='A'&&str2[i]<='Z')
				str2[i]+=32;
		}
		printf("%d\n",compare(str1,str2));
	}
	return 0;
}
/*

Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input

Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output

If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

input

aaaa
aaaA
abs
Abz
abcdefg
AbCdEfF

output

0
-1
1

Note

If you want more formal information about the lexicographical order (also known as the "dictionary order" or "alphabetical order"), you can visit the following site:

http://en.wikipedia.org/wiki/Lexicographical_order

*/