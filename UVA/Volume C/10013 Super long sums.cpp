/* 9047301 10013 Super long sums Accepted C++ 0.624 2011-07-14 06:05:18 */
#include<stdio.h>
#include<string.h>
#define SIZE sizeof(char)
static char str1[1000001];
static char str2[1000001];
static char result[1000001];
int main(){
	bool first=true;
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		if(!first)
			putchar('\n');
		first=false;
		int carry,temp;
		int a,b;
		int n,j;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d%d",&a,&b);
			str1[j]='0'+a;
			str2[j]='0'+b;
		}
		str1[n]=str2[n]=result[n]='\0';
		for(j=n-1,carry=0;j>=0;j--){
			temp=str1[j]-'0'+str2[j]-'0'+carry;
			carry=temp/10;
			temp%=10;
			result[j]=temp+'0';
		}
		if(carry>0){
			memmove(&result[1],&result[0],SIZE*(n+1));
			result[0]='0'+carry;
		}
		printf("%s\n",result);
	}
	return 0;
}
/*

The creators of a new programming language D++ have found out that whatever limit for SuperLongInt type they make, sometimes programmers need to operate even larger numbers. A limit of 1000 digits is so small... You have to find the sum of two numbers with maximal size of 1.000.000 digits.

The Input

The first line of a input file is an integer N, then a blank line followed by N input blocks. The first line of an each input block contains a single number M (1<=M<=1000000) ¡X the length of the integers (in order to make their lengths equal, some leading zeroes can be added). It is followed by these integers written in columns. That is, the next M lines contain two digits each, divided by a space. Each of the two given integers is not less than 1, and the length of their sum does not exceed M.

There is a blank line between input blocks.

The Output

Each output block should contain exactly M digits in a single line representing the sum of these two integers.

There is a blank line between output blocks.

Sample Input
2

4
0 4
4 2
6 8
3 7

3
3 0
7 9
2 8

 Sample Output
4750

470

*/