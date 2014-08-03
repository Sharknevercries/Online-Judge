/* 10008 What's Cryptanalysis? Accepted C++ 0.012 2011-02-25 14:00:26 */
#include<stdio.h>
char to_big(char c){
	return c>='a'?c-32:(c); 
}
int main(){
	int frequent[26]={0};
	int fre_max;
	int n;
	while(scanf("%d",&n)==1){
		int i,j;
		char c=getchar();
		fre_max=0;
		while(n--){			
			char str[10000];
			gets(str);
			for(i=0;str[i]!='\0';i++)
				if((str[i]>='a'&&'z'>=str[i])||(str[i]>='A'&&'Z'>=str[i])){
					frequent[(int)to_big(str[i])-'A']++;
					if(fre_max<frequent[(int)to_big(str[i])-'A'])
							fre_max=frequent[(int)to_big(str[i])-'A'];
				}
		}
		for(i=fre_max;i>0;i--)
			for(j=0;j<26;j++)
				if(frequent[j]==i)
					printf("%c %d\n",'A'+j,frequent[j]);
	}
	return 0;
}
/*

Cryptanalysis is the process of breaking someone else's cryptographic writing. This sometimes involves some kind of statistical analysis of a passage of (encrypted) text. Your task is to write a program which performs a simple analysis of a given text. 
Input  
The first line of input contains a single positive decimal integer n. This is the number of lines which follow in the input. The next n lines will contain zero or more characters (possibly including whitespace). This is the text which must be analyzed. 
Output  
Each line of output contains a single uppercase letter, followed by a single space, then followed by a positive decimal integer. The integer indicates how many times the corresponding letter appears in the input text. Upper and lower case letters in the input are to be considered the same. No other characters must be counted. The output must be sorted in descending count order; that is, the most frequent letter is on the first output line, and the last line of output indicates the least frequent letter. If two letters have the same frequency, then the letter which comes first in the alphabet must appear first in the output. If a letter does not appear in the text, then that letter must not appear in the output. 

Sample Input  

3
This is a test.
Count me 1 2 3 4 5.
Wow!!!!  Is this question easy?

Sample Output  

S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1

--------------------------------------------------------------------------------

Miguel Revilla 
2000-08-22 

*/