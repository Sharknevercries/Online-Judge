/* 6958841	 2014-06-25 20:06:50	Shark	 440A - Forgotten Episode	 GNU C++	Accepted	 46 ms	 100 KB */
#include<cstdio>
#define abs(x) ( (x) >= 0 ? (x) : -(x) )
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		long long int M[50000];
		long long int avg = 0;
		long long int ans = 0;
		long long int remain = 0;
		for (int i = 0; i < n; i++)
			scanf("%lld", M + i);
		for (int i = 0; i < n; i++)
			avg += M[i];
		avg /= n;
		for (int i = 0; i < n; i++)
			M[i] -= avg;
		for (int i = 0; i < n; i++){
			remain += M[i];
			ans += abs(remain);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

B. Balancer
time limit per test0.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya has k matches, placed in n matchboxes lying in a line from left to right. We know that k is divisible by n. Petya wants all boxes to have the same number of matches inside. For that, he can move a match from its box to the adjacent one in one move. How many such moves does he need to achieve the desired configuration?

Input
The first line contains integer n (1 ≤ n ≤ 50000). The second line contains n non-negative numbers that do not exceed 109, the i-th written number is the number of matches in the i-th matchbox. It is guaranteed that the total number of matches is divisible by n.

Output
Print the total minimum number of moves.

Sample test(s)
input
6
1 6 2 5 3 7
output
12

*/