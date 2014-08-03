/* 5413770	 Dec 12, 2013 12:50:21 PM	Shark	 364A - Matrix	 GNU C++	Accepted	 46 ms	 100 KB */
#include<cstdio>
#include<string.h>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int sum[4001] = { 0 };
		int Q[36001] = { 0 };
		int total = 0;
		char S[4001];
		int len;
		long long int ans = 0;
		scanf("%s", S);
		len = strlen(S);
		for (int i = 1; i <= len; i++){
			sum[i] = sum[i - 1] + S[i - 1] - '0';
			for (int j = 0; j < i; j++)
				Q[sum[i] - sum[j]]++;
		}
		for (int i = 0; i <= 36000; i++)
			total += Q[i];
		for (int i = 1; i <= len; i++){
			for (int j = i; j <= len; j++){
				if (sum[j] - sum[i - 1] > 0 && n % (sum[j] - sum[i - 1]) == 0){
					if (n / (sum[j] - sum[i - 1]) <= 36000)
						ans += Q[n / (sum[j] - sum[i - 1])];
				}
				else if (sum[j] - sum[i - 1] == 0 && n == 0){
					ans += total;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

A. Matrix
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a string of decimal digits s. Let's define bij = si·sj. Find in matrix b the number of such rectangles that the sum bij for all cells (i, j) that are the elements of the rectangle equals a in each rectangle.

A rectangle in a matrix is a group of four integers (x, y, z, t) (x ≤ y, z ≤ t). The elements of the rectangle are all cells (i, j) such that x ≤ i ≤ y, z ≤ j ≤ t.

Input
The first line contains integer a (0 ≤ a ≤ 109), the second line contains a string of decimal integers s (1 ≤ |s| ≤ 4000).

Output
Print a single integer — the answer to a problem.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Sample test(s)
input
10
12345
output
6
input
16
439873893693495623498263984765
output
40

*/