/* 740 Baudot Data Communication Code Accepted C++ 0.012 2011-02-24 11:37:11 */
#include<stdio.h>
#define SHIFT_DOWN '\0'
#define SHIFT_UP '\1'
#define DOWN_MODE 1
#define UP_MODE 2
struct daubot{
	char Down_Shift;
	char Up_Shift;
};
static struct daubot table[32];
void analysis(char str1[],char str2[]){
	int i,k;
	for(i=k=0;str1[i]!='\0';i++){
		if(str1[i]==' '){
			switch(k){
			case 0:
				table[i].Down_Shift=table[i].Up_Shift=' '; break;
			case 1:
				table[i].Down_Shift=table[i].Up_Shift=SHIFT_DOWN;	break;
			case 2:
				table[i].Down_Shift=table[i].Up_Shift=SHIFT_UP; break;}
			k++;continue;}
		table[i].Down_Shift=str1[i];
		table[i].Up_Shift=str2[i];}
}
int main(){
	char str1[100];
	char str2[100];	
	char temp[100];
	gets(str1);
	gets(str2);
	analysis(str1,str2);
	while(gets(temp)){
		int sum;
		int i,j,k;
		int mode=DOWN_MODE;
		for(i=0;temp[i]!='\0';i+=5){
			for(j=0,sum=0;j<5;j++)
				sum=sum*2+temp[i+j]-'0';
			if(mode==DOWN_MODE){
				if(table[sum].Down_Shift==SHIFT_DOWN)
					mode=DOWN_MODE;
				else if(table[sum].Down_Shift==SHIFT_UP)
					mode=UP_MODE;
				else
					printf("%c",table[sum].Down_Shift);}
			else{
				if(table[sum].Up_Shift==SHIFT_DOWN)
					mode=DOWN_MODE;
				else if(table[sum].Up_Shift==SHIFT_UP)
					mode=UP_MODE;
				else
					printf("%c",table[sum].Up_Shift);}
		}
		putchar('\n');
	}
	return 0;
}
/*

Data are communicated between digital computers as sequences of bits. To provide meaning to a sequence of bits, the bits are grouped to form a data character and an encoding scheme, or translation table, is provided to allow a computer system to translate each group of bits into a character. The ideal encoding scheme will provide a unique code for every possible character to be communicated and stored in the computer, but this requires that each group have a sufficient number of bits for each data character. 

A code used early in the data communications industry is the Baudot code. Baudot uses five bits per character, thus allowing up to 32 distinct characters. As a technique used to extend this limitation, the code uses up-shift and down-shift modes as is used on a typewriter. In the Baudot code, each five bits transmitted must be interpreted according to whether they are up-shifted (figures) or down-shifted (letters). For example, the bit pattern 11111 represents up-shift and the bit pattern 11011 represents down-shift characters. All characters transmitted after the sequence 11111 but before the shifted sequence 11011 are treated as up-shift characters. All characters transmitted after the sequence 11011 are treated as down-shift characters until the pattern 11111 is recognized. The complete BAUDOT code (modified for this problem) is shown in the table at the end of this problem. 

Input  

The input consists of two parts. The first part is the Baudot character set: line one contains the 32 down-shift characters and line two contains the 32 up-shift characters. (Note: spaces are inserted for the shift characters.) The remainder of the input file consists of one or more messages encoded using the Baudot code. Each message will be on a line in the input file. Each line will consist of 1's and 0's, with no characters between the bits. There can be up to 80 bits per message. 
The input file will be terminated by end-of-file. The initial state of each message should be assumed to be in the down-shift state. 

Output 

The output should consist of one line of text for each message. The output should contain the character representation, as translated using BAUDOT, of each of the messages. 

Sample Input  

<T*O HNM=LRGIPCVEZDBSYFXAWJ UQK 
>5@9 %,.+)4&80:;3"$?#6!/-2' 71( 
100100110011000010011111101110000111110111101
001100001101111001001111100001001100010001100110111100000111

Sample Output  

DIAL:911
NOV 5, 8AM

Bit Pattern Down-Shift Character Up-Shift Character 
00000 < > 
00001 T 5 
00010 * @ 
00011 O 9 
00100 Space Space 
00101 H % 
00110 N , 
00111 M . 
01000 = + 
01001 L ) 
01010 R 4 
01011 G & 
01100 I 8 
01101 P 0 
01110 C : 
01111 V ; 
10000 E 3 
10001 Z " 
10010 D $ 
10011 B ? 
10100 S # 
10101 Y 6 
10110 F ! 
10111 X / 
11000 A - 
11001 W 2 
11010 J ' 
11011 Shift Down Shift Down 
11100 U 7 
11101 Q 1 
11110 K ( 
11111 Shift Up Shift Up 

Table: The BAUDOT code 

--------------------------------------------------------------------------------

Miguel A. Revilla 
2000-02-09 

*/