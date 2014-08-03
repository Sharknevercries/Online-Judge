/* 8876568 10494 If We Were a Child Again Accepted C++ 0.024 2011-05-23 11:07:41 */
#include<stdio.h>
int main(){
	char str[10000];
	char opr;
	unsigned long long div;
	while(scanf("%s %c%llu",str,&opr,&div)==3){
		if(str[0]=='0'&&str[1]=='\0'){ //  特殊測資
			puts("0");
			continue;
		}
		bool zero;
		unsigned long long m;
		int i;
		for(i=m=zero=0;str[i]!='\0';i++){
			m*=10;
			m+=str[i]-'0';			
			if(opr=='/'){
				if(m>=div){
					zero=true;
					printf("%llu",m/div);
					m%=div;
					}
				else if(zero==true)
					putchar('0');
			}
			else if(opr=='%'&&m>=div){
				m%=div;
			}			
		}
		if(opr=='/'&&zero==false) // 若被除數小於除數時
			putchar('0');
		if(opr=='%')
			printf("%d",m);
		putchar('\n');
	}
	return 0;
}
/*

“Oooooooooooooooh!

If I could do the easy mathematics like my school days!!

I can guarantee, that I’d not make any mistake this time!!”

Says a smart university student!!

But his teacher even smarter – “Ok! I’d assign you such projects in your software lab. Don’t be so sad.”

“Really!!” - the students feels happy. And he feels so happy that he cannot see the smile in his teacher’s face.

The Problem

The first project for the poor student was to make a calculator that can just perform the basic arithmetic operations.

But l

Input

Input is a sequence of lines. Each line will contain an input number. One or more spaces. A sign (division or mod). Again spaces. And another input number. Both the input numbers are non-negative integer. The first one may be arbitrarily long. The second number n will be in the range (0 < n < 231).
 
Output

A line for each input, each containing an integer. See the sample input and output. Output should not contain any extra space.
 
Sample Input

110 / 100
99 % 10
2147483647 / 2147483647
2147483646 % 2147483647
 
Sample Output

1
9
1
2147483646 

--------------------------------------------------------------------------------

Problemsetter:  S. M. Ashraful Kadir, University of Dhaka

*/