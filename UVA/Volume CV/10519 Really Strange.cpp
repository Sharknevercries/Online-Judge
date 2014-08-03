/* 9117069 10519 !! Really Strange !! Accepted C++ 0.008 2011-08-05 12:58:42 */
#include<stdio.h>
#include<string.h>
void mul(char str1[],char str2[],char result[]){
	int len_str1=strlen(str1);
	int len_str2=strlen(str2);
	int len_result=len_str1+len_str2;
	int i,j,temp,carry;

	for(i=0;i<len_result;i++)
		result[i]='0';
	result[i]='\0';

	for(i=len_str1-1;i>=0;i--){
		for(j=len_str2-1,carry=0;j>=0;j--){
			temp=(str1[i]-'0')*(str2[j]-'0')+result[i+j+1]-'0'+carry;
			carry=temp/10;
			temp%=10;
			result[i+j+1]='0'+temp;
		}
		result[i]='0'+carry;
	}

	for(i=0;result[i]=='0'&&result[i]!='\0';i++);
	if(result[i]=='\0')
		result[1]='\0';
	else if(i>0){
		for(j=0;result[i]!='\0';j++,i++)
			result[j]=result[i];
		result[j]='\0';
	}
}
void minus(char str1[],char str2[]){
	int len_str1=strlen(str1);
	int len_str2=strlen(str2);
	int i,j,carry,temp;
	
	for(i=len_str1-1,j=len_str2-1,carry=0;i>=0;i--,j--){ // In this problom, str1>str2
		if(j>=0)
			temp=str1[i]-str2[j]-carry;
		else
			temp=str1[i]-'0'-carry;
		carry = (temp>=0) ? 0 : 1;
		temp += (temp>=0) ? 0 : 10;
		str1[i]='0'+ temp;
	}

	for(i=0;str1[i]=='0'&&str1[i]!='\0';i++);
	if(str1[i]=='\0')
		str1[1]='\0';
	else if(i>0){
		for(j=0;str1[i]!='\0';j++,i++)
			str1[j]=str1[i];
		str1[j]='\0';
	}
	
}
/*

Raju has recently passed BSc. Engineering in Computer Science & Engineering from BUET ( Bangladesh University of Extraordinary Talents), the best university of Bangladesh. After passing, he has been appointed manager of BCS ( Bangladesh Calculation Society ). His first project is to visit a district and then to report the total number of distinct regions there. But, going there, he is astonished to see a very strange phenomena of the local people. He discovered that, the people make their area circular. Every two area have exactly two points to intersect and no three circles intersect in a common point. There are so many people so that it's very hard to calculate total number of distinct regions for Raju. So, only in this case he seeks for your help.
 
Input
 
The problem contains multiple test cases. You are given total number of circular area n in separate lines (n<=10100). And you know the number houses in the world can't be fraction or negative. Input is terminated by end of file.

 Output
 
For each line of the input, your correct program should output the value of the total number of regions in separate lines for each value of n.
 
Sample Input
 
3
4 

Sample Output
 
8
14 

Anupam Bhattacharjee ( BUET PESSIMISTIC )
Small is a relative term and it is very hard to define...

 */