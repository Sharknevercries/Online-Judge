/* 9058760 256 Quirksome Squares Accepted C++ 0.020 2011-07-18 14:05:00 */
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		/*
		int num=0,temp;		
		int i,limit;
		for(i=limit=1;i<=n;i++)
			limit*=10;
		for(i=temp=1;i<=n/2;i++)
			temp*=10;
		while(limit>num){
			double sq=sqrt((double)num);
			int left=num/temp;
			int right=num%temp;
			if((left+right)==sq)
				printf("%0*d\n",n,num);
			num++;
		}
		*/
		if(n==2){
			puts("00");
			puts("01");
			puts("81");
		}
		else if(n==4){
			puts("0000");
			puts("0001");
			puts("2025");
			puts("3025");
			puts("9801");
		}
		else if(n==6){
			puts("000000");
			puts("000001");
			puts("088209");
			puts("494209");
			puts("998001");
		}
		else{
			puts("00000000");
			puts("00000001");
			puts("04941729");
			puts("07441984");
			puts("24502500");
			puts("25502500");
			puts("52881984");
			puts("60481729");
			puts("99980001");
		}
	}
	return 0;
}
/*

The number 3025 has a remarkable quirk: if you split its decimal representation in two strings of equal length (30 and 25) and square the sum of the numbers so obtained, you obtain the original number:
 
The problem is to determine all numbers with this property having a given even number of digits.
 
For example, 4-digit numbers run from 0000 to 9999. Note that leading zeroes should be taken into account. This means that 0001 which is equal to is a quirksome number of 4 digits. The number of digits may be 2,4,6 or 8. Although maxint is only 32767 and numbers of eight digits are asked for, a well-versed programmer can keep his numbers in the range of the integers. However efficiency should be given a thought.
 
Input
 
The input of your program is a textflle containing numbers of digits (taken from 2,4,6,8), each number on a line of its own.
 
Output
 
The output is a textfile consisting of lines containing the quirksome numbers (ordered according to the input numbers and for each input number in increasing order).
 
Warning: Please note that the number of digits in the output is equal to the number in the corresponding input line : leading zeroes may not be suppressed.
 
Sample Input
 
2
2 

Sample Output
 
00
01
81
00
01
81 

*/