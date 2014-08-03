/* 1294369	 Mar 6, 2012 6:01:07 PM	Shark	 94A - Restoring Password	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
#include<string.h>
int main(){
	char code[100];
	char text[10][11];
	while(scanf("%s",code)==1){
		for(int i=0;i<10;i++)
			scanf("%s",text[i]);
		for(int i=0;i<8;i++)
			for(int j=0;j<10;j++)
				if(strncmp(code+i*10,text[j],10)==0){
					printf("%d",j);
					break;
				}
		putchar('\n');
	}
	return 0;
}
/*

Igor K. always used to trust his favorite Kashpirovsky Antivirus. That is why he didn't hesitate to download the link one of his groupmates sent him via QIP Infinium. The link was said to contain "some real funny stuff about swine influenza". The antivirus had no objections and Igor K. run the flash application he had downloaded. Immediately his QIP Infinium said: "invalid login/password".

Igor K. entered the ISQ from his additional account and looked at the info of his main one. His name and surname changed to "H1N1" and "Infected" correspondingly, and the "Additional Information" field contained a strange-looking binary code 80 characters in length, consisting of zeroes and ones. "I've been hacked" ¡X thought Igor K. and run the Internet Exploiter browser to quickly type his favourite search engine's address.

Soon he learned that it really was a virus that changed ISQ users' passwords. Fortunately, he soon found out that the binary code was actually the encrypted password where each group of 10 characters stood for one decimal digit. Accordingly, the original password consisted of 8 decimal digits.

Help Igor K. restore his ISQ account by the encrypted password and encryption specification.

Input

The input data contains 11 lines. The first line represents the binary code 80 characters in length. That is the code written in Igor K.'s ISQ account's info. Next 10 lines contain pairwise distinct binary codes 10 characters in length, corresponding to numbers 0, 1, ..., 9.

Output

Print one line containing 8 characters ¡X The password to Igor K.'s ISQ account. It is guaranteed that the solution exists.

input

01001100100101100000010110001001011001000101100110010110100001011010100101101100
0100110000
0100110010
0101100000
0101100010
0101100100
0101100110
0101101000
0101101010
0101101100
0101101110
00001000011100010110010011111101111010100111101010111000101001001111111110001010
1100011011
1100010110
0011101111
0100111111
0001010100
1110001010
0111101010
0000100001
1110011011
0010011010

output

12345678
71366535

*/