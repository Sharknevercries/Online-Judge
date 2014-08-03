/* 5349000	 Dec 4, 2013 8:09:19 PM	Shark	 220A - Little Elephant and Problem	 GNU C++	Accepted	92 ms	800 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[100000];
		int S[100000];
		int count = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &M[i]);
			S[i] = M[i];
		}
		std::sort(S, S + n);
		for (int i = 0; i < n; i++){
			if (S[i] != M[i])
				count++;
		}
		if (count == 0 || count == 2)
			puts("YES");
		else
			puts("NO");
		
	}
	return 0;
}
/*

A. Little Elephant and Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Little Elephant has got a problem — somebody has been touching his sorted by non-decreasing array a of length n and possibly swapped some elements of the array.

The Little Elephant doesn't want to call the police until he understands if he could have accidentally changed the array himself. He thinks that he could have accidentally changed array a, only if array a can be sorted in no more than one operation of swapping elements (not necessarily adjacent). That is, the Little Elephant could have accidentally swapped some two elements.

Help the Little Elephant, determine if he could have accidentally changed the array a, sorted by non-decreasing, himself.

Input
The first line contains a single integer n (2 ≤ n ≤ 105) — the size of array a. The next line contains n positive integers, separated by single spaces and not exceeding 109, — array a.

Note that the elements of the array are not necessarily distinct numbers.

Output
In a single line print "YES" (without the quotes) if the Little Elephant could have accidentally changed the array himself, and "NO" (without the quotes) otherwise.

Sample test(s)
input
2
1 2
output
YES
input
3
3 2 1
output
YES
input
4
4 3 2 1
output
NO
Note
In the first sample the array has already been sorted, so to sort it, we need 0 swap operations, that is not more than 1. Thus, the answer is "YES".

In the second sample we can sort the array if we swap elements 1 and 3, so we need 1 swap operation to sort the array. Thus, the answer is "YES".

In the third sample we can't sort the array in more than one swap operation, so the answer is "NO".

*/