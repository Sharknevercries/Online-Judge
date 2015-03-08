/* 10066147	2015-02-28 16:11:33	Shark	519B - A and B and Compilation Errors	GNU C++	Accepted	93 ms	1200 KB */
#include<bits\stdc++.h>
using namespace std;
int A[100005];
int B[100005];
int C[100005];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A + i);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", B + i);
	for (int i = 0; i < n - 2; i++)
		scanf("%d", C + i);
	sort(A, A + n);
	sort(B, B + n - 1);
	sort(C, C + n - 2);
	for (int i = 0; i < n; i++){
		if (A[i] != B[i]){
			printf("%d\n", A[i]);
			break;
		}
	}
	for (int i = 0; i < n - 1; i++){
		if (B[i] != C[i]){
			printf("%d\n", B[i]);
			break;
		}
	}
	return 0;
}
/*

B. A and B and Compilation Errors
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A and B are preparing themselves for programming contests.

B loves to debug his code. But before he runs the solution and starts debugging, he has to first compile the code.

Initially, the compiler displayed n compilation errors, each of them is represented as a positive integer. After some effort, B managed to fix some mistake and then another one mistake.

However, despite the fact that B is sure that he corrected the two errors, he can not understand exactly what compilation errors disappeared — the compiler of the language which B uses shows errors in the new order every time! B is sure that unlike many other programming languages, compilation errors for his programming language do not depend on each other, that is, if you correct one error, the set of other error does not change.

Can you help B find out exactly what two errors he corrected?

Input
The first line of the input contains integer n (3 ≤ n ≤ 105) — the initial number of compilation errors.

The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the errors the compiler displayed for the first time.

The third line contains n - 1 space-separated integers b1, b2, ..., bn - 1 — the errors displayed at the second compilation. It is guaranteed that the sequence in the third line contains all numbers of the second string except for exactly one.

The fourth line contains n - 2 space-separated integers с1, с2, ..., сn - 2 — the errors displayed at the third compilation. It is guaranteed that the sequence in the fourth line contains all numbers of the third line except for exactly one.

Output
Print two numbers on a single line: the numbers of the compilation errors that disappeared after B made the first and the second correction, respectively.

Sample test(s)
input
5
1 5 8 123 7
123 7 5 1
5 1 7
output
8
123
input
6
1 4 3 3 5 7
3 7 5 4 3
4 3 7 5
output
1
3
Note
In the first test sample B first corrects the error number 8, then the error number 123.

In the second test sample B first corrects the error number 1, then the error number 3. Note that if there are multiple errors with the same number, B can correct only one of them in one step.

*/