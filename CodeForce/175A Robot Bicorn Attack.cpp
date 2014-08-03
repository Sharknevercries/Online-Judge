/* 5001384	 Nov 6, 2013 11:41:54 AM	Shark	 175A - Robot Bicorn Attack	 GNU C++	Accepted	62 ms	0 KB */
#include<stdio.h>
#include<string.h>
#define LIMIT 1000000
#define FAIL 1000001
char str[100];
int len;
int get(int start,int end){
	if( start+1<=end&&str[start]=='0' )
		return FAIL;

	int tmp=0;
	for(int i=start;i<=end;i++)
		tmp=tmp*10+str[i]-'0';
	return tmp;
}
int main(){
	while( scanf("%s",str)==1 ){
		int i,j,k,ans;

		len=strlen(str);
		ans=-1;
		for(i=0;i<len&&i<=6;i++)
			for(j=i+1;j<len-1&&j-i<=7;j++)
				if( len-1-j<=7 ){
					int a,b,c;
					a=get(0,i);
					b=get(i+1,j);
					c=get(j+1,len-1);
					if( a<=LIMIT&&b<=LIMIT&&c<=LIMIT )
						if( a+b+c>ans )
							ans=a+b+c;
				}
		printf("%d\n",ans);
	}
	return 0;
}
/*

A. Robot Bicorn Attack
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya plays Robot Bicorn Attack.

The game consists of three rounds. For each one a non-negative integer amount of points is given. The result of the game is the sum of obtained points. Vasya has already played three rounds and wrote obtained points one by one (without leading zeros) into the string s. Vasya decided to brag about his achievement to the friends. However, he has forgotten how many points he got for each round. The only thing he remembers is the string s.

Help Vasya to find out what is the maximum amount of points he could get. Take into account that Vasya played Robot Bicorn Attack for the first time, so he could not get more than 1000000 (106) points for one round.

Input
The only line of input contains non-empty string s obtained by Vasya. The string consists of digits only. The string length does not exceed 30 characters.

Output
Print the only number ¡X the maximum amount of points Vasya could get. If Vasya is wrong and the string could not be obtained according to the rules then output number -1.

Sample test(s)
input
1234
output
37
input
9000
output
90
input
0009
output
-1
Note
In the first example the string must be split into numbers 1, 2 and 34.

In the second example the string must be split into numbers 90, 0 and 0.

In the third example the string is incorrect, because after splitting the string into 3 numbers number 00 or 09 will be obtained, but numbers cannot have leading zeroes.

*/