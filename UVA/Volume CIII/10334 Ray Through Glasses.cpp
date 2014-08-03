/* 9350691 10334 Ray Through Glasses Accepted C++ 0.008 2011-10-09 10:13:56 */
#include<stdio.h>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
char DP[1001][300];
void plus(char str1[],char str2[],char result[]){
	int len_1=strlen(str1);
	int len_2=strlen(str2);
	int result_len=MAX(len_1,len_2)+1;
	int i,j,k,temp,carry;

	for(i=0;i<result_len;i++)
		result[i]='0';
	result[i]='\0';
	
	for(i=len_1-1,j=len_2-1,k=result_len-1,carry=0;i>=0||j>=0;){
		if(i>=0&&j>=0)
			temp=str1[i--]-'0'+str2[j--]-'0'+carry;
		else if(i>=0)
			temp=str1[i--]-'0'+carry;
		else
			temp=str2[j--]-'0'+carry;
		carry=temp/10;
		temp%=10;
		result[k--]=temp+'0';
	}
	result[k--]=carry+'0';
	if(result[0]=='0')
		memmove(&result[0],&result[1],sizeof(char)*result_len);
}
void make_DP(){
	DP[0][0]='1';
	DP[1][0]='2';
	DP[0][1]=DP[1][1]='\0';
	for(int i=2;i<=1000;i++)
		plus(DP[i-2],DP[i-1],DP[i]);	
}
int main(){
	make_DP();
	int n;
	while(scanf("%d",&n)==1)
		printf("%s\n",DP[n]);
	return 0;
}
/*

Suppose we put two panes of glass back-to-back. How many ways are there for light rays to pass through or be reflected after changing direction n times ? Following figure shows the situations when the value of n is 0, 1 and 2. 
   
 Input  

It is a set of lines with an integer n where 0 <= n <= 1000 in each of them. 

Output  

For every one of these integers a line containing as described above. 

Sample Input  

0
1
2

 Sample Output  
 
1
2
3

--------------------------------------------------------------------------------

Mohammad Sajjad Hossain 
2002-06-16 

*/