/* 9190611 10922 2 the 9s Accepted C++ 0.024 2011-08-25 13:44:22 */
#include<stdio.h>
int degree(char str[],int d){
	int sum,i;
	for(i=sum=0;str[i]!='\0';i++)
		sum+=str[i]-'0';
	if(sum%9!=0)
		return false;
	if(sum==9)
		return d;
	else{
		char temp[1000];
		sprintf(temp,"%d",sum);
		return degree(temp,d+1);
	}
}
int main(){
	char str[10000];
	while(gets(str)){
		if(str[0]=='0'&&str[1]=='\0')
			break;
		int ans=degree(str,1);
		if(ans==false)
			printf("%s is not a multiple of 9.\n",str) ;
		else
			printf("%s is a multiple of 9 and has 9-degree %d.\n",str,ans);
	}
	return 0;
}
/*

Introduction to the problem
 
A well-known trick to know if an integer N is a multiple of nine is to compute the sum S of its digits. If S is a multiple of nine, then so is N. This is a recursive test, and the depth of the recursion needed to obtain the answer on N is called the 9-degree of N.
 
Your job is, given a positive number N, determine if it is a multiple of nine and,if it is, its 9-degree.
 
Description of the input
 
The input is a file such that each line contains a positive number. A line containing the number 0 is the end of the input. The given numbers can contain up to 1000 digits.
 
Description of the output
 
The output of the program shall indicate, for each input number, if it is a multiple of nine, and in case it is, the value of its nine-degree. See the sample output for an example of the expected formatting of the output.
 
Sample input:
 
999999999999999999999
9
9999999999999999999999999999998
0
 
Sample output
 
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.
 
--------------------------------------------------------------------------------

Problem setter: David Deharbe, Copyright 2005 UFRN. All rights reserved.
 
*/