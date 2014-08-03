/* 8892377 10633 Rare Easy Problem Accepted C++ 0.008 2011-05-27 11:03:38 */
#include<stdio.h>
int main(){
	unsigned long long m;
	while(scanf("%llu",&m)==1){
		if(m==0) break;
		unsigned long long result[100]={0};
		unsigned long long a,b;
		int index;
		for(a=m/9,b=m%9,index=0;a>0&&(b>=0&&b<=9);a--,b+=9)
			result[index++]=10*a+b;
		printf("%llu",result[--index]);
		for(index--;index>=0;)
			printf(" %llu",result[index--]);
		putchar('\n');
	}
	return 0;
}
/*
 
N is a random number, which for some reason, is at least two digits.  John Doe, a nondescript man, performs an operation on N: he chops off the last digit to form a new number M, and then finds N-M.  This excites him in a hard-to-justify way.  He then tells you N-M.  Thrilled by the fascinating back-story behind this number, you make it your life goal to figure out what N was.

By the way, John was later eaten by a tiger.

Input  

Input consists of multiple lines, one line per case.  Each line contains a single positive integer between 10 and 10^18 inclusive, giving the value of N-M.  Input is terminated by a line containing 0.

Output 

For each case, print one line containing the possible values of N in sorted order.  Separate consecutive numbers with a single space.

Sample Input                            

18
0 

Output for Sample Input

19 20

--------------------------------------------------------------------------------

Problemsetter: Derek Kisman, Member of Elite Problemsetters' Panel
Special Thanks: Monirul Hasan, Member of Elite Problemsetters' Panel (Alternate Sol and Title of the Problem :)) 
¡§Without the constant support and, yes, competition, provided by all of the talented people here, many of us could not achieve our full potential; nor even, perhaps, realize what that potential is.¡¨

-Derek Kisman

*/