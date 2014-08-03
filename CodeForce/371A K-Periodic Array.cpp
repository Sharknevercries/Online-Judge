/* 5390344	 Dec 8, 2013 5:10:42 PM	Shark	 A - K-Periodic Array	 GNU C++	Accepted	15 ms	0 KB */
#include<stdio.h>
int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		int M[100];
		bool found = true;
		int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &M[i]);
		for (int i = 0; i < k; i++){
			for (int j = 0; j < n / k; j++){
				if (M[i] != M[i + j*k])
					found = false;
			}
		}
		if (found)
			puts("0");
		else{
			for (int i = 0; i < k; i++){
				int A = 0, B = 0;
				for (int j = 0; j < n / k; j++){
					if (M[i + j*k] == 1)
						A++;
					else
						B++;
				}
				if (A>B)
					ans += B;
				else
					ans += A;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*

A. K-Periodic Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
This task will exclusively concentrate only on the arrays where all elements equal 1 and/or 2.

Array a is k-period if its length is divisible by k and there is such array b of length k, that a is represented by array b written exactly  times consecutively. In other words, array a is k-periodic, if it has period of length k.

For example, any array is n-periodic, where n is the array length. Array [2, 1, 2, 1, 2, 1] is at the same time 2-periodic and 6-periodic and array [1, 2, 1, 1, 2, 1, 1, 2, 1] is at the same time 3-periodic and 9-periodic.

For the given array a, consisting only of numbers one and two, find the minimum number of elements to change to make the array k-periodic. If the array already is k-periodic, then the required value equals 0.

Input
The first line of the input contains a pair of integers n, k (1 ≤ k ≤ n ≤ 100), where n is the length of the array and the value n is divisible by k. The second line contains the sequence of elements of the given array a1, a2, ..., an (1 ≤ ai ≤ 2), ai is the i-th element of the array.

Output
Print the minimum number of array elements we need to change to make the array k-periodic. If the array already is k-periodic, then print 0.

Sample test(s)
input
6 2
2 1 2 2 2 1
output
1
input
8 4
1 1 2 1 1 1 2 1
output
0
input
9 3
2 1 1 1 2 1 1 1 2
output
3
Note
In the first sample it is enough to change the fourth element from 2 to 1, then the array changes to [2, 1, 2, 1, 2, 1].

In the second sample, the given array already is 4-periodic.

In the third sample it is enough to replace each occurrence of number two by number one. In this case the array will look as [1, 1, 1, 1, 1, 1, 1, 1, 1] — this array is simultaneously 1-, 3- and 9-periodic.

*/