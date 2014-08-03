/* 4744168	 Oct 11, 2013 3:18:41 PM	Shark	 26A - Almost Prime	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<math.h>
int main(){
	int Prime[3000];
	Prime[0]=2,Prime[1]=3;
	int ptr=2;
	for(int i=5;i<=3500;i+=2){
		int j;
		for(j=0;j<ptr;j++)
			if( i%Prime[j]==0 )
				break;
		if( j>=ptr )
			Prime[ptr++]=i;
	}

	int n;
	while( scanf("%d",&n)==1 ){
		int ans=0;
		for(int i=6;i<=n;i++){
			int count=0;
			for(int j=0;Prime[j]<=i;j++)
				if( i%Prime[j]==0 )
					count++;
			if( count==2 )
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

A. Almost Prime
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A number is called almost prime if it has exactly two distinct prime divisors. For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not. Find the amount of almost prime numbers which are between 1 and n, inclusive.

Input
Input contains one integer number n (1 ≤ n ≤ 3000).

Output
Output the amount of almost prime numbers between 1 and n, inclusive.

Sample test(s)
input
10
output
2
input
21
output
8

*/