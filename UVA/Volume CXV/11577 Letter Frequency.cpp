/* 9083756 11577 Letter Frequency Accepted C++ 0.016 2011-07-27 04:16:29 */
#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	(void) getchar();
	for(int i=1;i<=t;i++){
		char str[250];
		int count[27]={0};
		gets(str);
		for(int j=0;str[j]!='\0';j++)
			if(str[j]>='a'&&str[j]<='z')
				count[str[j]-'a'+1]++;
			else if(str[j]>='A'&&str[j]<='Z')
				count[str[j]-'A'+1]++;

		int max;
		max=0;
		for(int j=1;j<=26;j++)
			if(count[j]>max)
				max=count[j];
		for(int j=1;j<=26;j++)
			if(count[j]==max)
				printf("%c",(char)'a'+j-1);
		putchar('\n');
	}
	return 0;
}
/*

In this problem we are interested in the frequency of letters in a given line of text. Specifically, we want to know the most frequently occurring letter(s) in the text, ignoring case (to be clear, "letters" refers precisely to the 26 letters of the alphabet).
 
Input begins with the number of test cases on its own line. Each test case consists of a single line of text. The line may contain non-letter characters, but is guaranteed to contain at least one letter and less than 200 characters in total.
 
For each test case, output a line containing the most frequently occurring letter(s) from the text in lowercase (if there are ties, output all such letters in alphabetical order).
 
Sample input

1
Computers account for only 5% of the country's commercial electricity consumption.

 Sample output

 co

--------------------------------------------------------------------------------
 Sumudu Fernando

*/