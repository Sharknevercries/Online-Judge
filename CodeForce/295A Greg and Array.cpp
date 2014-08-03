/* 5356124	 Dec 5, 2013 9:32:51 PM	Shark	 295A - Greg and Array	 GNU C++	Accepted	 248 ms	 4700 KB */
#include<stdio.h>
#include<string.h>
long long int A[100001];
long long int B[100001]; // record how much value to fix
long long int C[100001]; // record how many operations
long long int M[100001][3];
int main(){
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(C, 0, sizeof(C));
		memset(M, 0, sizeof(M));
		for (int i = 0; i < n; i++)
			scanf("%lld", &A[i]);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 3; j++)
				scanf("%lld", &M[i][j]);
			M[i][0]--, M[i][1]--;
		}
		for (int i = 0; i < k; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			C[a]++, C[b + 1]--;
		}
		long long int tmp = 0;
		for (int i = 0; i < m; i++){
			tmp += C[i];
			B[M[i][0]] += tmp*M[i][2];
			B[M[i][1] + 1] -= tmp*M[i][2];
		}
		tmp = 0;
		for (int i = 0; i < n; i++){
			tmp += B[i];
			if (i == 0)
				printf("%lld", tmp + A[i]);
			else
				printf(" %lld", tmp + A[i]);
		}
		putchar('\n');
	}
	return 0;
}
/*

A. Greg and Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Greg has an array a = a1, a2, ..., an and m operations. Each operation looks as: li, ri, di, (1 ≤ li ≤ ri ≤ n). To apply operation i to the array means to increase all array elements with numbers li, li + 1, ..., ri by value di.

Greg wrote down k queries on a piece of paper. Each query has the following form: xi, yi, (1 ≤ xi ≤ yi ≤ m). That means that one should apply operations with numbers xi, xi + 1, ..., yi to the array.

Now Greg is wondering, what the array a will be after all the queries are executed. Help Greg.

Input
The first line contains integers n, m, k (1 ≤ n, m, k ≤ 105). The second line contains n integers: a1, a2, ..., an (0 ≤ ai ≤ 105) — the initial array.

Next m lines contain operations, the operation number i is written as three integers: li, ri, di, (1 ≤ li ≤ ri ≤ n), (0 ≤ di ≤ 105).

Next k lines contain the queries, the query number i is written as two integers: xi, yi, (1 ≤ xi ≤ yi ≤ m).

The numbers in the lines are separated by single spaces.

Output
On a single line print n integers a1, a2, ..., an — the array after executing all the queries. Separate the printed numbers by spaces.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.

Sample test(s)
input
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3
output
9 18 17
input
1 1 1
1
1 1 1
1 1
output
2
input
4 3 6
1 2 3 4
1 2 1
2 3 2
3 4 4
1 2
1 3
2 3
1 2
1 3
2 3
output
5 18 31 20

*/