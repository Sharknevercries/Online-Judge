/* 4566993	 Sep 26, 2013 4:10:59 PM	Shark	 347B - Fixed Points	 GNU C++	Accepted	30 ms	400 KB */
#include<stdio.h>
int main(){
	int n;
	int M[100000];
	int count=0;
	bool found=false;

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&M[i]);
	for(int i=0;i<n;i++)
		if(M[i]==i)
			count++;
	for(int i=0;i<n;i++)
		if(M[i]!=i&&M[M[i]]==i)
			found=true;
	if(found)
		count+=2;
	else if(count!=n)
		count++;
	printf("%d\n",count);
	return 0;
}
/*

B. Fixed Points
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation of length n is an integer sequence such that each integer from 0 to (n - 1) appears exactly once in it. For example, sequence [0, 2, 1] is a permutation of length 3 while both [0, 2, 2] and [1, 2, 3] are not.

A fixed point of a function is a point that is mapped to itself by the function. A permutation can be regarded as a bijective function. We'll get a definition of a fixed point in a permutation. An integer i is a fixed point of permutation a0, a1, ..., an - 1 if and only if ai = i. For example, permutation [0, 2, 1] has 1 fixed point and permutation [0, 1, 2] has 3 fixed points.

You are given permutation a. You are allowed to swap two elements of the permutation at most once. Your task is to maximize the number of fixed points in the resulting permutation. Note that you are allowed to make at most one swap operation.

Input
The first line contains a single integer n (1 ≤ n ≤ 105). The second line contains n integers a0, a1, ..., an - 1 — the given permutation.

Output
Print a single integer — the maximum possible number of fixed points in the permutation after at most one swap operation.

Sample test(s)
input
5
0 1 3 4 2
output
3

*/