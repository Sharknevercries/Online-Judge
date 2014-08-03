/* 8877026 10515 Powers Et Al. Accepted C++ 0.068 2011-05-23 13:09:16 */
#include<stdio.h>
#include<string.h>
int main(){
	int table[10][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
	char str1[1000],str2[1000];
	while(scanf("%s%s",str1,str2)==2){
		if(str1[0]=='0'&&str2[0]=='0')
			break;
		if(str2[0]=='0')
			puts("1");
		else{
			int len1=strlen(str1);
			int len2=strlen(str2);
			int m;
			if(len2-2>=0)
				sscanf(str2+len2-2,"%d",&m);
			else
				sscanf(str2+len2-1,"%d",&m);
			if(m==0)
				printf("%d\n",table[str1[len1-1]-'0'][3]);
			else
				printf("%d\n",table[str1[len1-1]-'0'][(m-1)%4]);
		}
	}
	return 0;
}
/*

Finding the exponent of any number can be very troublesome as it grows exponentially J. But in this problem you will have to do a very simple task. Given two non-negative numbers m and n, you will have to find the last digit of mn in decimal number system.

Input

The input file contains less than 100000 lines. Each line contains two integers m and n (Less than 10^101). Input is terminated by a line containing two zeroes. This line should not be processed.

Output

For each set of input you must produce one line of output which contains a single digit. This digit is the last digit of mn.

Sample Input                               

2 2
2 5
0 0 

Output for Sample Input

4
2
 
--------------------------------------------------------------------------------

Problemsetter: Shahriar Manzoor

*/