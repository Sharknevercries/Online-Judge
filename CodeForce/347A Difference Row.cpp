/* 4566942	 Sep 26, 2013 4:01:53 PM	Shark	 347A - Difference Row	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y) { int temp=x;	x=y;	y=temp;	}

int main(){
	int n;
	int M[10000];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&M[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(M[i]>M[j])
				SWAP(M[i],M[j]);
	SWAP(M[0],M[n-1]);
	printf("%d",M[0]);
	for(int i=1;i<n;i++)
		printf(" %d",M[i]);
	putchar('\n');
	return 0;
}
/*

A. Difference Row
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You want to arrange n integers a1, a2, ..., an in some order in a row. Let's define the value of an arrangement as the sum of differences between all pairs of adjacent integers.

More formally, let's denote some arrangement as a sequence of integers x1, x2, ..., xn, where sequence x is a permutation of sequence a. The value of such an arrangement is (x1 - x2) + (x2 - x3) + ... + (xn - 1 - xn).

Find the largest possible value of an arrangement. Then, output the lexicographically smallest sequence x that corresponds to an arrangement of the largest possible value.

Input

The first line of the input contains integer n (2 ≤ n ≤ 100). The second line contains n space-separated integers a1, a2, ..., an (|ai| ≤ 1000).

Output

Print the required sequence x1, x2, ..., xn. Sequence x should be the lexicographically smallest permutation of a that corresponds to an arrangement of the largest possible value.

Sample test(s)

input
5
100 -100 50 0 -50

output
100 -50 0 50 -100 

Note
In the sample test case, the value of the output arrangement is (100 - ( - 50)) + (( - 50) - 0) + (0 - 50) + (50 - ( - 100)) = 200. No other arrangement has a larger value, and among all arrangements with the value of 200, the output arrangement is the lexicographically smallest one.

Sequence x1, x2, ... , xp is lexicographically smaller than sequence y1, y2, ... , yp if there exists an integer r (0 ≤ r < p) such that x1 = y1, x2 = y2, ... , xr = yr and xr + 1 < yr + 1.

*/