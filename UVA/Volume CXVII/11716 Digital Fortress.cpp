/* 9190571 11716 Digital Fortress Accepted C++ 0.020 2011-08-25 13:30:17 */
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	(void)getchar();
	for(int t=1;t<=n;t++){
		char str[10001];
		gets(str);
		
		int len=strlen(str);
		if((double)sqrt((double)len)==(int)sqrt((double)len)){
			int sq=sqrt((double)len);
			int i,j;
			for(i=0;i<sq;i++)
				for(j=i;j<len;j+=sq)
					printf("%c",str[j]);
			putchar('\n');
		}
		else
			puts("INVALID");
	}
	return 0;
}
/*

I IU P C   2 0 0 9
 
Problem D: Digital Fortress
 
In the last IIUPC there was a problem called Da Vinci Code prepared on the story of the bestselling book of Dan Brown, The Da Vinci Code. Here is another problem based on his another techno-thriller novel Digital Fortress. In this problem, you will be given a cipher text. Your task is to decipher the text using the decrypting technique described below. Let’s take an example. A cipher text is given as follows:

 WECGEWHYAAIORTNU 

The output will be:

    WEAREWATCHINGYOU
	
For this problem, there are 16 characters in the given cipher text “WECGEWHYAAIORTNU” which is square of 4. These letters have to be arranged in n ´ n (in this example 4 ´ 4) grid and each letter from the given input will be placed in a grid in row major order (1st row, 2nd row, 3rd row, …). When the given cipher text is placed in the grid it looks like as follow:

 W E C G

 E W H Y

 A A I O

 R T N U

From the above grid if we take the letters in column major order (1st column, 2nd column, 3rd column, …) then we get the following decrypted text:

    WEAREWATCHINGYOU

Input
 
Input starts with a line consisting of a single number T. T test cases follow. Each test case consists of one line. This line contains the cipher text. The cipher text contains either UPPERCASE letters or blank spaces. Total number of character in the text will not be more 10,000.

Output
 
For each test case, the output contains a single line containing the decrypted text. If the number of characters in the input text is not square of any number, then give the output “INVALID”.

Sample Input
 
3
WECGEWHYAAIORTNU
DAVINCICODE
DTFRIAOEGLRSI TS 

Output for Sample Input

WEAREWATCHINGYOU
INVALID
DIGITAL FORTRESS
 
Problem Setter: Mohammed Shamsul Alam

Special Thanks: Tanveer Ahsan

*/