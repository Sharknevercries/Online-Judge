/* 4676870	 Oct 5, 2013 7:04:04 AM	Shark	 352A - Jeff and Digits	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#define SWAP(x,y){ int temp=x;	x=y;	y=temp;	}

int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int S[2]={0}; // (0,5)
		int ptr=0;
		char str[10000];
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			if( tmp==5 )
				S[1]++;
			else
				S[0]++;
		}
		if( S[0]>0 )
			if( S[1]>=9 ){
				for(int i=0;i<S[0];i++)
					str[ptr++]='0';
				int count=S[1];
				while( count>=9 ){
					for(int i=0;i<9;i++)
						str[ptr++]='5';
					count-=9;
				}
				str[ptr]='\0';
				for(int i=0,j=ptr-1;i<j;i++,j--)
					SWAP(str[i],str[j]);
				printf("%s\n",str);
			}
			else
				puts("0");
		else
			puts("-1");

	}
	return 0;
}
/*

A. Jeff and Digits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jeff's got n cards, each card contains either digit 0, or digit 5. Jeff can choose several cards and put them in a line so that he gets some number. What is the largest possible number divisible by 90 Jeff can make from the cards he's got?

Jeff must make the number without leading zero. At that, we assume that number 0 doesn't contain any leading zeroes. Jeff doesn't have to use all the cards.

Input
The first line contains integer n (1 ≤ n ≤ 103). The next line contains n integers a1, a2, ..., an (ai = 0 or ai = 5). Number ai represents the digit that is written on the i-th card.

Output
In a single line print the answer to the problem — the maximum number, divisible by 90. If you can't make any divisible by 90 number from the cards, print -1.

Sample test(s)
input
4
5 0 5 0
output
0
input
11
5 5 5 5 5 5 5 5 0 5 5
output
5555555550
Note
In the first test you can make only one number that is a multiple of 90 — 0.

In the second test you can make number 5555555550, it is a multiple of 90.

*/