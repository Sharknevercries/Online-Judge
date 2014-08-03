/* 4752457	 Oct 12, 2013 9:33:13 AM	Shark	 B - Reading	 GNU C++	Accepted	60 ms	136 KB */
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y) { int tmp=x;	x=y;	y=tmp;	}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	while( scanf("%d%d",&n,&k)==2 ){
		int M[1000];
		int N[1000];
		int S[1000];
		int min;
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		for(int i=0;i<n;i++)
			N[i]=i;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if( M[i]<M[j] ){
					SWAP(M[i],M[j]);
					SWAP(N[i],N[j]);
				}
		printf("%d\n",M[k-1]);

		for(int i=0;i<k;i++)
			S[i]=N[i]+1;
		for(int i=0;i<k;i++)
			for(int j=i+1;j<k;j++)
				if( S[i]>S[j] )
					SWAP(S[i],S[j]);
		printf("%d",S[0]);
		for(int i=1;i<k;i++)
			printf(" %d",S[i]);
		putchar('\n');
	}
	return 0;
}
/*

B. Reading
time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt
Vasya is going to the Olympics in the city Ntown by train. The boy wants to read the textbook to prepare for the Olympics. He counted that he needed k hours for this. He also found that the light in the train changes every hour. The light is measured on a scale from 0 to 100, where 0 is very dark, and 100 is very light.

Vasya has a train lighting schedule for all n hours of the trip — n numbers from 0 to 100 each (the light level in the first hour, the second hour and so on). During each of those hours he will either read the whole time, or not read at all. He wants to choose k hours to read a book, not necessarily consecutive, so that the minimum level of light among the selected hours were maximum. Vasya is very excited before the upcoming contest, help him choose reading hours.

Input
The first input line contains two integers n and k (1 ≤ n ≤ 1000, 1 ≤ k ≤ n) — the number of hours on the train and the number of hours to read, correspondingly. The second line contains n space-separated integers ai (0 ≤ ai ≤ 100), ai is the light level at the i-th hour.

Output
In the first output line print the minimum light level Vasya will read at. In the second line print k distinct space-separated integers b1, b2, ..., bk, — the indexes of hours Vasya will read at (1 ≤ bi ≤ n). The hours are indexed starting from 1. If there are multiple optimal solutions, print any of them. Print the numbers bi in an arbitrary order.

Sample test(s)
input
5 3
20 10 30 40 10
output
20
1 3 4 
input
6 5
90 20 35 40 60 100
output
35
1 3 4 5 6 
Note
In the first sample Vasya should read at the first hour (light 20), third hour (light 30) and at the fourth hour (light 40). The minimum light Vasya will have to read at is 20.

*/