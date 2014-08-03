/* 1309059	 Mar 7, 2012 6:43:41 PM	Shark	 160B - Unlucky Ticket	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
#include<algorithm>
bool min_check(int A[],int B[],int n){
	for(int i=0;i<n;i++)
		if(A[i]>=B[i])
			return false;
	return true;
}
bool max_check(int A[],int B[],int n){
	for(int i=0;i<n;i++)
		if(A[i]<=B[i])
			return false;
	return true;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		char str[1000];
		int M1[100],M2[100];
		scanf("%s",str);
		for(int i=0;i<n;i++)
			M1[i]=str[i]-'0';
		for(int i=n;i<2*n;i++)
			M2[i-n]=str[i]-'0';
		std::sort(M1,M1+n);
		std::sort(M2,M2+n);
		if(min_check(M1,M2,n)||max_check(M1,M2,n))
			puts("YES");
		else
			puts("NO");

	}
	return 0;
}
/*

Each of you probably has your personal experience of riding public transportation and buying tickets. After a person buys a ticket (which traditionally has an even number of digits), he usually checks whether the ticket is lucky. Let us remind you that a ticket is lucky if the sum of digits in its first half matches the sum of digits in its second half.

But of course, not every ticket can be lucky. Far from it! Moreover, sometimes one look at a ticket can be enough to say right away that the ticket is not lucky. So, let's consider the following unluckiness criterion that can definitely determine an unlucky ticket. We'll say that a ticket is definitely unlucky if each digit from the first half corresponds to some digit from the second half so that each digit from the first half is strictly less than the corresponding digit from the second one or each digit from the first half is strictly more than the corresponding digit from the second one. Each digit should be used exactly once in the comparisons. In other words, there is such bijective correspondence between the digits of the first and the second half of the ticket, that either each digit of the first half turns out strictly less than the corresponding digit of the second half or each digit of the first half turns out strictly more than the corresponding digit from the second half.

For example, ticket 2421 meets the following unluckiness criterion and will not be considered lucky (the sought correspondence is 2 > 1 and 4 > 2), ticket 0135 also meets the criterion (the sought correspondence is 0 < 3 and 1 < 5), and ticket 3754 does not meet the criterion.

You have a ticket in your hands, it contains 2n digits. Your task is to check whether it meets the unluckiness criterion.

Input

The first line contains an integer n (1 ≤ n ≤ 100). The second line contains a string that consists of 2n digits and defines your ticket.

Output

In the first line print "YES" if the ticket meets the unluckiness criterion. Otherwise, print "NO" (without the quotes).

input

2
2421
2
0135
2
3754

output

YES
YES
NO

*/