/* 9025366 495 Fibonacci Freeze Accepted C++ 0.068 2011-07-07 09:51:40 */
#include<stdio.h>
#include<string.h>
#define MAX(x,y) ( x>=y?x:y )
char result[5001][2000];
void plus(char str1[],char str2[],char result[]){
	int len1=strlen(str1);
	int len2=strlen(str2);
	int len_result=MAX(len1,len2)+1;
	int i,j,k,carry,temp;
	for(i=0;i<len_result;i++)
		result[i]='0';
	result[i]='\0';
	for(i=len1-1,j=len2-1,k=len_result-1,carry=0;i>=0||j>=0;){
		if(i>=0&&j>=0)
			temp=str1[i--]-'0'+str2[j--]-'0'+carry;		
		else if(i>=0)
			temp=str1[i--]-'0'+carry;
		else
			temp=str2[j--]-'0'+carry;
		carry=temp/10;
		result[k--]+=temp%10;				
	}
	result[k]+=carry;
	if(result[0]=='0')
		for(i=0;i<len_result;i++)
			result[i]=result[i+1];
}
int main(){
	result[0][0]='0';
	result[1][0]='1';
	result[0][1]=result[1][1]='\0';	
	for(int i=2;i<=5000;i++)
		plus(result[i-2],result[i-1],result[i]);	
	int n;
	while(scanf("%d",&n)==1)
		printf("The Fibonacci number for %d is %s\n",n,result[n]);
	return 0;
}
/*

The Fibonacci numbers (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...) are defined by the recurrence:
 
Write a program to calculate the Fibonacci Numbers. 

Input and Output
 
The input to your program would be a sequence of numbers smaller or equal than 5000, each on a separate line, specifying which Fibonacci number to calculate.
 
Your program should output the Fibonacci number for each input value, one per line.
 
Sample Input

5
7
11 

Sample Output

The Fibonacci number for 5 is 5
The Fibonacci number for 7 is 13
The Fibonacci number for 11 is 89 

*/