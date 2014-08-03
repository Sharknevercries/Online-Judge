/* 1205697	 Feb 20, 2012 5:11:54 PM	Shark	 110A - Nearly Lucky Number	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str[100];
	while(scanf("%s",str)==1){
		int count=0;
		for(int i=0;str[i]!='\0';i++)
			if(str[i]=='4'||str[i]=='7')
				count++;
		bool IS=true;
		if(count==0)
			IS=false;
		while(count>0&&IS){
			if(count%10==4||count%10==7)
				;
			else
				IS=false;
			count/=10;
		}
		if(IS)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. He wonders whether number n is a nearly lucky number.

Input

The only line contains an integer n (1 ≤ n ≤ 1018).

Please do not use the %lld specificator to read or write 64-bit numbers in С++. It is preferred to use the cin, cout streams or the %I64d specificator.

Output

Print on the single line "YES" if n is a nearly lucky number. Otherwise, print "NO" (without the quotes).

input
40047
7747774
1000000000000000000

output

NO
YES
NO

Note

In the first sample there are 3 lucky digits (first one and last two), so the answer is "NO".

In the second sample there are 7 lucky digits, 7 is lucky number, so the answer is "YES".

In the third sample there are no lucky digits, so the answer is "NO".

*/