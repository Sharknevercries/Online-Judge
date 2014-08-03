/* 1254539	 Mar 1, 2012 6:25:22 PM	Shark	 146A - Lucky Ticket	 GNU C++	Accepted	 30 ms	 1300 K */
#include<stdio.h>
int main(){
	int n;
	char str[100];
	while(scanf("%d%s",&n,str)==2){
		int count1=0,count2=0;
		bool IS=true;
		for(int i=0;str[i]!='\0'&&IS;i++)
			if(str[i]!='4'&&str[i]!='7')
				IS=false;
		if(IS){
			for(int i=0;i<n/2;i++)
				count1+=str[i]-'0';
			for(int i=n/2;i<n;i++)
				count2+=str[i]-'0';
			if(count1==count2)
				puts("YES");
			else
				puts("NO");
		}
		else
			puts("NO");
	}
	return 0;
}
/*

Petya loves lucky numbers very much. Everybody knows that lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya loves tickets very much. As we know, each ticket has a number that is a positive integer. Its length equals n (n is always even). Petya calls a ticket lucky if the ticket's number is a lucky number and the sum of digits in the first half (the sum of the first n / 2 digits) equals the sum of digits in the second half (the sum of the last n / 2 digits). Check if the given ticket is lucky.

Input

The first line contains an even integer n (2 ≤ n ≤ 50) — the length of the ticket number that needs to be checked. The second line contains an integer whose length equals exactly n — the ticket number. The number may contain leading zeros.

Output

On the first line print "YES" if the given ticket number is lucky. Otherwise, print "NO" (without the quotes).

input

2
47
4
4738
4
4774

output

NO
NO
YES

Note

In the first sample the sum of digits in the first half does not equal the sum of digits in the second half (4 ≠ 7).

In the second sample the ticket number is not the lucky number.

*/