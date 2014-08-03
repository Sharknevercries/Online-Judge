/* 9209180 465 Overflow Accepted C++ 0.012 2011-08-31 14:49:35 */
#include<stdio.h>
#define INT_MAX 2147483647
int main(){
	char str1[10000],str2[10000];
	double a,b;
	char c;
	while(scanf("%s %c%s",str1,&c,str2)==3){	
		printf("%s %c %s\n",str1,c,str2);
		sscanf(str1,"%lf",&a);
		sscanf(str2,"%lf",&b);
		bool real1,real2;
		real1=real2=false;
		if(a>INT_MAX){
			puts("first number too big");
			if(b!=0)
				real1=true;
		}
		if(b>INT_MAX){
			puts("second number too big");
			if(a!=0)
				real2=true;
		}
		if(real1||real2)
			puts("result too big");
		else{
			if(c=='+'&&INT_MAX<b+a)
				puts("result too big");
			else if(c=='*'&&(a!=0&&b!=0)&&(INT_MAX<b*a))
				puts("result too big");
		}		
	}
	return 0;
}
/*

Write a program that reads an expression consisting of two non-negative integer and an operator. Determine if either integer or the result of the expression is too large to be represented as a ``normal'' signed integer (type integer if you are working Pascal, type int if you are working in C).
 
Input
 
An unspecified number of lines. Each line will contain an integer, one of the two operators + or *, and another integer.
 
Output
 
For each line of input, print the input followed by 0-3 lines containing as many of these three messages as are appropriate: ``first number too big'', ``second number too big'', ``result too big''.
 
Sample Input
 
300 + 3
9999999999999999999999 + 11 

Sample Output
 
300 + 3
9999999999999999999999 + 11
first number too big
result too big 

*/