/* 6763814	 Jun 1, 2014 2:40:15 PM	Shark	 435B - Pasha Maximizes	 GNU C++	Accepted	 31 ms	 0 KB */
#include<cstdio>
#include<iostream>
int main(){
	char S[100];
	int m;
	while (scanf("%s%d", S, &m) == 2){
		int cost = 0, start = 0;
		int C[10] = { 0 };
		for (int i = 0; S[i] != '\0'; i++)
			C[S[i] - '0']++;
		while (cost < m){
			bool swap = false;
			for (int i = 9; i >= 0; i--){
				if (C[i] > 0){
					for (int j = start; S[j] != '\0'; j++){
						if (S[j] - '0' == i){
							if (cost + j - start <= m){
								C[i]--;
								cost += j - start;
								for (int k = j; k > start; k--)
									std::swap(S[k], S[k - 1]);
								swap = true;
								start++;
								break;
							}
							else
								break;
						}
					}
				}
				if (swap)
					break;
			}
			if (!swap)
				break;
		}
		printf("%s\n", S);
	}
	return 0;
}
/*

B. Pasha Maximizes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pasha has a positive integer a without leading zeroes. Today he decided that the number is too small and he should make it larger. Unfortunately, the only operation Pasha can do is to swap two adjacent decimal digits of the integer.

Help Pasha count the maximum number he can get if he has the time to make at most k swaps.

Input
The single line contains two integers a and k (1 ≤ a ≤ 1018; 0 ≤ k ≤ 100).

Output
Print the maximum number that Pasha can get if he makes at most k swaps.

Sample test(s)
input
1990 1
output
9190
input
300 0
output
300
input
1034 2
output
3104
input
9090000078001234 6
output
9907000008001234

*/