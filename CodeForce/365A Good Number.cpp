/* 5271000	 Nov 27, 2013 3:05:55 PM	Shark	 365A - Good Number	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		int count = 0;
		for (int i = 0; i < n; i++){
			char S[100];
			bool F[10] = { false };
			bool NOT = false;
			scanf("%s", S);
			for (int j = 0; S[j] != '\0' && !NOT; j++)
				F[S[j] - '0'] = true;
			for (int j = 0; j <= k; j++){
				if (!F[j])
					NOT = true;
			}
			if (!NOT)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
/*

A. Good Number
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's call a number k-good if it contains all digits not exceeding k (0, ..., k). You've got a number k and an array a containing n numbers. Find out how many k-good numbers are in a (count each number every time it occurs in array a).

Input
The first line contains integers n and k (1 ≤ n ≤ 100, 0 ≤ k ≤ 9). The i-th of the following n lines contains integer ai without leading zeroes (1 ≤ ai ≤ 109).

Output
Print a single integer — the number of k-good numbers in a.

Sample test(s)
input
10 6
1234560
1234560
1234560
1234560
1234560
1234560
1234560
1234560
1234560
1234560
output
10
input
2 1
1
10
output
1

*/